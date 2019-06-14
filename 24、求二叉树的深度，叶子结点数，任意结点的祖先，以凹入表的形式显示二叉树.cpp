/*
 * �����������ȣ�Ҷ�ӽ����������������ȣ��԰�������ʽ��ʾ������
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
		printf("%c",p->data.t->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * ������������
 * @param Tree T ���������ڵ�
 * @return int ���
 */
int depth(Tree T)
{
	int l,r;
	if(T == NULL){
		return 0;
	}else{
		l = depth(T->lchild);
		r = depth(T->rchild);
		if(l >= r){
			return l+1;
		}else{
			return r+1;
		}
	}
}

/*
 * ���������Ҷ�ӽڵ���
 * @param Tree T ���������ڵ�
 * @param int *numҶ�ӽ����
 */
void leaveNum(Tree T,int *num)
{
	if(T == NULL){
		return;
	}else{
		leaveNum(T->lchild,num);
		leaveNum(T->rchild,num);
		if(T->lchild == NULL && T->rchild == NULL){
			(*num) ++;
		}
	}
}

/*
 * �������������
 * @param Tree T ���������ڵ�
 * @param char data �ڵ�����
 */
 void getPrior(Tree T,char data)
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
					if(x.t->data == data){
						displayStack(s);
						return;
					}
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
	}
	else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * �԰�������ʽ��ʾ������
 * @param Tree T ���������ڵ�
 * @param int level ���
 * @param char c ����
 */
void disp(Tree T,int level,char c)
{
	int i,k;
	if(T == NULL){
		return;
	}else{
		for(i=1;i<level;i++){
			putchar(' ');
		}
		printf("%c(%c)",T->data,c);
		for(k=i+4;k<20;k++){
			printf("-");
		}
		putchar('\n');
		disp(T->lchild,level+2,'L');
		disp(T->rchild,level+2,'R');
	}
}

int main()
{
	Tree T;
	char x;
	int n = 0;
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("���������Ϊ:%d\n",depth(T));
	leaveNum(T,&n);
	printf("Ҷ�ӽ����Ϊ:%d\n",n);
	getchar();
	printf("��������ҽ��:");
	scanf("%c",&x);
	printf("���Ƚ��Ϊ:");
	getPrior(T,x);
	printf("�����Ϊ:\n");
	disp(T,1,'D');
	return 0;
}

/*
ABC##DE#G##F###
*/