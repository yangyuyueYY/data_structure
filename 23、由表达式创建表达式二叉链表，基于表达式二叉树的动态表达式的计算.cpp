/*
 * 由表达式创建表达式二叉链表，基于表达式二叉树的动态表达式的计算
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct node1
{
	char data;
	struct node1 *next;
}Node1,*Stack1;

typedef struct node2
{
	Tree data;
	struct node2 *next;
}Node2,*Stack2;

/*
 * 链栈：初始化
 * @param Stack1 *L 指向链栈头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initStack1(Stack1 *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链栈：初始化
 * @param Stack2 *L 指向链栈头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initStack2(Stack2 *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链栈：得到栈顶
 * @param Stack1 L 链栈头指针
 * @param char *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack1 L,char *data)
{
	if(L == NULL){
		printf("栈为空!\n");
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * 链栈：进栈
 * @param Stack1 *L 链栈头指针
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack1(Stack1 *L, char x)
{ 
	Stack1 q;
	q = (Stack1) malloc (sizeof(Node1));
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
 * 链栈：进栈
 * @param Stack2 *L 链栈头指针
 * @param Tree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack2(Stack2 *L, Tree x)
{ 
	Stack2 q;
	q = (Stack2) malloc (sizeof(Node2));
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
 * @param Stack1 *L 链栈首地址
 * @param char *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack1(Stack1 *L, char *x)
{ 
	Stack1 p = *L;
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
 * 链栈：出栈
 * @param Stack2 *L 链栈首地址
 * @param Tree *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack2(Stack2 *L, Tree *x)
{ 
	Stack2 p = *L;
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
 * @param Stack1 L 链栈
 */
void displayStack(Stack1 L)
{
	int i = 0;
	Stack1 p = L;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%c ",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
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
 * 由表达式创建表达式二叉链表
 * @param Tree *T 根节点指针
 * @param char *cal 计算表达式
 * @return int 是否创建成功，0成功，-1失败
 */
int createTree(Tree *T,char *cal)
{
	int n,i;
	char x;
	Tree p,q;
	n = strlen(cal);
	Stack1 s1;
	Stack2 s2;
	initStack1(&s1);
	initStack2(&s2);
	pushStack1(&s1,'#');
	for(i=0;i<n;i++){
		if((cal[i] <= 'z' && cal[i] >= 'a') || (cal[i] <= 'Z' && cal[i] >= 'A')){
			p = (Tree)malloc(sizeof(Node));
			p->data = cal[i];
			p->lchild = NULL;
			p->rchild = NULL;
			pushStack2(&s2,p);
		}else if(cal[i] == '('){
			pushStack1(&s1,cal[i]);
		}else if(cal[i] == '+' || cal[i] == '-' || cal[i] == '*' || cal[i] == '/'){
			getTopStack(s1,&x);
			if(judge(x) < judge(cal[i])){
				pushStack1(&s1,cal[i]);
			}else{
				popStack1(&s1,&x);
				p = (Tree)malloc(sizeof(Node));
				p->data = x;
				popStack2(&s2,&q);
				p->rchild = q;
				popStack2(&s2,&q);
				p->lchild = q;
				pushStack2(&s2,p);
				pushStack1(&s1,cal[i]);
			}
		}else if(cal[i] == ')'){
			popStack1(&s1,&x);
			while(x != '('){
				p = (Tree)malloc(sizeof(Node));
				p->data = x;
				popStack2(&s2,&q);
				p->rchild = q;
				popStack2(&s2,&q);
				p->lchild = q;
				pushStack2(&s2,p);
				popStack1(&s1,&x);
			}
		}
	}
	popStack1(&s1,&x);
	while(x != '#'){
		p = (Tree)malloc(sizeof(Node));
		p->data = x;
		popStack2(&s2,&q);
		p->rchild = q;
		popStack2(&s2,&q);
		p->lchild = q;
		pushStack2(&s2,p);
		popStack1(&s1,&x);
		if(x == '#'){
			*T = p;
		}
	}
	return 0;
}

/*
 * 二叉树的先序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * 基于表达式二叉树的动态表达式的计算
 * @param Tree T 二叉树的根节点
 * @return double 计算结果
 */
double culexp(Tree T)
{
	double result,a,b;
	if(T){
		if(T->data <= 'z' && T->data >= 'a'){
			printf("请输入变量%c:",T->data);
			scanf("%lf",&result);
			return result;
		}
		a = culexp(T->lchild);
		b = culexp(T->rchild);
		switch(T->data){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(fabs(b)<1e-6){
				printf("除数不能为零!\n");
				exit(0);
			}else{
				return a/b;
			}
		}
	}
}

int main()
{
	Tree T;
	char a[20];
	printf("请输入表达式:");
	scanf("%s",a);
	if(0 == createTree(&T,a)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("计算结果为：");
	printf("%g",culexp(T));
	putchar('\n');
	return 0;
}

/*
(a+b)*c-d/e
*/