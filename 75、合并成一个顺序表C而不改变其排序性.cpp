/*
 * 假设有两个已排序的顺序表A和B，编写一个函数将他们合并成一个顺序表C而不改变其排序性
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
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
	q->data = (int *)malloc(max * sizeof(int));
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
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int insertSqlist(SqList *q, int pos, int x)
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
		printf("%d ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * 顺序合并两顺序表
 * @param SqList q1 顺序表A
 * @param SqList q2 顺序表B
 * @param SqList *q3 合并后的顺序表
 */
void mergeSqlist(SqList q1,SqList q2,SqList *q3)
{ 
	int i=0,j=0;
	while(i<q1.length && j<q2.length){
		if(q1.data[i]<=q2.data[j]){
			insertSqlist(q3, (*q3).length+1, q1.data[i]);
			i++;
		}else{
			insertSqlist(q3, (*q3).length+1, q2.data[j]);
			j++;
		}
	}
	while(i<q1.length){
		insertSqlist(q3, (*q3).length+1, q1.data[i]);
		i++;
	}
	while(j<q1.length){
		insertSqlist(q3, (*q3).length+1, q2.data[j]);
		j++;
	}
	(*q3).length--;
	return;
}

int main()
{
	SqList q1,q2,q3;
	initSqlist(&q1,20);
	initSqlist(&q2,20);
	initSqlist(&q3,40);
	int i,n,x;
	printf("请输入顺序表A的数据数:");
	scanf("%d",&n);
	printf("请输入%d个有序数据:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&q1, q1.length+1,x);
	}
	printf("请输入顺序表B的数据数:");
	scanf("%d",&n);
	printf("请输入%d个有序数据:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&q2, q2.length+1,x);
	}
	printf("顺序表构建成功!\n");
	printf("顺序表A:");
	displaySqlist(q1);
	printf("顺序表B:");
	displaySqlist(q2);
	printf("合并中……\n");
	mergeSqlist(q1,q2,&q3);
	printf("合并后顺序表为:");
	displaySqlist(q3);
	return 0;
}
