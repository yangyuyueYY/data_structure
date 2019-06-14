/*
 * 求关键路径：输入顶点和弧的信息，建立其带入度的邻接表；计算每个顶点的入度；对其进行拓扑排序
 * 排序过程中求顶点ve[i]；将得到的拓扑序列进栈；按逆拓扑序列求顶点的vl[i]；
 * 计算每条弧的ee[i]和el[i]，找出ee[i]==el[i]的活动
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	int adjvex;
	int weight;
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
	int i,m,n,d,k;
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
		scanf("%d%d%d%d",&m,&n,&d,&k);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = n;
		p->weight = d;
		p->num = k;
		p->nextArc = G->adjlist[m].firstArc;
		G->adjlist[m].firstArc = p;
		G->adjlist[n].count ++;
	}
	return 0;
}

/*
 * 拓扑排序算法
 * @param ALGraph G 图
 * @param int *a 拓扑序列
 * @param int *ve ve数据
 * @return int 是否为有向无环图，0不是，1是
 */
int top_sort(ALGraph G,int *a,int *ve)
{
	Stack s;
	int i,m=0,x,j=0;
	int *ru;
	ArcNode *p;
	initStack(&s,20);
	ru = (int*)malloc(G.vexNum * sizeof(int));
	if(ru == NULL){
		return -1;
	}
	for(i=0;i<G.vexNum;i++){
		ru[i] = G.adjlist[i].count;
		ve[i] = 0;
		if(G.adjlist[i].count == 0){
			pushStack(&s,i);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		a[j] = x;
		j++;
		m ++;
		p = G.adjlist[x].firstArc;
		while(p){
			ru[p->adjvex] --;
			if(ru[p->adjvex] == 0){
				pushStack(&s,p->adjvex);
			}
			if(p->weight+ve[x] > ve[p->adjvex]){
				ve[p->adjvex] = p->weight+ve[x];
			}
			p = p->nextArc;
		}
	}
	if(m < G.vexNum){
		return 0;
	}
	return 1;
}

/*
 * 求vl
 * @param ALGraph G 图
 * @param int *a 拓扑序列
 * @param int *ve ve数据
 * @param int *vl vl数据
 */
void calvl(ALGraph G,int *a,int *ve,int *vl)
{
	int i,j,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		vl[i] = 100000;
	}
	vl[G.vexNum-1] = ve[G.vexNum-1];
	
	for(i=G.vexNum-1;i>=0;i--){
		for(j=0;j<G.vexNum;j++){
			p = G.adjlist[j].firstArc;
			while(p){
				if(p->adjvex == a[i]){
					for(k=0;k<G.vexNum;k++){
						if(a[k] == j){
							break;
						}
					}
					if(vl[i] - p->weight < vl[k]){
						vl[k] = vl[i] - p->weight;
					}
				}
				p = p->nextArc;
			}
		}
	}
}

/*
 * 求ee
 * @param ALGraph G 图
 * @param int *ve ve数据
 * @param int *ee ee数据
 * @param int *a 拓扑序列
 */
void calee(ALGraph G,int *ve,int *ee,int *a)
{
	int i,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		p = G.adjlist[i].firstArc;
		while(p){
			for(k=0;k<G.vexNum;k++){
				if(a[k] == i){
					break;
				}
			}
			ee[p->num - 1] = ve[i];
			p = p->nextArc;
		}
	}
}

/*
 * 求el
 * @param ALGraph G 图
 * @param int *vl vl数据
 * @param int *el el数据
 * @param int *a 拓扑序列
 */
void calel(ALGraph G,int *vl,int *el,int *a)
{
	int i,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		p = G.adjlist[i].firstArc;
		while(p){
			for(k=0;k<G.vexNum;k++){
				if(a[k] == p->adjvex){
					break;
				}
			}
			el[p->num - 1] = vl[k] - p->weight;
			p = p->nextArc;
		}
	}
}

/*
 * 求关键路径
 * @param ALGraph G 图
 * @param int *ee ee数据
 * @param int *el el数据
 * @param int *path 关键路径
 * @return int 关键路径长度
 */
int keypath(ALGraph G,int *ee,int *el,int *path)
{
	int n,i;
	n = 0;
	for(i=0;i<G.arcNum;i++){
		if(ee[i] == el[i]){
			path[n] = i+1;
			n ++;
		}
	}
	return n;
}

int main()
{
	ALGraph G;
	int a[20],ee[20],ve[20],el[20],vl[20],i,path[20],n;
	if(0 == createGraph(&G)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	if(0 == top_sort(G,a,ve)){
		putchar('\n');
		printf("不是有向无环图!\n");
	}else{
		putchar('\n');
		printf("是有向无环图!\n");
	}
	printf("拓扑排序序列为:");
	for(i=0;i<G.vexNum;i++){
		printf("%c ",G.adjlist[a[i]].vertex);
	}
	putchar('\n');
	printf("ve为:");
	for(i=0;i<G.vexNum;i++){
		printf("%d ",ve[i]);
	}
	putchar('\n');
	calvl(G,a,ve,vl);
	printf("vl为:");
	for(i=0;i<G.vexNum;i++){
		printf("%d ",vl[i]);
	}
	putchar('\n');
	calee(G,ve,ee,a);
	printf("ee为:");
	for(i=0;i<G.arcNum;i++){
		printf("%d ",ee[i]);
	}
	putchar('\n');
	calel(G,vl,el,a);
	printf("el为:");
	for(i=0;i<G.arcNum;i++){
		printf("%d ",el[i]);
	}
	putchar('\n');
	n = keypath(G,ee,el,path);
	printf("关键路径为:");
	for(i=0;i<n;i++){
		printf("%d ",path[i]);
	}
	putchar('\n');
	return 0;
}

/*
6
123456
8
0 2 3 2
0 1 3 1
1 4 3 4
1 3 2 3
2 5 3 6
2 3 3 5
3 5 2 7 
4 5 1 8
*/
