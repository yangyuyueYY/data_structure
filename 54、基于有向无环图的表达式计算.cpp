/*
 * 基于有向无环图的表达式计算
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
	int data;
	int tag;
	ArcNode *firstArc;
}VertexNode;

typedef struct
{
	VertexNode *adjlist;
	int vexNum;
	int arcNum;
}ALGraph;

/*
 * 创建一个邻接表表示的图
 * @param ALGraph *G 图
 * @return int 是否创建成功
 */
int createGraph(ALGraph *G)
{
	ArcNode *p;
	int i,m,n;
	printf("请输入顶点数和弧数:");
	scanf("%d%d",&G->vexNum,&G->arcNum);
	G->adjlist = (VertexNode *)malloc(G->vexNum*sizeof(VertexNode));
	if(G->adjlist == NULL){
		return -1;
	}
	printf("请输入%d个顶点数据:",G->vexNum);
	getchar();
	for(i=0;i<G->vexNum;i++){
		scanf("%c",&G->adjlist[i].vertex);
		G->adjlist[i].firstArc = NULL;
		G->adjlist[i].data = 0;
		G->adjlist[i].tag = 0;
	}
	for(i=0;i<G->arcNum;i++){
		printf("请输入第%d条边的两个邻接点的序号（从0开始）:",i+1);
		scanf("%d%d",&m,&n);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = n;
		p->nextArc = G->adjlist[m].firstArc;
		G->adjlist[m].firstArc = p;
	}
	return 0;
}

/*
 * 判断字符是否为运算符
 * @param char c 待检验字符
 * @return int 是否为运算符，1是，0不是
 */
int in(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/'){
		return 1;
	}
	return 0;
}

/*
 * 表达式计算
 * @param ALGraph G 图
 */
void calculate(ALGraph G)
{
	int flag = 1,i,n1,n2;
	ArcNode *p,*q;
	while(flag){
		for(i=0;i<G.vexNum;i++){
			if(in(G.adjlist[i].vertex)){
				if(G.adjlist[i].tag == 0){
					p = G.adjlist[i].firstArc;
					q = p->nextArc;
					if(in(G.adjlist[q->adjvex].vertex) && G.adjlist[q->adjvex].tag == 1){
						n1 = G.adjlist[q->adjvex].data;
					}else if(in(G.adjlist[q->adjvex].vertex) == 0 && G.adjlist[q->adjvex].tag == 0){
						printf("请输入变量%c的值：",G.adjlist[q->adjvex].vertex);
						scanf("%d",&n1);
						G.adjlist[q->adjvex].data = n1;
						G.adjlist[q->adjvex].tag = 1;
					}
					if(in(G.adjlist[p->adjvex].vertex) && G.adjlist[p->adjvex].tag == 1){
						n2 = G.adjlist[p->adjvex].data;
					}else if(in(G.adjlist[p->adjvex].vertex) == 0 && G.adjlist[p->adjvex].tag == 0){
						printf("请输入变量%c的值：",G.adjlist[p->adjvex].vertex);
						scanf("%d",&n2);
						G.adjlist[p->adjvex].data = n2;
						G.adjlist[p->adjvex].tag = 1;
					}
					if(G.adjlist[p->adjvex].tag == 1 && G.adjlist[q->adjvex].tag == 1){
						n1 = G.adjlist[p->adjvex].data;
						n2 = G.adjlist[q->adjvex].data;
						switch(G.adjlist[i].vertex){
						case '+':
							G.adjlist[i].data = n1 + n2;
							break;
						case '-':
							G.adjlist[i].data = n1 - n2;
							break;
						case '*':
							G.adjlist[i].data = n1 * n2;
							break;
						case '/':
							G.adjlist[i].data = n1/n2;
							break;
						}
						G.adjlist[i].tag = 1;
					}
				}
			}
			
		}
		flag = 0;
		for(i=0;i<G.vexNum;i++){
			if(in(G.adjlist[i].vertex) && G.adjlist[i].tag == 0){
				flag = 1;
				break;
			}
		}
	}
}

/*
 * 过程展示
 * @param ALGraph G 图
 */
void dispAlgraph(ALGraph G)
{
	int i;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		if(G.adjlist[i].tag == 1){
			printf("%2d%10c%10d%3d----",i,G.adjlist[i].vertex,G.adjlist[i].data,G.adjlist[i].tag);
		}else{
			printf("%2d%10c%10s%3d----",i,G.adjlist[i].vertex," ",G.adjlist[i].tag);
		}
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%5d",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
	putchar('\n');
}

int main()
{
	ALGraph G;
	if(0 == createGraph(&G)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	calculate(G);
	dispAlgraph(G);
	printf("result=%d\n",G.adjlist[0].data);
	return 0;
}

/*
12 14
*+*+ab*+cde*
0 1
0 11
1 2
1 11
2 3
2 6
3 4
3 5
6 5
6 7
7 8
7 9
11 7
11 10
1
2
3
4
5
*/