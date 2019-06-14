/*
 * ɭ�ֵĻ�������������������������������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *fch,*nsib;
}CSNode,*CSTree;

typedef struct
{
	CSTree *data;
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
	q->data = (CSTree *)malloc(max * sizeof(CSTree));
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
 * @param CSTree *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,CSTree *data)
{
	if(isEmptyQueue(q) == 0){
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
 * @param CSTree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, CSTree x)
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
 * @param CSTree *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, CSTree *x)
{ 
	if(isEmptyQueue(*q) == 0){
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
}

/*
 * ���������ֵ�����
 * @param CSTree *T �����ָ��
 * @return int �Ƿ񴴽��ɹ���0�ɹ���-1ʧ��
 */
int create(CSTree *T)
{
	char fa,ch;
	Queue Q;
	CSTree p,s,r;
	initQueue(&Q,20);
	*T = NULL;
	getchar();
	printf("������ߣ������ӣ�:");
	scanf("%c,%c",&fa,&ch);
	while(ch != '#'){
		p = (CSTree)malloc(sizeof(CSNode));
		if(p == NULL){
			return -1;
		}
		p->data = ch;
		p->fch = NULL;
		p->nsib = NULL;
		enQueue(&Q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(Q,&s);
			while(s->data != fa){
				deQueue(&Q, &s);
				getHeadQueue(Q,&s);
			}
			if(s->fch == NULL){
				s->fch = p;
				r = p;
			}else{
				r->nsib = p;
				r = p;
			}
		}
		getchar();
		scanf("%c,%c",&fa,&ch);
	}
	return 0;
}

/*
 * ��ɭ��ת��Ϊ������
 * @param CSTree *TR ���ĸ��������
 * @param int n ����Ԫ�ظ���
 * @return int �Ƿ�ת���ɹ���0�ɹ���-1ʧ��
 */
int createBitree(CSTree *TR,int n)
{
	int i;
	for(i=n-1;i>0;i--){
		TR[i-1]->nsib = TR[i];
	}
	return 0;
}

/* 
 * ɭ�ֵ��������
 * @param CSTree T �����
 */
void preDisplay(CSTree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->fch);
		preDisplay(T->nsib);
	}
}

/* 
 * ɭ�ֵ��������
 * @param CSTree T �����
 */
void midDisplay(CSTree T)
{
	if(T){
		midDisplay(T->fch);
		printf("%c",T->data);
		midDisplay(T->nsib);
	}
}

int main()
{
	int n,i;
	CSTree *TR;
	printf("������ɭ�������ĸ���:");
	scanf("%d",&n);
	TR = (CSTree *)malloc(n * sizeof(CSTree));
	for(i=0;i<n;i++){
		printf("��ʼ�����%d����:",i+1);
		create(&TR[i]);
	}
	if(0 == createBitree(TR,n)){
		printf("ɭ�ִ����ɹ�!\n");
	}else{
		printf("ɭ�ִ���ʧ��!\n");
		return -1;
	}
	printf("�������Ϊ:\n");
	preDisplay(TR[0]);
	putchar('\n');
	printf("�������Ϊ:\n");
	midDisplay(TR[0]);
	putchar('\n');
	return 0;
}

/*
3
#,A
A,B
A,C
A,D
D,#
#,E
E,F
F,#
#,G
G,H
G,I
I,J
J,#
*/