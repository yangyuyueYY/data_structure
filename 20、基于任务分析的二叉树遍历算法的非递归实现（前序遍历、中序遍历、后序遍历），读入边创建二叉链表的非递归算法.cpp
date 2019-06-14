/*
 * ������������Ķ����������㷨�ķǵݹ�ʵ�֣�ǰ�������������������������������ߴ�����������ķǵݹ��㷨
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct node1
{
	Tree data;
	struct node1 *next;
}SqNode,*SqList;

typedef struct
{
	SqList L;
	SqList R;
}Queue;

typedef struct
{
	Tree t;
	int e;
}Data;

typedef struct node2
{
	Data data;
	struct node2 *next;
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
 * �����еĻ�����������ʼ��
 * @param Queue *q ������
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initQueue(Queue *q)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->next = NULL;
	p->data = NULL;
	q->L = p;
	q->R = p;
	return 0;
}

/*
 * �����У��ж϶ӿ�
 * @param Queue q ������
 * @return int �Ƿ�ӿգ�0Ϊ�ӿգ�1��Ϊ��
 */
int isEmptyQueue(Queue q)
{
	if(q.L == q.R){
		return 0;
	}
	return 1;
}

/*
 * �����У��õ���ͷ
 * @param Queue q ������
 * @param Tree *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,Tree *data)
{
	if(isEmptyQueue(q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	*data = q.L->next->data;
	return 0;
}

/*
 * �����У�������
 * @param Queue *q �������׵�ַ
 * @param Tree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, Tree x)
{
	int i = 0;
	SqList s = NULL;
	s = (SqList) malloc (sizeof(SqNode));
	if(NULL == s){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	s->data = x;
	s->next = q->R->next;
	q->R->next = s;
	q->R = s;
	return 0;
}

/*
 * �����У�������
 * @param Queue *q �������׵�ַ
 * @param Tree *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, Tree *x)
{
	SqList p = q->L,s;
	if(isEmptyQueue(*q) == 0){
		printf("����Ϊ��!\n");
		return -1;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 0;
}

/*
 * ����ߴ�����������ķǵݹ��㷨
 * @param Tree *T ���ڵ�ָ��
 * @return int �Ƿ񴴽��ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int createTree(Tree *T)
{
	Queue q;
	initQueue(&q);
	char fa,ch;
	int lrflag,i=1;
	Tree p,x;
	printf("�������%d������Ϣ��",i);
	scanf("%c,%c,%d",&fa,&ch,&lrflag);
	i ++;
	while(ch != '#'){
		p = (Tree)malloc(sizeof(Node));
		p->data = ch;
		p->lchild = NULL;
		p->rchild = NULL;
		enQueue(&q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(q,&x);
			while(x->data != fa){
				deQueue(&q,&x);
				getHeadQueue(q,&x);
			}
			if(x->data == fa){
				if(lrflag == 0){
					x->lchild = p;
				}else if(lrflag == 1){
					x->rchild = p;
				}
			}
		}
		getchar();
		printf("�������%d������Ϣ��",i);
		scanf("%c,%c,%d",&fa,&ch,&lrflag);
		i ++;
	}
	return 0;
}

/*
 * ������������Ķ����������㷨�ķǵݹ�ʵ��:ǰ�����
 * @param Tree T ���ڵ�
 */
void preDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
		}
	}
}

/*
 * ������������Ķ����������㷨�ķǵݹ�ʵ��:�������
 * @param Tree T ���ڵ�
 */
void midDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
		}
	}
}

/*
 * ������������Ķ����������㷨�ķǵݹ�ʵ��:�������
 * @param Tree T ���ڵ�
 */
void afterDisplay(Tree T)
{
	Stack s;
	Data x,y;
	initStack(&s);
	if(T){
		x.t = T;
		x.e = 0;
		pushStack(&s,x);
		if(T->rchild){
			x.t = T->rchild;
			x.e = 1;
			pushStack(&s,x);
		}
		if(T->lchild){
			x.t = T->lchild;
			x.e = 1;
			pushStack(&s,x);
		}
	}
	while(isEmptyStack(s) != 0){
		popStack(&s,&x);
		if(x.e == 0){
			printf("%c",x.t->data);
		}else{
			y.t = x.t;
			y.e = 0;
			pushStack(&s,y);
			if(x.t->rchild){
				y.t = x.t->rchild;
				y.e = 1;
				pushStack(&s,y);
			}
			if(x.t->lchild){
				y.t = x.t->lchild;
				y.e = 1;
				pushStack(&s,y);
			}
		}
	}
}

int main()
{
	Tree T;
	if(createTree(&T) == 0){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("ǰ�����Ϊ:");
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
#,A,0
A,B,0
B,C,1
C,D,0
C,E,1
D,F,0
D,G,1
F,#,0
*/
