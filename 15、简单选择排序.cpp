/*
 * 简单选择排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 简单选择排序
 * @param int *a 数据
 * @param int n 数据个数
 * @return int 是否排序成功
 */
int selectSort(int *a,int n)
{
	int i,min,t,j,s;
	for(i=1;i<n;i++){
		min = a[i];
		s = i;
		for(j=i+1;j<=n;j++){
			if(a[j] < min){
				min = a[j];
				s = j;
			}
		}
		t = a[i];
		a[i] = a[s];
		a[s] = t;
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
	if(0 == selectSort(a,n)){
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
7
37 18 64 14 96 48 41
*/

