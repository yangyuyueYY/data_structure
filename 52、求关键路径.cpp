/*
 * ��ؼ�·�������붥��ͻ�����Ϣ�����������ȵ��ڽӱ�����ÿ���������ȣ����������������
 * ����������󶥵�ve[i]�����õ����������н�ջ���������������󶥵��vl[i]��
 * ����ÿ������ee[i]��el[i]���ҳ�ee[i]==el[i]�Ļ
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	int adjvex;
	int weight;
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
	int i,m,n,d,k;
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
		scanf("%d%d%d%d",&m,&n,&d,&k);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p == NULL){
			return -1;
		}
		p->adjvex = n;
		p->weight = d;
		p->num = k;
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
 * @param int *ve ve����
 * @return int �Ƿ�Ϊ�����޻�ͼ��0���ǣ�1��
 */
int top_sort(ALGraph G,int *a,int *ve)
{
	Stack s;
	int i,m=0,x,j=0;
	int *ru;
	ArcNode *p;
	initStack(&s,20);
	ru = (int*)malloc(G.vexNum * sizeof(int));
	if(ru == NULL){
		return -1;
	}
	for(i=0;i<G.vexNum;i++){
		ru[i] = G.adjlist[i].count;
		ve[i] = 0;
		if(G.adjlist[i].count == 0){
			pushStack(&s,i);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		a[j] = x;
		j++;
		m ++;
		p = G.adjlist[x].firstArc;
		while(p){
			ru[p->adjvex] --;
			if(ru[p->adjvex] == 0){
				pushStack(&s,p->adjvex);
			}
			if(p->weight+ve[x] > ve[p->adjvex]){
				ve[p->adjvex] = p->weight+ve[x];
			}
			p = p->nextArc;
		}
	}
	if(m < G.vexNum){
		return 0;
	}
	return 1;
}

/*
 * ��vl
 * @param ALGraph G ͼ
 * @param int *a ��������
 * @param int *ve ve����
 * @param int *vl vl����
 */
void calvl(ALGraph G,int *a,int *ve,int *vl)
{
	int i,j,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		vl[i] = 100000;
	}
	vl[G.vexNum-1] = ve[G.vexNum-1];
	
	for(i=G.vexNum-1;i>=0;i--){
		for(j=0;j<G.vexNum;j++){
			p = G.adjlist[j].firstArc;
			while(p){
				if(p->adjvex == a[i]){
					for(k=0;k<G.vexNum;k++){
						if(a[k] == j){
							break;
						}
					}
					if(vl[i] - p->weight < vl[k]){
						vl[k] = vl[i] - p->weight;
					}
				}
				p = p->nextArc;
			}
		}
	}
}

/*
 * ��ee
 * @param ALGraph G ͼ
 * @param int *ve ve����
 * @param int *ee ee����
 * @param int *a ��������
 */
void calee(ALGraph G,int *ve,int *ee,int *a)
{
	int i,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		p = G.adjlist[i].firstArc;
		while(p){
			for(k=0;k<G.vexNum;k++){
				if(a[k] == i){
					break;
				}
			}
			ee[p->num - 1] = ve[i];
			p = p->nextArc;
		}
	}
}

/*
 * ��el
 * @param ALGraph G ͼ
 * @param int *vl vl����
 * @param int *el el����
 * @param int *a ��������
 */
void calel(ALGraph G,int *vl,int *el,int *a)
{
	int i,k;
	ArcNode *p;
	for(i=0;i<G.vexNum;i++){
		p = G.adjlist[i].firstArc;
		while(p){
			for(k=0;k<G.vexNum;k++){
				if(a[k] == p->adjvex){
					break;
				}
			}
			el[p->num - 1] = vl[k] - p->weight;
			p = p->nextArc;
		}
	}
}

/*
 * ��ؼ�·��
 * @param ALGraph G ͼ
 * @param int *ee ee����
 * @param int *el el����
 * @param int *path �ؼ�·��
 * @return int �ؼ�·������
 */
int keypath(ALGraph G,int *ee,int *el,int *path)
{
	int n,i;
	n = 0;
	for(i=0;i<G.arcNum;i++){
		if(ee[i] == el[i]){
			path[n] = i+1;
			n ++;
		}
	}
	return n;
}

int main()
{
	ALGraph G;
	int a[20],ee[20],ve[20],el[20],vl[20],i,path[20],n;
	if(0 == createGraph(&G)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	if(0 == top_sort(G,a,ve)){
		putchar('\n');
		printf("���������޻�ͼ!\n");
	}else{
		putchar('\n');
		printf("�������޻�ͼ!\n");
	}
	printf("������������Ϊ:");
	for(i=0;i<G.vexNum;i++){
		printf("%c ",G.adjlist[a[i]].vertex);
	}
	putchar('\n');
	printf("veΪ:");
	for(i=0;i<G.vexNum;i++){
		printf("%d ",ve[i]);
	}
	putchar('\n');
	calvl(G,a,ve,vl);
	printf("vlΪ:");
	for(i=0;i<G.vexNum;i++){
		printf("%d ",vl[i]);
	}
	putchar('\n');
	calee(G,ve,ee,a);
	printf("eeΪ:");
	for(i=0;i<G.arcNum;i++){
		printf("%d ",ee[i]);
	}
	putchar('\n');
	calel(G,vl,el,a);
	printf("elΪ:");
	for(i=0;i<G.arcNum;i++){
		printf("%d ",el[i]);
	}
	putchar('\n');
	n = keypath(G,ee,el,path);
	printf("�ؼ�·��Ϊ:");
	for(i=0;i<n;i++){
		printf("%d ",path[i]);
	}
	putchar('\n');
	return 0;
}

/*
6
123456
8
0 2 3 2
0 1 3 1
1 4 3 4
1 3 2 3
2 5 3 6
2 3 3 5
3 5 2 7 
4 5 1 8
*/
