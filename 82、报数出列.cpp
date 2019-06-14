/*
 * Josephu���⣺����Ϊ1��2������n��n����Χ��һȦ��Լ�����Ϊk���˴�1��ʼ����
 * ����m���Ǹ��˳��У�������һλ�ִ�1��ʼ����������m���Ǹ����ֳ��У��Դ�����
 * ֱ�������˳���Ϊֹ���ɴ˲���һ�����ӱ�ŵ����С�
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
	int i;
	if(max < 0){
		printf("������������Ϸ�\n");
		return -1;
	}
	q->data = (int *)malloc(max * sizeof(int));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	for(i=0;i<max;i++){
		q->data[i] = i+1;
	}
	q->length = max;
	q-> size = max;
	return 0;
}

/*
 * �ж��Ƿ�����
 * @param SqList q ˳���
 * @return int �Ƿ��꣬0Ϊ���꣬-1Ϊû����
 */
int judgeSqlist(SqList q)
{
	int i;
	for(i=0;i<q.length;i++){
		if(q.data[i] != 0){
			return -1;
		}
	}
	return 0;
}

/*
 * ����
 * @param SqList q ˳���
 * @param int n ������
 * @param int k ��ʼ���
 * @param int m ��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int countSqlist(SqList q, int n,int k,int m)
{
	int i;
	if(k>n || k<1){
		printf("��ʼ��Ų��Ϸ�!\n");
		return -1;
	}
	k = (k+n-1)%n;
	while(judgeSqlist(q)!=0){
		i = 0;
		while(i<m){
			if(q.data[(k+1)%n-1] > 0){
				i++;
			}
			if(i == m){
				printf("%d ",q.data[(k+1)%n-1]);
				q.data[(k+1)%n-1] = 0;
			}
			k = (k+1)%n;
		}
	}
	putchar('\n');
	return 0;
}

int main()
{
	SqList q;
	int n,k,m;
	printf("����������n:");
	scanf("%d",&n);
	printf("�����������k:");
	scanf("%d",&k);
	printf("�����뱨������m:");
	scanf("%d",&m);
	printf("����˳��:");
	initSqlist(&q, n+1);
	countSqlist(q, n+1,k,m);
	return 0;
}
