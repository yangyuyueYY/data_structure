/*
 * 划分子集问题（运动会排时间）：设定项目、报名、项目编排、显示
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue;

/*
 * 链队列的基本操作：初始化
 * @param Queue *q 链队列
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initQueue(Queue *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->next = NULL;
	p->data = 0;
	q->L = p;
	q->R = p;
	return 0;
}

/*
 * 链队列：判断队空
 * @param Queue q 链队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.L == q.R){
		return 0;
	}
	return 1;
}

/*
 * 链队列：求队列长度
 * @param Queue q 链队列
 * @return int 队列长度
 */
int getLengthQueue(Queue q)
{
	SqList p = q.L;
	int i = 0;
	while(p != q.R){
		i ++;
		p = p->next;
	}
	return i;
}

/*
 * 顺序队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, int x)
{
	int i = 0;
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("空间分配失败\n");
		return -1;
	}
	s->data = x;
	s->next = q->R->next;
	q->R->next = s;
	q->R = s;
	return 0;
}

/*
 * 链队列：出队列
 * @param Queue *q 链队列首地址
 * @param int *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, int *x)
{
	SqList p = q->L,s;
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 0;
}

/*
 * 顺序队列：遍历
 * @param Queue q 顺序队列
 */
void displayQueue(Queue q)
{
	int i = 0;
	SqList p = q.L->next;
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return;
	}
	while(p != NULL){
		printf("%d ",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 编排项目并显示
 * @param int n 项目数
 * @param int *a 项目冲突表
 * @return int 是否安排成功，0成功，-1不成功
 */
int arrange(int n,int *a)
{
	int i,*b,x,j,m;
	Queue q;
	initQueue(&q);
	b = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		b[i] = *(a+0*n+i);
	}
	printf("0 ");
	for(i=1;i<n;i++){
		if(b[i] == 0){
			for(j=0;j<n;j++){
				b[j] += *(a+i*n+j);
			}
			printf("%d ",i);
		}else{
			enQueue(&q, i);
		}
	}
	putchar('\n');
	while(isEmptyQueue(q) != 0){
		deQueue(&q, &x);
		printf("%d ", x);
		for(i=0;i<n;i++){
			b[i] = *(a+x*n+i);
		}
		m = getLengthQueue(q);
		for(i=1;i<=m;i++){
			deQueue(&q, &x);
			if(b[x] == 0){
				for(j=0;j<n;j++){
					b[j] += *(a+x*n+j);
				}
				printf("%d ",x);
			}else{
				enQueue(&q, x);
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,m,i,j,t,s;
	int *a,*b;
	printf("请输入项目数:");
	scanf("%d",&n);
	a = (int *)malloc(n*n*sizeof(int));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			*(a+i*n+j) = 0;
		}
	}
	printf("请输入报名人数:");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("请输入第%d人项目数:",i+1);
		scanf("%d",&t);
		if(i == 0){
			b = (int *)malloc(t*sizeof(int));
		}else{
			b = (int *)realloc(b,t*sizeof(int));
		}
		printf("请输入第%d人项目:",i+1);
		for(j=0;j<t;j++){
			scanf("%d",&b[j]);
		}
		for(s=0;s<t;s++){
			for(j=s;j<t;j++){
				*(a+b[s]*n+b[j]) = 1;
				*(a+b[j]*n+b[s]) = 1;
			}
			*(a+b[s]*n+b[s]) = 0;
		}
	}
	printf("编排结果为:\n");
	arrange(n,a);
	return 0;
}											
/*
9
7
3
1 4 8
2
1 7
2
8 3
3
1 0 5
2
3 4
3
5 6 2
2
6 4
*/