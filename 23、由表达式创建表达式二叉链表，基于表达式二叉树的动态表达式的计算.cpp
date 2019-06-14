/*
 * �ɱ��ʽ�������ʽ�����������ڱ��ʽ�������Ķ�̬���ʽ�ļ���
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

typedef struct node1
{
	char data;
	struct node1 *next;
}Node1,*Stack1;

typedef struct node2
{
	Tree data;
	struct node2 *next;
}Node2,*Stack2;

/*
 * ��ջ����ʼ��
 * @param Stack1 *L ָ����ջͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initStack1(Stack1 *L)
{
	*L = NULL;
	return 0;
}

/*
 * ��ջ����ʼ��
 * @param Stack2 *L ָ����ջͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initStack2(Stack2 *L)
{
	*L = NULL;
	return 0;
}

/*
 * ��ջ���õ�ջ��
 * @param Stack1 L ��ջͷָ��
 * @param char *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack1 L,char *data)
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
 * @param Stack1 *L ��ջͷָ��
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack1(Stack1 *L, char x)
{ 
	Stack1 q;
	q = (Stack1) malloc (sizeof(Node1));
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
 * @param Stack2 *L ��ջͷָ��
 * @param Tree x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack2(Stack2 *L, Tree x)
{ 
	Stack2 q;
	q = (Stack2) malloc (sizeof(Node2));
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
 * @param Stack1 *L ��ջ�׵�ַ
 * @param char *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack1(Stack1 *L, char *x)
{ 
	Stack1 p = *L;
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
 * ��ջ����ջ
 * @param Stack2 *L ��ջ�׵�ַ
 * @param Tree *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack2(Stack2 *L, Tree *x)
{ 
	Stack2 p = *L;
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
 * @param Stack1 L ��ջ
 */
void displayStack(Stack1 L)
{
	int i = 0;
	Stack1 p = L;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		printf("%c ",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * �ж���������ȼ�
 * @param char m �����
 * @return int ���ȼ���0,1,2
 */
int judge(char m){
	if(m == '('){
		return 0;
	}
	if(m == '+' || m == '-'){
		return 1;
	}
	if(m == '*' || m == '/'){
		return 2;
	}
	if(m == '#'){
		return -1;
	}
	return -1;
}

/*
 * �ɱ��ʽ�������ʽ��������
 * @param Tree *T ���ڵ�ָ��
 * @param char *cal ������ʽ
 * @return int �Ƿ񴴽��ɹ���0�ɹ���-1ʧ��
 */
int createTree(Tree *T,char *cal)
{
	int n,i;
	char x;
	Tree p,q;
	n = strlen(cal);
	Stack1 s1;
	Stack2 s2;
	initStack1(&s1);
	initStack2(&s2);
	pushStack1(&s1,'#');
	for(i=0;i<n;i++){
		if((cal[i] <= 'z' && cal[i] >= 'a') || (cal[i] <= 'Z' && cal[i] >= 'A')){
			p = (Tree)malloc(sizeof(Node));
			p->data = cal[i];
			p->lchild = NULL;
			p->rchild = NULL;
			pushStack2(&s2,p);
		}else if(cal[i] == '('){
			pushStack1(&s1,cal[i]);
		}else if(cal[i] == '+' || cal[i] == '-' || cal[i] == '*' || cal[i] == '/'){
			getTopStack(s1,&x);
			if(judge(x) < judge(cal[i])){
				pushStack1(&s1,cal[i]);
			}else{
				popStack1(&s1,&x);
				p = (Tree)malloc(sizeof(Node));
				p->data = x;
				popStack2(&s2,&q);
				p->rchild = q;
				popStack2(&s2,&q);
				p->lchild = q;
				pushStack2(&s2,p);
				pushStack1(&s1,cal[i]);
			}
		}else if(cal[i] == ')'){
			popStack1(&s1,&x);
			while(x != '('){
				p = (Tree)malloc(sizeof(Node));
				p->data = x;
				popStack2(&s2,&q);
				p->rchild = q;
				popStack2(&s2,&q);
				p->lchild = q;
				pushStack2(&s2,p);
				popStack1(&s1,&x);
			}
		}
	}
	popStack1(&s1,&x);
	while(x != '#'){
		p = (Tree)malloc(sizeof(Node));
		p->data = x;
		popStack2(&s2,&q);
		p->rchild = q;
		popStack2(&s2,&q);
		p->lchild = q;
		pushStack2(&s2,p);
		popStack1(&s1,&x);
		if(x == '#'){
			*T = p;
		}
	}
	return 0;
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * ���ڱ��ʽ�������Ķ�̬���ʽ�ļ���
 * @param Tree T �������ĸ��ڵ�
 * @return double ������
 */
double culexp(Tree T)
{
	double result,a,b;
	if(T){
		if(T->data <= 'z' && T->data >= 'a'){
			printf("���������%c:",T->data);
			scanf("%lf",&result);
			return result;
		}
		a = culexp(T->lchild);
		b = culexp(T->rchild);
		switch(T->data){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(fabs(b)<1e-6){
				printf("��������Ϊ��!\n");
				exit(0);
			}else{
				return a/b;
			}
		}
	}
}

int main()
{
	Tree T;
	char a[20];
	printf("��������ʽ:");
	scanf("%s",a);
	if(0 == createTree(&T,a)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("������Ϊ��");
	printf("%g",culexp(T));
	putchar('\n');
	return 0;
}

/*
(a+b)*c-d/e
*/