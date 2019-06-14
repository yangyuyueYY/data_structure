/*
 * 折半插入排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 折半插入排序
 * @param int *a 数据
 * @param int n 数据个数
 * @return int 是否排序成功
 */
int bInsertSort(int *a,int n)
{
	int i,low,high,mid,j;
	for(i=2;i<=n;i++){
		a[0] = a[i];
		low = 1;
		high = i-1;
		while(low <= high){
			mid = (low + high)/2;
			if(a[mid] < a[0]){
				low += 1;
			}else{
				high -= 1;
			}
		}
		for(j=i-1;j>=high+1;j--){
			a[j+1] = a[j];
		}
		a[high+1] = a[0];
	}
	return 0;
}

int main()
{
	int n,i;
	int *a;
	printf("请输入元素个数:");
	scanf("%d",&n);
	a = (int*)malloc((n+1)*sizeof(int));
	if(a == NULL){
		return -1;
	}
	printf("请输入%d个整数:",n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("排序前:");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	if(0 == bInsertSort(a,n)){
		printf("排序后:");
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		putchar('\n');
	}else{
		printf("排序失败!\n");
	}
	return 0;
}

/*
10
26 18 20 18 38 30 20 23 31 29
*/

