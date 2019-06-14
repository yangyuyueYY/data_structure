/*
 * 链队列的基本操作：初始化、判断队空、求队列长度、得到队头、清空、进队列、出队列、遍历
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
	strcpy(p->data.name,"");
	p->data.score = 0;
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
 * 链队列：得到队头
 * @param Queue q 链队列
 * @param Data *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,Data *data)
{
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*data = q.L->next->data;
	return 0;
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
 * 链队列：清空队列
 * @param Queue *q 链队列指针
 * @return int 是否清空成功，0成功，-1不成功
 */
int emptyQueue(Queue *q)
{
	q->R = q->L;
	return 0;
}


/*
 * 顺序队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, Data x)
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
 * @param Data *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Data *x)
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
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

int main()
{
	Queue q;
	int i;
	Data data;
	printf("链队列的基本操作：初始化、判断队空、求队列长度、得到队头、清空、进队列、出队列、遍历\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("***************************************************\n");
		printf("     1--初始化      2--判断队空     3--取长度      \n");  
		printf("     4--取队头      5--清空         6--进队列      \n");
		printf("     7--出队列      8--遍历         0--退出        \n");
		printf("***************************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initQueue(&q)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			if(0 == isEmptyQueue(q)){
				printf("栈为空\n");
			}else{
				printf("栈不为空\n");
			}
			break;
		case 3:
			printf("队列的长度为:%d",getLengthQueue(q));
			break;
		case 4:
			if(0 == getHeadQueue(q,&data)){
				printf("队头为:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyQueue(&q) == 0){
				printf("清空成功!\n");
			}
			break;
		case 6:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == enQueue(&q,data)){
				printf("进队列成功\n");
			}
			break;
		case 7:
			if(0 == deQueue(&q,&data)){
				printf("出队列数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 8:
			printf("数据为:\n");
			displayQueue(q);
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
