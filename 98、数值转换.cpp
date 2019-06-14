/*
 * 数值转换。编写程序，将十进制整数N转换为d进制数，其转换步骤是重复以下两步，直到N等于0
 * X = N mod d，N = N div d
 */
#include <stdio.h>
#include <string.h>

int change(int n,int d,char *a)
{
	char y;
	int x,i=0;
	while(n > 0){
		x = n % d;
		n = n / d;
		if(x >= 10){
			y = (x - 10) + 'A';
		}else{ 
			y = x + '0';
		}
		a[i] = y;
		i++;
	}
	a[i] = '\0';
	return 0;
}

int main()
{
	int n,d,i,m;
	char a[20];
	printf("请输入十进制整数:");
	scanf("%d",&n);
	printf("请输入转换后的进制:");
	scanf("%d",&d);
	change(n,d,a);
	m = strlen(a);
	for(i=m-1;i>=0;i--){
		printf("%c",a[i]);
	}
	putchar('\n');
	return 0;
}
