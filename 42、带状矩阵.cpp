/*
 * 编写创建n阶整型带状矩阵A和输出n阶整型带状称矩阵的算法
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 创建并显示n阶整型对称矩阵
 * @param int *a 矩阵
 * @param int *n 矩阵阶数
 * @return int 是否成功，0成功，1失败
 */
int create(int *a,int n)
{
	int i,j,w;
	printf("请输入矩阵阶数:");
	scanf("%d",&n);
	printf("请输入矩阵带宽:");
	scanf("%d",&w);
	a = (int *)malloc(n*w*sizeof(int));
	printf("请输入带状矩阵:");
	for(i=0;i<n;i++){
		for(j=0;j<w;j++){
			scanf("%d",a+i*w+j);
		}
	}
	printf("矩阵为:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<i-(w-1)/2 || j>i+(w-1)/2){
				printf("0 ");
			}else{
				printf("%d ",*(a+i*w+j-i+1));
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,*a;
	create(a,n);
	return 0;
}

/*
5
3
0 1 2
3 4 5
6 7 8
9 1 2
3 4 0
*/
