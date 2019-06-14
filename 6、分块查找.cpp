/*
 * �ֿ����
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int num;
	int max;
}Data;

/*
 * �ֿ����
 * @param Data *L ���ݿ�
 * @parma int n ���ݿ����
 * @param int x ����������
 * @param int *pos ���ݴ�ſ��ڲ�λ��
 * @return int ���ݿ���,�Ҳ���Ϊ-1
 */
int search(Data *L,int n,int x,int *pos)
{
	int i,j;
	for(i=0;i<n;i++){
		if(L[i].max >= x){
			break;
		}
	}
	if(i == n){
		return -1;
	}
	for(j=0;j<L[i].num;j++)
	{
		if(L[i].data[j] == x){
			*pos = j+1;
			return i+1;	
		}
	}
	return -1;
}

int main()
{
	int n,i,m,max,j,pos,x,a;
	int *data;
	Data *L;
	printf("���������:");
	scanf("%d",&n);
	L = (Data *)malloc(n*sizeof(Data));
	for(i=0;i<n;i++){
		printf("�������%d��Ԫ�ظ��������ֵ:",i+1);
		scanf("%d%d",&m,&max);
		data = (int *)malloc(sizeof(int));
		L[i].max = max;
		L[i].num = m;
		printf("�������%d���%d������",i+1,m);
		for(j=0;j<m;j++){
			scanf("%d",&data[j]);
		}
		L[i].data = data;
	}
	printf("����Ϊ:");
	for(i=0;i<n;i++){
		printf("��%d��:���ֵ:%d\n",i+1,L[i].max);
		for(j=0;j<L[i].num;j++){
			printf("%d ",L[i].data[j]);
		}
		putchar('\n');
	}
	printf("���������������:");
	scanf("%d",&x);
	if((a=search(L,n,x,&pos)) == -1){
		printf("����%d������!\n",x);
	}else{
		printf("����%d�ڵ�%d��ĵ�%d��λ��!\n",x,a,pos);
	}
	return 0;
}

/*
3
3 5
3 5 4
4 10
8 6 7 9
3 15
14 12 13
*/