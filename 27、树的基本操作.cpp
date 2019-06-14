/*
 * ���Ļ������������������ֵ������ȸ������������������α���
 * �����ң������룬���ɾ������������ȣ��������ʾ������Ҷ�ӽ���·��
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *fch,*nsib;
}CSNode,*CSTree;

typedef struct
{
	CSTree *data;
	int head;
	int rear;
	int size;
}Queue;//ѭ������

typedef struct node1
{
	char data;
	struct node1 *next;
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
	q->data = (CSTree *)malloc(max * sizeof(CSTree));
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
 * ˳����У��õ���ͷ
 * @param Queue q ˳�����
 * @param CSTree *data ��ͷ����
 * @return int �Ƿ��ȡ�ɹ���0�ɹ���-1���ɹ�
 */
int getHeadQueue(Queue q,CSTree *data)
{
	if(isEmptyQueue(q) == 0){
		return -1;
	}
	*data = q.data[q.head];
	return 0;
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
 * ˳����У���ն���
 * @param Queue *q ˳�����ָ��
 * @return int �Ƿ���ճɹ���0�ɹ���-1���ɹ�
 */
int emptyQueue(Queue *q)
{
	q->rear = q->head;
	return 0;
}

/*
 * ˳����У�������
 * @param Queue *q ˳������׵�ַ
 * @param CSTree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int enQueue(Queue *q, CSTree x)
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
 * @param CSTree *x����������
 * @return int �Ƿ�����гɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deQueue(Queue *q, CSTree *x)
{ 
	if(isEmptyQueue(*q) == 0){
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
}

/*
 * ���������ֵ�����
 * @param CSTree *T �����ָ��
 * @return int �Ƿ񴴽��ɹ���0�ɹ���-1ʧ��
 */
int create(CSTree *T)
{
	char fa,ch;
	Queue Q;
	CSTree p,s,r;
	initQueue(&Q,20);
	*T = NULL;
	printf("������ߣ������ӣ�:");
	scanf("%c,%c",&fa,&ch);
	while(ch != '#'){
		p = (CSTree)malloc(sizeof(CSNode));
		if(p == NULL){
			return -1;
		}
		p->data = ch;
		p->fch = NULL;
		p->nsib = NULL;
		enQueue(&Q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(Q,&s);
			while(s->data != fa){
				deQueue(&Q, &s);
				getHeadQueue(Q,&s);
			}
			if(s->fch == NULL){
				s->fch = p;
				r = p;
			}else{
				r->nsib = p;
				r = p;
			}
		}
		getchar();
		scanf("%c,%c",&fa,&ch);
	}
	return 0;
}

/*
 * �ȸ�����
 * @param CSTree T �����
 */
void preDisplay(CSTree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->fch);
		preDisplay(T->nsib);
	}
}

/*
 * ������ַ
 * @param CSTree T �����
 */
void display(CSTree T)
{
	if(T){
		printf("%c:%p\n",T->data,T);
		display(T->fch);
		display(T->nsib);
	}
}

/*
 * �������
 * @param CSTree T �����
 */
void postDisplay(CSTree T)
{
	if(T){
		postDisplay(T->fch);
		printf("%c",T->data);
		postDisplay(T->nsib);
	}
}

/*
 * ������
 * @param CSTree T �����
 * @param char x ����������
 * @param CSTree *p ����ַ
 */
void search(CSTree T,char x,CSTree *p)
{
	if(T){
		if(T->data == x){
			*p = T;
		}else{
			search(T->fch,x,p);
			search(T->nsib,x,p);
		}
	}
}

/*
 * ������
 * @param CSTree *T �����ָ��
 * @param char fa �����
 * @param char ch ��������
 * @return int �Ƿ����ɹ���0�ɹ���-1ʧ��
 */
int insert(CSTree *T,char fa,char ch)
{
	CSTree p = NULL,s;
	search(*T,fa,&p);
	if(p){
		s = (CSTree)malloc(sizeof(CSNode));
		if(s == NULL){
			return -1;
		}
		s->data = ch;
		s->fch = NULL;
		s->nsib = NULL;
		if(p->fch == NULL){
			p->fch = s;
		}else{
			p = p->fch;
			while(p->nsib){
				p = p->nsib;
			}
			p->nsib = s;
		}
		return 0;
	}
	return -1;
}

/*
 * ��α���
 * @param CSTree T �����
 */
