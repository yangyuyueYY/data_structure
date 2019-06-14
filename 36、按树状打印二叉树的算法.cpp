/*
 * 假设以二叉链表存储的二叉树中，每个结点所含数据元素均为单字母，试编写算法，按树状打印二叉树的算法
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
	Tree data;
	int n;
}Data;

typedef struct
{
	Data *data;
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
	q->data = (Data *)malloc(max * sizeof(Data));
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
 * @param Data *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,Data *data)
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
 * @param Data x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, Data x)
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
 * @param Data *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, Data *x)
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
 * 求深度
 * @param Tree T 根结点
 * @return int 深度
 */
int depth(Tree T)
{
	int h1,h2;
	if(T == NULL){
		return 0;
	}else{
		h1 = depth(T->lchild);
		h2 = depth(T->rchild);
		if(h1>=h2){
			return h1+1;
		}else{
			return h2+1;
		}
	}
}

/*
 * 树状打印二叉树
 * @param Tree T 根结点
 */
void display(Tree T)
{
	Queue q;
	int n = depth(T);
	printf("%d\n",n);
	int i,m=1,y,j;
	int *b = (int *)malloc(n*sizeof(int));
	if(b == NULL){
		return;
	}
	b[n-1] = 1;
	for(i=n-2;i>=0;i--){
		b[i] = 2*b[i+1];
	}
	int *c = (int *)malloc(n*sizeof(int));
	if(c == NULL){
		return;
	}
	c[n-1] = 0;
	for(i=n-2;i>=0;i--){
		c[i] = c[i+1] + 2;
	}
	initQueue(&q,20);
	Data x,t;
	if(T){
		x.data = T;
		x.n = 1;
		enQueue(&q,x);
	}
	Tree p = T;
	for(i=0;i<n-1;i++){
		m *= 2;
	}
	char *a = (char *)malloc(m*n*sizeof(char));
	if(a == NULL){
		return;
	}else{
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				*(a+m*i+j) = ' ';
			}
			printf("\n");
		}
		while(isEmptyQueue(q) != 0){
			deQueue(&q,&x);
			y = x.n-1;
			printf("%d",y);
			printf("%c ",x.data->data);
			*(a+m*y+c[y]) = x.data->data;
			c[y] += b[y];
			if(x.data->lchild){
				t.data = x.data->lchild;
				t.n = x.n + 1;
				enQueue(&q,t);
			}else{
				if(y<n){			
					c[y+1] += b[y+1];
				}
			}
			if(x.data->rchild){
				t.data = x.data->rchild;
				t.n = x.n + 1;
				enQueue(&q,t);
			}else{
				if(y<n){
					c[y+1] += b[y+1];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",*(a+m*i+j));
		}
		printf("\n");
	}
}

int main()
{
	Tree T;
	int i=0;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("打印结果:\n");
	display(T);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###

*/