/*
 * �����Ӽ����⣨�˶�����ʱ�䣩���趨��Ŀ����������Ŀ���š���ʾ
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
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
	p->data = 0;
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
 * �����У�����г���
 * @param Queue q ������
 * @return int ���г���
 */
int getLengthQueue(Queue q)
{
	SqList p = q.L;
	int i = 0;
	while(p != q.R){
		i ++;
		p = p->next;
	}
	return i;
}

/*
 * ˳����У�������
 * @param Queue *q ˳������׵�ַ
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, int x)
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
 * @param int *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, int *x)
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
 * ˳����У�����
 * @param Queue q ˳�����
 */
void displayQueue(Queue q)
{
	int i = 0;
	SqList p = q.L->next;
	if(isEmptyQueue(q) == 0){
		printf("����Ϊ��!\n");
		return;
	}
	while(p != NULL){
		printf("%d ",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * ������Ŀ����ʾ
 * @param int n ��Ŀ��
 * @param int *a ��Ŀ��ͻ��
 * @return int �Ƿ��ųɹ���0�ɹ���-1���ɹ�
 */
int arrange(int n,int *a)
{
	int i,*b,x,j,m;
	Queue q;
	initQueue(&q);
	b = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		b[i] = *(a+0*n+i);
	}
	printf("0 ");
	for(i=1;i<n;i++){
		if(b[i] == 0){
			for(j=0;j<n;j++){
				b[j] += *(a+i*n+j);
			}
			printf("%d ",i);
		}else{
			enQueue(&q, i);
		}
	}
	putchar('\n');
	while(isEmptyQueue(q) != 0){
		deQueue(&q, &x);
		printf("%d ", x);
		for(i=0;i<n;i++){
			b[i] = *(a+x*n+i);
		}
		m = getLengthQueue(q);
		for(i=1;i<=m;i++){
			deQueue(&q, &x);
			if(b[x] == 0){
				for(j=0;j<n;j++){
					b[j] += *(a+x*n+j);
				}
				printf("%d ",x);
			}else{
				enQueue(&q, x);
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,m,i,j,t,s;
	int *a,*b;
	printf("��������Ŀ��:");
	scanf("%d",&n);
	a = (int *)malloc(n*n*sizeof(int));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			*(a+i*n+j) = 0;
		}
	}
	printf("�����뱨������:");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("�������%d����Ŀ��:",i+1);
		scanf("%d",&t);
		if(i == 0){
			b = (int *)malloc(t*sizeof(int));
		}else{
			b = (int *)realloc(b,t*sizeof(int));
		}
		printf("�������%d����Ŀ:",i+1);
		for(j=0;j<t;j++){
			scanf("%d",&b[j]);
		}
		for(s=0;s<t;s++){
			for(j=s;j<t;j++){
				*(a+b[s]*n+b[j]) = 1;
				*(a+b[j]*n+b[s]) = 1;
			}
			*(a+b[s]*n+b[s]) = 0;
		}
	}
	printf("���Ž��Ϊ:\n");
	arrange(n,a);
	return 0;
}											
/*
9
7
3
1 4 8
2
1 7
2
8 3
3
1 0 5
2
3 4
3
5 6 2
2
6 4
*/