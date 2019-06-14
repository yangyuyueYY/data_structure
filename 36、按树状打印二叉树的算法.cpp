/*
 * �����Զ�������洢�Ķ������У�ÿ�������������Ԫ�ؾ�Ϊ����ĸ���Ա�д�㷨������״��ӡ���������㷨
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct
{
	Tree data;
	int n;
}Data;

typedef struct
{
	Data *data;
	int head;
	int rear;
	int size;
}Queue;//ѭ������

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
	q->data = (Data *)malloc(max * sizeof(Data));
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
 * @param Data *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,Data *data)
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
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, Data x)
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
 * @param Data *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, Data *x)
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
 * �ݹ鴴���������Ķ�������ṹ
 * @param Tree *T �����������ָ��
 * @return int �Ƿ񴴽��ɹ�,0�ɹ���-1ʧ��
 */
int createTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}
	else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/* 
 * �����
 * @param Tree T �����
 * @return int ���
 */
int depth(Tree T)
{
	int h1,h2;
	if(T == NULL){
		return 0;
	}else{
		h1 = depth(T->lchild);
		h2 = depth(T->rchild);
		if(h1>=h2){
			return h1+1;
		}else{
			return h2+1;
		}
	}
}

/*
 * ��״��ӡ������
 * @param Tree T �����
 */
void display(Tree T)
{
	Queue q;
	int n = depth(T);
	printf("%d\n",n);
	int i,m=1,y,j;
	int *b = (int *)malloc(n*sizeof(int));
	if(b == NULL){
		return;
	}
	b[n-1] = 1;
	for(i=n-2;i>=0;i--){
		b[i] = 2*b[i+1];
	}
	int *c = (int *)malloc(n*sizeof(int));
	if(c == NULL){
		return;
	}
	c[n-1] = 0;
	for(i=n-2;i>=0;i--){
		c[i] = c[i+1] + 2;
	}
	initQueue(&q,20);
	Data x,t;
	if(T){
		x.data = T;
		x.n = 1;
		enQueue(&q,x);
	}
	Tree p = T;
	for(i=0;i<n-1;i++){
		m *= 2;
	}
	char *a = (char *)malloc(m*n*sizeof(char));
	if(a == NULL){
		return;
	}else{
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				*(a+m*i+j) = ' ';
			}
			printf("\n");
		}
		while(isEmptyQueue(q) != 0){
			deQueue(&q,&x);
			y = x.n-1;
			printf("%d",y);
			printf("%c ",x.data->data);
			*(a+m*y+c[y]) = x.data->data;
			c[y] += b[y];
			if(x.data->lchild){
				t.data = x.data->lchild;
				t.n = x.n + 1;
				enQueue(&q,t);
			}else{
				if(y<n){			
					c[y+1] += b[y+1];
				}
			}
			if(x.data->rchild){
				t.data = x.data->rchild;
				t.n = x.n + 1;
				enQueue(&q,t);
			}else{
				if(y<n){
					c[y+1] += b[y+1];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",*(a+m*i+j));
		}
		printf("\n");
	}
}

int main()
{
	Tree T;
	int i=0;
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("��ӡ���:\n");
	display(T);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###

*/