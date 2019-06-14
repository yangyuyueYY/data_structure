/*
 * 在行编辑程序中，设用户输入一行的过程中允许用户输入出差错，并在发现有误时通过#和@退行符进行改正
 * 当输出回车时处理所有的输入字符得到最终的输入，试编写算法实现行输入处理过程
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
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
 * 链栈：进栈
 * @param Stack *L 链栈头指针
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, char x)
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
 * @param char *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, char *x)
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
		printf("%c", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 字符串编辑
 * @param char *a 输入字符串
 * @return int 是否成功，0成功，-1失败
 */
int edit(char *a)
{
	Stack q,p;
	initStack(&q);
	initStack(&p);
	int n,i;
	char x;
	n = strlen(a);
	for(i=0;i<n;i++){
		if(a[i] == '#'){
			popStack(&q,&x);
		}else if(a[i] == '@'){
			emptyStack(&q);
		}else{
			pushStack(&q,a[i]);
		}
	}
	while(isEmptyStack(q) != 0){
		popStack(&q,&x);
		pushStack(&p,x);
	}
	displayStack(p);
	return 0;
}

int main()
{
	char a[40];
	printf("请输入字符串:");
	scanf("%s",a);
	printf("数据为:");
	edit(a);
	return 0;
}
