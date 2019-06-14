/*
 * 一家石油公司在6个地点有储油罐(a,b,c,d,e,f)，现要在这些储油罐之间建造若干输油管道，以便在这些储油罐之间调配石油
 * 并顺带向沿途的客户供出。因为建造输油管十分昂贵，所有公司希望建造尽可能少的输油管。
 * 另一方面，每条输油管在向客户提供油时都会产生些利润，公司希望所产生的总利润最大
 * 由于各种原因，并非在任意两个储油罐之间否可以建造输油管，6个储油罐及它们之间可以建造的输油管如下图所示
 * 顶点表示储油罐，便表示可能建造的输油管，边上的权表示相应输油管所产生的利润。
 * 假设每条输油管的建造费用都相同，编程实现为该公司设计最佳的建造输油管的方案:克鲁斯卡尔算法
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
	int vj;
	int weight;
}Arcs;

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
			G->arcs[i][j] = 100000;
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
 * 克鲁斯卡尔算法
 * @param MGraph G 图
 */
void kruskal(MGraph G)
{
	int k,i,j,min,t=0,flag,*visited,m=0;
	int n,*already;
	int a[20][20];
	MGraph H;
	initGraph(&H);
	H.vexNum = G.vexNum;
	H.arcNum = 0;
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			a[i][j] = -1;
		}
		a[i][0] = i;
	}
	visited = (int *)malloc(G.vexNum*sizeof(int));
	already = (int *)malloc(G.vexNum*sizeof(int));
	if(visited == NULL || already == NULL){
		return;
	}
	for(i=0;i<G.vexNum;i++){
		already[i] = 1;
		H.vexs[i] = G.vexs[i];
	}
	Arcs *arc = (Arcs *)malloc(2 * G.arcNum * sizeof(Arcs));
	if(arc == NULL){
		return;
	}
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			if(G.arcs[i][j] != 0 && G.arcs[i][j] != 100000){
				arc[t].vi = i;
				arc[t].vj = j;
				arc[t].weight = G.arcs[i][j];
				t++;
			}
		}
	}
	for(i=0;i<G.vexNum-1;i++){
		min = 100000;
		for(j=0;j<G.arcNum*2;j++){
			if(min > arc[j].weight){
				k = j;
				min = arc[j].weight;
			}
		}
		if(min == 100000){
			break;
		}
		for(j=0;j<G.vexNum;j++){
			visited[j] = 0;
		}
		H.arcNum ++;
		H.arcs[arc[k].vi][arc[k].vj] = 1;
		H.arcs[arc[k].vj][arc[k].vi] = 1;
		printf("%c--%c:%d\n",G.vexs[arc[k].vi],G.vexs[arc[k].vj],-min);
		a[arc[k].vi][already[arc[k].vi]] = arc[k].vj;
		a[arc[k].vj][already[arc[k].vj]] = arc[k].vi;
		already[arc[k].vi] ++;
		already[arc[k].vj] ++;
		for(j=0;j<already[arc[k].vi];j++){
			a[a[arc[k].vi][j]][already[a[arc[k].vi][j]]] = arc[k].vj;
			already[a[arc[k].vi][j]] ++;
		}
		for(j=0;j<already[arc[k].vj];j++){
			a[a[arc[k].vj][j]][already[a[arc[k].vj][j]]] = arc[k].vi;
			already[a[arc[k].vj][j]] ++;
		}
		for(j=0;j<G.arcNum*2;j++){
			for(t=0;t<already[arc[k].vi];t++){
				for(n=0;n<already[arc[k].vi];n++){
					if((arc[j].vi == a[arc[k].vi][t] && arc[j].vj == a[arc[k].vi][n]) || (arc[j].vj == a[arc[k].vi][t] && arc[j].vi == a[arc[k].vi][n])){
						arc[j].weight = 100000;
					}
				}
			}
			for(t=0;t<already[arc[k].vj];t++){
				for(n=0;n<already[arc[k].vj];n++){
					if((arc[j].vi == a[arc[k].vj][t] && arc[j].vj == a[arc[k].vj][n]) || (arc[j].vj == a[arc[k].vj][t] && arc[j].vi == a[arc[k].vj][n])){
						arc[j].weight = 100000;
					}
				}
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
	printf("方案为:\n");
	kruskal(G);
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