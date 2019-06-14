/*
 * �����������ͷ���ĵ�����ĵݹ��㷨
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
 * ��ʽ�洢���Ա�(����ͷ���)����ʼ��
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initSqlist(SqList *L)
{
	*L = NULL;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)������
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @param int pos ����λ��
 * @param char data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList *L, int pos, char data)
{
	int i = 1;
	SqList p = *L,q = NULL;
	if(1 == pos){
		q = (SqList) malloc (sizeof(SqNode));
		if(NULL == q){
			printf("�ռ����ʧ��\n");
			return -1;
		}
		q->data = data;
		q->next = *L;
		*L = q;
		return 0;
	}
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
 * ��ʽ�洢���Ա�(����ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		printf("%c",p->data);
		i ++;
		p = p->next;
	}
	putchar('\n');
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)���������
 * @param SqList p ��ǰָ��
 */
void contrarySqlist(SqList p)
{
	if(p == NULL){
		return;
	}else{
		contrarySqlist(p->next);
		printf("%c",p->data);
	}
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i;
	char a[40];
	printf("������һ���ַ�����:");
	scanf("%s",a);
	n = strlen(a);
	for(i=0;i<n;i++){
		insertSqlist(&L, i+1, a[i]);
	}
	printf("����Ϊ:");
	displaySqlist(L);
	printf("�������Ϊ:");
	contrarySqlist(L);
	putchar('\n');
	return 0;
}
