/*
 * ��д����ݹ麯��F(n)�ķ������������ݹ飺F(n)=n+1(n=0),m*F(n/2)(n>0)
 */
#include <stdio.h>

/*
 * �ݹ麯������
 * @param int n
 * @param int m
 * @return int ������
 */
int calculate1(int n,int m)
{
	if(n == 0){
		return n+1;
	}else if(n>0){
		return m*calculate1(n/2,m);
	}
	return -1;
}

/*
 * �ǵݹ麯������
 * @param int n
 * @param int m
 * @return int ������
 */
int calculate2(int n,int m)
{
	int i=0,j,x=1;
	if(n == 0){
		return n+1;
	}else if(n > 0){
		while(n > 0){
			i ++;
			n = n/2;
		}
		for(j=0;j<i;j++){
			x *= m;
		}
		return x;
	}
	return -1;
}

int main()
{
	int m,n,x;
	printf("������m:");
	scanf("%d",&m);
	printf("������n:");
	scanf("%d",&n);
	printf("�ݹ������Ϊ:%d\n",calculate1(n,m));
	printf("�ǵݹ������Ϊ:%d\n",calculate2(n,m));
	return 0;
}
