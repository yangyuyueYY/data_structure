m/*
 * 已知p指向双向循环链表中的一个结点，其结点结构为data、llink、rlink三个域
 * 写出算法change(p)，交换p所指向的结点和它的前驱结点的顺序
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * llink;
	struct node * rlink;
}CNode,* CList;

/*
 * 双向循环链表：初始化
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
	p->llink = p;
	p->rlink = p;
	*L = p;
	return 0;
}

/*
 * 双向循环链表：插入
 * @param CList L头指针
 * @param int pos 插入位置
 * @param int data 插入数据
 * @return int 是否插入成功，0为成功，-1为失败
 */
int insertCNode(CList L, int pos, int data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->rlink != L){
		i ++;
		p = p->rlink;
	}
	if(i > pos-1 || (i < pos-1 && p->rlink == L)){
		printf("位置不合法\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("空间申请失败\n");
		return -1;
	}
	q->data = data;
	q->llink = p;
	q->rlink = p->rlink;
	p->rlink->llink = q;
	p->rlink = q;
	return 0;
}

/*
 * 双向循环链表：向后遍历
 * @param CList L 头指针
 */
void displayCNode2(CList L)
{
	int i = 0;
	CList p = L->rlink;
	if(p == L){
		printf("该链表为空\n");
		return;
	}
	while(p != L){
		printf("%d ",p->data);
		p = p->rlink;
		i ++;
	}
	putchar('\n');
	return;
}

/*
 * 交换结点和其前驱结点
 * @param CList L 头指针
 * @return int 是否交换成功，0为成功，-1为不成功
 */
int changeCNode(CList p)
{
	CList q = p->llink;
	int temp;
	temp = p->data;
	p->data = q->data;
	q->data = temp;
	return 0;
}

int main()
{
	CList L,p;
	initCNode(&L);
	p = L->rlink;
	int n,i,x;
	printf("请输入数据个数:");
	scanf("%d",&n);
	printf("请输入%d个数据:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertCNode(L, i+1, x);
	}
	printf("双向循环链表构建成功!\n");
	printf("数据为:");
	displayCNode2(L);
	printf("请输入p的位置:");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		p = p->rlink;
	}
	printf("交换中……\n");
	changeCNode(p);
	printf("交换后数据为:");
	displayCNode2(L);
	return 0;
}
