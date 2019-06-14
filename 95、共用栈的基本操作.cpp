/*
 * ����ջ�Ļ�����������ʼ�����ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������
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
	int top1;
	int top2;
	int size;
}Stack;//����ջ

/*
 * ����ջ����ʼ��
 * @param Stack* q ����ջ�׵�ַ
 * @param int max ���������
 * @return int �Ƿ��ʼ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int initStack(Stack *q, int max)
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
	q->top1 = 0;
	q->top2 = max-1;
	q->size = max;
	return 0;
}

/*
 * ����ջ���ж�1ջջ��
 * @param Stack q ����ջ
 * @return int �Ƿ�Ϊ�գ�1��Ϊ�գ�0Ϊ��
 */
int isEmptyStack1(Stack q)
{
	if(q.top1 == 0){
		return 0;
	}
	return 1;
}

/*
 * ����ջ���ж�2ջջ��
 * @param Stack q ����ջ
 * @return int �Ƿ�Ϊ�գ�1��Ϊ�գ�0Ϊ��
 */
int isEmptyStack2(Stack q)
{
	if(q.top2 == q.size - 1){
		return 0;
	}
	return 1;
}

/*
 * ����ջ���õ�1ջջ��
 * @param Stack q ����ջ
 * @param Data *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack1(Stack q,Data *data)
{
	if(isEmptyStack1(q) == 0){
		printf("1ջΪ��!\n");
		return -1;
	}
	*data = q.data[q.top1-1];
	return 0;
}

/*
 * ����ջ���õ�2ջջ��
 * @param Stack q ����ջ
 * @param Data *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack2(Stack q,Data *data)
{
	if(isEmptyStack2(q) == 0){
		printf("2ջΪ��!\n");
		return -1;
	}
	*data = q.data[q.top2+1];
	return 0;
}

/*
 * ����ջ�����1ջ
 * @param Stack *q ����ջ�׵�ַ
 * @return int �Ƿ���ճɹ���-1ʧ�ܣ�0�ɹ�
 */
int emptyStack1(Stack *q)
{
	q->top1 = 0;
	return 0;
}

/*
 * ����ջ�����2ջ
 * @param Stack *q ����ջ�׵�ַ
 * @return int �Ƿ���ճɹ���-1ʧ�ܣ�0�ɹ�
 */
int emptyStack2(Stack *q)
{
	q->top2 = q->size - 1;
	return 0;
}

/*
 * ����ջ����1ջ����
 * @param Stack q ����ջ
 * @return int ջ�ĳ���
 */
int getLengthStack1(Stack q)
{
	return q.top1;
}

/*
 * ����ջ����2ջ����
 * @param Stack q ����ջ
 * @return int ջ�ĳ���
 */
int getLengthStack2(Stack q)
{
	return q.size-q.top2-1;
}

/*
 * ����ջ����1ջ
 * @param Stack *q ����ջ�׵�ַ
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack1(Stack *q, Data x)
{ 
	if(q->top1 == q->top2){
		printf("ջ��!\n");
		return -1;
	}
	q->data[q->top1++] = x;
	return 0;
}

/*
 * ����ջ����2ջ
 * @param Stack *q ����ջ�׵�ַ
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack2(Stack *q, Data x)
{ 
	if(q->top1 == q->top2){
		printf("ջ��!\n");
		return -1;
	}
	q->data[q->top2--] = x;
	return 0;
}

/*
 * ����ջ����1ջ
 * @param Stack *q ����ջ�׵�ַ
 * @param Data *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack1(Stack *q, Data *x)
{ 
	if(isEmptyStack1(*q) == 0){
		printf("ջ��!\n");
		return -1;
	}
	*x = q->data[--q->top1];
	return 0;
}

/*
 * ����ջ����2ջ
 * @param Stack *q ����ջ�׵�ַ
 * @param Data *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack2(Stack *q, Data *x)
{ 
	if(isEmptyStack2(*q) == 0){
		printf("ջ��!\n");
		return -1;
	}
	*x = q->data[++q->top2];
	return 0;
}

/*
 * ����ջ������1ջ
 * @param Stack q ����ջ
 */
void displayStack1(Stack q)
{ 
	int i;
	if(isEmptyStack1(q) == 0){
		printf("ջ��\n");
		return;
	}
	for(i=0;i<q.top1;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

/*
 * ����ջ������2ջ
 * @param Stack q ����ջ
 */
void displayStack2(Stack q)
{ 
	int i;
	if(isEmptyStack2(q) == 0){
		printf("ջ��\n");
		return;
	}
	for(i=q.top2+1;i<q.size;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	Stack q;
	int max,i;
	Data data;
	printf("����ջ�Ļ�����������ʼ�����ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************************\n");
		printf("       1--��ʼ��      2--�ж�1ջ��     3--�ж�2ջ��      \n");  
		printf("       4--�õ�1ջ��   5--�õ�2ջ��     6--���1ջ        \n");
		printf("       7--���2ջ     8--��1ջ��       9--��2ջ��        \n");
		printf("       10--��1ջ      11--��2ջ        12--��1ջ         \n");
		printf("       13--��2ջ      14--����1        15--����2         \n");
		printf("                      0--�˳�                            \n");
		printf("*********************************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("�����빲��ջ������");
			scanf("%d",&max);
			if(0 == initStack(&q,max)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			if(0 == isEmptyStack1(q)){
				printf("ջΪ��\n");
			}else{
				printf("ջ��Ϊ��\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack2(q)){
				printf("ջΪ��\n");
			}else{
				printf("ջ��Ϊ��\n");
			}
			break;
		case 4:
			if(0 == getTopStack1(q,&data)){
				printf("ջ��Ϊ:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(0 == getTopStack2(q,&data)){
				printf("ջ��Ϊ:%s  %g\n",data.name,data.score);
			}
			break;
		case 6:
			if(emptyStack1(&q) == 0){
				printf("��ճɹ�!\n");
			}
			break;
		case 7:
			if(emptyStack2(&q) == 0){
				printf("��ճɹ�!\n");
			}
			break;
		case 8:
			printf("ջ�ĳ���Ϊ:%d",getLengthStack1(q));
			break;
		case 9:
			printf("ջ�ĳ���Ϊ:%d",getLengthStack2(q));
			break;
		case 10:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == pushStack1(&q,data)){
				printf("��ջ�ɹ�\n");
			}
			break;
		case 11:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == pushStack2(&q,data)){
				printf("��ջ�ɹ�\n");
			}
			break;
		case 12:
			if(0 == popStack1(&q,&data)){
				printf("��ջ������:%s %g\n",data.name,data.score);
			}
			break;
		case 13:
			if(0 == popStack2(&q,&data)){
				printf("��ջ������:%s %g\n",data.name,data.score);
			}
			break;
		case 14:
			printf("����Ϊ:\n");
			displayStack1(q);
			break;
		case 15:
			printf("����Ϊ:\n");
			displayStack2(q);
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
