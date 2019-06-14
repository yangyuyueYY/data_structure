/*
 * ��ѧ�ƻ�����ϵͳ
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char name[20];
	int time;
}Data;

typedef struct node
{
	int adjvex;
	struct node *nextArc;
}ArcNode;

typedef struct 
{
	int count;
	Data vertex;
	ArcNode *firstArc;
}VertexNode;

typedef struct
{
	VertexNode *adjlist;
	int vexNum;
	int arcNum;
}ALGraph;

typedef struct
{
	int *data;
	int top;
	int size;
}Stack;//˳��ջ

/*
 * ˳��ջ����ʼ��
 * @param Stack* q ˳��ջ�׵�ַ
 * @param int max ���������
 * @return int �Ƿ��ʼ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int initStack(Stack *q, int max)
{
	if(max < 0){
		printf("������������Ϸ�\n");
		return -1;
	}
	q->data = (int *)malloc(max * sizeof(int));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * ˳��ջ���ж�ջ��
 * @param Stack q ˳��ջ
 * @return int �Ƿ�Ϊ�գ�1��Ϊ�գ�0Ϊ��
 */
int isEmptyStack(Stack q)
{
	if(q.top == 0){
		return 0;
	}
	return 1;
}

/*
 * ˳��ջ���õ�ջ��
 * @param Stack q ˳��ջ
 * @param int *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack q,int *data)
{
	if(q.top == 0){
		printf("ջΪ��!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
}

/*
 * ˳��ջ�����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @return int �Ƿ���ճɹ���-1ʧ�ܣ�0�ɹ�
 */
int emptyStack(Stack *q)
{
	q->top = 0;
	return 0;
}

/*
 * ˳��ջ����ջ����
 * @param Stack q ˳��ջ
 * @return int ջ�ĳ���
 */
int getLengthStack(Stack q)
{
	return q.top;
}

/*
 * ˳��ջ����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *q, int x)
{ 
	if(q->top == q->size){
		printf("ջ��!\n");
		return -1;
	}
	q->data[q->top++] = x;
	return 0;
}

/*
 * ˳��ջ����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @param int *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *q, int *x)
{ 
	if(q->top == 0){
		printf("ջ��!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * ˳��ջ������
 * @param Stack q ˳��ջ
 */
void displayStack(Stack q)
{ 
	int i;
	if(q.top == 0){
		printf("��˳���Ϊ��\n");
		return;
	}
	for(i=0;i<q.top;i++){
		printf("%d ",q.data);
	}
	return;
}

/*
 * ����һ���ڽӱ��ʾ��ͼ
 * @param ALGraph *G ͼ
 * @return int �Ƿ񴴽��ɹ�
 */
int createGraph(ALGraph *G)
{
	ArcNode *p;
	int i,m,n;
	printf("������γ����ͻ������ÿո������:");
	scanf("%d %d",&G->vexNum,&G->arcNum);
	G->adjlist = (VertexNode *)malloc(G->vexNum*sizeof(VertexNode));
	if(G->adjlist == NULL){
		return -1;
	}
	for(i=0;i<G->vexNum;i++){
		printf("�������%d�ſγ̵����ƺ�ѧʱ����",i+1);
		scanf("%s %d",G->adjlist[i].vertex.name,&G->adjlist[i].vertex.time);
		G->adjlist[i].firstArc = NULL;
		G->adjlist[i].count = 0;
	}
	for(i=0;i<G->arcNum;i++){
		printf("�������%d����β�ͻ�ͷ����ţ��ÿո������:",i+1);
		scanf("%d%d",&m,&n);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = n;
		p->nextArc = G->adjlist[m].firstArc;
		G->adjlist[m].firstArc = p;
		G->adjlist[n].count ++;
	}
	return 0;
}

/*
 * ���������㷨
 * @param ALGraph G ͼ
 * @param int *a ��������
 * @return int �Ƿ�Ϊ�����޻�ͼ��0���ǣ�1��
 */
int top_sort(ALGraph G,int *a)
{
	Stack s;
	int i,m=0,x,*ru,j=0,flag=0;
	ArcNode *p;
	initStack(&s,20);
	ru = (int *)malloc(G.vexNum*sizeof(int));
	if(ru == NULL){
		return -1;
	}
	printf("���µĿγ̿�������ͬһ��ѧ�ڣ�");
	for(i=0;i<G.vexNum;i++){
		ru[i] = G.adjlist[i].count;
		if(G.adjlist[i].count == 0){
			printf("��%s��",G.adjlist[i].vertex.name);
			pushStack(&s,i);
			a[j] = i;
			j++;
		}
	}
	putchar('\n');
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		m ++;
		p = G.adjlist[x].firstArc;
		flag = 0;
		while(p){
			ru[p->adjvex] --;
			if(ru[p->adjvex] == 0){
				if(flag == 0){
					printf("���µĿγ̿�������ͬһ��ѧ�ڣ�");
					flag = 1;
				}
				pushStack(&s,p->adjvex);
				printf("��%s��",G.adjlist[p->adjvex].vertex.name);
				a[j] = p->adjvex;
				j ++;
			}
			p = p->nextArc;
		}
		if(flag == 1){
			putchar('\n');
		}
	}
	if(m < G.vexNum){
		return 0;
	}
	return 1;
}

int main()
{
	ALGraph G;
	int a[20];
	int i,j;
	if(0 == createGraph(&G)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	top_sort(G,a);
	printf("�γ̵�˳��Ϊ��\n");
	for(j=0;j<G.vexNum;j++){
		for(i=0;i<2;i++){
			printf("%d:%s(%d)   ",j+1,G.adjlist[a[j]].vertex.name,G.adjlist[a[j]].vertex.time);
			if(i == 0){
				j++;
			}
		}
		putchar('\n');
	}
	return 0;
}

/*
8 9
��Ϣ���� 30
�ߵ���ѧ 90
C������� 56
��ɢ��ѧ 60
���ݽṹ 64
��������� 48
����ԭ�� 48
����ϵͳ 64
0 2
1 3
2 5
2 4
3 4
4 6
4 7
5 6
5 7
*/