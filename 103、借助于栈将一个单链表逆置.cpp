/*
 * 写一个算法，借助于栈将一个单链表逆置
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct node
{
	Data data;
	struct node *next;
}Node,*Stack;

typedef struct node1
{
	Data data;
	struct node1 *next;
}SqNode,*SqList;

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
 * 链栈：进栈
 * @param Stack *L 链栈头指针
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, Data x)
{ 
	Stack q;
	q = (Stack) malloc (sizeof(Node));
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
 * @param Data *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, Data *x)
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
 * 链式存储线性表(带头结点)：初始化
 * @param SqList *L 指向线性表头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initSqlist(SqList *L)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->next = NULL;
	strcpy(p->data.name,"");
	p->data.score = 0;
	*L = p;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：遍历
 * @param SqList L 线性表头指针
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L->next;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

/*
 * 链式存储线性表(带头结点)：尾插
 * @param SqList L 线性表头指针
 * @param Data data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertTailSqlist(SqList L, Data data)
{
	SqList p = L,q = NULL;
	while(p->next != NULL){
		p = p->next;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/* 
 * 逆置
 * @param SqList L单链表
 * @return int 是否逆置成功，0成功，-1失败
 */
int contrary(SqList L)
{
	Stack q;
	Data data;
	initStack(&q);
	SqList p = L->next;
	while(p){
		pushStack(&q,p->data);
		p = p->next;
	}
	p = L->next;
	while(isEmptyStack(q) != 0){
		popStack(&q,&data);
		p->data = data;
		p = p->next;
	}
	return 0;
}

int main()
{
	int n,i;
	SqList L;
	Data data;
	initSqlist(&L);
	printf("请输入数据数:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("请输入第%d个数据:",i+1);
		scanf("%s",data.name);
		scanf("%f",&data.score);
		insertTailSqlist(L,data);
	}
	printf("数据为:\n");
	displaySqlist(L);
	contrary(L);
	printf("逆置后数据为:\n");
	displaySqlist(L);
	return 0;
}
