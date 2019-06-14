/*
 * 链栈的基本操作：初始化、销毁、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历
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
 * 链栈：销毁
 * @param Stack *L 指向链栈头指针的指针
 * @return int 销毁是否成功，0为成功，-1为失败
 */
int destroyStack(Stack *L)
{
	Stack p = *L,q;
	while(p->next){
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
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
 * 链栈：得到栈顶
 * @param Stack L 链栈头指针
 * @param Data *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack L,Data *data)
{
	if(L == NULL){
		printf("栈为空!\n");
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * 链栈：清空栈
 * @param Stack *L 指向链栈头指针的指针
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack(Stack *L)
{
	(*L) = NULL;
	return 0;
}

/*
 * 链栈：求栈长度
 * @param Stack L 链栈
 * @return int 栈的长度
 */
int getLengthStack(Stack L)
{
	Stack p = L;
	int i = 0;
	while(p){
		i++;
		p = p->next;
	}
	return i;
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
	Stack p = L;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

int main()
{
	Stack L;
	int i;
	Data data;
	printf("链栈的基本操作：初始化、销毁、判断栈空、得到栈顶、清空栈、求栈的长度、进栈、出栈、遍历\n");
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
			if(0 == initStack(&L)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			if(0 == destroyStack(&L)){
				printf("销毁成功\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack(L)){
				printf("栈为空\n");
			}else{
				printf("栈不为空\n");
			}
			break;
		case 4:
			if(0 == getTopStack(L,&data)){
				printf("栈顶为:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyStack(&L) == 0){
				printf("清空成功!\n");
			}
			break;
		case 6:
			printf("栈的长度为:%d",getLengthStack(L));
			break;
		case 7:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == pushStack(&L,data)){
				printf("进栈成功\n");
			}
			break;
		case 8:
			if(0 == popStack(&L,&data)){
				printf("出栈数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 9:
			printf("数据为:\n");
			displayStack(L);
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
