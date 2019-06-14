/*
 * �����еĻ�����������ʼ�����ж϶ӿա�����г��ȡ��õ���ͷ����ա������С������С�����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct node
{
	Data data;
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
	strcpy(p->data.name,"");
	p->data.score = 0;
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
 * �����У��õ���ͷ
 * @param Queue q ������
 * @param Data *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,Data *data)
{
	if(isEmptyQueue(q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	*data = q.L->next->data;
	return 0;
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
 * �����У���ն���
 * @param Queue *q ������ָ��
 * @return int �Ƿ���ճɹ���0�ɹ���-1���ɹ�
 */
int emptyQueue(Queue *q)
{
	q->R = q->L;
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
 * @param Data *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, Data *x)
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
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

int main()
{
	Queue q;
	int i;
	Data data;
	printf("�����еĻ�����������ʼ�����ж϶ӿա�����г��ȡ��õ���ͷ����ա������С������С�����\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("***************************************************\n");
		printf("     1--��ʼ��      2--�ж϶ӿ�     3--ȡ����      \n");  
		printf("     4--ȡ��ͷ      5--���         6--������      \n");
		printf("     7--������      8--����         0--�˳�        \n");
		printf("***************************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initQueue(&q)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			if(0 == isEmptyQueue(q)){
				printf("ջΪ��\n");
			}else{
				printf("ջ��Ϊ��\n");
			}
			break;
		case 3:
			printf("���еĳ���Ϊ:%d",getLengthQueue(q));
			break;
		case 4:
			if(0 == getHeadQueue(q,&data)){
				printf("��ͷΪ:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyQueue(&q) == 0){
				printf("��ճɹ�!\n");
			}
			break;
		case 6:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == enQueue(&q,data)){
				printf("�����гɹ�\n");
			}
			break;
		case 7:
			if(0 == deQueue(&q,&data)){
				printf("������������:%s %g\n",data.name,data.score);
			}
			break;
		case 8:
			printf("����Ϊ:\n");
			displayQueue(q);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("����ѡ��ʧ�ܣ�����������\n");
		}
		getchar();
	}
	return 0;
}
