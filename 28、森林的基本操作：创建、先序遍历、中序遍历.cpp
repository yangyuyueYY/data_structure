/*
 * 森林的基本操作：创建、先序遍历、中序遍历
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *fch,*nsib;
}CSNode,*CSTree;

typedef struct
{
	CSTree *data;
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
	q->data = (CSTree *)malloc(max * sizeof(CSTree));
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
 * @param CSTree *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,CSTree *data)
{
	if(isEmptyQueue(q) == 0){
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
 * @param CSTree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, CSTree x)
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
 * @param CSTree *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, CSTree *x)
{ 
	if(isEmptyQueue(*q) == 0){
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
}

/*
 * 创建孩子兄弟链表
 * @param CSTree *T 根结点指针
 * @return int 是否创建成功，0成功，-1失败
 */
int create(CSTree *T)
{
	char fa,ch;
	Queue Q;
	CSTree p,s,r;
	initQueue(&Q,20);
	*T = NULL;
	getchar();
	printf("请输入边（父，子）:");
	scanf("%c,%c",&fa,&ch);
	while(ch != '#'){
		p = (CSTree)malloc(sizeof(CSNode));
		if(p == NULL){
			return -1;
		}
		p->data = ch;
		p->fch = NULL;
		p->nsib = NULL;
		enQueue(&Q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(Q,&s);
			while(s->data != fa){
				deQueue(&Q, &s);
				getHeadQueue(Q,&s);
			}
			if(s->fch == NULL){
				s->fch = p;
				r = p;
			}else{
				r->nsib = p;
				r = p;
			}
		}
		getchar();
		scanf("%c,%c",&fa,&ch);
	}
	return 0;
}

/*
 * 将森林转化为二叉树
 * @param CSTree *TR 树的根结点数组
 * @param int n 数组元素个数
 * @return int 是否转化成功，0成功，-1失败
 */
int createBitree(CSTree *TR,int n)
{
	int i;
	for(i=n-1;i>0;i--){
		TR[i-1]->nsib = TR[i];
	}
	return 0;
}

/* 
 * 森林的先序遍历
 * @param CSTree T 根结点
 */
void preDisplay(CSTree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->fch);
		preDisplay(T->nsib);
	}
}

/* 
 * 森林的中序遍历
 * @param CSTree T 根结点
 */
void midDisplay(CSTree T)
{
	if(T){
		midDisplay(T->fch);
		printf("%c",T->data);
		midDisplay(T->nsib);
	}
}

int main()
{
	int n,i;
	CSTree *TR;
	printf("请输入森林中树的个数:");
	scanf("%d",&n);
	TR = (CSTree *)malloc(n * sizeof(CSTree));
	for(i=0;i<n;i++){
		printf("开始构造第%d棵树:",i+1);
		create(&TR[i]);
	}
	if(0 == createBitree(TR,n)){
		printf("森林创建成功!\n");
	}else{
		printf("森林创建失败!\n");
		return -1;
	}
	printf("先序遍历为:\n");
	preDisplay(TR[0]);
	putchar('\n');
	printf("中序遍历为:\n");
	midDisplay(TR[0]);
	putchar('\n');
	return 0;
}

/*
3
#,A
A,B
A,C
A,D
D,#
#,E
E,F
F,#
#,G
G,H
G,I
I,J
J,#
*/