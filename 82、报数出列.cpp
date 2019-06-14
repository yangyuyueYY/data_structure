/*
 * Josephu问题：设编号为1，2，…，n的n个人围坐一圈，约定编号为k的人从1开始报数
 * 数到m的那个人出列，它的下一位又从1开始报数，数到m的那个人又出列，以此类推
 * 直到所有人出列为止，由此产生一个出队编号的序列。
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
	int i;
	if(max < 0){
		printf("最大数据量不合法\n");
		return -1;
	}
	q->data = (int *)malloc(max * sizeof(int));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	for(i=0;i<max;i++){
		q->data[i] = i+1;
	}
	q->length = max;
	q-> size = max;
	return 0;
}

/*
 * 判断是否报完数
 * @param SqList q 顺序表
 * @return int 是否报完，0为报完，-1为没报完
 */
int judgeSqlist(SqList q)
{
	int i;
	for(i=0;i<q.length;i++){
		if(q.data[i] != 0){
			return -1;
		}
	}
	return 0;
}

/*
 * 报数
 * @param SqList q 顺序表
 * @param int n 总人数
 * @param int k 起始编号
 * @param int m 报数周期
 * @return int 是否报数成功，-1为失败，0为成功
 */
int countSqlist(SqList q, int n,int k,int m)
{
	int i;
	if(k>n || k<1){
		printf("起始编号不合法!\n");
		return -1;
	}
	k = (k+n-1)%n;
	while(judgeSqlist(q)!=0){
		i = 0;
		while(i<m){
			if(q.data[(k+1)%n-1] > 0){
				i++;
			}
			if(i == m){
				printf("%d ",q.data[(k+1)%n-1]);
				q.data[(k+1)%n-1] = 0;
			}
			k = (k+1)%n;
		}
	}
	putchar('\n');
	return 0;
}

int main()
{
	SqList q;
	int n,k,m;
	printf("请输入人数n:");
	scanf("%d",&n);
	printf("请输入起点编号k:");
	scanf("%d",&k);
	printf("请输入报数数字m:");
	scanf("%d",&m);
	printf("报数顺序:");
	initSqlist(&q, n+1);
	countSqlist(q, n+1,k,m);
	return 0;
}
