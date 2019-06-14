/*
 * 二叉树中所有叶子结点的路径
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}Node,*Tree;

typedef struct node1
{
	char data;
	struct node1 *next;
}Node1,*Stack;

/*
 * 链栈：初始化
 * @param Stack *L 指向链栈头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initStack(Stack *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链栈：判断栈空
 * @param Stack L 链栈头指针
 * @return int 链栈是否成功，0为空，1不为空
 */
int isEmptyStack(Stack L)
{
	if(L == NULL){
		return 0;
	}
	return 1;
}

/*
 * 链栈：得到栈顶
 * @param Stack L 链栈头指针
 * @param char *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack L,char *data)
{
	if(L == NULL){
		printf("栈为空!\n");
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * 链栈：进栈
 * @param Stack *L 链栈头指针
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, char x)
{ 
	Stack q;
	q = (Stack) malloc (sizeof(Node1));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = x;
	q->next = *L;
	*L = q;
	return 0;
}

/*
 * 链栈：出栈
 * @param Stack *L 链栈首地址
 * @param char *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, char *x)
{ 
	Stack p = *L;
	if(*L == NULL){
		printf("栈空!\n");
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
}

/*
 * 链栈：遍历
 * @param Stack L 链栈
 */
void displayStack(Stack L)
{
	char a[20],j;
	int i = 0;
	Stack p = L;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		a[i] = p->data;
		i ++;
		p = p->next;
	}
	for(j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}
	putchar('\n');
}


/* 
 * 创建二叉树
 * @param Tree *T 根结点指针
 * @return int 是否创建成功，0成功，-1失败
 */
int create(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}else{
		*T = (Tree)malloc(sizeof(Node));
		if(*T == NULL){
			return -1;
		}
		(*T)->data = ch;
		create(&(*T)->lchild);
		create(&(*T)->rchild);
	}
	return 0;
}

/*
 * 显示二叉树中所有叶子结点的路径
 * @param Tree T 根结点
 * @param Stack *s 栈指针
 */
void displayPath(Tree T,Stack *s)
{
	char x;
	if(T){
		pushStack(s,T->data);
		if(T->lchild == NULL && T->rchild == NULL){
			displayStack(*s);
		}else{
			displayPath(T->lchild,s);
			displayPath(T->rchild,s);
		}
		popStack(s,&x);
	}
}

int main()
{
	Tree T;
	Stack s;
	initStack(&s);
	printf("请输入创建字符串:");
	if(0 == create(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("所有结点路径为:\n");
	displayPath(T,&s);
	return 0;
}

/*
ABC##DE#G##F###
*/