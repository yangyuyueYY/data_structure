/*
 * �����뷴������ͬ���ַ����г�Ϊ�������У��Ա�дһ���㷨���ж�һ�ζ�����@��������ĸ����
 * �Ƿ����硰����1&����2��ģʽ���ַ����С���������1������2���������ַ�&��������2������1��������
 * Ҫ����ջ�Ͷ�����ʵ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
	int head;
	int rear;
	int size;
}Queue;//ѭ������

typedef struct
{
	char *data;
	int top;
	int size;
}Stack;//˳��ջ

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
	q->data = (char *)malloc(max * sizeof(char));
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
 * ˳����У�����г���
 * @param Queue q ˳�����
 * @return int ���г���
 */
int getLengthQueue(Queue q)
{
	return (q.rear+q.size-q.head)%q.size;
}

/*
 * ˳����У�������
 * @param Queue *q ˳������׵�ַ
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, char x)
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
 * @param char *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, char *x)
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
	q->data = (char *)malloc(max * sizeof(char));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
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
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *q, char x)
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
 * @param char *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *q, char *x)
{ 
	if(q->top == 0){
		printf("ջ��!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * �ж������Ƿ����
 * @param char *a ����
 * @return int �Ƿ���ģ�1�ǣ�0��
 */
int judge(char *a)
{
	int i=0,n;
	Queue q;
	Stack s;
	char x,y;
	initQueue(&q,20);
	initStack(&s,20);
	n = strlen(a);
	while(a[i] != '&'){
		enQueue(&q,a[i]);
		i ++;
	}
	i ++;
	while(a[i] != '@'){
		pushStack(&s,a[i]);
		i++;
	}
	while(isEmptyStack(s) != 0 && isEmptyQueue(q) != 0){
		deQueue(&q, &x);
		popStack(&s, &y);
		if(x != y){
			return 0;
		}
	}
	if(isEmptyStack(s) != 0 || isEmptyQueue(q) != 0){
		return 0;
	}
	return 1;
}

int main()
{
	char a[40];
	printf("����������:");
	scanf("%s",a);
	if(judge(a) == 0){
		printf("���в�����!\n");
	}else{
		printf("���л���!\n");
	}
	return 0;
}
