/*
 * 写出线性表就地逆转算法：顺序表实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
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
	q->data = (char *)malloc(max * sizeof(char));
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
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int insertSqlist(SqList *q, int pos, char x)
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
		printf("%c ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * 就地逆转
 * @param SqList q 顺序表首地址
 * @return int 是否逆转成功，-1为失败，0为成功
 */
int contrarySqlist(SqList q)
{ 
	int i,j;
	char temp;
	for(i=0,j=q.length-1;i<=j;i++,j--){
		temp = q.data[i];
		q.data[i] = q.data[j];
		q.data[j] = temp;
	}
	return 0;
}

int main()
{
	SqList q;
	initSqlist(&q, 20);
	printf("请输入一组字符数据：\n");
	scanf("%s",q.data);
	q.length = strlen(q.data);
	printf("该顺序表为:");
	displaySqlist(q);
	printf("逆转中……\n");
	contrarySqlist(q);
	printf("逆转后该顺序表为:");
	displaySqlist(q);
	return 0;
}
