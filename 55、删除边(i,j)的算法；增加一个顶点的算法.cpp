/*
 * 已知无向图采用邻接表存储方式，写出删除边(i,j)的算法；增加一个顶点的算法
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
 * 删除边
 * @param ALGraph *G 图指针
 * @return int 是否删除成功
 */
int deletearc(ALGraph *G)
{
	int m,n;
	ArcNode *p,*q;
	printf("请输入待删除边:");
	scanf("%d%d",&m,&n);
	p = G->adjlist[m].firstArc;
	if(p){
		if(p->adjvex == n){
			G->adjlist[m].firstArc = p->nextArc;
			delete p;
		}else{
			while(p->nextArc){
				if(p->nextArc->adjvex == n){
					q = p->nextArc;
					p->nextArc = q->nextArc;
					delete q;
					break;
				}
				p = p->nextArc;
			}
		}
	}
	p = G->adjlist[n].firstArc;
	if(p){
		if(p->adjvex == m){
			G->adjlist[n].firstArc = p->nextArc;
			delete p;
		}else{
			while(p->nextArc){
				if(p->nextArc->adjvex == m){
					q = p->nextArc;
					p->nextArc = q->nextArc;
					delete q;
					break;
				}
				p = p->nextArc;
			}
		}
	}
	G->arcNum --;
	return 0;
}

/*
 * 增加点
 * @param ALGraph *G 图
 * @return int 是否增加成功
 */
int addvex(ALGraph *G)
{
	getchar();
	printf("请输入点数据:");
	scanf("%c",&G->adjlist[G->vexNum].vertex);
	G->adjlist[G->vexNum].firstArc = NULL;
	G->vexNum ++;
	return 0;
}

int main()
{
	ALGraph G;
	int i;
	ArcNode *p;
	if(0 == createGraph(&G)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("初始邻接为:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c：",i,G.adjlist[i].vertex);
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%d ",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
	deletearc(&G);
	printf("删边后邻接为:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c：",i,G.adjlist[i].vertex);
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%d ",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
	addvex(&G);
	printf("加点后邻接为:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c：",i,G.adjlist[i].vertex);
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%d ",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
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