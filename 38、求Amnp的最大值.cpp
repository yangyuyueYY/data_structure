/*
 * 求Amnp的最大值
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
	int z;
}node;

/*
 * 求最大值
 * @param int m
 * @param int n
 * @param int p
 * @param int *a矩阵
 * @return int 最大值
 */
int max(int m,int n,int p,int *a,node *b)
{
	int max,i,j,t;
	max = *a;
	b->x = 0;
	b->y = 0;
	b->z = 0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(t=0;t<p;t++){
				if(max < *(a+i*n*p+j*p+t)){
					b->x = i;
					b->y = j;
					b->z = t;
					max = *(a+i*n*p+j*p+t);
				}
			}
		}
	}
	return max;
}

int main()
{
	int m,n,p,i,j,t;
	int *a;
	node b;
	printf("请输入m:");
	scanf("%d",&m);
	printf("请输入n:");
	scanf("%d",&n);
	printf("请输入p:");
	scanf("%d",&p);
	a = (int *)malloc(m*n*p*sizeof(int));
	printf("请输入矩阵数据:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(t=0;t<p;t++){
				scanf("%d",a+i*n*p+j*p+t);
			}
		}
	}
	t = max(m,n,p,a,&b);
	printf("最大值:(%d,%d,%d) %d\n",b.x,b.y,b.z,t);
	return 0;
}
