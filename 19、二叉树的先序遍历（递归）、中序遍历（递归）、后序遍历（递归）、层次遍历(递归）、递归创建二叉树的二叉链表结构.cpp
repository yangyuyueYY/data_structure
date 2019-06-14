/*
 * ������������������ݹ飩������������ݹ飩������������ݹ飩����α���(�ݹ飩���ݹ鴴���������Ķ�������ṹ
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

typedef struct node1
{
	Tree data;
	struct node1 *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue;

/*
 * �����еĻ�����������ʼ��
 * @param Queue *q ������
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initQueue(Queue *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->next = NULL;
	p->data = NULL;
	q->L = p;
	q->R = p;
	return 0;
}

/*
 * �����У��ж϶ӿ�
 * @param Queue q ������
 * @return int �Ƿ�ӿգ�0Ϊ�ӿգ�1��Ϊ��
 */
int isEmptyQueue(Queue q)
{
	if(q.L == q.R){
		return 0;
	}
	return 1;
}

/*
 * �����У�������
 * @param Queue *q ˳������׵�ַ
 * @param Tree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, Tree x)
{
	int i = 0;
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	s->data = x;
	s->next = q->R->next;
	q->R->next = s;
	q->R = s;
	return 0;
}

/*
 * �����У�������
 * @param Queue *q �������׵�ַ
 * @param Tree *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, Tree *x)
{
	SqList p = q->L,s;
	if(isEmptyQueue(*q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
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
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void midDisplay(Tree T)
{
	if(T){
		midDisplay(T->lchild);
		printf("%c",T->data);
		midDisplay(T->rchild);
	}
}

/*
 * �������ĺ���������ݹ飩
 * @param Tree T �����������
 */
void afterDisplay(Tree T)
{
	if(T){
		afterDisplay(T->lchild);
		afterDisplay(T->rchild);
		printf("%c",T->data);
	}
}

/*
 * �������Ĳ�α������ݹ飩
 * @param Tree T �����������
 */
void levelDisplay(Queue *q,Tree T)
{
	initQueue(q);
	char x;
	if(T){
		enQueue(q,T->data);
	}
	while(isEmptyQueue(*q) != 0){
		deQueue(q,&x);
		printf("%c",x->data);
		lif(x->lchild){
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
	char a[20];
	int i=0;
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	midDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	afterDisplay(T);
	putchar('\n');
	printf("��α���Ϊ:");
	levelDisplay(&q,T);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/