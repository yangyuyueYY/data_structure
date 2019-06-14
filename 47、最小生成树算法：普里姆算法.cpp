/*
 * ��С�������㷨������ķ�㷨
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
 * ��ʼ��ͼ
 * @param MGraph *G ͼ
 * @return int �Ƿ��ʼ���ɹ�
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
 * ����һ���ڽӾ����ʾ��ͼ
 * @param MGraph *G ͼ
 * @return int �Ƿ񴴽��ɹ�
 */
int createGraph(MGraph *G)
{
	int i,m,n,d;
	printf("���������:");
	scanf("%d",&G->vexNum);
	printf("������%d��������:",G->vexNum);
	getchar();
	for(i=0;i<G->vexNum;i++){
		scanf("%c",&G->vexs[i]);
	}
	printf("���������:");
	scanf("%d",&G->arcNum);
	for(i=0;i<G->arcNum;i++){
    	printf("�������%d���߼�Ȩֵ:",i+1);
		scanf("%d%d%d",&m,&n,&d);
		G->arcs[m][n] = d;
		G->arcs[n][m] = d;
	}
	return 0;
}

/*
 * ����ķ�㷨
 * @param MGraph G ͼ
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
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	visited = (int *)malloc(G.vexNum*sizeof(int));
	if(visited == NULL){
		return -1;
	}
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("�ڽӾ���Ϊ:\n");
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			printf("%d ",G.arcs[i][j]);
		}
		printf("\n");
	}
	printf("��С������Ϊ:\n");
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