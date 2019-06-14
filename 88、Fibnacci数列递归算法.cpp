/*
 * Fibnacci数列递归算法
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 求第n项数据
 * @param int n 项数
 * @param int *a 最终数列
 * return int 数据
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
	printf("请输入fibnacci数列项数:");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	fibnacci(n,a);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
