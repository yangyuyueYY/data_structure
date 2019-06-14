/*
 * ��֪����ͷ������������list�������н�㹹��Ϊ(data��link),����dataΪ������linkΪָ����
 * ��дһ�㷨��������������������ֵ�Ĵ�С��С�����������ӡ�Ҫ�����ӹ����в���ʹ�ó�������������κν��ռ�
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
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
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param int data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int updateSqlist(SqList L, int pos, int data)
{
	int i = 1;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->link;
	}
	if(i > pos || NULL == p){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)����ȡ
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ��ȡλ��
 * @param int *data ��ȡ����
 * @return int ��ȡ�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getDataSqlist(SqList L, int pos, int *data)
{
	int i = 1;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->link;
	}
	if(i > pos || NULL == p){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	*data = p->data;
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
		printf("%d ", p->data);
		i ++;
		p = p->link;
	}
	putchar('\n');
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)������
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @param int pos ����λ��
 * @param int data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList *L, int pos, int data)
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
		q->link = *L;
		*L = q;
		return 0;
	}
	while(i < pos-1 && p != NULL){
		i ++;
		p = p->link;
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
	q->link = p->link;
	p->link = q;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int n ���ݸ���
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int sortSqlist(SqList L, int n)
{
	int i,j,a,b;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			getDataSqlist(L,i+1,&a);
			getDataSqlist(L,j+1,&b);
			if(a>b){
				updateSqlist(L, i+1, b);
				updateSqlist(L, j+1, a);
			}
		}
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	int n,i,x;
	printf("���������ݸ���:");
	scanf("%d",&n);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&L, i+1, x);
	}
	printf("�����ɹ�!\n");
	printf("����Ϊ:");
	displaySqlist(L);
	printf("�����С���\n");
	sortSqlist(L,n);
	printf("���������Ϊ:");
	displaySqlist(L);
	return 0;
}
