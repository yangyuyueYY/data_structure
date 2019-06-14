/*
 * ͼ����ز���������һ���ڽӾ����ʾ��ͼ�������ڽӾ���洢�ṹ����ͨͼ��������ȱ����ĵݹ��㷨��
 * �����ڽӾ���洢�ṹ����ͨͼ��������ȱ����ķǵݹ��㷨�������ڽӾ���洢�ṹ����ͨͼ�Ĺ�����ȱ�����
 * �����ڽӾ���洢�ṹ�ķ���ͨͼ��������ȱ����������ڽӾ���洢�ṹ�ķ���ͨͼ�Ĺ�����ȱ�����
 * ��һ������ͼ�����ж���ļ�·�������ܶ������⣩���ж�ͼ���Ƿ���ڻ���������ͼ�Ķ���a��i֮��ļ�·��
 * ������ͼ�Ķ���vi��vj֮������·��
 * @author v_yuyueyang 2017-08-26
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

typedef struct node
{
	struct node *prior;
	int data;
	struct node *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue1;

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
 * �����еĻ�����������ʼ��
 * @param Queue *q ������
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initQueue1(Queue1 *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->prior = NULL;
	p->next = NULL;
	p->data = -1;
	q->L = p;
	q->R = p;
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
 * �����У��ж϶ӿ�
 * @param Queue q ������
 * @return int �Ƿ�ӿգ�0Ϊ�ӿգ�1��Ϊ��
 */
int isEmptyQueue1(Queue1 q)
{
	if(q.L == q.R){
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
 * �����У�������
 * @param Queue *q ˳������׵�ַ
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue1(Queue1 *q, int x)
{
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	s->data = x;
	s->next = NULL;
	s->prior = q->L;
	q->R->next = s;
	q->R = s;
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
 * �����У�������
 * @param Queue1 *q �������׵�ַ
 * @param int *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue1(Queue1 *q, int *x)
{
	q->L = q->L->next;
	return 0;
}

/*
 * ˳����У�����
 * @param Queue q ˳�����
 */
void displayQueue(Queue q)
{ 
	int i=0,t = q.head;
	if(isEmptyQueue(q) == 0){
		printf("����Ϊ��!\n");
		return;
	}
	while(t != q.rear){
		printf("%d",q.data[t]); 
		t = (t+1)%q.size;
		i++;
	}
	return;
}

/*
 * �����У�����
 * @param Queue q ������
 */
void displayQueue1(Queue1 q)
{
	int i = 0;
	SqList p = q.R->prior;
	if(isEmptyQueue1(q) == 0){
		printf("����Ϊ��!\n");
		return;
	}
	while(p != NULL){
		printf("%d ", p->data);
		i ++;
		p = p->prior;
	}
	putchar('\n');
}

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
 * ˳��ջ������
 * @param Stack* q ˳��ջ�׵�ַ
 * @return int �Ƿ����ٳɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int destroyStack(Stack *q)
{
	free(q->data);
	free(&q->top);
	free(&q->size);
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
			G->arcs[i][j] = 0;
		}
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
	int i,m,n;
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
		printf("�������%d����:",i+1);
		scanf("%d%d",&m,&n);
		G->arcs[m][n] = 1;
		G->arcs[n][m] = 1;
	}
	return 0;
}

/*
 * �����ڽӾ���洢�ṹ����ͨͼ��������ȱ����ĵݹ��㷨
 * @param MGraph G ͼ
 * @param int v �������
 * @param int *visited ���ʱ��
 */
void DFSRecurse(MGraph G,int v,int *visited)
{
	int i;
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	for(i=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1 && visited[i] == 0){
			DFSRecurse(G,i,visited);
		}
	}
	if(i == G.vexNum){
		return;
	}
}

/*
 * �����ڽӾ���洢�ṹ����ͨͼ��������ȱ����ķǵݹ��㷨
 * @param MGraph G ͼ
 * @param int v �������
 * @param int *visited ���ʱ��
 */
void DFSUnrecurse(MGraph G,int v,int *visited)
{
	int i,x;
	Stack s;
	initStack(&s,20);
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	pushStack(&s,v);
	while(isEmptyStack(s) != 0){
		getTopStack(s,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				printf("%c",G.vexs[i]);
				visited[i] = 1;
				pushStack(&s,i);
				break;
			}
		}
		if(i == G.vexNum){
			popStack(&s,&x);
		}
	}
}

/*
 * �����ڽӾ���洢�ṹ����ͨͼ�Ĺ�����ȱ���
 * @param MGraph G ͼ
 * @param int v �������
 * @param int *visited ���ʱ��
 */
void GFSUnrecurse(MGraph G,int v,int *visited)
{
	int i,x;
	Queue q;
	initQueue(&q,20);
	printf("%c",G.vexs[v]);
	visited[v] = 1;
	enQueue(&q,v);
	while(isEmptyQueue(q) != 0){
		deQueue(&q,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				printf("%c",G.vexs[i]);
				visited[i] = 1;
				enQueue(&q,i);
			}
		}
	}
}

/*
 * �����ڽӾ���洢�ṹ�ķ���ͨͼ��������ȱ���
 * @param MGraph G ͼ
 * @param int *visited ���ʱ��
 */
void DFSUnlink(MGraph G,int *visited)
{
	int i = 0;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFSUnrecurse(G,i,visited);
		}
	}
}

