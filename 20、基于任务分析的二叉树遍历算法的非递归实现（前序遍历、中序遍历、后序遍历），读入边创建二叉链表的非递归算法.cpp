/*
 * 基于任务分析的二叉树遍历算法的非递归实现（前序遍历、中序遍历、后序遍历），读入边创建二叉链表的非递归算法
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct node1
{
	Tree data;
	struct node1 *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue;

typedef struct
{
	Tree t;
	int e;
}Data;

typedef struct node2
{
	Data data;
	struct node2 *next;
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
 * 链队列的基本操作：初始化
 * @param Queue *q 链队列
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initQueue(Queue *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->next = NULL;
	p->data = NULL;
	q->L = p;
	q->R = p;
	return 0;
}

/*
 * 链队列：判断队空
 * @param Queue q 链队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.L == q.R){
		return 0;
	}
	return 1;
}

/*
 * 链队列：得到队头
 * @param Queue q 链队列
 * @param Tree *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,Tree *data)
{
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*data = q.L->next->data;
	return 0;
}

/*
 * 链队列：进队列
 * @param Queue *q 链队列首地址
 * @param Tree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, Tree x)
{
	int i = 0;
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("空间分配失败\n");
		return -1;
	}
	s->data = x;
	s->next = q->R->next;
	q->R->next = s;
	q->R = s;
	return 0;
}

/*
 * 链队列：出队列
 * @param Queue *q 链队列首地址
 * @param Tree *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Tree *x)
{
	SqList p = q->L,s;
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 0;
}

/*
 * 读入边创建二叉链表的非递归算法
 * @param Tree *T 根节点指针
 * @return int 是否创建成功，0为成功，-1为失败
 */
int createTree(Tree *T)
{
	Queue q;
	initQueue(&q);
	char fa,ch;
	int lrflag,i=1;
	Tree p,x;
	printf("请输入第%d条边信息：",i);
	scanf("%c,%c,%d",&fa,&ch,&lrflag);
	i ++;
	while(ch != '#'){
		p = (Tree)malloc(sizeof(Node));
		p->data = ch;
		p->lchild = NULL;
		p->rchild = NULL;
		enQueue(&q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(q,&x);
			while(x->data != fa){
				deQueue(&q,&x);
				getHeadQueue(q,&x);
			}
			if(x->data == fa){
				if(lrflag == 0){
					x->lchild = p;
				}else if(lrflag == 1){
					x->rchild = p;
				}
			}
		}
		getchar();
		printf("请输入第%d条边信息：",i);
		scanf("%c,%c,%d",&fa,&ch,&lrflag);
		i ++;
	}
	return 0;
}

/*
 * 基于任务分析的二叉树遍历算法的非递归实现:前序遍历
 * @param Tree T 根节点
 */
void preDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
		}
	}
}

/*
 * 基于任务分析的二叉树遍历算法的非递归实现:中序遍历
 * @param Tree T 根节点
 */
void midDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
		}
	}
}

/*
 * 基于任务分析的二叉树遍历算法的非递归实现:后序遍历
 * @param Tree T 根节点
 */
void afterDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
		}
	}
}

int main()
{
	Tree T;
	if(createTree(&T) == 0){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("前序遍历为:");
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
#,A,0
A,B,0
B,C,1
C,D,0
C,E,1
D,F,0
D,G,1
F,#,0
*/
