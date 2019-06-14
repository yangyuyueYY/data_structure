/*
 * 二叉树的先序遍历（递归）、中序遍历（递归）、后序遍历（递归）、层次遍历(递归）、递归创建二叉树的二叉链表结构
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct node1
{
	Tree data;
	struct node1 *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue;

/*
 * 链队列的基本操作：初始化
 * @param Queue *q 链队列
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initQueue(Queue *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->next = NULL;
	p->data = NULL;
	q->L = p;
	q->R = p;
	return 0;
}

/*
 * 链队列：判断队空
 * @param Queue q 链队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.L == q.R){
		return 0;
	}
	return 1;
}

/*
 * 链队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param Tree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, Tree x)
{
	int i = 0;
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("空间分配失败\n");
		return -1;
	}
	s->data = x;
	s->next = q->R->next;
	q->R->next = s;
	q->R = s;
	return 0;
}

/*
 * 链队列：出队列
 * @param Queue *q 链队列首地址
 * @param Tree *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Tree *x)
{
	SqList p = q->L,s;
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 0;
}

/* 
 * 递归创建二叉树的二叉链表结构
 * @param Tree *T 二叉树根结点指针
 * @return int 是否创建成功,0成功，-1失败
 */
int createTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}
	else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * 二叉树的先序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * 二叉树的中序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void midDisplay(Tree T)
{
	if(T){
		midDisplay(T->lchild);
		printf("%c",T->data);
		midDisplay(T->rchild);
	}
}

/*
 * 二叉树的后序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void afterDisplay(Tree T)
{
	if(T){
		afterDisplay(T->lchild);
		afterDisplay(T->rchild);
		printf("%c",T->data);
	}
}

/*
 * 二叉树的层次遍历（递归）
 * @param Tree T 二叉树根结点
 */
void levelDisplay(Queue *q,Tree T)
{
	initQueue(q);
	char x;
	if(T){
		enQueue(q,T->data);
	}
	while(isEmptyQueue(*q) != 0){
		deQueue(q,&x);
		printf("%c",x->data);
		lif(x->lchild){
			enQueue(q,x->lchild);
		}
		if(x->rchild){
			enQueue(q,x->rchild);
		}
	}
}

int main()
{
	Queue q;
	Tree T;
	char a[20];
	int i=0;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("中序遍历为:");
	midDisplay(T);
	putchar('\n');
	printf("后序遍历为:");
	afterDisplay(T);
	putchar('\n');
	printf("层次遍历为:");
	levelDisplay(&q,T);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/