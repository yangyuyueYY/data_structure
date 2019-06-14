/*
 * ��ʽ�洢���Ա�(����ͷ���)����ʼ�������롢ɾ�������¡���ȡ����λ��ȡ����������ͷ�塢β��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct node
{
	Data data;
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
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertSqlist(SqList *L, int pos, Data data)
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
 * ��ʽ�洢���Ա�(����ͷ���)��ɾ��
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @param int pos ɾ��λ��
 * @param Data *data ɾ������
 * @return int ɾ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int deleteSqlist(SqList *L, int pos, Data *data)
{
	int i = 1;
	SqList p = *L,q = NULL;
	if(NULL == *L){
		printf("���Ա�Ϊ��\n");
		return -1;
	}
	if(1 == pos){
		*data = p->data;
	    *L = (*L)->next;
		free(p);
		return 0;
	}
	while(i < pos-1 && p->next != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || NULL == p->next){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);
	return 0;
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int updateSqlist(SqList L, int pos, Data data)
{
	int i = 1;
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
 * ��ʽ�洢���Ա�(����ͷ���)����ȡ
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ��ȡλ��
 * @param Data *data ��ȡ����
 * @return int ��ȡ�Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getDataSqlist(SqList L, int pos, Data *data)
{
	int i = 1;
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
 * ��ʽ�洢���Ա�(����ͷ���)����λ
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
	while(p != NULL && (strcmp(data.name,p->data.name) != 0 || fabs(p->data.score - data.score) > 1e-6)){
		i ++;
		p = p->next;
	}
	if(p == NULL){
		printf("�����ݲ�����\n");
		return -1;
	}
	*pos = i+1;
	return 0;
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)��ȡ��
 * @param SqList L ���Ա�ͷָ��
 * @param int *pos ����
 * @return int ȡ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getLengthSqlist(SqList L, int *pos)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
		return -1;
	}
	while(p != NULL){
		i ++;
		p = p->next;
	}
	*pos = i;
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
		printf("%d  name:%s  score:%g\n", i+1, p->data.name, p->data.score);
		i ++;
		p = p->next;
	}
}

/*
 * ��ʽ�洢���Ա�(����ͷ���)��ͷ��
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertHeadSqlist(SqList *L, Data data)
{
	SqList p = *L,q = NULL;
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

/*
 * ��ʽ�洢���Ա�(����ͷ���)��β��
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

int main()
{
	SqList L;
	int i,pos;
	Data data;
	printf("��ʽ�洢���Ա�(����ͷ���)����ʼ�������롢ɾ�������¡���ȡ����λ��ȡ����������ͷ�塢β��\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--��ʼ��      2--����     3--ɾ��      \n");  
		printf("     4--����        5--��ȡ     6--��λ      \n");
		printf("     7--����        8--ȡ��     9--ͷ��      \n");
		printf("            10--β��    0--�˳�              \n");
		printf("*********************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initSqlist(&L)){
				printf("��ʼ���ɹ�\n");
			}
			break;
		case 2:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			printf("���������λ��:");
			scanf("%d",&pos);
			if(0 == insertSqlist(&L,pos,data)){
				printf("����ɹ�\n");
			}
			break;
		case 3:
			printf("������ɾ��λ��:");
			scanf("%d",&pos);
			if(0 == deleteSqlist(&L,pos,&data)){
				printf("ɾ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			printf("���������λ��:");
			scanf("%d",&pos);
			if(0 == updateSqlist(L,pos,data)){
				printf("���³ɹ�\n");
			}
			break;
		case 5:
			printf("�������ȡ����λ��:");
			scanf("%d",&pos);
			if(0 == getDataSqlist(L,pos,&data)){
				printf("��λ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == getPosSqlist(L,&pos,data)){
				printf("������λ����:%d\n",pos);
			}
			break;
		case 7:
			printf("������:\n");
			displaySqlist(L);
			break;
		case 8:
			if(0 == getLengthSqlist(L,&pos)){
				printf("��ǰ���Ա���Ϊ:%d\n",pos);
			}
			break;
		case 9:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == insertHeadSqlist(&L,data)){
				printf("����ɹ�\n");
			}
			break;
		case 10:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == insertTailSqlist(L,data)){
				printf("����ɹ�\n");
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("����ѡ��ʧ�ܣ�����������\n");
		}
		getchar();
	}
	return 0;
}
