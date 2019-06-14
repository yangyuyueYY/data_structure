/*
 * ÿһ�Զ���֮�����·�������������㷨
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

typedef int PATHINT[MAX];

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
 * ���������㷨
 * @param MGraph G ͼ
 */
void floyd(MGraph G)
{
	int d[MAX][MAX],n[MAX][MAX];
	PATHINT path[MAX][MAX];
	int i,j,k,t;
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			d[i][j] = G.arcs[i][j];
			for(k=0;k<G.vexNum;k++){
				path[i][j][k] = -1;
			}
			path[i][j][0] = i;
			path[i][j][1] = j;
			n[i][j] = 2;
		}
	}
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			for(k=0;k<G.vexNum;k++){
				if(d[j][k] > d[j][i] + d[i][k]){
					d[j][k] = d[j][i] + d[i][k];
					for(t=0;t<n[j][i];t++){
						path[j][k][t] = path[j][i][t];
					}
					n[j][k] = n[j][i];
					for(t=1;t<n[i][k];t++){
						path[j][k][n[j][k]] = path[i][k][t];
						n[j][k] ++;
					}
				}
			}
		}
	}
	for(i=0;i<G.vexNum;i++){
		for(j=0;j<G.vexNum;j++){
			printf("%c��%c:%d -- ",G.vexs[i],G.vexs[j],d[i][j],n[i][j]);
			if(i == j){
				printf("%c ",G.vexs[path[i][j][0]]);
			}else{
				for(k=0;k<n[i][j];k++){
					printf("%c ",G.vexs[path[i][j][k]]);
				}
			}
			putchar('\n');
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
	printf("ÿһ�Զ���֮�����·��Ϊ:\n");
	floyd(G);
	return 0;
}

/*
4
abcd
8
0 1 1
0 3 4
1 2 9
1 3 2
2 0 3
2 1 5
2 3 8
3 2 6
*/