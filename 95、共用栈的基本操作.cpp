/*
 * 共用栈的基本操作：初始化、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历
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
	int top1;
	int top2;
	int size;
}Stack;//共用栈

/*
 * 共用栈：初始化
 * @param Stack* q 共用栈首地址
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
	q->top1 = 0;
	q->top2 = max-1;
	q->size = max;
	return 0;
}

/*
 * 共用栈：判断1栈栈空
 * @param Stack q 共用栈
 * @return int 是否为空，1不为空，0为空
 */
int isEmptyStack1(Stack q)
{
	if(q.top1 == 0){
		return 0;
	}
	return 1;
}

/*
 * 共用栈：判断2栈栈空
 * @param Stack q 共用栈
 * @return int 是否为空，1不为空，0为空
 */
int isEmptyStack2(Stack q)
{
	if(q.top2 == q.size - 1){
		return 0;
	}
	return 1;
}

/*
 * 共用栈：得到1栈栈顶
 * @param Stack q 共用栈
 * @param Data *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack1(Stack q,Data *data)
{
	if(isEmptyStack1(q) == 0){
		printf("1栈为空!\n");
		return -1;
	}
	*data = q.data[q.top1-1];
	return 0;
}

/*
 * 共用栈：得到2栈栈顶
 * @param Stack q 共用栈
 * @param Data *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack2(Stack q,Data *data)
{
	if(isEmptyStack2(q) == 0){
		printf("2栈为空!\n");
		return -1;
	}
	*data = q.data[q.top2+1];
	return 0;
}

/*
 * 共用栈：清空1栈
 * @param Stack *q 共用栈首地址
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack1(Stack *q)
{
	q->top1 = 0;
	return 0;
}

/*
 * 共用栈：清空2栈
 * @param Stack *q 共用栈首地址
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack2(Stack *q)
{
	q->top2 = q->size - 1;
	return 0;
}

/*
 * 共用栈：求1栈长度
 * @param Stack q 共用栈
 * @return int 栈的长度
 */
int getLengthStack1(Stack q)
{
	return q.top1;
}

/*
 * 共用栈：求2栈长度
 * @param Stack q 共用栈
 * @return int 栈的长度
 */
int getLengthStack2(Stack q)
{
	return q.size-q.top2-1;
}

/*
 * 共用栈：进1栈
 * @param Stack *q 共用栈首地址
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack1(Stack *q, Data x)
{ 
	if(q->top1 == q->top2){
		printf("栈满!\n");
		return -1;
	}
	q->data[q->top1++] = x;
	return 0;
}

/*
 * 共用栈：进2栈
 * @param Stack *q 共用栈首地址
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack2(Stack *q, Data x)
{ 
	if(q->top1 == q->top2){
		printf("栈满!\n");
		return -1;
	}
	q->data[q->top2--] = x;
	return 0;
}

/*
 * 共用栈：出1栈
 * @param Stack *q 共用栈首地址
 * @param Data *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack1(Stack *q, Data *x)
{ 
	if(isEmptyStack1(*q) == 0){
		printf("栈空!\n");
		return -1;
	}
	*x = q->data[--q->top1];
	return 0;
}

/*
 * 共用栈：出2栈
 * @param Stack *q 共用栈首地址
 * @param Data *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack2(Stack *q, Data *x)
{ 
	if(isEmptyStack2(*q) == 0){
		printf("栈空!\n");
		return -1;
	}
	*x = q->data[++q->top2];
	return 0;
}

/*
 * 共用栈：遍历1栈
 * @param Stack q 共用栈
 */
void displayStack1(Stack q)
{ 
	int i;
	if(isEmptyStack1(q) == 0){
		printf("栈空\n");
		return;
	}
	for(i=0;i<q.top1;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

/*
 * 共用栈：遍历2栈
 * @param Stack q 共用栈
 */
void displayStack2(Stack q)
{ 
	int i;
	if(isEmptyStack2(q) == 0){
		printf("栈空\n");
		return;
	}
	for(i=q.top2+1;i<q.size;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	Stack q;
	int max,i;
	Data data;
	printf("共用栈的基本操作：初始化、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************************\n");
		printf("       1--初始化      2--判断1栈空     3--判断2栈空      \n");  
		printf("       4--得到1栈顶   5--得到2栈顶     6--清空1栈        \n");
		printf("       7--清空2栈     8--求1栈长       9--求2栈长        \n");
		printf("       10--进1栈      11--进2栈        12--出1栈         \n");
		printf("       13--出2栈      14--遍历1        15--遍历2         \n");
		printf("                      0--退出                            \n");
		printf("*********************************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("请输入共用栈容量：");
			scanf("%d",&max);
			if(0 == initStack(&q,max)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			if(0 == isEmptyStack1(q)){
				printf("栈为空\n");
			}else{
				printf("栈不为空\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack2(q)){
				printf("栈为空\n");
			}else{
				printf("栈不为空\n");
			}
			break;
		case 4:
			if(0 == getTopStack1(q,&data)){
				printf("栈顶为:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(0 == getTopStack2(q,&data)){
				printf("栈顶为:%s  %g\n",data.name,data.score);
			}
			break;
		case 6:
			if(emptyStack1(&q) == 0){
				printf("清空成功!\n");
			}
			break;
		case 7:
			if(emptyStack2(&q) == 0){
				printf("清空成功!\n");
			}
			break;
		case 8:
			printf("栈的长度为:%d",getLengthStack1(q));
			break;
		case 9:
			printf("栈的长度为:%d",getLengthStack2(q));
			break;
		case 10:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == pushStack1(&q,data)){
				printf("进栈成功\n");
			}
			break;
		case 11:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == pushStack2(&q,data)){
				printf("进栈成功\n");
			}
			break;
		case 12:
			if(0 == popStack1(&q,&data)){
				printf("出栈数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 13:
			if(0 == popStack2(&q,&data)){
				printf("出栈数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 14:
			printf("数据为:\n");
			displayStack1(q);
			break;
		case 15:
			printf("数据为:\n");
			displayStack2(q);
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
