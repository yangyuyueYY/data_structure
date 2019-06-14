/*
 * �����������Ա�ĺϲ����ϲ���һ�±�
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}SqNode,*SqList;

/*
 * ���Ա�(��ͷ���)����ʼ��
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
 * ���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
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
 * ���Ա�(��ͷ���)������
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
		printf("%d  %d\n", i+1, p->data);
		i ++;
		p = p->next;
	}
}

/*
 * �����������Ա�ĺϲ�����ԭ���в���ϲ���
 * @param SqList L1 ���Ա�һͷָ��
 * @param SqList L2 ���Ա��ͷָ��
 * @param SqList L3 ���Ա���ͷָ��
 * @return int �Ƿ�ϲ��ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int linkSqlist(SqList L1,SqList L2,SqList L3)
{
	SqList pa = L1->next,pb = L2->next,pc = L3;
	SqList p;
	if(L1->next == NULL){
		L3 = L2;
		return 0;
	}
	if(L2->next == NULL){
		L3 = L1;
		return 0;
	}
	while(pa && pb){
		if(pa->data <= pb->data){
			p = (SqList)malloc(sizeof(SqNode));
			p->data = pa->data;
			p->next = pc->next;
			pc->next = p;
			pc = pc->next;
			pa = pa->next;
		}else{
			p = (SqList)malloc(sizeof(SqNode));
			p->data = pb->data;
			p->next = pc->next;
			pc->next = p;
			pc = pc->next;
			pb = pb->next;
		}
	}
	while(pa){
		p = (SqList)malloc(sizeof(SqNode));
		p->data = pa->data;
		p->next = pc->next;
		pc->next = p;
		pc = pc->next;
		pa = pa->next;
	}
	while(pb){
		p = (SqList)malloc(sizeof(SqNode));
		p->data = pb->data;
		p->next = pc->next;
		pc->next = p;
		pc = pc->next;
		pb = pb->next;
	}
	return 0;
}

int main()
{
	SqList L1,L2,L3;
	initSqlist(&L1);
	initSqlist(&L2);
	initSqlist(&L3);
	int i = 1,x,flag=0;
	printf("�������һ���������Ա�:\n");
	do{
		printf("����Ԫ��:");
		scanf("%d",&x);
		if(0 == insertSqlist(L1,i,x)){
			printf("��Ԫ���Ѳ���,�Ƿ����(1Ϊ������0Ϊ����):");
			scanf("%d",&flag);
			i ++;
		}else{
			printf("����ʧ��\n");
			exit(0);
		}
	}while(flag == 1);
	i = 1;
	printf("������ڶ����������Ա�:\n");
	do{
		printf("����Ԫ��:");
		scanf("%d",&x);
		if(0 == insertSqlist(L2,i,x)){
			printf("��Ԫ���Ѳ���,�Ƿ����(1Ϊ������0Ϊ����):");
			scanf("%d",&flag);
			i ++;
		}else{
			printf("����ʧ��\n");
			exit(0);
		}
	}while(flag == 1);
	printf("�����Ա����ɹ�!\n");
	printf("���Ա�һ:\n");
	displaySqlist(L1);
	printf("���Ա��:\n");
	displaySqlist(L2);
	printf("���Ա���:\n");
	displaySqlist(L3);
	printf("�ϲ��С���\n");
	linkSqlist(L1,L2,L3);
	printf("�����Ա�ϲ��ɹ�!\n");
	printf("���Ա�һ:\n");
	displaySqlist(L1);
	printf("���Ա��:\n");
	displaySqlist(L2);
	printf("���Ա���:\n");
	displaySqlist(L3);
	return 0;
}