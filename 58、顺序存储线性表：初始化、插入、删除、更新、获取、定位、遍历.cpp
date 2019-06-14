/*
 * ˳��洢���Ա���ʼ�������롢ɾ�������¡���ȡ����λ������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//�������Ͷ��� 
typedef struct
{
	char name[20];
	float score;
}Data;//�������

typedef struct
{
	Data *data;
	int length;
	int size;
}SqList;//˳���

/*
 * ˳��洢���Ա���ʼ��
 * @param SqList* q ˳����׵�ַ
 * @param int max ���������
 * @return int �Ƿ��ʼ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int initSqlist(SqList *q, int max)
{
	if(max < 0){
		printf("������������Ϸ�\n");
		return -1;
	}
	q->data = (Data *)malloc(max * sizeof(Data));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->length = 0;
	q-> size = max;
	return 0;
}

/*
 * ˳��洢���Ա�����
 * @param SqList* q ˳����׵�ַ
 * @param int pos ����λ��
 * @param Data x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int insertSqlist(SqList *q, int pos, Data x)
{ 
	int i;
	if(pos < 0 || pos > q->length+1){
		printf("����λ�ò��Ϸ�\n");
		return -1;
	}
	if(q->length >= q->size){
		printf("˳�������\n");
		return -1;
	}
	for(i=q->length;i>=pos;i--){
		q->data[i] = q->data[i-1];
	}
	q->data[pos-1] = x;
	q->length ++;
	return 0;
}

/*
 * ˳��洢���Ա�ɾ��
 * @param SqList* q ˳����׵�ַ
 * @param int pos ɾ��λ��
 * @param Data* xɾ������
 * @return int �Ƿ�ɾ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deleteSqlist(SqList *q, int pos, Data *x)
{ 
	int i;
	if(pos < 1 || pos > q->length){
		printf("ɾ��λ�ò��Ϸ�\n");
		return -1;
	}
	if(q->length <= 0){
		printf("˳���Ϊ��\n");
		return -1;
	}
	*x = q->data[pos-1];
	for(i=pos-1;i<q->length-1;i++){
		q->data[i] = q->data[i+1];
	}
	q->length --;
	return 0;
}

/*
 * ˳��洢���Ա�����
 * @param SqList q ˳���
 * @param int pos ����λ��
 * @param Data x��������
 * @return int �Ƿ���³ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int updateSqlist(SqList q, int pos, Data x)
{ 
	if(pos < 1 || pos > q.length){
		printf("����λ�ò��Ϸ�\n");
		return -1;
	}
	q.data[pos-1] = x;
	return 0;
}

/*
 * ˳��洢���Ա���ȡ
 * @param SqList q ˳���
 * @param int pos ��ȡλ��
 * @param Data *x��ȡ����ָ��
 * @return int �Ƿ��ȡ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int getDataSqlist(SqList q, int pos, Data *x)
{ 
	if(pos < 1 || pos > q.length){
		printf("��ȡλ�ò��Ϸ�\n");
		return -1;
	}
	*x = q.data[pos-1] ;
	return 0;
}

/*
 * ˳��洢���Ա���λ
 * @param SqList q ˳���
 * @param int *pos λ�õ�ַ
 * @param Data x �趨λ����
 * @return int �Ƿ�λ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int getPosSqlist(SqList q, int *pos, Data x)
{ 
	int i;
	for(i=0;i<q.length;i++){
		if(strcmp(q.data[i].name,x.name) == 0 && fabs(q.data[i].score-x.score) < 1e-6){
			*pos = i+1;
			return 0;
		}
	}
	if(i >= q.length){
		printf("��λʧ��\n");
		return -1;
	}
	return -1;
}

/*
 * ˳��洢���Ա�����
 * @param SqList q ˳���
 */
void displaySqlist(SqList q)
{ 
	int i;
	if(q.length == 0){
		printf("��˳���Ϊ��\n");
		return;
	}
	for(i=0;i<q.length;i++){
		printf("%d  name:%s  score:%g\n",i+1,q.data[i].name,q.data[i].score);
	}
	return;
}

int main()
{
	SqList q;
	int max,i,pos;
	Data data;
	printf("˳��洢���Ա���ʼ�������롢ɾ�������¡���ȡ����λ������\n");
	printf("�س����롭��\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--��ʼ��      2--����     3--ɾ��      \n");  
		printf("     4--����        5--��ȡ     6--��λ      \n");
		printf("     7--����        0--�˳�                  \n");
		printf("*********************************************\n");
		printf("��ѡ�����:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("������˳���������");
			scanf("%d",&max);
			if(0 == initSqlist(&q,max)){
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
			if(0 == insertSqlist(&q,pos,data)){
				printf("����ɹ�\n");
			}
			break;
		case 3:
			printf("������ɾ��λ��:");
			scanf("%d",&pos);
			if(0 == deleteSqlist(&q,pos,&data)){
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
			if(0 == updateSqlist(q,pos,data)){
				printf("���³ɹ�\n");
			}
			break;
		case 5:
			printf("�������ȡ����λ��:");
			scanf("%d",&pos);
			if(0 == getDataSqlist(q,pos,&data)){
				printf("��λ��������:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("������name:");
			scanf("%s",data.name);
			printf("������score:");
			scanf("%f",&data.score);
			if(0 == getPosSqlist(q,&pos,data)){
				printf("������λ����:%d\n",pos);
			}
			break;
		case 7:
			printf("������:\n");
			displaySqlist(q);
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
