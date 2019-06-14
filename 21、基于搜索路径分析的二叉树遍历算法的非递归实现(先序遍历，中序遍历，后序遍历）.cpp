/*
 * 基于搜索路径分析的二叉树遍历算法的非递归实现(先序遍历，中序遍历，后序遍历）
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct
{
	Tree t;
	char lr;
}Data;

typedef struct node1
{
	Data data;
	struct node1 *next;
}Node1,*Stack;

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
	q = (Stack) malloc (sizeof(Node1));
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
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
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
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * 递归创建二叉树的二叉链表结构
 * @param Tree *T 二叉树根结点指针
 * @return int 是否创建成功,0成功，-1失败
 */
int createTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * 基于搜索路径分析的二叉树遍历算法的非递归实现：后序遍历
 * @param Tree T 根节点
 */
 void afterDisplay(Tree T)
 {
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 x.t = T;
		 x.lr = 'L';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 x.t = p->lchild;
			 x.lr = 'L';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 x.lr = 'R';
			 pushStack(&s,x);
			 if(p->rchild){
				 p = p->rchild;
				 x.t = p;
				 x.lr = 'L';
				 pushStack(&s,x);
				 while(p->lchild){
					 x.t = p->lchild;
					 x.lr = 'L';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }else{
				getTopStack(s,&x);
				while(isEmptyStack(s) != 0 && x.lr == 'R'){
					popStack(&s,&x);
					printf("%c",x.t->data);
					getTopStack(s,&x);
				}
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
 }

 /*
 * 基于搜索路径分析的二叉树遍历算法的非递归实现：前序遍历
 * @param Tree T 根节点
 */
void preDisplay(Tree T)
{
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 printf("%c",T->data);
		 x.t = T;
		 x.lr = ' ';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 printf("%c",p->lchild->data);
			 x.t = p->lchild;
			 x.lr = ' ';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 if(x.t->rchild){
				 p = x.t->rchild;
				 printf("%c",p->data);
				 x.t = p;
				 x.lr = ' ';
				 pushStack(&s,x);
				 while(p->lchild){
					 printf("%c",p->lchild->data);
					 x.t = p->lchild;
					 x.lr = ' ';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
}

/*
 * 基于搜索路径分析的二叉树遍历算法的非递归实现：中序遍历
 * @param Tree T 根节点
 */
void midDisplay(Tree T)
{
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 x.t = T;
		 x.lr = ' ';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 x.t = p->lchild;
			 x.lr = ' ';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 printf("%c",x.t->data);
			 if(x.t->rchild){
				 p = x.t->rchild;
				 x.t = p;
				 x.lr = ' ';
				 pushStack(&s,x);
				 while(p->lchild){
					 x.t = p->lchild;
					 x.lr = ' ';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
}

int main()
{
	Tree T;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("中序遍历为:");
	midDisplay(T);
	putchar('\n');
	printf("后序遍历为:");
	afterDisplay(T);
	putchar('\n');
	return 0;
}
/*
ABC##DE#G##F###
*/