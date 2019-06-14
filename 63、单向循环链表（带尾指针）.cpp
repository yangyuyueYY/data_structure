/*
 * ����ѭ��������βָ�룩����ʼ�������룬ɾ��������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct node
{
	Data data;
	struct node *next;
}CNode,* CList;

/*
 * ����ѭ��������βָ�룩����ʼ��
 * @param CList *R βָ��ָ��
 * @return int �Ƿ��ʼ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initCNode(CList *R)
{
	CList p = (CList) malloc (sizeof(CNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	strcpy(p->data.name,"");
	p->data.score = 0;
	*R = p;
	p->next = *R;
	return 0;
}

/*
 * ����ѭ��������βָ�룩������
 * @param CList *R βָ��ָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertCNode(CList *R, int pos, Data data)
{
	int i = 0;
	CList p = (*R)->next,q;
	while(i < pos-1 && p != R){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p == *R)){
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
	if(i == pos-1 && p == *R){
		*R = q;
	}
	return 0;
}

/*
 * ����ѭ��������βָ�룩��ɾ��
 * @param CList *R βָ��ָ��
 * @param int pos ɾ��λ��
 * @param Data *data ɾ������
 * @return int �Ƿ�ɾ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int deleteCNode(CList *R, int pos, Data *data)
{
	int i = 0;
	CList p = R,q;
	if(R->next == R){
		printf("������Ϊ��\n");
		return -1;
	}
	while(i < pos-1 && p->next->next != R){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next->next == R)){
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
 * ����ѭ��������βָ�룩������
 * @param CList R βָ��
 */
void displayCNode(CList R)
{
	int i = 0;
	CList p = R->next;
	if(R->next == R){
		printf("������Ϊ��\n");
		return;
	}
	while(p != R){
		printf("%d  name:%s  score:%g\n",i+1,p->data.name,p->data.score);
		p = p->next;
		i ++;
	}
	return;
}

int main()
{
	CList R;
	int i,pos;
	Data data;
	printf("����ѭ��������βָ�룩����ʼ�������룬ɾ��������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--��ʼ��      2--����     3--ɾ��      \n");  
		printf("     4--����        0--�˳�                  \n");
		printf("*********************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initCNode(&R)){
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
			if(0 == insertCNode(R,pos,data)){
				printf("����ɹ�\n");
			}
			break;
		case 3:
			printf("������ɾ��λ��:");
			scanf("%d",&pos);
			if(0 == deleteCNode(R,pos,&data)){
				printf("ɾ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("������:\n");
			displayCNode(R);
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
