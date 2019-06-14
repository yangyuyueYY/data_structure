/*
 * ��ջ�Ļ�����������ʼ�������١��ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������
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
 * ��ջ������
 * @param Stack *L ָ����ջͷָ���ָ��
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int destroyStack(Stack *L)
{
	Stack p = *L,q;
	while(p->next){
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
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
 * ��ջ���õ�ջ��
 * @param Stack L ��ջͷָ��
 * @param Data *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack L,Data *data)
{
	if(L == NULL){
		printf("ջΪ��!\n");
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * ��ջ�����ջ
 * @param Stack *L ָ����ջͷָ���ָ��
 * @return int �Ƿ���ճɹ���-1ʧ�ܣ�0�ɹ�
 */
int emptyStack(Stack *L)
{
	(*L) = NULL;
	return 0;
}

/*
 * ��ջ����ջ����
 * @param Stack L ��ջ
 * @return int ջ�ĳ���
 */
int getLengthStack(Stack L)
{
	Stack p = L;
	int i = 0;
	while(p){
		i++;
		p = p->next;
	}
	return i;
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
	Stack p = L;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

int main()
{
	Stack L;
	int i;
	Data data;
	printf("��ջ�Ļ�����������ʼ�������١��ж�ջ�ա��õ�ջ�������ջ����ջ�ĳ��ȡ���ջ����ջ������\n");
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
			if(0 == initStack(&L)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			if(0 == destroyStack(&L)){
				printf("���ٳɹ�\n");
			}
			break;
		case 3:
			if(0 == isEmptyStack(L)){
				printf("ջΪ��\n");
			}else{
				printf("ջ��Ϊ��\n");
			}
			break;
		case 4:
			if(0 == getTopStack(L,&data)){
				printf("ջ��Ϊ:%s  %g\n",data.name,data.score);
			}
			break;
		case 5:
			if(emptyStack(&L) == 0){
				printf("��ճɹ�!\n");
			}
			break;
		case 6:
			printf("ջ�ĳ���Ϊ:%d",getLengthStack(L));
			break;
		case 7:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == pushStack(&L,data)){
				printf("��ջ�ɹ�\n");
			}
			break;
		case 8:
			if(0 == popStack(&L,&data)){
				printf("��ջ������:%s %g\n",data.name,data.score);
			}
			break;
		case 9:
			printf("����Ϊ:\n");
			displayStack(L);
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
