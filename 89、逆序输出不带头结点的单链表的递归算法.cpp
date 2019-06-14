/*
 * 逆序输出不带头结点的单链表的递归算法
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
 * 链式存储线性表(不带头结点)：插入
 * @param SqList *L 指向线性表头指针的指针
 * @param int pos 插入位置
 * @param char data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList *L, int pos, char data)
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
		q->next = *L;
		*L = q;
		return 0;
	}
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
		printf("%c",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 链式存储线性表(不带头结点)：逆序输出
 * @param SqList p 当前指针
 */
void contrarySqlist(SqList p)
{
	if(p == NULL){
		return;
	}else{
		contrarySqlist(p->next);
		printf("%c",p->data);
	}
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i;
	char a[40];
	printf("请输入一串字符数据:");
	scanf("%s",a);
	n = strlen(a);
	for(i=0;i<n;i++){
		insertSqlist(&L, i+1, a[i]);
	}
	printf("数据为:");
	displaySqlist(L);
	printf("逆序输出为:");
	contrarySqlist(L);
	putchar('\n');
	return 0;
}
