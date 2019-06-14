/*
 * ��Amnp�����ֵ
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
 * �����ֵ
 * @param int m
 * @param int n
 * @param int p
 * @param int *a����
 * @return int ���ֵ
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
	printf("������m:");
	scanf("%d",&m);
	printf("������n:");
	scanf("%d",&n);
	printf("������p:");
	scanf("%d",&p);
	a = (int *)malloc(m*n*p*sizeof(int));
	printf("�������������:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(t=0;t<p;t++){
				scanf("%d",a+i*n*p+j*p+t);
			}
		}
	}
	t = max(m,n,p,a,&b);
	printf("���ֵ:(%d,%d,%d) %d\n",b.x,b.y,b.z,t);
	return 0;
}
