/*
 * ��֪��ͷ���ĵ�����L�еĽ���ǰ�����ֵ�������е�
 * ��дһ�㷨����ֵΪx�Ľ����뵽��L�У�ʹ��L��Ȼ����
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}SqNode,*SqList;

/*
 * ��ʽ�洢���Ա�(��ͷ���)����ʼ��
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initSqlist(SqList *L)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->next = NULL;
	p->data = 0;
	*L = p;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param int data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList L, int pos, int data)
{
	int i = 0;
	SqList p = L,q = NULL;
	while(i < pos-1 && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || NULL == p){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L->next;
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

/*
 * ��ʽ�洢���Ա�(��ͷ���)��β��
 * @param SqList L ���Ա�ͷָ��
 * @param int data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertTailSqlist(SqList L, int data)
{
	SqList p = L,q = NULL;
	while(p->next != NULL){
		p = p->next;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * �������
 * @param SqList L ���Ա�ͷָ��
 * @param int data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int orderSqlist(SqList L,int data)
{
	SqList p = L->next,q = L,s;
	while(p != NULL && p->data < data){
		p = p->next;
		q = q->next;
	}
	s = (SqList)malloc(sizeof(SqNode));
	if(s == NULL){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	s->data = data;
	s->next = q->next;
	q->next = s;
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i,x;
	printf("������Ԫ�ظ���:");
	scanf("%d",&n);
	printf("������%d����������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L,x);
	}
	printf("������ɹ�!\n");
	printf("����Ϊ:");
	displaySqlist(L);
	printf("������Ҫ��������:");
	scanf("%d",&x);
	printf("�����С���\n");
	orderSqlist(L,x);
	printf("���������Ϊ:");
	displaySqlist(L);
	return 0;
}
