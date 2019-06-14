/*
 * ˳��ջ�Ļ�����������ʼ�������١��ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������
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
	q->data = (Data *)malloc(max * sizeof(Data));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * ˳��ջ������
 * @param Stack* q ˳��ջ�׵�ַ
 * @return int �Ƿ����ٳɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int destroyStack(Stack *q)
{
	free(q->data);
	free(&q->top);
	free(&q->size);
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
 * @param Data *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack q,Data *data)
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
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *q, Data x)
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
 * @param Data *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *q, Data *x)
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
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	Stack q;
	int max,i;
	Data data;
	printf("˳��ջ�Ļ�����������ʼ�������١��ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*************************************************\n");
		printf("     1--��ʼ��      2--����     3--�ж�ջ��      \n");  
		printf("     4--ȡջ��      5--���     6--ȡ����        \n");
		printf("     7--��ջ        8--��ջ     9--����          \n");
		printf("                    0--�˳�                      \n");
		printf("*************************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("������˳��ջ������");
			scanf("%d",&max);
			if(0 == initStack(&q,max)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			if(0 == destroyStack(&q)){
				printf("���ٳɹ�\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack(q)){
				printf("ջΪ��\n");
			}else{
				printf("ջ��Ϊ��\n");
			}
			break;
		case 4:
			if(0 == getTopStack(q,&data)){
				printf("ջ��Ϊ:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyStack(&q) == 0){
				printf("��ճɹ�!\n");
			}
			break;
		case 6:
			printf("ջ�ĳ���Ϊ:%d",getLengthStack(q));
			break;
		case 7:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == pushStack(&q,data)){
				printf("��ջ�ɹ�\n");
			}
			break;
		case 8:
			if(0 == popStack(&q,&data)){
				printf("��ջ������:%s %g\n",data.name,data.score);
			}
			break;
		case 9:
			printf("����Ϊ:\n");
			displayStack(q);
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
