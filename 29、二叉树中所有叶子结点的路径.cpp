/*
 * ������������Ҷ�ӽ���·��
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}Node,*Tree;

typedef struct node1
{
	char data;
	struct node1 *next;
}Node1,*Stack;

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
 * ��ջ���õ�ջ��
 * @param Stack L ��ջͷָ��
 * @param char *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack L,char *data)
{
	if(L == NULL){
		printf("ջΪ��!\n");
		return -1;
	}
	*data = L->data;
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
	q = (Stack) malloc (sizeof(Node1));
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
	char a[20],j;
	int i = 0;
	Stack p = L;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		a[i] = p->data;
		i ++;
		p = p->next;
	}
	for(j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}
	putchar('\n');
}


/* 
 * ����������
 * @param Tree *T �����ָ��
 * @return int �Ƿ񴴽��ɹ���0�ɹ���-1ʧ��
 */
int create(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}else{
		*T = (Tree)malloc(sizeof(Node));
		if(*T == NULL){
			return -1;
		}
		(*T)->data = ch;
		create(&(*T)->lchild);
		create(&(*T)->rchild);
	}
	return 0;
}

/*
 * ��ʾ������������Ҷ�ӽ���·��
 * @param Tree T �����
 * @param Stack *s ջָ��
 */
void displayPath(Tree T,Stack *s)
{
	char x;
	if(T){
		pushStack(s,T->data);
		if(T->lchild == NULL && T->rchild == NULL){
			displayStack(*s);
		}else{
			displayPath(T->lchild,s);
			displayPath(T->rchild,s);
		}
		popStack(s,&x);
	}
}

int main()
{
	Tree T;
	Stack s;
	initStack(&s);
	printf("�����봴���ַ���:");
	if(0 == create(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("���н��·��Ϊ:\n");
	displayPath(T,&s);
	return 0;
}

/*
ABC##DE#G##F###
*/