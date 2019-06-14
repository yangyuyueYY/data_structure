/*
 * ���������������������������ϲ��Ҹ������*p�����������еĺ��
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	int ltag,rtag;
	struct node *lchild,*rchild;
}Node,*Tree;

/*
 * �������㷨
 * @param Tree p �����
 * @param Tree *pre ����ǰ�����
 */
void inTreading(Tree p,Tree *pre)
{
	if(p){
		if(p->lchild == NULL){
			p->ltag = 1;
			p->lchild = *pre;
		}else{
			p->ltag = 0;
		}
		if((*pre)->rchild == NULL){
			(*pre)->rtag = 1;
			(*pre)->rchild = p;
		}else{
			(*pre)->rtag = 0;
		}
		*pre = p;
		inTreading(p->lchild,pre);
		inTreading(p->rchild,pre);
	}
}

/*
 * ���������������ͷ��㣬������
 * @param Tree *head ͷ���
 * @param Tree T ͷָ��
 * @return int �Ƿ���ӳɹ���0�ɹ���-1ʧ��
 */
int inOrderThr(Tree *head,Tree T)
{
	Tree p;
	*head = (Tree)malloc(sizeof(Node));
	if((*head) == NULL){
		return -1;
	}
	(*head)->data = ' ';
	(*head)->ltag = 0;
	(*head)->rchild = *head;
	(*head)->rtag = 1;
	if(T == NULL){
		(*head)->lchild = *head;
	}else{
		(*head)->lchild = T;
		p = *head;
		inTreading(T,&p);
		p->rchild = *head;
		p->rtag = 1;
		(*head)->rchild = p;
	}
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
 * ���Ҹ�����������������еĺ��
 * @param Tree p Ŀ����
 * @param Tree *q ������
 * @return int �Ƿ���ҳɹ���0�ɹ���-1ʧ��
 */
int postNode(Tree p,Tree *q)
{
	if(p->rtag == 1){
		*q = p->rchild;
		return 0;
	}
	if(p->ltag == 0){
		*q = p->lchild;
		return 0;
	}
	if(p->rtag == 0){
		*q = p->rchild;
		return 0;
	}
	return -1;
}

/*
 * ����ֵΪx�Ľ��
 * @param Tree head ͷ���
 * @param char x ����������
 * @return Tree Ŀ���ַ
 */
Tree search(Tree head,char x)
{
	Tree q;
	Tree p = head->lchild;
	while(p != head && p->data != x){
		postNode(p,&q);
		p = q;
	}
	return p;
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void preDisplay(Tree T,char x,Tree *p)
{
	if(T){
		if(T->data == x){
			*p = T;
		}
		preDisplay(T->lchild,x,p);
		preDisplay(T->rchild,x,p);
	}
}

int main()
{
	Tree T,head,p,q;
	char x;
	printf("�������������������:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
		return -1;
	}
	getchar();
	printf("���������������:");
	scanf("%c",&x);
	preDisplay(T,x,&p);
	if(0 == inOrderThr(&head,T)){
		printf("�������ɹ�!\n");
	}else{
		printf("������ʧ��!\n");
		return -1;
	}
	printf("�������̽��Ϊ:");
	postNode(p,&q);
	printf("%c",q->data);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/