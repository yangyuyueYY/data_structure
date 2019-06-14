/*
 * 表达式求值：直接求值
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
 * 顺序栈：得到栈顶
 * @param Stack q 顺序栈
 * @param char *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack q,char *data)
{
	if(q.top == 0){
		printf("栈为空!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
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
		printf("%c ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * 判断运算符优先级
 * @param char m 运算符
 * @return int 优先级：0,1,2
 */
int judge(char m){
	if(m == '('){
		return 0;
	}
	if(m == '+' || m == '-'){
		return 1;
	}
	if(m == '*' || m == '/'){
		return 2;
	}
	if(m == '#'){
		return -1;
	}
	return -1;
}

/*
 * 表达式计算
 * @param char *a 表达式
 * @return int 最终计算值
 */
int calculate(char *a)
{
	int n,i,x,y;
	char top,t1,t2,t,data,result;
	int tn;
	Stack s1,s2;
	n = strlen(a);
	initStack(&s1,20);
	initStack(&s2,20);
	pushStack(&s2, '#');
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			pushStack(&s1, a[i]);
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			getTopStack(s2,&top);
			x = judge(top);
			y = judge(a[i]);
			if(x < y){
				pushStack(&s2, a[i]);
			}else{
				popStack(&s2, &top);
				popStack(&s1, &t2);
				popStack(&s1, &t1);
				if(top == '+'){
					tn = (t1-'0') + (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '-'){
					tn = (t1-'0') - (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '*'){
					tn = (t1-'0') * (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '/'){
					tn = (t1-'0') / (t2-'0');
					pushStack(&s1, tn+'0');
				}
				pushStack(&s2, a[i]);
			}
		}else if(a[i] == '('){
			pushStack(&s2, a[i]);
		}else if(a[i] == ')'){
			popStack(&s2, &data);
			while(data != '('){
				popStack(&s1, &t2);
				popStack(&s1, &t1);
				if(data == '+'){
					tn = (t1-'0') + (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '-'){
					tn = (t1-'0') - (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '*'){
					tn = (t1-'0') * (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '/'){
					tn = (t1-'0') / (t2-'0');
					pushStack(&s1, tn+'0');
				}
				popStack(&s2, &data);
			}
		}
	}
	popStack(&s2, &data);
	while(data != '#'){
		popStack(&s1, &t2);
		popStack(&s1, &t1);
		if(data == '+'){
			tn = (t1-'0') + (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '-'){
			tn = (t1-'0') - (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '*'){
			tn = (t1-'0') * (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '/'){
			tn = (t1-'0') / (t2-'0');
			pushStack(&s1, tn+'0');
		}
		popStack(&s2, &data);
	}
	popStack(&s1,&result);
	return result-'0';
}

int main()
{
	char a[40];
	printf("请输入表达式:");
	scanf("%s",a);
	printf("表达式结果为:%d\n",calculate(a));
	return 0;
}
