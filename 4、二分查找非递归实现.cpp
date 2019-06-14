/*
 * ���ֲ��ҷǵݹ�ʵ��
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ���ֲ��ҷǵݹ�ʵ��
 * @param int *data ��������
 * @param int n ���ݸ���
 * @param int x ����������
 * @return int ����λ�ã��Ҳ�������-1
 */
int search(int *data,int n,int x)
{
	int low = 0,high = n-1;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(data[mid] == x){
			return mid+1;
		}else if(data[mid] > x){
			high = mid - 1;
		}else{
			low = mid + 1;
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
	if((a=search(data,n,x)) == -1){
		printf("����%d������!\n",x);
	}else{
		printf("����%dλ��Ϊ%d!\n",x,a);
	}
	return 0;
}