/*
 * 已知带头结点的单链表L中的结点是按整数值递增排列的
 * 试写一算法，将值为x的结点插入到表L中，使得L仍然有序
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}SqNode,*SqList;

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
	p->data = 0;
	*L = p;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：插入
 * @param SqList L 线性表头指针
 * @param int pos 插入位置
 * @param int data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList L, int pos, int data)
{
	int i = 0;
	SqList p = L,q = NULL;
	while(i < pos-1 && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || NULL == p){
		printf("位置不合法\n");
		return -1;
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
		printf("%d ", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 链式存储线性表(带头结点)：尾插
 * @param SqList L 线性表头指针
 * @param int data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertTailSqlist(SqList L, int data)
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
 * 按序插入
 * @param SqList L 线性表头指针
 * @param int data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int orderSqlist(SqList L,int data)
{
	SqList p = L->next,q = L,s;
	while(p != NULL && p->data < data){
		p = p->next;
		q = q->next;
	}
	s = (SqList)malloc(sizeof(SqNode));
	if(s == NULL){
		printf("空间分配失败\n");
		return -1;
	}
	s->data = data;
	s->next = q->next;
	q->next = s;
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i,x;
	printf("请输入元素个数:");
	scanf("%d",&n);
	printf("请输入%d个有序整数:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L,x);
	}
	printf("链表构造成功!\n");
	printf("数据为:");
	displaySqlist(L);
	printf("请输入要插入数据:");
	scanf("%d",&x);
	printf("插入中……\n");
	orderSqlist(L,x);
	printf("插入后数据为:");
	displaySqlist(L);
	return 0;
}
