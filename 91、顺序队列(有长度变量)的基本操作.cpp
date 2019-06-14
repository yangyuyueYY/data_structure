/*
 * 顺序队列(有长度变量)的基本操作：初始化、判断队空、求队列长度、得到队头、清空、进队列、出队列、遍历
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
	int head;
	int rear;
	int length;
	int size;
}Queue;//顺序队列

/*
 * 顺序队列：初始化
 * @param Queue* q 顺序队列首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initQueue(Queue *q, int max)
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
	q->head = 0;
	q->rear = 0;
	q->length = 0;
	q->size = max;
	return 0;
}

/*
 * 顺序队列：判断队空
 * @param Queue q 顺序队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.length == 0){
		return 0;
	}
	return 1;
}

/*
 * 顺序队列：得到队头
 * @param Queue q 顺序队列
 * @param Data *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,Data *data)
{
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*data = q.data[q.head];
	return 0;
}

/*
 * 顺序队列：求队列长度
 * @param Queue q 顺序队列
 * @return int 队列长度
 */
int getLengthQueue(Queue q)
{
	return q.length;
}

/*
 * 顺序队列：清空队列
 * @param Queue *q 顺序队列指针
 * @return int 是否清空成功，0成功，-1不成功
 */
int emptyQueue(Queue *q)
{
	q->length = 0;
	q->rear = q->head;
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
	if(q->length == q->size){
		printf("队列已满!\n");
		return -1;
	}
	q->data[q->rear] = x;
	if(q->rear == q->size - 1){
		q->rear = 0;
	}else{
		q->rear ++;
	}
	q->length ++;
	return 0;
}

/*
 * 顺序队列：出队列
 * @param Queue *q 顺序队列首地址
 * @param Data *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Data *x)
{ 
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*x = q->data[q->head];
	if(q->head == q->size - 1){
		q->head = 0;
	}else{
		q->head ++;
	}
	q->length --;
	return 0;
}

/*
 * 顺序队列：遍历
 * @param Queue q 顺序队列
 */
void displayQueue(Queue q)
{ 
	int i,t=q.head;
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return;
	}
	for(i=0;i<q.length;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[t].name,q.data[t].score); 
		if(t == q.size-1){
			t = 0;
		}else{
			t++;
		}
	}
	return;
}

int main()
{
	Queue q;
	int max,i;
	Data data;
	printf("顺序队列(有长度变量)的基本操作：初始化、判断队空、求队列长度、得到队头、清空、进队列、出队列、遍历\n");
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
			printf("请输入顺序队列容量：");
			scanf("%d",&max);
			if(0 == initQueue(&q,max)){
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
