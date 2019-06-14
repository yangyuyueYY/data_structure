/*
 * 两个有序线性表的合并（合并成一新表）
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}SqNode,*SqList;

/*
 * 线性表(带头结点)：初始化
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
 * 线性表(带头结点)：插入
 * @param SqList L 线性表头指针
 * @param int pos 插入位置
 * @param Data data 插入数据
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
 * 线性表(带头结点)：遍历
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
		printf("%d  %d\n", i+1, p->data);
		i ++;
		p = p->next;
	}
}

/*
 * 两个有序线性表的合并（在原表中插入合并）
 * @param SqList L1 线性表一头指针
 * @param SqList L2 线性表二头指针
 * @param SqList L3 线性表三头指针
 * @return int 是否合并成功，0为成功，-1为失败
 */
int linkSqlist(SqList L1,SqList L2,SqList L3)
{
	SqList pa = L1->next,pb = L2->next,pc = L3;
	SqList p;
	if(L1->next == NULL){
		L3 = L2;
		return 0;
	}
	if(L2->next == NULL){
		L3 = L1;
		return 0;
	}
	while(pa && pb){
		if(pa->data <= pb->data){
			p = (SqList)malloc(sizeof(SqNode));
			p->data = pa->data;
			p->next = pc->next;
			pc->next = p;
			pc = pc->next;
			pa = pa->next;
		}else{
			p = (SqList)malloc(sizeof(SqNode));
			p->data = pb->data;
			p->next = pc->next;
			pc->next = p;
			pc = pc->next;
			pb = pb->next;
		}
	}
	while(pa){
		p = (SqList)malloc(sizeof(SqNode));
		p->data = pa->data;
		p->next = pc->next;
		pc->next = p;
		pc = pc->next;
		pa = pa->next;
	}
	while(pb){
		p = (SqList)malloc(sizeof(SqNode));
		p->data = pb->data;
		p->next = pc->next;
		pc->next = p;
		pc = pc->next;
		pb = pb->next;
	}
	return 0;
}

int main()
{
	SqList L1,L2,L3;
	initSqlist(&L1);
	initSqlist(&L2);
	initSqlist(&L3);
	int i = 1,x,flag=0;
	printf("请输入第一个有序线性表:\n");
	do{
		printf("输入元素:");
		scanf("%d",&x);
		if(0 == insertSqlist(L1,i,x)){
			printf("该元素已插入,是否继续(1为继续，0为结束):");
			scanf("%d",&flag);
			i ++;
		}else{
			printf("构造失败\n");
			exit(0);
		}
	}while(flag == 1);
	i = 1;
	printf("请输入第二个有序线性表:\n");
	do{
		printf("输入元素:");
		scanf("%d",&x);
		if(0 == insertSqlist(L2,i,x)){
			printf("该元素已插入,是否继续(1为继续，0为结束):");
			scanf("%d",&flag);
			i ++;
		}else{
			printf("构造失败\n");
			exit(0);
		}
	}while(flag == 1);
	printf("两线性表构建成功!\n");
	printf("线性表一:\n");
	displaySqlist(L1);
	printf("线性表二:\n");
	displaySqlist(L2);
	printf("线性表三:\n");
	displaySqlist(L3);
	printf("合并中……\n");
	linkSqlist(L1,L2,L3);
	printf("两线性表合并成功!\n");
	printf("线性表一:\n");
	displaySqlist(L1);
	printf("线性表二:\n");
	displaySqlist(L2);
	printf("线性表三:\n");
	displaySqlist(L3);
	return 0;
}