/*
 * ����ѭ��������ͷָ�룩����ʼ�������룬ɾ��������
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
 * ����ѭ��������ͷָ�룩����ʼ��
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
	strcpy(p->data.name,"");
	p->data.score = 0;
	*L = p;
	p->next = *L;
	return 0;
}

/*
 * ����ѭ��������ͷָ�룩������
 * @param CList L ͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertCNode(CList L, int pos, Data data)
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
 * ����ѭ��������ͷָ�룩��ɾ��
 * @param CList L ͷָ��
 * @param int pos ɾ��λ��
 * @param Data *data ɾ������
 * @return int �Ƿ�ɾ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int deleteCNode(CList L, int pos, Data *data)
{
	int i = 0;
	CList p = L,q;
	if(L->next == L){
		printf("������Ϊ��\n");
		return -1;
	}
	while(i < pos-1 && p->next->next != L){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next->next == L)){
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
		printf("%d  name:%s  score:%g\n",i+1,p->data.name,p->data.score);
		p = p->next;
		i ++;
	}
	return;
}

int main()
{
	CList L;
	int i,pos;
	Data data;
	printf("����ѭ��������ͷָ�룩����ʼ�������룬ɾ��������\n");
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
			if(0 == initCNode(&L)){
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
			if(0 == insertCNode(L,pos,data)){
				printf("����ɹ�\n");
			}
			break;
		case 3:
			printf("������ɾ��λ��:");
			scanf("%d",&pos);
			if(0 == deleteCNode(L,pos,&data)){
				printf("ɾ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("������:\n");
			displayCNode(L);
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
