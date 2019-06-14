/*
 * ���賤�ȴ���1��ѭ���������У�����ͷ���Ҳ��ͷָ�룬pΪָ���������ĳһ����ָ�룬��дһ������ɾ���ý���ǰ�����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
}CNode,* CList;

/*
 * ����ѭ����������ͷָ�룩����ʼ��
 * @param CList *L ͷָ��ָ��
 * @return int �Ƿ��ʼ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initCNode(CList *L)
{
	CList p = (CList) malloc (sizeof(CNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->data = 0;
	*L = p;
	p->next = *L;
	return 0;
}

/*
 * ����ѭ��������ͷָ�룩������
 * @param CList L ͷָ��
 * @param int pos ����λ��
 * @param int data ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertCNode(CList L, int pos, int data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->next != L){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next == L)){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * ����ѭ��������ͷָ�룩������
 * @param CList L ͷָ��
 */
void displayCNode(CList L)
{
	int i = 0;
	CList p = L->next;
	if(L->next == L){
		printf("������Ϊ��\n");
		return;
	}
	while(p != L){
		printf("%d ",p->data);
		p = p->next;
		i ++;
	}
	putchar('\n');
	return;
}

/*
 * ����p��ǰ�����
 * @param CList p Ŀ��ָ��
 * @param int *x ǰ���������
 * @return �Ƿ��ҵ����ҵ�Ϊ0���Ҳ���Ϊ-1
 */
int seekCNode(CList p,int *x)
{
	CList q = p;
	while(q->next != p){
		q = q->next;
	}
	*x = q->data;
	return 0;
}

int main()
{
	CList L,p;
	initCNode(&L);
	p = L->next;
	int i,n,x;
	printf("���������ݸ���:\n");
	scanf("%d",&n);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertCNode(L, i+1, x);
	}
	printf("����ѭ�����������!\n");
	printf("����Ϊ:");
	displayCNode(L);
	printf("ָ��pΪĳ���ָ��:");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		p = p->next;
	}
	printf("����p��ǰ����㡭��\n");
	seekCNode(p,&x);
	printf("ǰ���������Ϊ:%d\n",x);
	return 0;
}
