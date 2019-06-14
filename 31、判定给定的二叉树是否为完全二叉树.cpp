/*
 * 判定给定的二叉树是否为完全二叉树
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct
{
	Tree *data;
	int head;
	int rear;
	int size;
}Queue;//循环队列

/*
 * 循环队列：初始化
 * @param Queue* q 循环队列首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initQueue(Queue *q, int max)
{
	if(max < 0){
		printf("最大数据量不合法\n");
		return -1;
	}
	q->data = (Tree *)malloc(max * sizeof(Tree));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	q->head = 0;
	q->rear = 0;
	q->size = max;
	return 0;
}

/*
 * 循环队列：判断队空
 * @param Queue q 循环队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.head == q.rear){
		return 0;
	}
	return 1;
}

/*
 * 顺序队列：得到队头
 * @param Queue q 顺序队列
 * @param Tree *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,Tree *data)
{
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*data = q.data[q.head];
	return 0;
}

/*
 * 顺序队列：求队列长度
 * @param Queue q 顺序队列
 * @return int 队列长度
 */
int getLengthQueue(Queue q)
{
	return (q.rear+q.size-q.head)%q.size;
}

/*
 * 顺序队列：清空队列
 * @param Queue *q 顺序队列指针
 * @return int 是否清空成功，0成功，-1不成功
 */
int emptyQueue(Queue *q)
{
	q->rear = q->head;
	return 0;
}

/*
 * 顺序队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param Tree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, Tree x)
{ 
	if((q->rear+1)%q->size == q->head){
		printf("队列已满!\n");
		return -1;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % q->size;
	return 0;
}

/*
 * 顺序队列：出队列
 * @param Queue *q 顺序队列首地址
 * @param Tree *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Tree *x)
{ 
	if(isEmptyQueue(*q) == 0){
		printf("队列为空!\n");
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
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
 * 判断给定二叉树是否为完全二叉树
 * @param Tree T 根结点
 * @param Queue *q 队列指针
 * @param int *flag 标记是否已有空结点
 * @param int *y 是否为完全二叉树，0否，1是
 */
void isFull(Queue *q,Tree T,int *flag,int *y)
{
	initQueue(q,20);
	Tree x;
	if(T){
		enQueue(q,T);
	}
	while(isEmptyQueue(*q) != 0){
		deQueue(q,&x);
		if(x->lchild == NULL && x->rchild != NULL){
			*y = 0;
		}
		if(*flag == 1){
			if(x->lchild || x->rchild){
				*y = 0;
			}
		}else{
			if(x->rchild == NULL){
				*flag = 1;
			}
		}
		if(x->lchild){
			enQueue(q,x->lchild);
		}
		if(x->rchild){
			enQueue(q,x->rchild);
		}
	}
}

int main()
{
	Queue q;
	Tree T;
	int flag=0,y=1;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	isFull(&q,T,&flag,&y);
	if(y == 1){
		printf("是完全二叉树!\n");
	}else{
		printf("不是完全二叉树!\n");
	}
	return 0;
}

/*
不是
ABC##DE#G##F###  
是
abd##e##cf##g##
*/