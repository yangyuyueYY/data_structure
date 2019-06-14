/*
 * ���ֲ��ҵݹ�ʵ��
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ���ֲ��ҵݹ�ʵ��
 * @param int *data ��������
 * @param int low ��λ
 * @param int high ��λ
 * @param int x ����������
 * @return int ����λ�ã��Ҳ�������-1
 */
int search(int *data,int low,int high,int x)
{
	int mid = (low + high)/2;
	if(low > high){
		return -1;
	}else{
		if(data[mid] == x){
			return mid+1;
		}else if(data[mid] > x){
			return search(data,low,mid-1,x);
		}else{
			return search(data,mid+1,high,x);
		}
	}
	return -1;
}

int main()
{
	int *data,n,i,x,a;
	printf("���������ݸ���:");
	scanf("%d",&n);
	data = (int *)malloc(n*sizeof(int));
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("���Ա�Ϊ:");
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	putchar('\n');
	printf("���������������:");
	scanf("%d",&x);
	if((a=search(data,0,n-1,x)) == -1){
		printf("����%d������!\n",x);
	}else{
		printf("����%dλ��Ϊ%d!\n",x,a);
	}
	return 0;
}