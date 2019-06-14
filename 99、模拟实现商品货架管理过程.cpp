/*
 * ��Ʒ���ܿ��Կ�����ջ��ջ����Ʒ�������������磬ջ����Ʒ�������������
 * �ϻ�ʱ���Ա�֤�������ڽϽ�����Ʒ���ڱȽ��µ�λ�ã�����һ��ջ��Ϊ��ת��ģ��ʵ����Ʒ���ܹ������
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
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
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *L, int x)
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
 * @param int *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *L, int *x)
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
		printf("%d ", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

int main()
{
	int n,i;
	Stack L1,L2;
	initStack(&L1);
	initStack(&L2);
	printf("��������Ʒ��:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		pushStack(&L1,i+1);
	}
	printf("ջ1Ϊ:");
	displayStack(L1);
	while(isEmptyStack(L1)!=0){
		popStack(&L1,&i);
		pushStack(&L2,i);
	}
	printf("ջ2Ϊ:");
	displayStack(L2);
	return 0;
}
