/*
 * 教学计划编排系统
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
}Stack;//顺序栈

/*
 * 顺序栈：初始化
 * @param Stack* q 顺序栈首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initStack(Stack *q, int max)
{
	if(max < 0){
		printf("最大数据量不合法\n");
		return -1;
	}
	q->data = (int *)malloc(max * sizeof(int));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * 顺序栈：判断栈空
 * @param Stack q 顺序栈
 * @return int 是否为空，1不为空，0为空
 */
int isEmptyStack(Stack q)
{
	if(q.top == 0){
		return 0;
	}
	return 1;
}

/*
 * 顺序栈：得到栈顶
 * @param Stack q 顺序栈
 * @param int *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack q,int *data)
{
	if(q.top == 0){
		printf("栈为空!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
}

/*
 * 顺序栈：清空栈
 * @param Stack *q 顺序栈首地址
 * @return int 是否清空成功，-1失败，0成功
 */
int emptyStack(Stack *q)
{
	q->top = 0;
	return 0;
}

/*
 * 顺序栈：求栈长度
 * @param Stack q 顺序栈
 * @return int 栈的长度
 */
int getLengthStack(Stack q)
{
	return q.top;
}

/*
 * 顺序栈：进栈
 * @param Stack *q 顺序栈首地址
 * @param int x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *q, int x)
{ 
	if(q->top == q->size){
		printf("栈满!\n");
		return -1;
	}
	q->data[q->top++] = x;
	return 0;
}

/*
 * 顺序栈：出栈
 * @param Stack *q 顺序栈首地址
 * @param int *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *q, int *x)
{ 
	if(q->top == 0){
		printf("栈空!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * 顺序栈：遍历
 * @param Stack q 顺序栈
 */
void displayStack(Stack q)
{ 
	int i;
	if(q.top == 0){
		printf("该顺序表为空\n");
		return;
	}
	for(i=0;i<q.top;i++){
		printf("%d ",q.data);
	}
	return;
}

/*
 * 创建一个邻接表表示的图
 * @param ALGraph *G 图
 * @return int 是否创建成功
 */
int createGraph(ALGraph *G)
{
	ArcNode *p;
	int i,m,n;
	printf("请输入课程数和弧数（用空格隔开）:");
	scanf("%d %d",&G->vexNum,&G->arcNum);
	G->adjlist = (VertexNode *)malloc(G->vexNum*sizeof(VertexNode));
	if(G->adjlist == NULL){
		return -1;
	}
	for(i=0;i<G->vexNum;i++){
		printf("请输入第%d门课程的名称和学时数：",i+1);
		scanf("%s %d",G->adjlist[i].vertex.name,&G->adjlist[i].vertex.time);
		G->adjlist[i].firstArc = NULL;
		G->adjlist[i].count = 0;
	}
	for(i=0;i<G->arcNum;i++){
		printf("请输入第%d条弧尾和弧头的序号（用空格隔开）:",i+1);
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
 * 拓扑排序算法
 * @param ALGraph G 图
 * @param int *a 拓扑序列
 * @return int 是否为有向无环图，0不是，1是
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
	printf("如下的课程可以排在同一个学期：");
	for(i=0;i<G.vexNum;i++){
		ru[i] = G.adjlist[i].count;
		if(G.adjlist[i].count == 0){
			printf("《%s》",G.adjlist[i].vertex.name);
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
					printf("如下的课程可以排在同一个学期：");
					flag = 1;
				}
				pushStack(&s,p->adjvex);
				printf("《%s》",G.adjlist[p->adjvex].vertex.name);
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
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	top_sort(G,a);
	printf("课程的顺序为：\n");
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
信息技术 30
高等数学 90
C程序设计 56
离散数学 60
数据结构 64
汇编程序设计 48
编译原理 48
操作系统 64
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