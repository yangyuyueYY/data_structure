/*
 * ���ĳ��Դ�㵽�����������·�����Ͻ�˹�����㷨
 * ÿһ�Զ���֮�����·�����ظ��Ͻ�˹����
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
	}
	return 0;
}

/*
 * �Ͻ�˹�����㷨
 * @param MGraph G ͼ
 * @param int v ���
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
		printf("%c��%c:%d -- ",G.vexs[v],G.vexs[k],length[k]);
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
 * ÿһ�Զ���֮�����·��
 * @param MGraph G ͼ
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
	printf("����������±�:");
	scanf("%d",&v);
	printf("���·��Ϊ:\n");
	dijkstra(G,v);
	printf("ÿһ�Զ���֮�����·��Ϊ:\n");
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