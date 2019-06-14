/*
 * 基于栈的括号匹配
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
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
 * 顺序栈：进栈
 * @param Stack *q 顺序栈首地址
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *q, char x)
{ 
	if(q->top == q->size){
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
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * 判断括号是否匹配
 * @param char *a 待判断表达式
 * @return int 是否匹配，0为不匹配，1为匹配
 */
int match(char *a)
{ 
	Stack q;
	initStack(&q,20);
	char x;
	int i;
	int n = strlen(a);
	for(i=0;i<n;i++){
		switch(a[i]){
			case '(':
			case '[':
			case '{':
				pushStack(&q, a[i]);
				break;
			case ')':
				popStack(&q,&x);
				if(x != '('){
					return 0;
				}
				break;
			case ']':
				popStack(&q,&x);
				if(x != '['){
					return 0;
				}
				break;
			case '}':
				popStack(&q,&x);
				if(x != '{'){
					return 0;
				}
				break;
		}
		i++;
	}
	if(isEmptyStack(q) == 0){
		return 1;
	}
	return 0;
}

int main()
{	
	char a[40];
	printf("请输入表达式:");
	scanf("%s",a);
	if(match(a) == 0){
		printf("括号不匹配!\n");
	}else{
		printf("括号匹配!\n");
	}
	return 0;
}
