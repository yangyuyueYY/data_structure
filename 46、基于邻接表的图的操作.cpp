/*
 * ͼ�Ļ�������������һ���ڽӱ��ʾ��ͼ�������ڽӱ�洢�ṹ����ͨͼ��������ȱ����ĵݹ��㷨
 * �����ڽӱ�洢�ṹ����ͨͼ��������ȱ����ķǵݹ��㷨�������ڽӱ�洢�ṹ����ͨͼ�Ĺ�����ȱ���
 * �����ڽӱ�洢�ṹ�ķ���ͨͼ��������ȱ����������ڽӱ�洢�ṹ�ķ���ͨͼ�Ĺ�����ȱ���
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

typedef struct
{
	int *data;
	int top;
	int size;
}Stack;//˳��ջ

typedef struct
{
	int *data;
	int head;
	int rear;
	int size;
}Queue;//ѭ������

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
		printf("%d",q.data);
	}
	return;
}

/*
 * ѭ�����У���ʼ��
 * @param Queue* q ѭ�������׵�ַ
 * @param int max ���������
 * @return int �Ƿ��ʼ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int initQueue(Queue *q, int max)
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
	q->head = 0;
	q->rear = 0;
	q->size = max;
	return 0;
}

/*
 * ѭ�����У��ж϶ӿ�
 * @param Queue q ѭ������
 * @return int �Ƿ�ӿգ�0Ϊ�ӿգ�1��Ϊ��
 */
int isEmptyQueue(Queue q)
{
	if(q.head == q.rear){
		return 0;
	}
	return 1;
}

/*
 * ˳����У��õ���ͷ
 * @param Queue q ˳�����
 * @param int *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,int *data)
{
	if(isEmptyQueue(q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	*data = q.data[q.head];
	return 0;
}

/*
 * ˳����У�����г���
 * @param Queue q ˳�����
 * @return int ���г���
 */
int getLengthQueue(Queue q)
{
	return (q.rear+q.size-q.head)%q.size;
}

/*
 * ˳����У���ն���
 * @param Queue *q ˳�����ָ��
 * @return int �Ƿ���ճɹ���0�ɹ���-1���ɹ�
 */
int emptyQueue(Queue *q)
{
	q->rear = q->head;
	return 0;
}

/*
 * ˳����У�������
 * @param Queue *q ˳������׵�ַ
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, int x)
{ 
	if((q->rear+1)%q->size == q->head){
		printf("��������!\n");
		return -1;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % q->size;
	return 0;
}

/*
 * ˳����У�������
 * @param Queue *q ˳������׵�ַ
 * @param int *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, int *x)
{ 
	if(isEmptyQueue(*q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
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
 * �����ڽӱ�洢�ṹ����ͨͼ��������ȱ����ĵݹ��㷨
 * @param ALGrapg G ͼ
 * @param int v ���
 * @param int *visited ���ʱ��
 */
void DFSDisplay(ALGraph G,int v,int *visited)
{
	ArcNode *p = G.adjlist[v].firstArc;
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	while(p){
		if(visited[p->adjvex] == 0){
			DFSDisplay(G,p->adjvex,visited);
		}else{
			p = p->nextArc;
		}
	}
}

/*
 * �����ڽӱ�洢�ṹ����ͨͼ��������ȱ����ķǵݹ��㷨
 * @param ALGrapg G ͼ
 * @param int v ���
 * @param int *visited ���ʱ��
 */
void DFSDisplay1(ALGraph G,int v,int *visited)
{
	Stack s;
	int x;
	ArcNode *p;
	initStack(&s,20);
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	pushStack(&s,v);
	while(isEmptyStack(s) != 0){
		getTopStack(s,&x);
		p = G.adjlist[x].firstArc;
		while(p){
			if(visited[p->adjvex] == 0){
				printf("%c",G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;
				pushStack(&s,p->adjvex);
				break;
			}else{
				p = p->nextArc;
			}
		}
		if(p == NULL){
			popStack(&s,&x);
		}
	}
}

/*
 * �����ڽӱ�洢�ṹ����ͨͼ�Ĺ�����ȱ���
 * @param ALGraph G ͼ
 * @param int v ���
 * @param int *visited ���ʱ��
 */
void BFSDisplay(ALGraph G,int v,int *visited) 
{
	Queue q;
	int x;
	ArcNode *p;
	initQueue(&q,20);
	printf("%c",G.adjlist[v].vertex);
	visited[v] = 1;
	enQueue(&q,v);
	while(isEmptyQueue(q) != 0){
		deQueue(&q,&x);
		p = G.adjlist[x].firstArc;
		while(p){
			if(visited[p->adjvex] == 0){
				printf("%c",G.adjlist[p->adjvex].vertex);
				visited[p->adjvex] = 1;
				enQueue(&q,p->adjvex);
			}
			p = p->nextArc;
		}
	}
}

/*
 * �����ڽӱ�洢�ṹ�ķ���ͨͼ��������ȱ���
 * @param ALGraph G ͼ
 * @param int *visited ���ʱ��
 */
void DFSDisplay2(ALGraph G,int *visited)
{
	int i;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFSDisplay(G,i,visited);
		}
	}
}

/*
 * �����ڽӱ�洢�ṹ�ķ���ͨͼ�Ĺ�����ȱ���
 * @param ALGraph G ͼ
 * @param int *visited ���ʱ��
 */
void BFSDisplay1(ALGraph G,int *visited)
{
	int i;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			BFSDisplay(G,i,visited);
		}
	}
}

int main()
{
	ALGraph G;
	int i,found=0;
	int *visited;
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
	printf("��ͨͼ�ݹ���ȱ���:");
	DFSDisplay(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("��ͨͼ�ǵݹ���ȱ���:");
	DFSDisplay1(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("��ͨͼ��ȱ���:");
	BFSDisplay(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("����ͨͼ��ȱ���:");
	DFSDisplay2(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("����ͨͼ��ȱ���:");
	BFSDisplay1(G,visited);
	putchar('\n');
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