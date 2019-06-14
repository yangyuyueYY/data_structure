/*
 * 求从某个源点到其余各点的最短路径：迪杰斯特拉算法
 * 每一对顶点之间最短路径：重复迪杰斯特拉
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
	}
	return 0;
}

/*
 * 迪杰斯特拉算法
 * @param MGraph G 图
 * @param int v 起点
 */
void dijkstra(MGraph G,int v)
{
	int path[20][20];
	int *length,i,j,min,k,*already;
	length = (int *)malloc(G.vexNum*sizeof(int));
	already = (int *)malloc(G.vexNum*sizeof(int));
	if(length == NULL || already == NULL){
		return;
	}
	for(i=0;i<G.vexNum;i++){
		length[i] = G.arcs[v][i];
		already[i] = 1;
		for(j=0;j<G.vexNum;j++){
			path[i][j] = -1;
		}
		path[i][0] = v;
	}
	while(1){
		min = 100000;
		for(i=0;i<G.vexNum;i++){
			if(min > length[i] && length[i] != 0){
				k = i;
				min = length[i];
			}
		}
		if(min == 100000){
			break;
		}
		path[k][already[k]] = k;
		already[k] ++;
		printf("%c到%c:%d -- ",G.vexs[v],G.vexs[k],length[k]);
		for(i=0;i<already[k];i++){
			printf("%c ",G.vexs[path[k][i]]);
		}
		putchar('\n');
		length[k] = 0;
		for(i=0;i<G.vexNum;i++){
			if(min+G.arcs[k][i] < length[i] && min+G.arcs[k][i] != 0 ){
				for(j=0;j<already[k];j++){
					path[i][j] = path[k][j];
				}
				already[i] = already[k];
				length[i] = min+G.arcs[k][i];
			}
		}
	}
}

/*
 * 每一对顶点之间最短路径
 * @param MGraph G 图
 */
void minPath(MGraph G)
{
	int i;
	for(i=0;i<G.vexNum;i++){
		dijkstra(G,i);
	}
}

int main()
{
	MGraph G;
	int i,j,v;
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
	printf("请输入起点下标:");
	scanf("%d",&v);
	printf("最短路径为:\n");
	dijkstra(G,v);
	printf("每一对顶点之间最短路径为:\n");
	minPath(G);
	return 0;
}

/*
6
012345
8
0 2 10
0 4 30
0 5 100
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
*/