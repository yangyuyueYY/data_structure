/*
 * д�������Ա�͵���ת�㷨���ô�ͷ���ĵ�������ʵ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
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
	p->data = ' ';
	*L = p;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param char data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList L, int pos, char data)
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
 * @param int pos ����λ��
 * @param char data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int updateSqlist(SqList L, int pos, char data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)����ȡ
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ��ȡλ��
 * @param char *data ��ȡ����
 * @return int ��ȡ�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getDataSqlist(SqList L, int pos, char *data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	*data = p->data;
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
		printf("%c ", p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)��β��
 * @param SqList L ���Ա�ͷָ��
 * @param char data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertTailSqlist(SqList L, char data)
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
 * ���Ա���ת
 * @param SqList L ���Ա�ͷָ��
 * @param int n ���Ա���
 * @return int ��ת�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int contrarySqlist(SqList L,int n)
{
	int i,j;
	char a,b;
	for(i=1,j=n;i<=j;i++,j--){
		getDataSqlist(L, i, &a);
		getDataSqlist(L, j, &b);
		updateSqlist(L,i,b);
		updateSqlist(L,j,a);
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	char a[20];
	int n,i;
	printf("������һ���ַ�����:");
	scanf("%s",a);
	n = strlen(a);
	for(i=0;i<n;i++){
		insertTailSqlist(L, a[i]);
	}
	printf("�������ɹ�!\n");
	printf("����Ϊ:");
	displaySqlist(L);
	printf("��ת�С���\n");
	contrarySqlist(L,n);
	printf("��ת������Ϊ:");
	displaySqlist(L);
	return 0;
}
