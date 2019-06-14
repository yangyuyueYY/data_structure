/*
 * �ж������Ķ������Ƿ�Ϊ��ȫ������
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
	Tree *data;
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
	q->data = (Tree *)malloc(max * sizeof(Tree));
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
 * @param Tree *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,Tree *data)
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
 * @param Tree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, Tree x)
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
 * @param Tree *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, Tree *x)
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
 * �жϸ����������Ƿ�Ϊ��ȫ������
 * @param Tree T �����
 * @param Queue *q ����ָ��
 * @param int *flag ����Ƿ����пս��
 * @param int *y �Ƿ�Ϊ��ȫ��������0��1��
 */
void isFull(Queue *q,Tree T,int *flag,int *y)
{
	initQueue(q,20);
	Tree x;
	if(T){
		enQueue(q,T);
	}
	while(isEmptyQueue(*q) != 0){
		deQueue(q,&x);
		if(x->lchild == NULL && x->rchild != NULL){
			*y = 0;
		}
		if(*flag == 1){
			if(x->lchild || x->rchild){
				*y = 0;
			}
		}else{
			if(x->rchild == NULL){
				*flag = 1;
			}
		}
		if(x->lchild){
			enQueue(q,x->lchild);
		}
		if(x->rchild){
			enQueue(q,x->rchild);
		}
	}
}

int main()
{
	Queue q;
	Tree T;
	int flag=0,y=1;
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	isFull(&q,T,&flag,&y);
	if(y == 1){
		printf("����ȫ������!\n");
	}else{
		printf("������ȫ������!\n");
	}
	return 0;
}

/*
����
ABC##DE#G##F###  
��
abd##e##cf##g##
*/