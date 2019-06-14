/*
 * Fibnacci���еݹ��㷨
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ���n������
 * @param int n ����
 * @param int *a ��������
 * return int ����
 */
int fibnacci(int n,int *a){
	if(n == 1 || n == 2){
		a[n-1] = 1;
		return 1;
	}else{
		a[n-1] = fibnacci(n-1,a) + fibnacci(n-2,a);
		return a[n-1];
	}
}

int main()
{
	int n,*a,i;
	printf("������fibnacci��������:");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	fibnacci(n,a);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
