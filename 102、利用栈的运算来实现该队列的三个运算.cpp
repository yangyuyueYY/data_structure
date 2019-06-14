/*
 * ����������ջs1��s2��ģ��һ�����С�
 * ��֪ջ���������㶨�����£�PUSH(ST,x):Ԫ��x��STջ��POP(ST,x):STջ��Ԫ�س�ջ����������x��Sempty(ST):��STջ�Ƿ�Ϊ��
 * ��ô�������ջ��������ʵ�ָö��е���������:EnQueue:����һ��Ԫ�������,DeQueue()ɾ��һ��Ԫ�س����У�Queue_Empty()�ж���Ϊ��
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
}Node,*Stack;

/*
 * ��ջ����ʼ��
 * @param Stack *L ָ����ջͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initStack(Stack *L)
{
	*L = NULL;
	return 0;
}

/*
 * ��ջ���ж�ջ��
 * @param Stack L ��ջͷָ��
 * @return int ��ջ�Ƿ�ɹ���0Ϊ�գ�1��Ϊ��
 */
int isEmptyStack(Stack L)
{
	if(L == NULL){
		return 0;
	}
	return 1;
}

/*
 * ��ջ����ջ
 * @param Stack *L ��ջͷָ��
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *L, Data x)
{ 
	Stack q;
	q = (Stack) malloc (sizeof(Node));
	if(NULL == q){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	q->data = x;
	q->next = *L;
	*L = q;
	return 0;
}

/*
 * ��ջ����ջ
 * @param Stack *L ��ջ�׵�ַ
 * @param Data *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *L, Data *x)
{ 
	Stack p = *L;
	if(*L == NULL){
		printf("ջ��!\n");
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
}

/*
 * ��ջ������
 * @param Stack L ��ջ
 */
void displayStack(Stack L)
{
	int i = 0;
	Data x;
	Stack q;
	initStack(&q);
	while(isEmptyStack(L) != 0){
		popStack(&L,&x);
		pushStack(&q,x);
	}
	Stack p = q;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

/*
 * �����
 * @param Stack *q ջ
 * @param Data data ���������
 * @return int �Ƿ�����гɹ���0�ɹ���-1�ɹ�
 */
int enQueue(Stack *q,Data data)
{
	pushStack(q, data);
	return 0;
}

/*
 * ������
 * @param Stack *q ջ
 * @param Data *data ����������
 * @return int �Ƿ�����гɹ���0�ɹ���-1�ɹ�
 */
int deQueue(Stack *q,Data *data)
{
	Stack p;
	Data x;
	initStack(&p);
	while(isEmptyStack(*q) != 0){
		popStack(q,&x);
		pushStack(&p,x);
	}
	if(-1 == popStack(&p,data)){
		return -1;
	}
	while(isEmptyStack(p) != 0){
		popStack(&p,&x);
		pushStack(q,x);
	}
	return 0;
}

int main()
{
	Stack q;
	initStack(&q);
	int i;
	Data data;
	printf("ջģ����еĻ�����������ʼ�����ж϶��пա������С�������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*************************************************\n");
		printf("     1--��ʼ��      2--�п�     3--������        \n");  
		printf("     4--������      5--����     0--�˳�          \n");
		printf("*************************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initStack(&q)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			if(0 == isEmptyStack(q)){
				printf("����Ϊ��\n");
			}else{
				printf("���в�Ϊ��\n");
			}
			break;
		case 3:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == enQueue(&q,data)){
				printf("�����гɹ�\n");
			}
			break;
		case 4:
			if(0 == deQueue(&q,&data)){
				printf("������������:%s %g\n",data.name,data.score);
			}
			break;
		case 5:
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