void levelDisplay(CSTree T)
{
	Queue Q;
	initQueue(&Q,20);
	CSTree p,q;
	p = T;
	while(p){
		printf("%c",p->data);
		if(p->fch){
			enQueue(&Q,p->fch);
			q = p->fch;
			while(q->nsib){
				enQueue(&Q,q->nsib);
				q = q->nsib;
			}
		}
		p = NULL;
		deQueue(&Q,&p);
	}
}

/*
 * ɾ��������
 * @param CSTree T �����
 */
void deleteTree(CSTree T)
{
	if(T){
		deleteTree(T->fch);
		deleteTree(T->nsib);
		free(T);
	}
}

/*
 * ɾ�����
 * @param CSTree *T �����ָ��
 * @param char fa �����
 * @param char ch ��ɾ�����
 * @return int �Ƿ�ɾ���ɹ���0�ɹ���-1ʧ��
*/
int deleteNode(CSTree *T,char fa,char ch)
{
	CSTree p = NULL,q = NULL,s;
	if(fa == '#'){
		deleteTree(*T);
		*T = NULL;
		return 0;
	}
	search(*T,fa,&p);
	search(*T,ch,&q);
	if(p == NULL){
		printf("fa��ַʧЧ!");
		return -1;
	}
	if(q == NULL){
		printf("ch��ַʧЧ!");
		return -1;
	}
	if(p->fch == q){
		p->fch = q->nsib;
		q->nsib = NULL;
		deleteTree(q);
		return 0;
	}else{
		s = p->fch;
		while(s->nsib != q && s->nsib != NULL){
			s = s->nsib;
		}
		if(s->nsib == NULL){
			printf("�Ǹ��ӹ�ϵ!\n");
			return -1;
		}else{
			s->nsib = q->nsib;
			q->nsib = NULL;
			deleteTree(q);
			return 0;
		}
	}
}

/*
 * ���������
 * @param CSTree T �����
 * @return int �������
 */
int depth(CSTree T)
{
	int h1,h2;
	if(T == NULL){
		return 0;
	}else{
		h1 = depth(T->fch);
		h2 = depth(T->nsib);
		if(h1+1 >= h2){
			return h1+1;
		}else{
			return h2;
		}
	}
}

/*
 * ���İ������ʾ
 * @param CSTree T �����
 * @param int level ����
 */
void aoruDisplay(CSTree T,int level)
{
	int i,k;
	if(T){
		for(i=1;i<level;i++){
			putchar(' ');
		}
		printf("%c",T->data);
		putchar('+');
		for(k=i;k<70;k++){
			putchar('-');
		}
		putchar('\n');
		aoruDisplay(T->fch,level+4);
		aoruDisplay(T->nsib,level);
	}
}

/*
 * ��������Ҷ�ӽ���·��
 * @param CSTree T �����
 * @param Stack *s ջ
 */
void allTreePath(CSTree T,Stack *s)
{
	char a;
	while(T){
		pushStack(s,T->data);
		if(T->fch == NULL){
			displayStack(*s);
		}else{
			allTreePath(T->fch,s);
		}
		popStack(s,&a);
		T = T->nsib;
	}
}

int main()
{
	CSTree T,p;
	char fa,ch;
	char x;
	Stack s;
	initStack(&s);
	create(&T);
	printf("�ȸ�����Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	postDisplay(T);
	putchar('\n');
	printf("��α���Ϊ:");
	levelDisplay(T);
	putchar('\n');
	printf("������ַ��:\n");
	display(T);
	printf("����������ҽ��:");
	getchar();
	scanf("%c",&x);
	search(T,x,&p);
	printf("%c�ĵ�ַΪ%p\n",x,p);
	getchar();
	printf("������������㼰�丸���:");
	scanf("%c,%c",&ch,&fa);
	if(0 == insert(&T,fa,ch)){
		printf("����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�ȸ�����Ϊ:");
	preDisplay(T);
	putchar('\n');
	getchar();
	printf("�������ɾ����㼰�丸���:");
	scanf("%c,%c",&ch,&fa);
	if(0 == deleteNode(&T,fa,ch)){
		printf("ɾ���ɹ�!\n");
	}else{
		printf("ɾ��ʧ��!\n");
	}
	printf("�ȸ�����Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:%d\n",depth(T));
	printf("�����Ϊ:\n");
	aoruDisplay(T,1);
	printf("����Ҷ�ӽ��·��Ϊ:\n");
	allTreePath(T,&s);
	return 0;
}

/*
#,a
a,b
a,c
b,d
b,e
c,f
e,g
e,h
e,i
i,#
g
j,c
j,c
*/