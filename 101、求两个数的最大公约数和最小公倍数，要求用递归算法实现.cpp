/*
 * 求两个数的最大公约数和最小公倍数，要求用递归算法实现
 */

#include <stdio.h>

/*
 * 递归求最大公约数
 * @param int m
 * @param int n
 * @return int 最大公约数
 */
int maxyue(int m,int n)
{
	int x;
	if(m % n == 0){
		return n;
	}else{
		x = m%n;
		m = n;
		n = x;
		return(maxyue(m,n));
	}
}

int main()
{
	int m,n,t;
	printf("请输入两个数:");
	scanf("%d%d",&m,&n);
	if(m<n){
		t = m;
		m = n;
		n = t;
	}
	t = maxyue(m,n);
	printf("最大公约数为:%d\n",t);
	t = m * n / t;
	printf("最小公倍数为:%d\n",t);
	return 0;
}