/*
 * 已知两个单链表A和B分别表示两个集合，其元素递增排列
 * 编写一个函数求出A和B的交集C，要求C同样以元素递增的单链表形式存在
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
		printf("%d ",p->data);
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
 * 取交集
 * @param SqList L1 线性表A头指针
 * @param SqList L2 线性表B头指针
 * @param SqList L3 结果线性表头指针
 * @return int 取交集是否成功，0为成功，-1为失败
 */
int insectSqlist(SqList L1, SqList L2,SqList L3)
{
	SqList p1 = L1->next,p2 = L2->next;
	while(p1 && p2){
		if(p1->data < p2->data){
			p1 = p1->next;
		}else if(p1->data > p2->data){
			p2 = p2->next;
		}else{
			insertTailSqlist(L3, p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return 0;
}

int main()
{
	SqList L1,L2,L3;
	initSqlist(&L1);
	initSqlist(&L2);
	initSqlist(&L3);
	int n,i,x;
	printf("请输入线性表A的元素个数:");
	scanf("%d",&n);
	printf("请输入%d个元素:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L1, x);
	}
	printf("请输入线性表A的元素个数:");
	scanf("%d",&n);
	printf("请输入%d个元素:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L2, x);
	}
	printf("两线性表构建成功!\n");
	printf("线性表A:");
	displaySqlist(L1);
	printf("线性表B:");
	displaySqlist(L2);
	printf("取交集……\n");
	insectSqlist(L1,L2,L3);
	printf("交集为:");
	displaySqlist(L3);
	return 0;
}
