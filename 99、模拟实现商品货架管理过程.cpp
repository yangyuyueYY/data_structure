/*
 * 商品货架可以看作个栈，栈顶商品的生产日期最早，栈底商品的生产日期最近
 * 上货时，以保证生产日期较近的商品放在比较下的位置，用另一个栈作为周转，模拟实现商品货架管理过程
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
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
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, int x)
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
 * @param int *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, int *x)
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
		printf("%d ", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

int main()
{
	int n,i;
	Stack L1,L2;
	initStack(&L1);
	initStack(&L2);
	printf("请输入商品数:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		pushStack(&L1,i+1);
	}
	printf("栈1为:");
	displayStack(L1);
	while(isEmptyStack(L1)!=0){
		popStack(&L1,&i);
		pushStack(&L2,i);
	}
	printf("栈2为:");
	displayStack(L2);
	return 0;
}
