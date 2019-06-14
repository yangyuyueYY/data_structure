/*
 * 快速排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 一次快速排序
 * @param int *a 数据
 * @param int n 数据个数
 * @param int low 低位
 * @param int high 高位
 * @param int *count 计数器
 * @return int 是否排序成功
 */
int partition(int *a,int n,int low,int high,int *count)
{
	int i;
	a[0] = a[low];
	while(low < high){
		while(low < high && a[high] >= a[0]){
			high --;
		}
		a[low] = a[high];
		while(low < high && a[low] <= a[0]){
			low ++;
		}
		a[high] = a[low];
	}
	a[low] = a[0];
	printf("第%d次快速排序:",*count);
	(*count)++;
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return low;
}

/*
 * 快速排序
 * @param int *a 数据
 * @param int n 数据个数
 * @param int low 低位
 * @param int high 高位
 * @param int *count 计数器
 * @return int 是否排序成功
 */ 
int fastSort(int *a,int n,int low,int high,int *count)
{
	int p;
	if(low < high){
		p = partition(a,n,low,high,count);
		fastSort(a,n,low,p-1,count);
		fastSort(a,n,p+1,high,count);
	}
	return 0;
}

int main()
{
	int n,i;
	int *a,count = 1;
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
	printf("排序后:\n");
	if(0 == fastSort(a,n,1,n,&count)){
		
	}else{
		printf("排序失败!\n");
	}
	return 0;
}

/*
8
70 73 70 23 93 18 11 68
*/

