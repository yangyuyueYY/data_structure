/*
 * 顺序存储带岗哨的顺序查找
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 查找函数
 * @param int* data 数据线性表
 * @param int n 数据个数
 * @param int x 待查找数据
 * @return int 数据位置，找不到返回0
 */
int search(int *data, int n, int x)
{
	data[0] = x;
	while(1){
		if(data[n] == x){
			return n;
		}else{
			n --;
		}
	}
}

int main()
{
	int *data,n,i,x,a;
	printf("请输入数据个数:");
	scanf("%d",&n);
	data = (int *)malloc((n+1)*sizeof(int));
	printf("请输入%d个整数:",n);
	for(i=1;i<=n;i++){
		scanf("%d",&data[i]);
	}
	printf("线性表为:");
	for(i=1;i<=n;i++){
		printf("%d ",data[i]);
	}
	putchar('\n');
	printf("请输入待查找数据:");
	scanf("%d",&x);
	if((a=search(data,n,x)) == 0){
		printf("数据%d不存在!\n",x);
	}else{
		printf("数据%d位置为%d!\n",x,a);
	}
	return 0;
}