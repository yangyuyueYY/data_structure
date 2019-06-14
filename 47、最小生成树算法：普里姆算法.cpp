/*
 * 最小生成树算法：普里姆算法
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
		G->arcs[m][n] = d;
		G->arcs[n][m] = d;
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
		printf("%c--%c:%d\n",G.vexs[lowcost[k].vi],G.vexs[k],mincost);
		for(j=0;j<G.vexNum;j++){
			if(G.arcs[k][j] < lowcost[j].weight){
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
7
abcdefg
10
0 1 50
0 2 60
1 3 65
1 4 40
2 3 52
2 6 45
3 4 50
3 5 30
3 6 42
4 5 70
*/