/*
 * 拓扑排序算法
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
	int count;
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
		printf("%d ",q.data);
	}
	return;
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
		G->adjlist[i].count = 0;
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
		G->adjlist[n].count ++;
	}
	return 0;
}

/*
 * 拓扑排序算法
 * @param ALGraph G 图
 * @return int 是否为有向无环图，0不是，1是
 */
int top_sort(ALGraph G)
{
	Stack s;
	int i,m=0,x;
	ArcNode *p;
	initStack(&s,20);
	for(i=0;i<G.vexNum;i++){
		if(G.adjlist[i].count == 0){
			pushStack(&s,i);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		printf("%c ",G.adjlist[x].vertex);
		m ++;
		p = G.adjlist[x].firstArc;
		while(p){
			G.adjlist[p->adjvex].count --;
			if(G.adjlist[p->adjvex].count == 0){
				pushStack(&s,p->adjvex);
			}
			p = p->nextArc;
		}
	}
	if(m < G.vexNum){
		return 0;
	}
	return 1;
}

int main()
{
	ALGraph G;
	if(0 == createGraph(&G)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("拓扑排序序列为:");
	if(0 == top_sort(G)){
		putchar('\n');
		printf("不是有向无环图!\n");
	}else{
		putchar('\n');
		printf("是有向无环图!\n");
	}
	return 0;
}

/*
7
1234567
6
0 3
0 2
1 3
1 4
2 5
4 6
*/