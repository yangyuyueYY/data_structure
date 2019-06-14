/*
 * �����������Ĳ��ҡ� ���롢���졢ɾ��
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

/* 
 * �����������Ĳ���
 * @param Tree T ������
 * @param int k ����������
 * @param Tree *p ����·�����ʵ����һ�����
 * @param Tree *f ��ǰ���ʽ���˫��
 * @return int �Ƿ��ҵ���0�Ҳ�����1�ҵ�
 */
int search(Tree T,int k,Tree *p,Tree *f)
{
	if(T == NULL){
		*p = *f;
		return 0;
	}
	if(T->data == k){
		*p = T;
		return 1;
	}
	if(T->data < k){
		return search(T->lchild,k,p,&T);
	}else{
		return search(T->rchild,k,p,&T);
	}
}

/*
 * �����������Ĳ���
 * @param Tree *T ������
 * @param int k ����������
 * @return int �Ƿ����ɹ�
 */
int insert(Tree *T,int k)
{
	Tree s;
	if(*T == NULL){
		s = (Tree)malloc(sizeof(Node));
		if(s == NULL){
			return -1;
		}
		s->data = k;
		s->lchild = NULL;
		s->rchild = NULL;
		*T = s;
		return 0;
	}
	if((*T)->data < k){
		return insert(&((*T)->rchild),k);
	}else{
		return insert(&((*T)->lchild),k);
	}
}

/*
 * �����������Ĺ���
 * @param Tree *T ������
 * @return int �Ƿ���ɹ�
 */
int create(Tree *T)
{
	int n,i,k;
	*T = NULL;
	printf("���������ݸ���:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("�������%d������:",i+1);
		scanf("%d",&k);
		if(-1 == insert(T,k)){
			return -1;
		}
	}
	return 0;
}

/*
 * ɾ��������������ĳһ�����
 * @param Tree *p ��ɾ���
 * @return int �Ƿ�ɾ���ɹ�
 */
int del(Tree *p)
{
	Tree q,s;
	if((*p)->rchild == NULL){
		q = *p;
		*p = (*p)->lchild;
		free(q);
		return 0;
	}
	if((*p)->lchild == NULL){
		q = *p;
		*p = (*p)->rchild;
		free(q);
		return 0;
	}
	q = *p;
	s = (*p)->lchild;
	while(s->rchild){
		q = s;
		s = s->rchild;
	}
	(*p)->data = s->data;
	if(q != *p){
		q->rchild = s->lchild;
	}else{
		q->lchild = s->lchild;
	}
	free(s);
	return 0;
}

/*
 * ������������ɾ��
 * @param Tree *T ������
 * @param int k ��ɾ������
 * @return int �Ƿ�ɾ���ɹ�
 */
int deleteTree(Tree *T,int k)
{
	if(*T == NULL){
		return -1;
	}
	if((*T)->data == k){
		del(T);
		return 0;
	}
	if((*T)->data > k){
		return deleteTree(&(*T)->lchild,k);
	}else{
		return deleteTree(&(*T)->rchild,k);
	}
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%d ",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

int main()
{
	Tree T;
	int i=0;
	if(0 == create(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("������ɾ������:");
	scanf("%d",&i);
	deleteTree(&T,i);
	printf("ɾ�����������Ϊ:");
	preDisplay(T);
	putchar('\n');
	return 0;
}

/*
12
50
30
20
10
25
23
40
35
80
90
85
88
20
*/