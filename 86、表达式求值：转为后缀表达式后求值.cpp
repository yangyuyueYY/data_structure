/*
 * 表达式求值：转为后缀表达式后求值
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
 * 将原表达式转换为后缀表达式
 * @param char *a 原表达式
 * @return int 是否转换成功，0成功，-1失败
 */
int transform(char *a,char *b)
{
	int i,n,j=0;
	int x,y;
	char data;
	n = strlen(a);
	Stack q;
	initStack(&q, 20);
	pushStack(&q, '#');
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			b[j] = a[i];
			j ++;
		}else if(a[i] == '('){
			pushStack(&q, '(');
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			getTopStack(q,&data);
			x = judge(data);
			y = judge(a[i]);
			if(x < y){
				pushStack(&q, a[i]);
			}else{
				popStack(&q, &data);
				b[j] = data;
				j++;
				pushStack(&q, a[i]);
			}
		}else if(a[i] == ')'){
			popStack(&q, &data);
			while(data != '('){
				b[j] = data;
				j++;
				popStack(&q, &data);
			}
		}
	}
	getTopStack(q,&data);
	while(data != '#'){
		popStack(&q, &data);
		b[j] = data;
		j++;
	}	
	b[j-1] = '\0';
	return 0;
}

/*
 * 根据后缀表达式求值
 * @param char *a 后缀表达式
 * @return int 最终结果
 */
int calculate(char *a)
{
	Stack q;
	char data1,data2;
	initStack(&q, 20);
	int n,i,x;
	n = strlen(a);
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			pushStack(&q, a[i]);
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			popStack(&q, &data2);
			popStack(&q, &data1);
			if(a[i] == '+'){
				x = (data1 - '0') + (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '-'){
				x = (data1 - '0') - (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '*'){
				x = (data1 - '0') * (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '/'){
				x = (data1 - '0') / (data2 - '0');
				pushStack(&q,x+'0');
			}
		}
	}
	getTopStack(q,&data1);
	return data1-'0';
}

int main()
{
	char a[40],b[40];
	printf("请输入原表达式:");
	scanf("%s",a);
	printf("转换中……\n");
	transform(a,b);
	printf("转换后的后缀表达式为:");
	printf("%s\n",b);
	printf("计算结果为:%d\n",calculate(b));
	return 0;
}
