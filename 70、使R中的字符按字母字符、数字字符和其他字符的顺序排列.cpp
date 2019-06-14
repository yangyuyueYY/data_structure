/*
 * ���Ա�����n��Ԫ�أ�ÿ��Ԫ����һ���ַ����ִ�������R[n]��
 * ��дһ���㷨��ʹR�е��ַ�����ĸ�ַ��������ַ��������ַ���˳�����С�
 * Ҫ������ԭ���Ĵ洢�ռ䣬Ԫ���ƶ�������С
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
 * �ж��ַ����ȼ�
 * @param char x ���ж��ַ�
 * @return int �ַ����ȼ�����ĸΪ1������Ϊ2������Ϊ3
 */
int judge(char x)
{
	if((x<='z' && x>='a')||(x<='Z' && x>='A')){
		return 1;
	}else if(x<='9' && x>='0'){
		return 2;
	}else{
		return 3;
	}
}

/*
 * ���ַ���������
 * @param SqList q ˳����׵�ַ
 * @return int �Ƿ�ɾ������ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int sortSqlist(SqList q)
{ 
	int i,j;
	char temp;
	for(i=0;i<q.length;i++){
		for(j=q.length-1;i<=j;j--){
			if(judge(q.data[i]) > judge(q.data[j])){
				temp = q.data[i];
				q.data[i] = q.data[j];
				q.data[j] = temp;
			}
		}
	}
	return 0;
}

int main()
{
	SqList q;
	initSqlist(&q, 20);
	printf("������һ���ַ����ݣ�\n");
	scanf("%s",q.data);
	q.length = strlen(q.data);
	printf("��˳���Ϊ:");
	displaySqlist(q);
	printf("�����С���\n");
	sortSqlist(q);
	printf("������˳���Ϊ:");
	displaySqlist(q);
	return 0;
}
