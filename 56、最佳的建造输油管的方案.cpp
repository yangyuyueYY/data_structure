/*
 * 一家石油公司在6个地点有储油罐(a,b,c,d,e,f)，现要在这些储油罐之间建造若干输油管道，以便在这些储油罐之间调配石油
 * 并顺带向沿途的客户供出。因为建造输油管十分昂贵，所有公司希望建造尽可能少的输油管。
 * 另一方面，每条输油管在向客户提供油时都会产生些利润，公司希望所产生的总利润最大
 * 由于各种原因，并非在任意两个储油罐之间否可以建造输油管，6个储油罐及它们之间可以建造的输油管如下图所示
 * 顶点表示储油罐，便表示可能建造的输油管，边上的权表示相应输油管所产生的利润。
 * 假设每条输油管的建造费用都相同，编程实现为该公司设计最佳的建造输油管的方案:普里姆算法
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
	int vi;
	int weight;
}Lowcost;

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
			G->arcs[i][j] = 10000;
		}
		G->arcs[i][i] = 0;
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
	int i,m,n,d;
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
    	printf("请输入第%d条边及权值:",i+1);
		scanf("%d%d%d",&m,&n,&d);
		G->arcs[m][n] = -d;
		G->arcs[n][m] = -d;
	}
	return 0;
}

/*
 * 普里姆算法
 * @param MGraph G 图
 */
void prim(MGraph G)
{
	int i,mincost,j,k;
	Lowcost *lowcost = (Lowcost *)malloc(G.vexNum * sizeof(Lowcost));
	if(lowcost == NULL){
		return;
	}
	for(i=0;i<G.vexNum;i++){
		lowcost[i].vi = 0;
		lowcost[i].weight = G.arcs[0][i];
	}
	for(i=1;i<G.vexNum;i++){
		mincost = 10000;
		for(j=0;j<G.vexNum;j++){
			if(lowcost[j].weight < mincost && lowcost[j].weight != 0){
				mincost = lowcost[j].weight;
				k = j;
			}
		}
		if(mincost == 10000){
			break;
		}
		printf("%c--%c:%d\n",G.vexs[lowcost[k].vi],G.vexs[k],-mincost);
		lowcost[k].weight = 0;
		for(j=0;j<G.vexNum;j++){
			if(G.arcs[k][j] < lowcost[j].weight && lowcost[j].weight != 0){
				lowcost[j].weight = G.arcs[k][j];
				lowcost[j].vi = k;
			}
		}
	}
}

int main()
{
	MGraph G;
	int i,j;
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
	printf("最小生成树为:\n");
	prim(G);
	return 0;
}


/*
6
abcdef
10
0 1 3
0 2 3
1 2 2
1 5 4
2 5 1
2 3 1
2 4 4
3 4 3
3 5 2
4 5 2
*/