/*
 * �����ڽӾ���洢�ṹ�ķ���ͨͼ�Ĺ�����ȱ���
 * @param MGraph G ͼ
 * @param int *visited ���ʱ��
 */
void GFSUnlink(MGraph G,int *visited)
{
	int i = 0;
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			GFSUnrecurse(G,i,visited);
		}
	}
}

/*
 * ����vΪ���ļ�·��
 * @param MGraph G ͼ
 * @param int v ���
 * @param int *visited ���ʱ��
 * @param int *n ���ʽ����
 * @param char *path ·��
 * @param int  *flag�Ƿ����
 */
void DFS(MGraph G,int v,int *visited,int *n,char *path,int *flag)
{
	int i;
	path[*n] = G.vexs[v];
	visited[v] = 1;
	(*n) ++;
	if((*n) >= G.vexNum){
		printf("��·��Ϊ:");
		for(i=0;i<G.vexNum;i++){
			printf("%c ",path[i]);
		}
		putchar('\n');
		*flag = 1;
	}
	for(i=0;i<G.vexNum;i++){
		if(G.arcs[v][i] == 1 && visited[i] == 0){
			DFS(G,i,visited,n,path,flag);
		}
	}
	visited[v] = 0;
	(*n) --;
}

/*
 * ��һ������ͼ�����ж���ļ�·�������ܶ������⣩��
 * @param MGraph G ͼ
 * @param int *visited ���ʱ��
 * @return int �Ƿ����
 */
int Hamilton(MGraph G,int *visited)
{
	int i,n=0,flag=0;
	char path[20];
	for(i=0;i<G.vexNum;i++){
		if(visited[i] == 0){
			DFS(G,i,visited,&n,path,&flag);
		}
	}
	if(flag == 1){
		return 0;
	}
	return -1;
}

/*
 * �ж�ͼ���Ƿ���ڻ�
 * @param MGraph G ͼ
 * @param int *flag �Ƿ���ڻ�
 * @param int *visited ���ʱ��
 * @param int v ���
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
 * ������ͼ�Ķ���a��i֮��ļ�·��
 * @param MGraph G ͼ
 * @param int a ���
 * @param int i �յ�
 * @param char *path ·��
 * @param int *visited ���ʱ��
 * @param int *found �Ƿ��ҵ�
 * @param int *n ·���н����
 */
void DFSearchPath(MGraph G,int a,int i,char *path,int *visited,int *found,int *n)
{
	int j;
	visited[a] = 1;
	path[(*n)] = G.vexs[a];
	(*n)++;
	for(j=0;j<G.vexNum && (*found)==0;j++){
		if(G.arcs[a][j] == 1){
			if(j == i){
				*found = 1;
				path[(*n)] = G.vexs[j];
				(*n) ++;
			}else if(visited[j] == 0){
				DFSearchPath(G,j,i,path,visited,found,n);
			}
		}
	}
	if((*found) == 0){
		(*n) --;
	}
}

/*
 * ������ͼ�Ķ���vi��vj֮������·��
 * @param MGraph G ͼ
 * @param int vi ���
 * @param int vj �յ�
 * @param int *visited ���ʱ��
 */
void BFSearchPath(MGraph G,int vi,int vj,int *visited)
{
	Queue1 q;
	int i,x;
	initQueue1(&q);
	enQueue1(&q,vi);
	visited[vi] = 1;
	while(isEmptyQueue1(q) != 0){
		deQueue1(&q,&x);
		for(i=0;i<G.vexNum;i++){
			if(G.arcs[x][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				enQueue1(&q,i);
				if(i == vj){
					displayQueue1(q);
					break;
				}
			}
		}
		if(i >= G.vexNum){
			break;
		}
	}
}

int main()
{
	MGraph G;
	char path[20];
	int i,j,flag,n,found=0,t;
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
	printf("��ͨͼ�ݹ���ȱ���:");
	DFSRecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("*******************\n��ͨͼ�ǵݹ���ȱ���:");
	DFSUnrecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("��ͨͼ��ȱ���:");
	GFSUnrecurse(G,0,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("����ͨͼ��ȱ���:");
	DFSUnlink(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("����ͨͼ��ȱ���:");
	GFSUnlink(G,visited);
	putchar('\n');
	for(i=0;i<G.vexNum;i++){
		visited[i] = 0;
	}
	printf("*************************\n���ܶ�������:\n");
	if(0 == Hamilton(G,visited)){
	}else{
		printf("��·��������!");
	}
	putchar('\n');
	flag = 0;
	for(j=0;j<G.vexNum;j++){
		visited[j] = 0;
	}
	haveCircle(G,&flag,visited,0);
	if(flag == 1){
		printf("��ͼ���ڻ�·!\n");
	}else{
		printf("��ͼ�����ڻ�·!\n");
	}
	for(j=0;j<G.vexNum;j++){
		visited[j] = 0;
	}
	printf("�����������յ��±�:");
	scanf("%d%d",&i,&j);
	n = 0;
	DFSearchPath(G,i,j,path,visited,&found,&n);
	if(0 == found){
		printf("%c��%c���޼�·��!\n",G.vexs[i],G.vexs[j]);
	}else{
		printf("%c��%c���·��Ϊ:",G.vexs[i],G.vexs[j]);
		for(t=0;t<n;t++){
			printf("%c ",path[t]);
		}
		putchar('\n');
	}
	return 0;
}


/*
9
cbaefdihg
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
0 8
*/