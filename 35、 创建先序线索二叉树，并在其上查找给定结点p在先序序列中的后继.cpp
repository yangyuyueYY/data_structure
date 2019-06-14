/*
 * 创建先序线索二叉树，并在其上查找给定结点*p在先序序列中的后继
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	int ltag,rtag;
	struct node *lchild,*rchild;
}Node,*Tree;

/*
 * 线索化算法
 * @param Tree p 根结点
 * @param Tree *pre 中序前驱结点
 */
void inTreading(Tree p,Tree *pre)
{
	if(p){
		if(p->lchild == NULL){
			p->ltag = 1;
			p->lchild = *pre;
		}else{
			p->ltag = 0;
		}
		if((*pre)->rchild == NULL){
			(*pre)->rtag = 1;
			(*pre)->rchild = p;
		}else{
			(*pre)->rtag = 0;
		}
		*pre = p;
		inTreading(p->lchild,pre);
		inTreading(p->rchild,pre);
	}
}

/*
 * 给线索二叉树添加头结点，线索化
 * @param Tree *head 头结点
 * @param Tree T 头指针
 * @return int 是否添加成功，0成功，-1失败
 */
int inOrderThr(Tree *head,Tree T)
{
	Tree p;
	*head = (Tree)malloc(sizeof(Node));
	if((*head) == NULL){
		return -1;
	}
	(*head)->data = ' ';
	(*head)->ltag = 0;
	(*head)->rchild = *head;
	(*head)->rtag = 1;
	if(T == NULL){
		(*head)->lchild = *head;
	}else{
		(*head)->lchild = T;
		p = *head;
		inTreading(T,&p);
		p->rchild = *head;
		p->rtag = 1;
		(*head)->rchild = p;
	}
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
 * 查找给定结点在先序序列中的后继
 * @param Tree p 目标结点
 * @param Tree *q 结果结点
 * @return int 是否查找成功，0成功，-1失败
 */
int postNode(Tree p,Tree *q)
{
	if(p->rtag == 1){
		*q = p->rchild;
		return 0;
	}
	if(p->ltag == 0){
		*q = p->lchild;
		return 0;
	}
	if(p->rtag == 0){
		*q = p->rchild;
		return 0;
	}
	return -1;
}

/*
 * 查找值为x的结点
 * @param Tree head 头结点
 * @param char x 待查找数据
 * @return Tree 目标地址
 */
Tree search(Tree head,char x)
{
	Tree q;
	Tree p = head->lchild;
	while(p != head && p->data != x){
		postNode(p,&q);
		p = q;
	}
	return p;
}

/*
 * 二叉树的先序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void preDisplay(Tree T,char x,Tree *p)
{
	if(T){
		if(T->data == x){
			*p = T;
		}
		preDisplay(T->lchild,x,p);
		preDisplay(T->rchild,x,p);
	}
}

int main()
{
	Tree T,head,p,q;
	char x;
	printf("请输入二叉树创建序列:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
		return -1;
	}
	getchar();
	printf("请输入待查找数据:");
	scanf("%c",&x);
	preDisplay(T,x,&p);
	if(0 == inOrderThr(&head,T)){
		printf("线索化成功!\n");
	}else{
		printf("线索化失败!\n");
		return -1;
	}
	printf("其先序后继结点为:");
	postNode(p,&q);
	printf("%c",q->data);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/