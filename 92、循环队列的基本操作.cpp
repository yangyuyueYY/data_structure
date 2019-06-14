/*
 * ѭ�����еĻ�����������ʼ�����ж϶ӿա�����г��ȡ��õ���ͷ����ա������С������С�����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//�������Ͷ��� 
typedef struct
{
	char name[20];
	float score;
}Data;//�������

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
		printf("%d  name:%s  score:%g\n",i+1,q.data[t].name,q.data[t].score); 
		t = (t+1)%q.size;
		i++;
	}
	return;
}

int main()
{
	Queue q;
	int max,i;
	Data data;
	printf("˳�����(�г��ȱ���)�Ļ�����������ʼ�����ж϶ӿա�����г��ȡ��õ���ͷ����ա������С������С�����\n");
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
			printf("������˳�����������");
			scanf("%d",&max);
			if(0 == initQueue(&q,max)){
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
