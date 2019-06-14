/*
 * ��֪����ͼ�����ڽӱ�洢��ʽ��д��ɾ����(i,j)���㷨������һ��������㷨
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
 * ����һ���ڽӱ��ʾ��ͼ
 * @param ALGraph *G ͼ
 * @return int �Ƿ񴴽��ɹ�
 */
int createGraph(ALGraph *G)
{
	ArcNode *p;
	int i,m,n;
	printf("���������:");
	scanf("%d",&G->vexNum);
	G->adjlist = (VertexNode *)malloc(G->vexNum*sizeof(VertexNode));
	if(G->adjlist == NULL){
		return -1;
	}
	printf("������%d��������:",G->vexNum);
	getchar();
	for(i=0;i<G->vexNum;i++){
		scanf("%c",&G->adjlist[i].vertex);
		G->adjlist[i].firstArc = NULL;
	}
	printf("���������:");
	scanf("%d",&G->arcNum);
	for(i=0;i<G->arcNum;i++){
		printf("�������%d����:",i+1);
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
 * ɾ����
 * @param ALGraph *G ͼָ��
 * @return int �Ƿ�ɾ���ɹ�
 */
int deletearc(ALGraph *G)
{
	int m,n;
	ArcNode *p,*q;
	printf("�������ɾ����:");
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
 * ���ӵ�
 * @param ALGraph *G ͼ
 * @return int �Ƿ����ӳɹ�
 */
int addvex(ALGraph *G)
{
	getchar();
	printf("�����������:");
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
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("��ʼ�ڽ�Ϊ:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c��",i,G.adjlist[i].vertex);
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%d ",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
	deletearc(&G);
	printf("ɾ�ߺ��ڽ�Ϊ:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c��",i,G.adjlist[i].vertex);
		p = G.adjlist[i].firstArc;
		while(p){
			printf("%d ",p->adjvex);
			p = p->nextArc;
		}
		putchar('\n');
	}
	addvex(&G);
	printf("�ӵ���ڽ�Ϊ:\n");
	for(i=0;i<G.vexNum;i++){
		printf("%d  %c��",i,G.adjlist[i].vertex);
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