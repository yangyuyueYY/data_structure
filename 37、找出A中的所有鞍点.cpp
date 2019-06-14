/*
 * 若矩阵Am*n中存在某个元素aij满足：aij是第i行中最小值且是第j列中的最大值，则称该元素为矩阵A中的一个鞍点
 * 试编写一个算法，找出A中的所有鞍点
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}node;

/*
 * 找鞍点函数
 * @param int m
 * @param int n
 * @param int *a 鞍点数据
 * @return int 是否成功，0成功，-1失败
 */
int findPoint(int m,int n,int *a,node *node)
{
	int i,j,t=0,s;
	int min;
	for(i=0;i<m;i++){
		min = *(a+i*n+0);
		node[t].x = i;
		node[t].y = 0;
		for(j=0;j<n;j++){
			if(min > *(a+i*n+j)){
				node[t].x = i;
				node[t].y = j;
				min = *(a+i*n+j);
			}
		}
		j = node[t].y;
		for(s=0;s<m;s++){
			if(min < *(a+s*n+j)){
				break;
			}
		}
		if(s == m){
			t++;
		}
	}
	return t;
}

int main()
{
	int m,n,t,i,j;
	int *a;
	node x[20];
	printf("请输入行数:");
	scanf("%d",&m);
	printf("请输入列数:");
	scanf("%d",&n);
	a = (int *)malloc(m*n*sizeof(int));
	printf("请输入数据:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",a+i*n+j);
		}
	}
	t = findPoint(m,n,a,x);
	for(i=0;i<t;i++){
		printf("鞍点%d:(%d,%d) %d\n",i+1,x[i].x,x[i].y,*(a+x[i].x*n+x[i].y));
	}
	return 0;
}