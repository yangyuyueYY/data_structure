/*
 * ��̬������ʼ�������롢ɾ�������¡���ȡ����λ���������󳤶�
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

typedef struct
{
	Data data;
	int next;
}Node;

typedef struct
{
	Node *node;
	int sl;
	int av;
	int size;
}StaticLink;

/*
 * ��̬������ʼ��
 * @param StaticLink *L ��̬�����׵�ַ
 * @param int max �������
 * @return int �Ƿ��ʼ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initStaticLink(StaticLink *L, int max)
{
	Node *node;
	int i;
	if(max < 0){
		printf("����������벻�Ϸ�\n");
		return -1;
	}
	node = (Node *)malloc(max * sizeof(Node));
	if(NULL == node){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	node[0].next = -1;
	for(i=1;i<max;i++){
		strcpy(node[i].data.name,"");
		node[i].data.score = 0;
		node[i].next = i+1;
	}
	node[max-1].next = -1;
	L->node = node;
	L->sl = 0;
	L->av = 1;
	L->size = max;
	return 0;
}

/*
 * ��̬��������
 * @param StaticLink *L ��̬�����׵�ַ
 * @param int pos ����λ��
 * @param Data x ��������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertStaticLink(StaticLink *L, int pos, Data x)
{
	int i = 0, j = L->sl, s = L->av;
	if(-1 == L->node[L->av].next){
		printf("��̬��������\n");
		return -1;
	}
	while(i < pos-1 && j){
		j = L->node[j].next;
		i ++;
	}
	if(i > pos-1 || -1 == j){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	L->av = L->node[s].next;
	L->node[s].data = x;
	L->node[s].next = L->node[j].next;
	L->node[j].next = s;
	return 0;
}

/*
 * ��̬����ɾ��
 * @param StaticLink *L ��̬�����׵�ַ
 * @param int pos ɾ��λ��
 * @param Data *x ɾ������
 * @return int �Ƿ�ɾ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int deleteStaticLink(StaticLink *L, int pos, Data *x)
{
	int i = 0, j = L->sl, s;
	if(-1 == L->node[j].next){
		printf("����������Ϊ��\n");
		return -1;
	}
	while(i < pos-1 && L->node[j].next != -1){
		j = L->node[j].next;
		i ++;
	}
	if(i > pos-1 || -1 == L->node[j].next){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	s = L->node[j].next;
	*x = L->node[s].data;
	L->node[j].next = L->node[s].next;
	L->node[s].next = L->av;
	L->av = s;
	return 0;
}

/*
 * ��̬��������
 * @param StaticLink L ��̬����
 * @param int pos ����λ��
 * @param Data x ��������
 * @return int �Ƿ���³ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int updateStaticLink(StaticLink L, int pos, Data x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("����������Ϊ��\n");
		return -1;
	}
	while(i < pos && j != -1){
		j = L.node[j].next;
		i ++;
	}
	if(i > pos || -1 == j){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	L.node[j].data = x;
	return 0;
}

/*
 * ��̬������ȡ
 * @param StaticLink L ��̬����
 * @param int pos ��ȡλ��
 * @param Data *x ��ȡ����
 * @return int �Ƿ��ȡ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getDataStaticLink(StaticLink L, int pos, Data *x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("����������Ϊ��\n");
		return -1;
	}
	while(i < pos && j != -1){
		j = L.node[j].next;
		i ++;
	}
	if(i > pos || -1 == j){
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	*x = L.node[j].data;
	return 0;
}

/*
 * ��̬������λ
 * @param StaticLink L ��̬����
 * @param int *pos ��λ��λ��
 * @param Data x �趨λ����
 * @return int �Ƿ�λ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getPosStaticLink(StaticLink L, int *pos, Data x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("����������Ϊ��\n");
		return -1;
	}
	while((j != -1) && (strcmp(L.node[j].data.name,x.name) != 0 || fabs(L.node[j].data.score - x.score) > 1e-6)){
		j = L.node[j].next;
		i ++;
	}
	if(-1 == j){
		printf("�����ݲ�����\n");
		return -1;
	}
	*pos = i;
	return 0;
}

/*
 * ��̬��������
 * @param StaticLink L ��̬����
 */
void displayStaticLink(StaticLink L)
{
	int i = 1, j = L.node[L.sl].next;
	if(-1 == j){
		printf("����������Ϊ��\n");
		return;
	}
	while(j != -1){
		printf("%d  name:%s  score:%g\n",i,L.node[j].data.name,L.node[j].data.score);
		j = L.node[j].next;
		i ++;
	}
	return;
}

/*
 * ��̬����ȡ��
 * @param Staticnk L ��̬����
 * @param int *pos ����
 * @return int �Ƿ�ȡ���ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int getLengthStaticLink(StaticLink L, int *pos)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("����������Ϊ��\n");
		return -1;
	}
	while(L.node[j].next != -1){
		j = L.node[j].next;
		i ++;
	}
	*pos = i;
	return 0;
}

int main()
{
	StaticLink L;
	int i,pos,max;
	Data data;
	printf("��̬������ʼ�������롢ɾ�������¡���ȡ����λ���������󳤶�\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--��ʼ��      2--����     3--ɾ��      \n");  
		printf("     4--����        5--��ȡ     6--��λ      \n");
		printf("     7--����        8--ȡ��     0--�˳�      \n");
		printf("*********************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("������������");
			scanf("%d",&max);
			if(0 == initStaticLink(&L,max)){
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
			if(0 == insertStaticLink(&L,pos,data)){
				printf("����ɹ�\n");
			}
			break;
		case 3:
			printf("������ɾ��λ��:");
			scanf("%d",&pos);
			if(0 == deleteStaticLink(&L,pos,&data)){
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
			if(0 == updateStaticLink(L,pos,data)){
				printf("���³ɹ�\n");
			}
			break;
		case 5:
			printf("�������ȡ����λ��:");
			scanf("%d",&pos);
			if(0 == getDataStaticLink(L,pos,&data)){
				printf("��λ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == getPosStaticLink(L,&pos,data)){
				printf("������λ����:%d\n",pos);
			}
			break;
		case 7:
			printf("������:\n");
			displayStaticLink(L);
			break;
		case 8:
			if(0 == getLengthStaticLink(L,&pos)){
				printf("��ǰ���Ա���Ϊ:%d\n",pos);
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


