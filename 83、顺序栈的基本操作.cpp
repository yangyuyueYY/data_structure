/*
 * 顺序栈的基本操作：初始化、销毁、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历
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
	int top;
	int size;
}Stack;//顺序栈

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
	q->data = (Data *)malloc(max * sizeof(Data));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * 顺序栈：销毁
 * @param Stack* q 顺序栈首地址
 * @return int 是否销毁成功，-1为失败，0为成功
 */
int destroyStack(Stack *q)
{
	free(q->data);
	free(&q->top);
	free(&q->size);
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
 * 顺序栈：得到栈顶
 * @param Stack q 顺序栈
 * @param Data *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack q,Data *data)
{
	if(q.top == 0){
		printf("栈为空!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
}

/*
 * 顺序栈：清空栈
 * @param Stack *q 顺序栈首地址
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack(Stack *q)
{
	q->top = 0;
	return 0;
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
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *q, Data x)
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
 * @param Data *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *q, Data *x)
{ 
	if(q->top == 0){
		printf("栈空!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * 顺序栈：遍历
 * @param Stack q 顺序栈
 */
void displayStack(Stack q)
{ 
	int i;
	if(q.top == 0){
		printf("该顺序表为空\n");
		return;
	}
	for(i=0;i<q.top;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	Stack q;
	int max,i;
	Data data;
	printf("顺序栈的基本操作：初始化、销毁、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*************************************************\n");
		printf("     1--初始化      2--销毁     3--判断栈空      \n");  
		printf("     4--取栈顶      5--清空     6--取长度        \n");
		printf("     7--进栈        8--出栈     9--遍历          \n");
		printf("                    0--退出                      \n");
		printf("*************************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("请输入顺序栈容量：");
			scanf("%d",&max);
			if(0 == initStack(&q,max)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			if(0 == destroyStack(&q)){
				printf("销毁成功\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack(q)){
				printf("栈为空\n");
			}else{
				printf("栈不为空\n");
			}
			break;
		case 4:
			if(0 == getTopStack(q,&data)){
				printf("栈顶为:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyStack(&q) == 0){
				printf("清空成功!\n");
			}
			break;
		case 6:
			printf("栈的长度为:%d",getLengthStack(q));
			break;
		case 7:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == pushStack(&q,data)){
				printf("进栈成功\n");
			}
			break;
		case 8:
			if(0 == popStack(&q,&data)){
				printf("出栈数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 9:
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
