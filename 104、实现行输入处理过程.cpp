/*
 * ���б༭�����У����û�����һ�еĹ����������û������������ڷ�������ʱͨ��#��@���з����и���
 * ������س�ʱ�������е������ַ��õ����յ����룬�Ա�д�㷨ʵ�������봦�����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
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
 * ��ջ����ջ
 * @param Stack *L ��ջͷָ��
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *L, char x)
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
 * @param char *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *L, char *x)
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
		printf("%c", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * �ַ����༭
 * @param char *a �����ַ���
 * @return int �Ƿ�ɹ���0�ɹ���-1ʧ��
 */
int edit(char *a)
{
	Stack q,p;
	initStack(&q);
	initStack(&p);
	int n,i;
	char x;
	n = strlen(a);
	for(i=0;i<n;i++){
		if(a[i] == '#'){
			popStack(&q,&x);
		}else if(a[i] == '@'){
			emptyStack(&q);
		}else{
			pushStack(&q,a[i]);
		}
	}
	while(isEmptyStack(q) != 0){
		popStack(&q,&x);
		pushStack(&p,x);
	}
	displayStack(p);
	return 0;
}

int main()
{
	char a[40];
	printf("�������ַ���:");
	scanf("%s",a);
	printf("����Ϊ:");
	edit(a);
	return 0;
}
