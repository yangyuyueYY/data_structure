/*
 * ���һ���㷨��������A[n]�е�Ԫ��A[0]��A[n-1]ѭ������kλ����Ҫ��ֻ��һ��Ԫ�ش�С�ĸ��Ӵ洢��Ԫ���ƶ��򽻻�����ΪO(n)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * ��������kλ
 * @param int *a ����
 * @param int n Ԫ�ظ���
 * @param int k ����λ��
 * @return int �Ƿ�ɹ���0�ɹ���-1ʧ��
 */
int move(int *a,int n,int k)
{
	int i,j,t;
	for(j=0;j<k;j++){
		t = a[n-1];
		for(i=n-1;i>0;i--){
			a[i] = a[i-1];
		}
		a[0] = t;
	}
	return 0;
}

int main()
{
	int n,k,*a,i;
	printf("������Ԫ����:");
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int));
	printf("������%d��Ԫ��:",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("����������λ��:");
	scanf("%d",&k);
	move(a,n,k);
	printf("���ƺ�Ϊ:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
