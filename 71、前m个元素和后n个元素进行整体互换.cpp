/*
 * ���Ա���˳��洢�����һ���㷨���þ������ٵĸ����洢�ռ佫˳�����ǰm��Ԫ�غͺ�n��Ԫ�ؽ������廥��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
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
	q->data = (char *)malloc(max * sizeof(char));
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
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int insertSqlist(SqList *q, int pos, char x)
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
 * @param char* xɾ������
 * @return int �Ƿ�ɾ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int deleteSqlist(SqList *q, int pos, char *x)
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
 */
void displaySqlist(SqList q)
{ 
	int i;
	if(q.length == 0){
		printf("��˳���Ϊ��\n");
		return;
	}
	for(i=0;i<q.length;i++){
		printf("%c ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * ǰ�󻥻�����
 * @param SqList q ˳����׵�ַ
 * @param int m ǰm��
 * @param int n ��n��
 * @return int �Ƿ񻥻��ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int exchangeSqlist(SqList q,int m,int n)
{ 
	int i,flag;
	char temp;
	if(m+n > q.length){
		printf("Ԫ�ظ�������!");
		return -1;
	}
	if(m<=n){
		for(i=0;i<m;i++){
			temp = q.data[i];
			q.data[i] = q.data[q.length-n+i];
			q.data[q.length-n+i] = temp;
		}
		for(i=m;i<n;i++){
			insertSqlist(&q, i+1, q.data[q.length-n+i]);
		}
		q.length = q.length-(n-m);
	}else{
		for(i=0;i<n;i++){
			temp = q.data[i];
			q.data[i] = q.data[q.length-n+i];
			q.data[q.length-n+i] = temp;
		}
		flag = n;
		while(flag<m){
			insertSqlist(&q, q.length, q.data[n]);
			deleteSqlist(&q,n+1,&temp);
			flag ++;
		}
	}
	return 0;
}

int main()
{
	SqList q;
	int m,n;
	initSqlist(&q, 20);
	printf("������һ���ַ����ݣ�\n");
	scanf("%s",q.data);
	q.length = strlen(q.data);
	printf("��˳���Ϊ:");
	displaySqlist(q);
	printf("������ǰ���������������:");
	scanf("%d%d",&m,&n);
	printf("�����С���\n");
	exchangeSqlist(q,m,n);
	printf("������˳���Ϊ:");
	displaySqlist(q);
	return 0;
}
