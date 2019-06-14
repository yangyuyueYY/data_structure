/*
 * 二分查找递归实现
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 二分查找递归实现
 * @param int *data 数据数组
 * @param int low 低位
 * @param int high 高位
 * @param int x 待查找数据
 * @return int 数据位置，找不到返回-1
 */
int search(int *data,int low,int high,int x)
{
	int mid = (low + high)/2;
	if(low > high){
		return -1;
	}else{
		if(data[mid] == x){
			return mid+1;
		}else if(data[mid] > x){
			return search(data,low,mid-1,x);
		}else{
			return search(data,mid+1,high,x);
		}
	}
	return -1;
}

int main()
{
	int *data,n,i,x,a;
	printf("请输入数据个数:");
	scanf("%d",&n);
	data = (int *)malloc(n*sizeof(int));
	printf("请输入%d个整数:",n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("线性表为:");
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	putchar('\n');
	printf("请输入待查找数据:");
	scanf("%d",&x);
	if((a=search(data,0,n-1,x)) == -1){
		printf("数据%d不存在!\n",x);
	}else{
		printf("数据%d位置为%d!\n",x,a);
	}
	return 0;
}