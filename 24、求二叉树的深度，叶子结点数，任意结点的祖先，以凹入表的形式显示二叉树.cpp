/*
 * 求二叉树的深度，叶子结点数，任意结点的祖先，以凹入表的形式显示二叉树
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
		printf("%c",p->data.t->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * 求二叉树的深度
 * @param Tree T 二叉树根节点
 * @return int 深度
 */
int depth(Tree T)
{
	int l,r;
	if(T == NULL){
		return 0;
	}else{
		l = depth(T->lchild);
		r = depth(T->rchild);
		if(l >= r){
			return l+1;
		}else{
			return r+1;
		}
	}
}

/*
 * 求二叉树的叶子节点数
 * @param Tree T 二叉树根节点
 * @param int *num叶子结点数
 */
void leaveNum(Tree T,int *num)
{
	if(T == NULL){
		return;
	}else{
		leaveNum(T->lchild,num);
		leaveNum(T->rchild,num);
		if(T->lchild == NULL && T->rchild == NULL){
			(*num) ++;
		}
	}
}

/*
 * 求任意结点的祖先
 * @param Tree T 二叉树根节点
 * @param char data 节点内容
 */
 void getPrior(Tree T,char data)
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
					if(x.t->data == data){
						displayStack(s);
						return;
					}
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
	}
	else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * 以凹入表的形式显示二叉树
 * @param Tree T 二叉树根节点
 * @param int level 层次
 * @param char c 方向
 */
void disp(Tree T,int level,char c)
{
	int i,k;
	if(T == NULL){
		return;
	}else{
		for(i=1;i<level;i++){
			putchar(' ');
		}
		printf("%c(%c)",T->data,c);
		for(k=i+4;k<20;k++){
			printf("-");
		}
		putchar('\n');
		disp(T->lchild,level+2,'L');
		disp(T->rchild,level+2,'R');
	}
}

int main()
{
	Tree T;
	char x;
	int n = 0;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("二叉树深度为:%d\n",depth(T));
	leaveNum(T,&n);
	printf("叶子结点数为:%d\n",n);
	getchar();
	printf("请输入查找结点:");
	scanf("%c",&x);
	printf("祖先结点为:");
	getPrior(T,x);
	printf("凹入表为:\n");
	disp(T,1,'D');
	return 0;
}

/*
ABC##DE#G##F###
*/