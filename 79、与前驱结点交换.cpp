m/*
 * ��֪pָ��˫��ѭ�������е�һ����㣬����ṹΪdata��llink��rlink������
 * д���㷨change(p)������p��ָ��Ľ�������ǰ������˳��
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * llink;
	struct node * rlink;
}CNode,* CList;

/*
 * ˫��ѭ��������ʼ��
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
	p->llink = p;
	p->rlink = p;
	*L = p;
	return 0;
}

/*
 * ˫��ѭ����������
 * @param CList Lͷָ��
 * @param int pos ����λ��
 * @param int data ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertCNode(CList L, int pos, int data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->rlink != L){
		i ++;
		p = p->rlink;
	}
	if(i > pos-1 || (i < pos-1 && p->rlink == L)){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->llink = p;
	q->rlink = p->rlink;
	p->rlink->llink = q;
	p->rlink = q;
	return 0;
}

/*
 * ˫��ѭ������������
 * @param CList L ͷָ��
 */
void displayCNode2(CList L)
{
	int i = 0;
	CList p = L->rlink;
	if(p == L){
		printf("������Ϊ��\n");
		return;
	}
	while(p != L){
		printf("%d ",p->data);
		p = p->rlink;
		i ++;
	}
	putchar('\n');
	return;
}

/*
 * ����������ǰ�����
 * @param CList L ͷָ��
 * @return int �Ƿ񽻻��ɹ���0Ϊ�ɹ���-1Ϊ���ɹ�
 */
int changeCNode(CList p)
{
	CList q = p->llink;
	int temp;
	temp = p->data;
	p->data = q->data;
	q->data = temp;
	return 0;
}

int main()
{
	CList L,p;
	initCNode(&L);
	p = L->rlink;
	int n,i,x;
	printf("���������ݸ���:");
	scanf("%d",&n);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertCNode(L, i+1, x);
	}
	printf("˫��ѭ���������ɹ�!\n");
	printf("����Ϊ:");
	displayCNode2(L);
	printf("������p��λ��:");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		p = p->rlink;
	}
	printf("�����С���\n");
	changeCNode(p);
	printf("����������Ϊ:");
	displayCNode2(L);
	return 0;
}
