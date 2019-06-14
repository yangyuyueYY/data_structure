/*
 * 已知一顺序表A，其元素值非递减有序排列，编写一个函数删除顺序表中多余的值相同的元素
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
 * 有序顺序存储线性表：去重
 * @param SqList* q 顺序表首地址
 * @return int 是否去重成功，-1为失败，0为成功
 */
int singleSqlist(SqList *q)
{ 
	int i,x,j;
	if(q->length == 0){
		printf("该顺序表为空!\n");
		return -1;
	}
	x = q->data[0];
	for(i=1;i<q->length;i++){
		if(x == q->data[i]){
			q->data[i] = -100;
		}else{
			x = q->data[i];
		}
	}
	for(i=q->length-1;i>=0;i--){
		if(q->data[i] == -100){
			for(j=i;j<q->length-1;j++){
				q->data[j]= q->data[j+1];
			}
			q->length --;
		}
	}
	return 0;
}

int main()
{
	SqList q;
	initSqlist(&q, 20);
	printf("请输入一组非递减有序数据：\n");
	int flag,x,i=1;
	do{
		printf("第%d项:",i);
		scanf("%d",&x);
		i++;
		insertSqlist(&q, q.length+1,x);
		printf("请选择是否继续，1为继续，0为结束:");
		scanf("%d",&flag);
	}while(flag);
	printf("该顺序表为:");
	displaySqlist(q);
	printf("去重中……\n");
	singleSqlist(&q);
	printf("去重后该顺序表为:");
	displaySqlist(q);
	return 0;
}
