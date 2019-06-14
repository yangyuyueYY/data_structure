/*
 * 冒泡排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 冒泡排序
 * @param int *a 数据
 * @param int n 数据个数
 * @return int 是否排序成功
 */
int bubbleSort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
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
	if(0 == bubbleSort(a,n)){
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
8
23 14 18 25 3 27 19 25
*/

