/*
 * �������������Լ������С��������Ҫ���õݹ��㷨ʵ��
 */

#include <stdio.h>

/*
 * �ݹ������Լ��
 * @param int m
 * @param int n
 * @return int ���Լ��
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
	printf("������������:");
	scanf("%d%d",&m,&n);
	if(m<n){
		t = m;
		m = n;
		n = t;
	}
	t = maxyue(m,n);
	printf("���Լ��Ϊ:%d\n",t);
	t = m * n / t;
	printf("��С������Ϊ:%d\n",t);
	return 0;
}