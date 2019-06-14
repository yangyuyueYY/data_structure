/*
 * 假设长度大于1的循环单链表中，既无头结点也无头指针，p为指向该链表中某一结点的指针，编写一个函数删除该结点的前驱结点
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
}CNode,* CList;

/*
 * 单向循环链表（不带头指针）：初始化
 * @param CList *L 头指针指针
 * @return int 是否初始化成功，0为成功，-1为失败
 */
int initCNode(CList *L)
{
	CList p = (CList) malloc (sizeof(CNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->data = 0;
	*L = p;
	p->next = *L;
	return 0;
}

/*
 * 单向循环链表（带头指针）：插入
 * @param CList L 头指针
 * @param int pos 插入位置
 * @param int data 插入数据
 * @return int 是否插入成功，0为成功，-1为失败
 */
int insertCNode(CList L, int pos, int data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->next != L){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next == L)){
		printf("位置不合法\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("空间申请失败\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * 单向循环链表（带头指针）：遍历
 * @param CList L 头指针
 */
void displayCNode(CList L)
{
	int i = 0;
	CList p = L->next;
	if(L->next == L){
		printf("该链表为空\n");
		return;
	}
	while(p != L){
		printf("%d ",p->data);
		p = p->next;
		i ++;
	}
	putchar('\n');
	return;
}

/*
 * 查找p的前驱结点
 * @param CList p 目标指针
 * @param int *x 前驱结点数据
 * @return 是否找到，找到为0，找不到为-1
 */
int seekCNode(CList p,int *x)
{
	CList q = p;
	while(q->next != p){
		q = q->next;
	}
	*x = q->data;
	return 0;
}

int main()
{
	CList L,p;
	initCNode(&L);
	p = L->next;
	int i,n,x;
	printf("请输入数据个数:\n");
	scanf("%d",&n);
	printf("请输入%d个数据:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertCNode(L, i+1, x);
	}
	printf("单向循环链表构造完成!\n");
	printf("数据为:");
	displayCNode(L);
	printf("指定p为某结点指针:");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		p = p->next;
	}
	printf("查找p的前驱结点……\n");
	seekCNode(p,&x);
	printf("前驱结点数据为:%d\n",x);
	return 0;
}
