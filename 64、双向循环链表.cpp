/*
 * ˫��ѭ��������ʼ�������룬ɾ��������
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
	struct node * left;
	struct node * right;
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
	strcpy(p->data.name,"");
	p->data.score = 0;
	p->left = p;
	p->right = p;
	*L = p;
	return 0;
}

/*
 * ˫��ѭ����������
 * @param CList Lͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertCNode(CList L, int pos, Data data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->right != L){
		i ++;
		p = p->right;
	}
	if(i > pos-1 || (i < pos-1 && p->right == L)){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->left = p;
	q->right = p->right;
	p->right->left = q;
	p->right = q;
	return 0;
}

/*
 * ˫��ѭ������ɾ��
 * @param CList L ͷָ��
 * @param int pos ɾ��λ��
 * @param Data *data ɾ������
 * @return int �Ƿ�ɾ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int deleteCNode(CList L, int pos, Data *data)
{
	int i = 0;
	CList p = L,q;
	if(p->right == L){
		printf("������Ϊ��\n");
		return -1;
	}
	while(i < pos-1 && p->right->right != L){
		i ++;
		p = p->right;
	}
	if(i > pos-1 || (i < pos-1 && p->right->right == L)){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = p->right;
	*data = q->data;
	q->right->left = p;
	p->right = q->right;
	free(q);
	return 0;
}

/*
 * ˫��ѭ��������ǰ����
 * @param CList L ͷָ��
 */
void displayCNode1(CList L)
{
	int i = 0;
	CList p = L->left;
	if(p == L){
		printf("������Ϊ��\n");
		return;
	}
	while(p != L){
		printf("%d  name:%s  score:%g\n",i+1,p->data.name,p->data.score);
		p = p->left;
		i ++;
	}
	return;
}

/*
 * ˫��ѭ������������
 * @param CList L ͷָ��
 */
void displayCNode2(CList L)
{
	int i = 0;
	CList p = L->right;
	if(p == L){
		printf("������Ϊ��\n");
		return;
	}
	while(p != L){
		printf("%d  name:%s  score:%g\n",i+1,p->data.name,p->data.score);
		p = p->right;
		i ++;
	}
	return;
}

int main()
{
	CList L;
	int i,pos;
	Data data;
	printf("˫��ѭ��������ʼ�������룬ɾ��������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("***********************************************\n");
		printf("     1--��ʼ��      2--����       3--ɾ��      \n");  
		printf("     4--��ǰ����    5--������   0--�˳�      \n");
		printf("***********************************************\n");
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
			displayCNode1(L);
			break;
		case 5:
			printf("������:\n");
			displayCNode2(L);
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
