/*
 * 写出将线性表就地逆转算法，用带头结点的单链表来实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
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
	p->data = ' ';
	*L = p;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：插入
 * @param SqList L 线性表头指针
 * @param int pos 插入位置
 * @param char data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList L, int pos, char data)
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
 * 链式存储线性表(带头结点)：更新
 * @param SqList L 线性表头指针
 * @param int pos 更新位置
 * @param char data 更新数据
 * @return int 更新是否成功，0为成功，-1为失败
 */
int updateSqlist(SqList L, int pos, char data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		printf("位置不合法\n");
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：获取
 * @param SqList L 线性表头指针
 * @param int pos 获取位置
 * @param char *data 获取数据
 * @return int 获取是否成功，0为成功，-1为失败
 */
int getDataSqlist(SqList L, int pos, char *data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		printf("位置不合法\n");
		return -1;
	}
	*data = p->data;
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
		printf("%c ", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 链式存储线性表(带头结点)：尾插
 * @param SqList L 线性表头指针
 * @param char data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertTailSqlist(SqList L, char data)
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
 * 线性表逆转
 * @param SqList L 线性表头指针
 * @param int n 线性表长度
 * @return int 逆转是否成功，0为成功，-1为失败
 */
int contrarySqlist(SqList L,int n)
{
	int i,j;
	char a,b;
	for(i=1,j=n;i<=j;i++,j--){
		getDataSqlist(L, i, &a);
		getDataSqlist(L, j, &b);
		updateSqlist(L,i,b);
		updateSqlist(L,j,a);
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	char a[20];
	int n,i;
	printf("请输入一组字符数据:");
	scanf("%s",a);
	n = strlen(a);
	for(i=0;i<n;i++){
		insertTailSqlist(L, a[i]);
	}
	printf("链表创建成功!\n");
	printf("数据为:");
	displaySqlist(L);
	printf("逆转中……\n");
	contrarySqlist(L,n);
	printf("逆转后数据为:");
	displaySqlist(L);
	return 0;
}
