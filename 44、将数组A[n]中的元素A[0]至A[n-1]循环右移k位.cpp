/*
 * 设计一个算法，将数组A[n]中的元素A[0]至A[n-1]循环右移k位，并要求只用一个元素大小的附加存储，元素移动或交换次数为O(n)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 数组右移k位
 * @param int *a 数组
 * @param int n 元素个数
 * @param int k 右移位数
 * @return int 是否成功，0成功，-1失败
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
	printf("请输入元素数:");
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int));
	printf("请输入%d个元素:",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入右移位数:");
	scanf("%d",&k);
	move(a,n,k);
	printf("右移后为:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
