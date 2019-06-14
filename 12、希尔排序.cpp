/*
 * 希尔排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 步长为d的一次希尔排序
 * @param int *a 数据
 * @param int n 数据个数
 * @param int d 增量
 * @return int 是否排序成功
 */ 
int shellPass(int *a,int n,int d)
{
	int i,j,k;
	for(i=1;i<=d;i++){
		for(j=i+d;j<=n;j=j+d){
			a[0] = a[j];
			for(k=j-d;k>=0;k=k-d){
				if(a[k] > a[0]){
					a[k+d] = a[k];
				}else{
					a[k+d] = a[0];
					break;
				}
			}
			if(k<0){
				a[k+d] = a[0];
			}
		}
	}
	return 0;
}

/*
 * 希尔排序
 * @param int *a 数据
 * @param int n 数据个数
 * @param int *d 增量数组
 * @param int m 增量数组元素个数
 * @return int 是否排序成功
 */
int shellSort(int *a,int n,int *d,int m)
{
	int i,j;
	for(i=0;i<m;i++){
		printf("第%d次希尔排序（步长为%d):",i+1,d[i]);
		shellPass(a,n,d[i]);
		for(j=1;j<=n;j++){
			printf("%d ",a[j]);
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,i;
	int *a,d[3]={5,3,1};
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
	printf("希尔排序:\n");
	if(0 == shellSort(a,n,d,3)){
	}else{
		printf("排序失败!\n");
	}
	return 0;
}

/*
14
39 80 76 41 13 29 50 78 30 11 100 7 41 86
*/

