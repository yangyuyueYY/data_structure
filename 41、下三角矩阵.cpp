/*
 * 编写创建n阶整型下三角矩阵A和输出n阶整型下三角矩阵的算法
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 创建并显示n阶整型下三角矩阵
 * @param int *a 矩阵
 * @param int *n 矩阵阶数
 * @return int 是否成功，0成功，1失败
 */
int create(int *a,int *n)
{
	int m,i,j;
	printf("请输入矩阵阶数:");
	scanf("%d",n);
	m = (*n)*((*n)+1)/2+1;
	a = (int *)malloc(m*sizeof(int));
	printf("请按行顺序输入下三角矩阵:");
	for(i=0;i<m-1;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入上三角数据:");
	scanf("%d",&a[m-1]);
	printf("矩阵为:\n");
	for(i=0;i<*n;i++){
		for(j=0;j<*n;j++){
			if(i >= j){
				printf("%d ",a[i*(i+1)/2+j]);
			}else{
				printf("%d ",a[m-1]);
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,*a;
	create(a,&n);
	return 0;
}

/*
5
3 6 2 4 8 1 7 4 6 0 8 2 9 5 7
*/
