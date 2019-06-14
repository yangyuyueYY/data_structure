/*
 * 正读与反读都相同的字符序列称为回文序列，试编写一个算法，判断一次读入以@结束的字母序列
 * 是否形如“序列1&序列2”模式的字符序列。其中序列1和序列2都不含有字符&，且序列2是序列1的逆序列
 * 要求用栈和队列来实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
	int head;
	int rear;
	int size;
}Queue;//循环队列

typedef struct
{
	char *data;
	int top;
	int size;
}Stack;//顺序栈

/*
 * 循环队列：初始化
 * @param Queue* q 循环队列首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initQueue(Queue *q, int max)
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
	q->head = 0;
	q->rear = 0;
	q->size = max;
	return 0;
}

/*
 * 循环队列：判断队空
 * @param Queue q 循环队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.head == q.rear){
		return 0;
	}
	return 1;
}

/*
 * 顺序队列：求队列长度
 * @param Queue q 顺序队列
 * @return int 队列长度
 */
int getLengthQueue(Queue q)
{
	return (q.rear+q.size-q.head)%q.size;
}

/*
 * 顺序队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, char x)
{ 
	if((q->rear+1)%q->size == q->head){
		printf("队列已满!\n");
		return -1;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % q->size;
	return 0;
}

/*
 * 顺序队列：出队列
 * @param Queue *q 顺序队列首地址
 * @param char *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, char *x)
{ 
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
}

/*
 * 顺序栈：初始化
 * @param Stack* q 顺序栈首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initStack(Stack *q, int max)
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
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * 顺序栈：判断栈空
 * @param Stack q 顺序栈
 * @return int 是否为空，1不为空，0为空
 */
int isEmptyStack(Stack q)
{
	if(q.top == 0){
		return 0;
	}
	return 1;
}

/*
 * 顺序栈：求栈长度
 * @param Stack q 顺序栈
 * @return int 栈的长度
 */
int getLengthStack(Stack q)
{
	return q.top;
}

/*
 * 顺序栈：进栈
 * @param Stack *q 顺序栈首地址
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *q, char x)
{ 
	if(q->top == q->size){
		printf("栈满!\n");
		return -1;
	}
	q->data[q->top++] = x;
	return 0;
}

/*
 * 顺序栈：出栈
 * @param Stack *q 顺序栈首地址
 * @param char *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *q, char *x)
{ 
	if(q->top == 0){
		printf("栈空!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * 判断序列是否回文
 * @param char *a 序列
 * @return int 是否回文，1是，0否
 */
int judge(char *a)
{
	int i=0,n;
	Queue q;
	Stack s;
	char x,y;
	initQueue(&q,20);
	initStack(&s,20);
	n = strlen(a);
	while(a[i] != '&'){
		enQueue(&q,a[i]);
		i ++;
	}
	i ++;
	while(a[i] != '@'){
		pushStack(&s,a[i]);
		i++;
	}
	while(isEmptyStack(s) != 0 && isEmptyQueue(q) != 0){
		deQueue(&q, &x);
		popStack(&s, &y);
		if(x != y){
			return 0;
		}
	}
	if(isEmptyStack(s) != 0 || isEmptyQueue(q) != 0){
		return 0;
	}
	return 1;
}

int main()
{
	char a[40];
	printf("请输入序列:");
	scanf("%s",a);
	if(judge(a) == 0){
		printf("序列不回文!\n");
	}else{
		printf("序列回文!\n");
	}
	return 0;
}
