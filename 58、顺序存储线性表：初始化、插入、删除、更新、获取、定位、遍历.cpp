/*
 * 顺序存储线性表：初始化、插入、删除、更新、获取、定位、遍历
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//数据类型定义 
typedef struct
{
	char name[20];
	float score;
}Data;//结点数据

typedef struct
{
	Data *data;
	int length;
	int size;
}SqList;//顺序表

/*
 * 顺序存储线性表：初始化
 * @param SqList* q 顺序表首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initSqlist(SqList *q, int max)
{
	if(max < 0){
		printf("最大数据量不合法\n");
		return -1;
	}
	q->data = (Data *)malloc(max * sizeof(Data));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	q->length = 0;
	q-> size = max;
	return 0;
}

/*
 * 顺序存储线性表：插入
 * @param SqList* q 顺序表首地址
 * @param int pos 插入位置
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int insertSqlist(SqList *q, int pos, Data x)
{ 
	int i;
	if(pos < 0 || pos > q->length+1){
		printf("插入位置不合法\n");
		return -1;
	}
	if(q->length >= q->size){
		printf("顺序表已满\n");
		return -1;
	}
	for(i=q->length;i>=pos;i--){
		q->data[i] = q->data[i-1];
	}
	q->data[pos-1] = x;
	q->length ++;
	return 0;
}

/*
 * 顺序存储线性表：删除
 * @param SqList* q 顺序表首地址
 * @param int pos 删除位置
 * @param Data* x删除数据
 * @return int 是否删除成功，-1为失败，0为成功
 */
int deleteSqlist(SqList *q, int pos, Data *x)
{ 
	int i;
	if(pos < 1 || pos > q->length){
		printf("删除位置不合法\n");
		return -1;
	}
	if(q->length <= 0){
		printf("顺序表为空\n");
		return -1;
	}
	*x = q->data[pos-1];
	for(i=pos-1;i<q->length-1;i++){
		q->data[i] = q->data[i+1];
	}
	q->length --;
	return 0;
}

/*
 * 顺序存储线性表：更新
 * @param SqList q 顺序表
 * @param int pos 更新位置
 * @param Data x更新数据
 * @return int 是否更新成功，-1为失败，0为成功
 */
int updateSqlist(SqList q, int pos, Data x)
{ 
	if(pos < 1 || pos > q.length){
		printf("更新位置不合法\n");
		return -1;
	}
	q.data[pos-1] = x;
	return 0;
}

/*
 * 顺序存储线性表：获取
 * @param SqList q 顺序表
 * @param int pos 获取位置
 * @param Data *x获取数据指针
 * @return int 是否获取成功，-1为失败，0为成功
 */
int getDataSqlist(SqList q, int pos, Data *x)
{ 
	if(pos < 1 || pos > q.length){
		printf("获取位置不合法\n");
		return -1;
	}
	*x = q.data[pos-1] ;
	return 0;
}

/*
 * 顺序存储线性表：定位
 * @param SqList q 顺序表
 * @param int *pos 位置地址
 * @param Data x 需定位数据
 * @return int 是否定位成功，-1为失败，0为成功
 */
int getPosSqlist(SqList q, int *pos, Data x)
{ 
	int i;
	for(i=0;i<q.length;i++){
		if(strcmp(q.data[i].name,x.name) == 0 && fabs(q.data[i].score-x.score) < 1e-6){
			*pos = i+1;
			return 0;
		}
	}
	if(i >= q.length){
		printf("定位失败\n");
		return -1;
	}
	return -1;
}

/*
 * 顺序存储线性表：遍历
 * @param SqList q 顺序表
 */
void displaySqlist(SqList q)
{ 
	int i;
	if(q.length == 0){
		printf("该顺序表为空\n");
		return;
	}
	for(i=0;i<q.length;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	SqList q;
	int max,i,pos;
	Data data;
	printf("顺序存储线性表：初始化、插入、删除、更新、获取、定位、遍历\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--初始化      2--插入     3--删除      \n");  
		printf("     4--更新        5--获取     6--定位      \n");
		printf("     7--遍历        0--退出                  \n");
		printf("*********************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("请输入顺序表容量：");
			scanf("%d",&max);
			if(0 == initSqlist(&q,max)){
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
			if(0 == insertSqlist(&q,pos,data)){
				printf("插入成功\n");
			}
			break;
		case 3:
			printf("请输入删除位置:");
			scanf("%d",&pos);
			if(0 == deleteSqlist(&q,pos,&data)){
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
			if(0 == updateSqlist(q,pos,data)){
				printf("更新成功\n");
			}
			break;
		case 5:
			printf("请输入获取数据位置:");
			scanf("%d",&pos);
			if(0 == getDataSqlist(q,pos,&data)){
				printf("该位置数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == getPosSqlist(q,&pos,data)){
				printf("该数据位置是:%d\n",pos);
			}
			break;
		case 7:
			printf("数据是:\n");
			displaySqlist(q);
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
