/*
 * һ��ʯ�͹�˾��6���ص��д��͹�(a,b,c,d,e,f)����Ҫ����Щ���͹�֮�佨���������͹ܵ����Ա�����Щ���͹�֮�����ʯ��
 * ��˳������;�Ŀͻ���������Ϊ�������͹�ʮ�ְ������й�˾ϣ�����쾡�����ٵ����͹ܡ�
 * ��һ���棬ÿ�����͹�����ͻ��ṩ��ʱ�������Щ���󣬹�˾ϣ�������������������
 * ���ڸ���ԭ�򣬲����������������͹�֮�����Խ������͹ܣ�6�����͹޼�����֮����Խ�������͹�����ͼ��ʾ
 * �����ʾ���͹ޣ����ʾ���ܽ�������͹ܣ����ϵ�Ȩ��ʾ��Ӧ���͹�������������
 * ����ÿ�����͹ܵĽ�����ö���ͬ�����ʵ��Ϊ�ù�˾�����ѵĽ������͹ܵķ���:����ķ�㷨
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
		G->arcs[m][n] = -d;
		G->arcs[n][m] = -d;
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