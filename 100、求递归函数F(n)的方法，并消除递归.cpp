/*
 * 试写出求递归函数F(n)的方法，并消除递归：F(n)=n+1(n=0),m*F(n/2)(n>0)
 */
#include <stdio.h>

/*
 * 递归函数计算
 * @param int n
 * @param int m
 * @return int 计算结果
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
 * 非递归函数计算
 * @param int n
 * @param int m
 * @return int 计算结果
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
	printf("请输入m:");
	scanf("%d",&m);
	printf("请输入n:");
	scanf("%d",&n);
	printf("递归计算结果为:%d\n",calculate1(n,m));
	printf("非递归计算结果为:%d\n",calculate2(n,m));
	return 0;
}
