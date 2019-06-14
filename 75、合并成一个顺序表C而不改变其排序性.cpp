/*
 * �����������������˳���A��B����дһ�����������Ǻϲ���һ��˳���C�����ı���������
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
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
	q->data = (int *)malloc(max * sizeof(int));
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
 * @param int x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int insertSqlist(SqList *q, int pos, int x)
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
		printf("%d ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * ˳��ϲ���˳���
 * @param SqList q1 ˳���A
 * @param SqList q2 ˳���B
 * @param SqList *q3 �ϲ����˳���
 */
void mergeSqlist(SqList q1,SqList q2,SqList *q3)
{ 
	int i=0,j=0;
	while(i<q1.length && j<q2.length){
		if(q1.data[i]<=q2.data[j]){
			insertSqlist(q3, (*q3).length+1, q1.data[i]);
			i++;
		}else{
			insertSqlist(q3, (*q3).length+1, q2.data[j]);
			j++;
		}
	}
	while(i<q1.length){
		insertSqlist(q3, (*q3).length+1, q1.data[i]);
		i++;
	}
	while(j<q1.length){
		insertSqlist(q3, (*q3).length+1, q2.data[j]);
		j++;
	}
	(*q3).length--;
	return;
}

int main()
{
	SqList q1,q2,q3;
	initSqlist(&q1,20);
	initSqlist(&q2,20);
	initSqlist(&q3,40);
	int i,n,x;
	printf("������˳���A��������:");
	scanf("%d",&n);
	printf("������%d����������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&q1, q1.length+1,x);
	}
	printf("������˳���B��������:");
	scanf("%d",&n);
	printf("������%d����������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertSqlist(&q2, q2.length+1,x);
	}
	printf("˳������ɹ�!\n");
	printf("˳���A:");
	displaySqlist(q1);
	printf("˳���B:");
	displaySqlist(q2);
	printf("�ϲ��С���\n");
	mergeSqlist(q1,q2,&q3);
	printf("�ϲ���˳���Ϊ:");
	displaySqlist(q3);
	return 0;
}
