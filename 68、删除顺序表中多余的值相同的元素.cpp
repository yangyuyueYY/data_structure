/*
 * ��֪һ˳���A����Ԫ��ֵ�ǵݼ��������У���дһ������ɾ��˳����ж����ֵ��ͬ��Ԫ��
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
 * ����˳��洢���Ա�ȥ��
 * @param SqList* q ˳����׵�ַ
 * @return int �Ƿ�ȥ�سɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int singleSqlist(SqList *q)
{ 
	int i,x,j;
	if(q->length == 0){
		printf("��˳���Ϊ��!\n");
		return -1;
	}
	x = q->data[0];
	for(i=1;i<q->length;i++){
		if(x == q->data[i]){
			q->data[i] = -100;
		}else{
			x = q->data[i];
		}
	}
	for(i=q->length-1;i>=0;i--){
		if(q->data[i] == -100){
			for(j=i;j<q->length-1;j++){
				q->data[j]= q->data[j+1];
			}
			q->length --;
		}
	}
	return 0;
}

int main()
{
	SqList q;
	initSqlist(&q, 20);
	printf("������һ��ǵݼ��������ݣ�\n");
	int flag,x,i=1;
	do{
		printf("��%d��:",i);
		scanf("%d",&x);
		i++;
		insertSqlist(&q, q.length+1,x);
		printf("��ѡ���Ƿ������1Ϊ������0Ϊ����:");
		scanf("%d",&flag);
	}while(flag);
	printf("��˳���Ϊ:");
	displaySqlist(q);
	printf("ȥ���С���\n");
	singleSqlist(&q);
	printf("ȥ�غ��˳���Ϊ:");
	displaySqlist(q);
	return 0;
}
