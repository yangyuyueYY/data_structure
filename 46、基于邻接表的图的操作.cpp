/*
 * 图的基本操作：创建一个邻接表表示的图；基于邻接表存储结构的连通图的深度优先遍历的递归算法
 * 基于邻接表存储结构的连通图的深度优先遍历的非递归算法；基于邻接表存储结构的连通图的广度优先遍历
 * 基于邻接表存储结构的非连通图的深度优先遍历；基于邻接表存储结构的非连通图的广度优先遍历
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int adjvex;
	struct node *nextArc;
}ArcNode;

typedef struct 
{
	char vertex;
	ArcNode *firstArc;
}VertexNode;

typedef struct
{
	VertexNode *adjlist;
	int vexNum;
	int arcNum;
}ALGraph;

typedef struct
{
	int *data;
	int top;
	int size;
}Stack;//顺序栈

typedef struct
{
	int *data;
	int head;
	int rear;
	int size;
}Queue;//循环队列

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
	q->data = (int *)malloc(max * sizeof(int));
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
 * @param int *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack q,int *data)
{
	if(q.top == 0){
		printf("栈为空!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
}

/*
 * 顺序栈：清空栈
 * @param Stack *q 顺序栈首地址
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack(Stack *q)
{
	q->top = 0;
	return 0;
}

/*
 * 顺序栈：求栈长度
 * @param Stack q 顺序栈
 * @return int 栈的长度
 */
int getLengthStack(Stack q)
{
	return q.top;
}

/*
 * 顺序栈：进栈
 * @param Stack *q 顺序栈首地址
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *q, int x)
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
 * @param int *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *q, int *x)
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
		printf("%d",q.data);
	}
	return;
}

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
	q->data = (int *)malloc(max * sizeof(int));
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
 * @param int *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,int *data)
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
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, int x)
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
 * @param int *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, int *x)
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
 * 创建一个邻接表表示的图
 * @param ALGraph *G 图
 * @return int 是否创建成功
 */
int createGraph(ALGraph *G)
{
	ArcNode *p;
	int i,m,n;
	printf("请输入点数:");
	scanf("%d",&G->vexNum);
	G->adjlist = (VertexNode *)malloc(G->vexNum*sizeof(VertexNode));
	if(G->adjlist == NULL){
		return -1;
	}
	printf("请输入%d个点数据:",G->vexNum);
	getchar();
	for(i=0;i<G->vexNum;i++){
		scanf("%c",&G->adjlist[i].vertex);
		G->adjlist[i].firstArc = NULL;
	}
	printf("请输入边数:");
	scanf("%d",&G->arcNum);
	for(i=0;i<G->arcNum;i++){
		printf("请输入第%d条边:",i+1);
		scanf("%d%d",&m,&n);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = n;
		p->nextArc = G->adjlist[m].firstArc;
		G->adjlist[m].firstArc = p;
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = m;
		p->nextArc = G->adjlist[n].firstArc;
		G->adjlist[n].firstArc = p;
	}
	return 0;
}

/*
 * 基于邻接表存储结构的连通图的深度优先遍历的递归算法
 * @param ALGrapg G 图
 * @param int v 起点
 * @param int *visited 访问标记
 */
void DFSDisplay(ALGraph G,int v,int *visited)
{
	ArcNode *p = G.adjlist[v].firstArc;
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	while(p){
		if(visited[p->adjvex] == 0){
			DFSDisplay(G,p->adjvex,visited);
		}else{
			p = p->nextArc;
		}
	}
}

/*
 * 基于邻接表存储结构的连通图的深度优先遍历的非递归算法
 * @param ALGrapg G 图
 * @param int v 起点
 * @param int *visited 访问标记
 */
void DFSDisplay1(ALGraph G,int v,int *visited)
{
	Stack s;
	int x;
	ArcNode *p;
	initStack(&s,20);
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	pushStack(&s,v);
	while(isEmptyStack(s) != 0){
		getTopStack(s,&x);
		p = G.adjlist[x].firstArc;
		while(p){
			if(visited[p->adjvex] == 0){
				printf("%c",G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;
				pushStack(&s,p->adjvex);
				break;
			}else{
				p = p->nextArc;
			}
		}
		if(p == NULL){
			popStack(&s,&x);
		}
	}
}

/*
 * 基于邻接表存储结构的连通图的广度优先遍历
 * @param ALGraph G 图
 * @param int v 起点
 * @param int *visited 访问标记
 */
void BFSDisplay(ALGraph G,int v,int *visited) 
{
	Queue q;
	int x;
	ArcNode *p;
	initQueue(&q,20);
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	enQueue(&q,v);
	while(isEmptyQueue(q) != 0){
		deQueue(&q,&x);
		p = G.adjlist[x].firstArc;
		while(p){
			if(visited[p->adjvex] == 0){
				printf("%c",G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;
				enQueue(&q,p->adjvex);
			}
			p = p->nextArc;
		}
	}
}

/*
 * 基于邻接表存储结构的非连通图的深度优先遍历
 * @param ALGraph G 图
 * @param int *visited 访问标记
 */
void DFSDisplay2(ALGraph G,int *visited)
{
	int i;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFSDisplay(G,i,visited);
		}
	}
}

/*
 * 基于邻接表存储结构的非连通图的广度优先遍历
 * @param ALGraph G 图
 * @param int *visited 访问标记
 */
void BFSDisplay1(ALGraph G,int *visited)
{
	int i;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			BFSDisplay(G,i,visited);
		}
	}
}

int main()
{
	ALGraph G;
	int i,found=0;
	int *visited;
	if(0 == createGraph(&G)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	visited = (int *)malloc(G.vexNum*sizeof(int));
	if(visited == NULL){
		return -1;
	}
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("连通图递归深度遍历:");
	DFSDisplay(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("连通图非递归深度遍历:");
	DFSDisplay1(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("连通图广度遍历:");
	BFSDisplay(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("非连通图深度遍历:");
	DFSDisplay2(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("非连通图广度遍历:");
	BFSDisplay1(G,visited);
	putchar('\n');
	return 0;
}


/*
10
cbaefdihgk
11
1 2
0 1
0 2
0 3
1 3
2 5
3 8
4 5
4 6
4 7
6 7
*/