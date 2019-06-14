/*
 * 递归解决Hanoi塔问题
 */
#include <stdio.h>

/*
 * 移动单个盘
 * @param char a 源盘
 * @param int n 盘号
 * @param char b 目标盘
 * @return int 是否移动成功,0为成功，-1为失败
 */
int move(char a,int n,char b)
{
	printf("将%c盘的%d号盘移到%c上\n",a,n,b);
	return 0;
}

/*
 * Hanoi塔递归函数
 * @param int n 盘数
 * @param char a 源盘
 * @param char b 辅助盘
 * @param char c 目标盘
 * @return int 是否成功，0成功，-1失败
 */
int hanoi(int n,char a,char b,char c)
{
	if(n == 1){
		move(a,1,c);
		return 0;
	}else{
		hanoi(n-1,a,c,b);
		move(a,n,c);
		hanoi(n-1,b,a,c);
	}
}

int main()
{
	int n;
	printf("请输入盘数:");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	return 0;
}