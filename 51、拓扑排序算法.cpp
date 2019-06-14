/*
 * ���������㷨
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
	int count;
	char vertex;
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
		G->adjlist[i].count = 0;
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
		G->adjlist[n].count ++;
	}
	return 0;
}

/*
 * ���������㷨
 * @param ALGraph G ͼ
 * @return int �Ƿ�Ϊ�����޻�ͼ��0���ǣ�1��
 */
int top_sort(ALGraph G)
{
	Stack s;
	int i,m=0,x;
	ArcNode *p;
	initStack(&s,20);
	for(i=0;i<G.vexNum;i++){
		if(G.adjlist[i].count == 0){
			pushStack(&s,i);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		printf("%c ",G.adjlist[x].vertex);
		m ++;
		p = G.adjlist[x].firstArc;
		while(p){
			G.adjlist[p->adjvex].count --;
			if(G.adjlist[p->adjvex].count == 0){
				pushStack(&s,p->adjvex);
			}
			p = p->nextArc;
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
	if(0 == createGraph(&G)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("������������Ϊ:");
	if(0 == top_sort(G)){
		putchar('\n');
		printf("���������޻�ͼ!\n");
	}else{
		putchar('\n');
		printf("�������޻�ͼ!\n");
	}
	return 0;
}

/*
7
1234567
6
0 3
0 2
1 3
1 4
2 5
4 6
*/