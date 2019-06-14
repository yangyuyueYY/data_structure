/*
 * 线性表用顺序存储，设计一个算法，用尽可能少的辅助存储空间将顺序表中前m个元素和后n个元素进行整体互换
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
 * 顺序存储线性表：删除
 * @param SqList* q 顺序表首地址
 * @param int pos 删除位置
 * @param char* x删除数据
 * @return int 是否删除成功，-1为失败，0为成功
 */
int deleteSqlist(SqList *q, int pos, char *x)
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
 * 前后互换函数
 * @param SqList q 顺序表首地址
 * @param int m 前m个
 * @param int n 后n个
 * @return int 是否互换成功，-1为失败，0为成功
 */
int exchangeSqlist(SqList q,int m,int n)
{ 
	int i,flag;
	char temp;
	if(m+n > q.length){
		printf("元素个数不够!");
		return -1;
	}
	if(m<=n){
		for(i=0;i<m;i++){
			temp = q.data[i];
			q.data[i] = q.data[q.length-n+i];
			q.data[q.length-n+i] = temp;
		}
		for(i=m;i<n;i++){
			insertSqlist(&q, i+1, q.data[q.length-n+i]);
		}
		q.length = q.length-(n-m);
	}else{
		for(i=0;i<n;i++){
			temp = q.data[i];
			q.data[i] = q.data[q.length-n+i];
			q.data[q.length-n+i] = temp;
		}
		flag = n;
		while(flag<m){
			insertSqlist(&q, q.length, q.data[n]);
			deleteSqlist(&q,n+1,&temp);
			flag ++;
		}
	}
	return 0;
}

int main()
{
	SqList q;
	int m,n;
	initSqlist(&q, 20);
	printf("请输入一组字符数据：\n");
	scanf("%s",q.data);
	q.length = strlen(q.data);
	printf("该顺序表为:");
	displaySqlist(q);
	printf("请输入前后待交换的数据量:");
	scanf("%d%d",&m,&n);
	printf("交换中……\n");
	exchangeSqlist(q,m,n);
	printf("排序后该顺序表为:");
	displaySqlist(q);
	return 0;
}
