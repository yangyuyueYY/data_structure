/*
 * 图的相关操作：创建一个邻接矩阵表示的图；基于邻接矩阵存储结构的连通图的深度优先遍历的递归算法；
 * 基于邻接矩阵存储结构的连通图的深度优先遍历的非递归算法；基于邻接矩阵存储结构的连通图的广度优先遍历；
 * 基于邻接矩阵存储结构的非连通图的深度优先遍历；基于邻接矩阵存储结构的非连通图的广度优先遍历；
 * 求一条包含图中所有顶点的简单路径（哈密尔顿问题）；判断图中是否存在环；求无向图的顶点a到i之间的简单路径
 * 求无向图的顶点vi和vj之间的最短路径
 * @author v_yuyueyang 2017-08-26
 */
#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char vexs[MAX];
	int arcs[MAX][MAX];
	int vexNum;
	int arcNum;
}MGraph;

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

typedef struct node
{
	struct node *prior;
	int data;
	struct node *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue1;

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
 * 链队列的基本操作：初始化
 * @param Queue *q 链队列
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initQueue1(Queue1 *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->prior = NULL;
	p->next = NULL;
	p->data = -1;
	q->L = p;
	q->R = p;
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
 * 链队列：判断队空
 * @param Queue q 链队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue1(Queue1 q)
{
	if(q.L == q.R){
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
 * 链队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue1(Queue1 *q, int x)
{
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("空间分配失败\n");
		return -1;
	}
	s->data = x;
	s->next = NULL;
	s->prior = q->L;
	q->R->next = s;
	q->R = s;
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
 * 链队列：出队列
 * @param Queue1 *q 链队列首地址
 * @param int *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue1(Queue1 *q, int *x)
{
	q->L = q->L->next;
	return 0;
}

/*
 * 顺序队列：遍历
 * @param Queue q 顺序队列
 */
void displayQueue(Queue q)
{ 
	int i=0,t = q.head;
	if(isEmptyQueue(q) == 0){
		printf("队列为空!\n");
		return;
	}
	while(t != q.rear){
		printf("%d",q.data[t]); 
		t = (t+1)%q.size;
		i++;
	}
	return;
}

/*
 * 链队列：遍历
 * @param Queue q 链队列
 */
void displayQueue1(Queue1 q)
{
	int i = 0;
	SqList p = q.R->prior;
	if(isEmptyQueue1(q) == 0){
		printf("队列为空!\n");
		return;
	}
	while(p != NULL){
		printf("%d ", p->data);
		i ++;
		p = p->prior;
	}
	putchar('\n');
}

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
 * 顺序栈：销毁
 * @param Stack* q 顺序栈首地址
 * @return int 是否销毁成功，-1为失败，0为成功
 */
int destroyStack(Stack *q)
{
	free(q->data);
	free(&q->top);
	free(&q->size);
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
 * 初始化图
 * @param MGraph *G 图
 * @return int 是否初始化成功
 */ 
int initGraph(MGraph *G)
{
	int i,j;
	for(i=0;i<MAX;i++){
		G->vexs[i] = ' ';
		for(j=0;j<MAX;j++){
			G->arcs[i][j] = 0;
		}
	}
	G->arcNum = 0;
	G->vexNum = 0;
	return 0;
}

/*
 * 创建一个邻接矩阵表示的图
 * @param MGraph *G 图
 * @return int 是否创建成功
 */
int createGraph(MGraph *G)
{
	int i,m,n;
	printf("请输入点数:");
	scanf("%d",&G->vexNum);
	printf("请输入%d个点数据:",G->vexNum);
	getchar();
	for(i=0;i<G->vexNum;i++){
		scanf("%c",&G->vexs[i]);
	}
	printf("请输入边数:");
	scanf("%d",&G->arcNum);
	for(i=0;i<G->arcNum;i++){
		printf("请输入第%d条边:",i+1);
		scanf("%d%d",&m,&n);
		G->arcs[m][n] = 1;
		G->arcs[n][m] = 1;
	}
	return 0;
}

/*
 * 基于邻接矩阵存储结构的连通图的深度优先遍历的递归算法
 * @param MGraph G 图
 * @param int v 访问起点
 * @param int *visited 访问标记
 */
void DFSRecurse(MGraph G,int v,int *visited)
{
	int i;
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	for(i=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1 && visited[i] == 0){
			DFSRecurse(G,i,visited);
		}
	}
	if(i == G.vexNum){
		return;
	}
}

/*
 * 基于邻接矩阵存储结构的连通图的深度优先遍历的非递归算法
 * @param MGraph G 图
 * @param int v 访问起点
 * @param int *visited 访问标记
 */
void DFSUnrecurse(MGraph G,int v,int *visited)
{
	int i,x;
	Stack s;
	initStack(&s,20);
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	pushStack(&s,v);
	while(isEmptyStack(s) != 0){
		getTopStack(s,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				printf("%c",G.vexs[i]);
				visited[i] = 1;
				pushStack(&s,i);
				break;
			}
		}
		if(i == G.vexNum){
			popStack(&s,&x);
		}
	}
}

/*
 * 基于邻接矩阵存储结构的连通图的广度优先遍历
 * @param MGraph G 图
 * @param int v 访问起点
 * @param int *visited 访问标记
 */
void GFSUnrecurse(MGraph G,int v,int *visited)
{
	int i,x;
	Queue q;
	initQueue(&q,20);
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	enQueue(&q,v);
	while(isEmptyQueue(q) != 0){
		deQueue(&q,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				printf("%c",G.vexs[i]);
				visited[i] = 1;
				enQueue(&q,i);
			}
		}
	}
}

/*
 * 基于邻接矩阵存储结构的非连通图的深度优先遍历
 * @param MGraph G 图
 * @param int *visited 访问标记
 */
void DFSUnlink(MGraph G,int *visited)
{
	int i = 0;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFSUnrecurse(G,i,visited);
		}
	}
}

