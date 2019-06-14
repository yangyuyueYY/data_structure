/*
 * ��֪����������A��B�ֱ��ʾ�������ϣ���Ԫ�ص�������
 * ��дһ���������A��B�Ľ���C��Ҫ��Cͬ����Ԫ�ص����ĵ�������ʽ����
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
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L->next;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
	}
	while(p != NULL){
		printf("%d ",p->data);
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
 * ȡ����
 * @param SqList L1 ���Ա�Aͷָ��
 * @param SqList L2 ���Ա�Bͷָ��
 * @param SqList L3 ������Ա�ͷָ��
 * @return int ȡ�����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insectSqlist(SqList L1, SqList L2,SqList L3)
{
	SqList p1 = L1->next,p2 = L2->next;
	while(p1 && p2){
		if(p1->data < p2->data){
			p1 = p1->next;
		}else if(p1->data > p2->data){
			p2 = p2->next;
		}else{
			insertTailSqlist(L3, p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return 0;
}

int main()
{
	SqList L1,L2,L3;
	initSqlist(&L1);
	initSqlist(&L2);
	initSqlist(&L3);
	int n,i,x;
	printf("���������Ա�A��Ԫ�ظ���:");
	scanf("%d",&n);
	printf("������%d��Ԫ��:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L1, x);
	}
	printf("���������Ա�A��Ԫ�ظ���:");
	scanf("%d",&n);
	printf("������%d��Ԫ��:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertTailSqlist(L2, x);
	}
	printf("�����Ա����ɹ�!\n");
	printf("���Ա�A:");
	displaySqlist(L1);
	printf("���Ա�B:");
	displaySqlist(L2);
	printf("ȡ��������\n");
	insectSqlist(L1,L2,L3);
	printf("����Ϊ:");
	displaySqlist(L3);
	return 0;
}
