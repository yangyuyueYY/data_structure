/*
 * 线性表中有n个元素，每个元素是一个字符，现存于数组R[n]中
 * 试写一个算法，使R中的字符按字母字符、数字字符和其他字符的顺序排列。
 * 要求利用原来的存储空间，元素移动次数最小
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
 * 判断字符优先级
 * @param char x 待判断字符
 * @return int 字符优先级，字母为1，数字为2，其他为3
 */
int judge(char x)
{
	if((x<='z' && x>='a')||(x<='Z' && x>='A')){
		return 1;
	}else if(x<='9' && x>='0'){
		return 2;
	}else{
		return 3;
	}
}

/*
 * 按字符类型排序
 * @param SqList q 顺序表首地址
 * @return int 是否删除排序成功，-1为失败，0为成功
 */
int sortSqlist(SqList q)
{ 
	int i,j;
	char temp;
	for(i=0;i<q.length;i++){
		for(j=q.length-1;i<=j;j--){
			if(judge(q.data[i]) > judge(q.data[j])){
				temp = q.data[i];
				q.data[i] = q.data[j];
				q.data[j] = temp;
			}
		}
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
	printf("排序中……\n");
	sortSqlist(q);
	printf("排序后该顺序表为:");
	displaySqlist(q);
	return 0;
}
