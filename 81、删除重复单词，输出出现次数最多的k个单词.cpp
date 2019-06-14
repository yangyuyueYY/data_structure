/*
 * ���������n��Ӣ�ﵥ�ʣ������ʽΪn,w1,w2,����,wn,����n��ʾ�������Ӣ�ĵ��ʸ���
 * �Ա�һ���򣬽���һ����������ʵ�֣���������ظ����֣���ֻ�������ϱ���һ��
 * �����㻹Ӧ��һ�������򣬼�¼�����ظ����ֵĸ�����Ȼ��������ִ�������ǰk������
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char word[20];
	int count;
}Data;

typedef struct node
{
	Data data;
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
	strcpy(p->data.word,"");
	p->data.count = 0;
	*L = p;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList L, int pos, Data data)
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
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int updateSqlist(SqList L, int pos, Data data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)����ȡ
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ��ȡλ��
 * @param Data *data ��ȡ����
 * @return int ��ȡ�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getDataSqlist(SqList L, int pos, Data *data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		return -1;
	}
	*data = p->data;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)����λ
 * @param SqList L ���Ա�ͷָ��
 * @param int *pos ��λ����λ��
 * @param Data data Ҫ��λ������
 * @return int ��λ�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getPosSqlist(SqList L, int *pos, Data data)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		
	}
	while(p != NULL && (strcmp(data.word,p->data.word) != 0)){
		i ++;
		p = p->next;
	}
	if(p == NULL){
		return -1;
	}
	*pos = i;
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
		printf("%d  word:%s  count:%d\n", i+1, p->data.word, p->data.count);
		i ++;
		p = p->next;
	}
}

/*
 * ��ʽ�洢���Ա�(��ͷ���)��β��
 * @param SqList L ���Ա�ͷָ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertTailSqlist(SqList L, Data data)
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
 * ȡ���ִ�������k��
 * @param SqList L ���Ա�ͷָ��
 * @param int n ���ݸ���
 * @param int k ��ȡ���ݸ���
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int orderSqlist(SqList L, int n,int k)
{
	SqList p = L->next;
	if(k>n){
		printf("��ȡ���������Ϸ�\n");
		return -1;
	}
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
		return -1;
	}
	int i,j;
	Data a,b;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			getDataSqlist(L,i+1,&a);
			getDataSqlist(L,j+1,&b);
			if(a.count<b.count){
				updateSqlist(L, i+1, b);
				updateSqlist(L, j+1, a);
			}
		}
	}
	i = 0;
	while(p != NULL && i < k){
		printf("%d  word:%s  count:%d\n", i+1, p->data.word, p->data.count);
		i ++;
		p = p->next;
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	Data x;
	int n,i,p,k;
	printf("���������ݸ���:");
	scanf("%d",&n);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%s",x.word);
		x.count = 1;
		if(getPosSqlist(L,&p,x) == -1){
			insertTailSqlist(L, x);
		}else{
			getDataSqlist(L,p,&x);
			x.count ++;
			updateSqlist(L, p, x);
		}
	}
	printf("�����ɹ�!\n");
	printf("����Ϊ:\n");
	displaySqlist(L);
	printf("��������ʾ��������:");
	scanf("%d",&k);
	printf("��ȡ�С���\n");
	printf("��ȡ������Ϊ:\n");
	orderSqlist(L,n,k);
	return 0;
}
