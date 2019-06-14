/*
 * 堆排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 构造小根堆
 * @param int *a 数据
 * @param int s 根结点
 * @param int m 数据个数
 * @return int 是否构造成功
 */
int heapAdjust(int *a,int s,int m)
{
	int j,t;
	t = a[s];
	for(j=2*s;j<=m;j=j*2){
		if(j<m && a[j] < a[j+1]){
			j ++;
		}
		if(t >= a[j]){
			break;
		}
		a[s] = a[j];
		s = j;
	}
	a[s] = t;
	return 0;
}

/*
 * 堆排序
 * @param int *a 数据
 * @param int n 数据个数
 * @return int 是否排序成功
 */
int heapSort(int *a,int n)
{
	int t,i;
	for(i=n/2;i>0;i--){
		heapAdjust(a,i,n);
	}
	for(i=n;i>1;i--){
		t = a[i];
		a[i] = a[1];
		a[1] = t;
		heapAdjust(a,1,i-1);
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
	if(0 == heapSort(a,n)){
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
49 38 65 97 76 13 27 49
*/

