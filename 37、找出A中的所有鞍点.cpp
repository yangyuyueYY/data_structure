/*
 * ������Am*n�д���ĳ��Ԫ��aij���㣺aij�ǵ�i������Сֵ���ǵ�j���е����ֵ����Ƹ�Ԫ��Ϊ����A�е�һ������
 * �Ա�дһ���㷨���ҳ�A�е����а���
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}node;

/*
 * �Ұ��㺯��
 * @param int m
 * @param int n
 * @param int *a ��������
 * @return int �Ƿ�ɹ���0�ɹ���-1ʧ��
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
	printf("����������:");
	scanf("%d",&m);
	printf("����������:");
	scanf("%d",&n);
	a = (int *)malloc(m*n*sizeof(int));
	printf("����������:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",a+i*n+j);
		}
	}
	t = findPoint(m,n,a,x);
	for(i=0;i<t;i++){
		printf("����%d:(%d,%d) %d\n",i+1,x[i].x,x[i].y,*(a+x[i].x*n+x[i].y));
	}
	return 0;
}