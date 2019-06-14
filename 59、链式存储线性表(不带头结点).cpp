/*
 * 链式存储线性表(不带头结点)：初始化、插入、删除、更新、获取、定位、取长、遍历、头插、尾插
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
 * @param Data data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList *L, int pos, Data data)
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
 * 链式存储线性表(不带头结点)：删除
 * @param SqList *L 指向线性表头指针的指针
 * @param int pos 删除位置
 * @param Data *data 删除数据
 * @return int 删除是否成功，0为成功，-1为失败
 */
int deleteSqlist(SqList *L, int pos, Data *data)
{
	int i = 1;
	SqList p = *L,q = NULL;
	if(NULL == *L){
		printf("线性表为空\n");
		return -1;
	}
	if(1 == pos){
		*data = p->data;
	    *L = (*L)->next;
		free(p);
		return 0;
	}
	while(i < pos-1 && p->next != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || NULL == p->next){
		printf("位置不合法\n");
		return -1;
	}
	q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：更新
 * @param SqList L 线性表头指针
 * @param int pos 更新位置
 * @param Data data 更新数据
 * @return int 更新是否成功，0为成功，-1为失败
 */
int updateSqlist(SqList L, int pos, Data data)
{
	int i = 1;
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
 * 链式存储线性表(不带头结点)：获取
 * @param SqList L 线性表头指针
 * @param int pos 获取位置
 * @param Data *data 获取数据
 * @return int 获取是否成功，0为成功，-1为失败
 */
int getDataSqlist(SqList L, int pos, Data *data)
{
	int i = 1;
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
 * 链式存储线性表(不带头结点)：定位
 * @param SqList L 线性表头指针
 * @param int *pos 定位到的位置
 * @param Data data 要定位的数据
 * @return int 定位是否成功，0为成功，-1为失败
 */
int getPosSqlist(SqList L, int *pos, Data data)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		
	}
	while(p != NULL && (strcmp(data.name,p->data.name) != 0 || fabs(p->data.score - data.score) > 1e-6)){
		i ++;
		p = p->next;
	}
	if(p == NULL){
		printf("该数据不存在\n");
		return -1;
	}
	*pos = i+1;
	return 0;
}

/*
 * 链式存储线性表(不带头结点)：取长
 * @param SqList L 线性表头指针
 * @param int *pos 长度
 * @return int 取长是否成功，0为成功，-1为失败
 */
int getLengthSqlist(SqList L, int *pos)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		printf("线性表为空\n");
		return -1;
	}
	while(p != NULL){
		i ++;
		p = p->next;
	}
	*pos = i;
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
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

/*
 * 链式存储线性表(不带头结点)：头插
 * @param SqList *L 指向线性表头指针的指针
 * @param Data data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertHeadSqlist(SqList *L, Data data)
{
	SqList p = *L,q = NULL;
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

/*
 * 链式存储线性表(不带头结点)：尾插
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

int main()
{
	SqList L;
	int i,pos;
	Data data;
	printf("链式存储线性表(不带头结点)：初始化、插入、删除、更新、获取、定位、取长、遍历、头插、尾插\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--初始化      2--插入     3--删除      \n");  
		printf("     4--更新        5--获取     6--定位      \n");
		printf("     7--遍历        8--取长     9--头插      \n");
		printf("            10--尾插    0--退出              \n");
		printf("*********************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initSqlist(&L)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			printf("请输入插入位置:");
			scanf("%d",&pos);
			if(0 == insertSqlist(&L,pos,data)){
				printf("插入成功\n");
			}
			break;
		case 3:
			printf("请输入删除位置:");
			scanf("%d",&pos);
			if(0 == deleteSqlist(&L,pos,&data)){
				printf("删除数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			printf("请输入更新位置:");
			scanf("%d",&pos);
			if(0 == updateSqlist(L,pos,data)){
				printf("更新成功\n");
			}
			break;
		case 5:
			printf("请输入获取数据位置:");
			scanf("%d",&pos);
			if(0 == getDataSqlist(L,pos,&data)){
				printf("该位置数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == getPosSqlist(L,&pos,data)){
				printf("该数据位置是:%d\n",pos);
			}
			break;
		case 7:
			printf("数据是:\n");
			displaySqlist(L);
			break;
		case 8:
			if(0 == getLengthSqlist(L,&pos)){
				printf("当前线性表长度为:%d\n",pos);
			}
			break;
		case 9:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == insertHeadSqlist(&L,data)){
				printf("插入成功\n");
			}
			break;
		case 10:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == insertTailSqlist(L,data)){
				printf("插入成功\n");
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("操作选择失败，请重新输入\n");
		}
		getchar();
	}
	return 0;
}
