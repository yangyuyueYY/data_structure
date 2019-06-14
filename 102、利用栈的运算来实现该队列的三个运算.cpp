/*
 * 请利用两个栈s1和s2来模拟一个队列。
 * 已知栈的三个运算定义如下：PUSH(ST,x):元素x入ST栈；POP(ST,x):ST栈顶元素出栈，赋给变量x，Sempty(ST):判ST栈是否为空
 * 那么如何利用栈的运算来实现该队列的三个运算:EnQueue:插入一个元素入队列,DeQueue()删除一个元素出队列，Queue_Empty()判队列为空
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
}Node,*Stack;

/*
 * 链栈：初始化
 * @param Stack *L 指向链栈头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initStack(Stack *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链栈：判断栈空
 * @param Stack L 链栈头指针
 * @return int 链栈是否成功，0为空，1不为空
 */
int isEmptyStack(Stack L)
{
	if(L == NULL){
		return 0;
	}
	return 1;
}

/*
 * 链栈：进栈
 * @param Stack *L 链栈头指针
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, Data x)
{ 
	Stack q;
	q = (Stack) malloc (sizeof(Node));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = x;
	q->next = *L;
	*L = q;
	return 0;
}

/*
 * 链栈：出栈
 * @param Stack *L 链栈首地址
 * @param Data *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, Data *x)
{ 
	Stack p = *L;
	if(*L == NULL){
		printf("栈空!\n");
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
}

/*
 * 链栈：遍历
 * @param Stack L 链栈
 */
void displayStack(Stack L)
{
	int i = 0;
	Data x;
	Stack q;
	initStack(&q);
	while(isEmptyStack(L) != 0){
		popStack(&L,&x);
		pushStack(&q,x);
	}
	Stack p = q;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

/*
 * 入队列
 * @param Stack *q 栈
 * @param Data data 入队列数据
 * @return int 是否入队列成功，0成功，-1成功
 */
int enQueue(Stack *q,Data data)
{
	pushStack(q, data);
	return 0;
}

/*
 * 出队列
 * @param Stack *q 栈
 * @param Data *data 出队列数据
 * @return int 是否出队列成功，0成功，-1成功
 */
int deQueue(Stack *q,Data *data)
{
	Stack p;
	Data x;
	initStack(&p);
	while(isEmptyStack(*q) != 0){
		popStack(q,&x);
		pushStack(&p,x);
	}
	if(-1 == popStack(&p,data)){
		return -1;
	}
	while(isEmptyStack(p) != 0){
		popStack(&p,&x);
		pushStack(q,x);
	}
	return 0;
}

int main()
{
	Stack q;
	initStack(&q);
	int i;
	Data data;
	printf("栈模拟队列的基本操作：初始化、判断队列空、进队列、出队列\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*************************************************\n");
		printf("     1--初始化      2--判空     3--进队列        \n");  
		printf("     4--出队列      5--遍历     0--退出          \n");
		printf("*************************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initStack(&q)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			if(0 == isEmptyStack(q)){
				printf("队列为空\n");
			}else{
				printf("队列不为空\n");
			}
			break;
		case 3:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == enQueue(&q,data)){
				printf("进队列成功\n");
			}
			break;
		case 4:
			if(0 == deQueue(&q,&data)){
				printf("出队列数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 5:
			printf("数据为:\n");
			displayStack(q);
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