/*
 * 基于邻接矩阵存储结构的非连通图的广度优先遍历
 * @param MGraph G 图
 * @param int *visited 访问标记
 */
void GFSUnlink(MGraph G,int *visited)
{
	int i = 0;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			GFSUnrecurse(G,i,visited);
		}
	}
}

/*
 * 求以v为起点的简单路径
 * @param MGraph G 图
 * @param int v 起点
 * @param int *visited 访问标记
 * @param int *n 访问结点数
 * @param char *path 路径
 * @param int  *flag是否存在
 */
void DFS(MGraph G,int v,int *visited,int *n,char *path,int *flag)
{
	int i;
	path[*n] = G.vexs[v];
	visited[v] = 1;
	(*n) ++;
	if((*n) >= G.vexNum){
		printf("简单路径为:");
		for(i=0;i<G.vexNum;i++){
			printf("%c ",path[i]);
		}
		putchar('\n');
		*flag = 1;
	}
	for(i=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1 && visited[i] == 0){
			DFS(G,i,visited,n,path,flag);
		}
	}
	visited[v] = 0;
	(*n) --;
}

/*
 * 求一条包含图中所有顶点的简单路径（哈密尔顿问题）；
 * @param MGraph G 图
 * @param int *visited 访问标记
 * @return int 是否存在
 */
int Hamilton(MGraph G,int *visited)
{
	int i,n=0,flag=0;
	char path[20];
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFS(G,i,visited,&n,path,&flag);
		}
	}
	if(flag == 1){
		return 0;
	}
	return -1;
}

/*
 * 判断图中是否存在环
 * @param MGraph G 图
 * @param int *flag 是否存在环
 * @param int *visited 访问标记
 * @param int v 起点
 */
void haveCircle(MGraph G,int *flag,int *visited,int v)
{
	int m,n,i;
	visited[v] = 1;
	for(i=0,m=0,n=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1){
			m ++;
			if(visited[i] == 1){
				n ++;
			}
		}
	}
	if(m == n && m != 1){
		*flag = 1;
		return;
	}
	for(i=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1 && visited[i] == 0){
			haveCircle(G,flag,visited,i);
		}
	}
}

/*
 * 求无向图的顶点a到i之间的简单路径
 * @param MGraph G 图
 * @param int a 起点
 * @param int i 终点
 * @param char *path 路径
 * @param int *visited 访问标记
 * @param int *found 是否找到
 * @param int *n 路径中结点数
 */
void DFSearchPath(MGraph G,int a,int i,char *path,int *visited,int *found,int *n)
{
	int j;
	visited[a] = 1;
	path[(*n)] = G.vexs[a];
	(*n)++;
	for(j=0;j<G.vexNum && (*found)==0;j++){
		if(G.arcs[a][j] == 1){
			if(j == i){
				*found = 1;
				path[(*n)] = G.vexs[j];
				(*n) ++;
			}else if(visited[j] == 0){
				DFSearchPath(G,j,i,path,visited,found,n);
			}
		}
	}
	if((*found) == 0){
		(*n) --;
	}
}

/*
 * 求无向图的顶点vi和vj之间的最短路径
 * @param MGraph G 图
 * @param int vi 起点
 * @param int vj 终点
 * @param int *visited 访问标记
 */
void BFSearchPath(MGraph G,int vi,int vj,int *visited)
{
	Queue1 q;
	int i,x;
	initQueue1(&q);
	enQueue1(&q,vi);
	visited[vi] = 1;
	while(isEmptyQueue1(q) != 0){
		deQueue1(&q,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				enQueue1(&q,i);
				if(i == vj){
					displayQueue1(q);
					break;
				}
			}
		}
		if(i >= G.vexNum){
			break;
		}
	}
}

int main()
{
	MGraph G;
	char path[20];
	int i,j,flag,n,found=0,t;
	int *visited;
	initGraph(&G);
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
	printf("邻接矩阵为:\n");
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			printf("%d ",G.arcs[i][j]);
		}
		printf("\n");
	}
	printf("连通图递归深度遍历:");
	DFSRecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("*******************\n连通图非递归深度遍历:");
	DFSUnrecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("连通图广度遍历:");
	GFSUnrecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("非连通图深度遍历:");
	DFSUnlink(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("非连通图广度遍历:");
	GFSUnlink(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("*************************\n哈密尔顿问题:\n");
	if(0 == Hamilton(G,visited)){
	}else{
		printf("简单路径不存在!");
	}
	putchar('\n');
	flag = 0;
	for(j=0;j<G.vexNum;j++){
		visited[j] = 0;
	}
	haveCircle(G,&flag,visited,0);
	if(flag == 1){
		printf("该图存在环路!\n");
	}else{
		printf("该图不存在环路!\n");
	}
	for(j=0;j<G.vexNum;j++){
		visited[j] = 0;
	}
	printf("请输入起点和终点下标:");
	scanf("%d%d",&i,&j);
	n = 0;
	DFSearchPath(G,i,j,path,visited,&found,&n);
	if(0 == found){
		printf("%c到%c间无简单路径!\n",G.vexs[i],G.vexs[j]);
	}else{
		printf("%c到%c间简单路径为:",G.vexs[i],G.vexs[j]);
		for(t=0;t<n;t++){
			printf("%c ",path[t]);
		}
		putchar('\n');
	}
	return 0;
}


/*
9
cbaefdihg
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
0 8
*/