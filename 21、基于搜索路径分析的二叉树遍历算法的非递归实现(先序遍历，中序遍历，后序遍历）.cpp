/*
 * ��������·�������Ķ����������㷨�ķǵݹ�ʵ��(���������������������������
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct
{
	Tree t;
	char lr;
}Data;

typedef struct node1
{
	Data data;
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
 * ��ջ����ջ
 * @param Stack *L ��ջͷָ��
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *L, Data x)
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
 * @param Data *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *L, Data *x)
{ 
	Stack p = *L;
	if(*L == NULL){
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
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
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * �ݹ鴴���������Ķ�������ṹ
 * @param Tree *T �����������ָ��
 * @return int �Ƿ񴴽��ɹ�,0�ɹ���-1ʧ��
 */
int createTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * ��������·�������Ķ����������㷨�ķǵݹ�ʵ�֣��������
 * @param Tree T ���ڵ�
 */
 void afterDisplay(Tree T)
 {
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 x.t = T;
		 x.lr = 'L';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 x.t = p->lchild;
			 x.lr = 'L';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 x.lr = 'R';
			 pushStack(&s,x);
			 if(p->rchild){
				 p = p->rchild;
				 x.t = p;
				 x.lr = 'L';
				 pushStack(&s,x);
				 while(p->lchild){
					 x.t = p->lchild;
					 x.lr = 'L';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }else{
				getTopStack(s,&x);
				while(isEmptyStack(s) != 0 && x.lr == 'R'){
					popStack(&s,&x);
					printf("%c",x.t->data);
					getTopStack(s,&x);
				}
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
 }

 /*
 * ��������·�������Ķ����������㷨�ķǵݹ�ʵ�֣�ǰ�����
 * @param Tree T ���ڵ�
 */
void preDisplay(Tree T)
{
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 printf("%c",T->data);
		 x.t = T;
		 x.lr = ' ';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 printf("%c",p->lchild->data);
			 x.t = p->lchild;
			 x.lr = ' ';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 if(x.t->rchild){
				 p = x.t->rchild;
				 printf("%c",p->data);
				 x.t = p;
				 x.lr = ' ';
				 pushStack(&s,x);
				 while(p->lchild){
					 printf("%c",p->lchild->data);
					 x.t = p->lchild;
					 x.lr = ' ';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
}

/*
 * ��������·�������Ķ����������㷨�ķǵݹ�ʵ�֣��������
 * @param Tree T ���ڵ�
 */
void midDisplay(Tree T)
{
	 Stack s;
	 Data x;
	 Tree p;
	 initStack(&s);
	 if(T){
		 x.t = T;
		 x.lr = ' ';
		 pushStack(&s,x);
		 p = T;
		 while(p->lchild){
			 x.t = p->lchild;
			 x.lr = ' ';
			 pushStack(&s,x);
			 p = p->lchild;
		 }
		 while(p){
			 popStack(&s,&x);
			 printf("%c",x.t->data);
			 if(x.t->rchild){
				 p = x.t->rchild;
				 x.t = p;
				 x.lr = ' ';
				 pushStack(&s,x);
				 while(p->lchild){
					 x.t = p->lchild;
					 x.lr = ' ';
					 pushStack(&s,x);
					 p = p->lchild;
				 }
			 }
			 if(isEmptyStack(s) != 0){
				 getTopStack(s,&x);
				 p = x.t;
			 }else{
				 p = NULL;
			 }
		 }
	 }
}

int main()
{
	Tree T;
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	midDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	afterDisplay(T);
	putchar('\n');
	return 0;
}
/*
ABC##DE#G##F###
*/