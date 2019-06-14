/*
 * 已知不带头结点的线性链表list，链表中结点构造为(data、link),其中data为数据域，link为指针域
 * 试写一算法，将该链表按结点数据域的值的大小从小到大重新链接。要求链接过程中不得使用除该链表以外的任何结点空间
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}SqNode,*SqList;

/*
 * 链式存储线性表(不带头结点)：初始化
 * @param SqList *L 指向线性表头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initSqlist(SqList *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：更新
 * @param SqList L 线性表头指针
 * @param int pos 更新位置
 * @param int data 更新数据
 * @return int 更新是否成功，0为成功，-1为失败
 */
int updateSqlist(SqList L, int pos, int data)
{
	int i = 1;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->link;
	}
	if(i > pos || NULL == p){
		printf("位置不合法\n");
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：获取
 * @param SqList L 线性表头指针
 * @param int pos 获取位置
 * @param int *data 获取数据
 * @return int 获取是否成功，0为成功，-1为失败
 */
int getDataSqlist(SqList L, int pos, int *data)
{
	int i = 1;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->link;
	}
	if(i > pos || NULL == p){
		printf("位置不合法\n");
		return -1;
	}
	*data = p->data;
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：遍历
 * @param SqList L 线性表头指针
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%d ", p->data);
		i ++;
		p = p->link;
	}
	putchar('\n');
}

/*
 * 链式存储线性表(不带头结点)：插入
 * @param SqList *L 指向线性表头指针的指针
 * @param int pos 插入位置
 * @param int data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList *L, int pos, int data)
{
	int i = 1;
	SqList p = *L,q = NULL;
	if(1 == pos){
		q = (SqList) malloc (sizeof(SqNode));
		if(NULL == q){
			printf("空间分配失败\n");
			return -1;
		}
		q->data = data;
		q->link = *L;
		*L = q;
		return 0;
	}
	while(i < pos-1 && p != NULL){
		i ++;
		p = p->link;
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
	q->link = p->link;
	p->link = q;
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：排序
 * @param SqList L 线性表头指针
 * @param int n 数据个数
 * @return int 排序是否成功，0为成功，-1为失败
 */
int sortSqlist(SqList L, int n)
{
	int i,j,a,b;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			getDataSqlist(L,i+1,&a);
			getDataSqlist(L,j+1,&b);
			if(a>b){
				updateSqlist(L, i+1, b);
				updateSqlist(L, j+1, a);
			}
		}
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i,x;
	printf("请输入数据个数:");
	scanf("%d",&n);
	printf("请输入%d个数据:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&L, i+1, x);
	}
	printf("构建成功!\n");
	printf("数据为:");
	displaySqlist(L);
	printf("排序中……\n");
	sortSqlist(L,n);
	printf("排序后数据为:");
	displaySqlist(L);
	return 0;
}
