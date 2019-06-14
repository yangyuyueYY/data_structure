/*
 * ��ֵת������д���򣬽�ʮ��������Nת��Ϊd����������ת���������ظ�����������ֱ��N����0
 * X = N mod d��N = N div d
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
	printf("������ʮ��������:");
	scanf("%d",&n);
	printf("������ת����Ľ���:");
	scanf("%d",&d);
	change(n,d,a);
	m = strlen(a);
	for(i=m-1;i>=0;i--){
		printf("%c",a[i]);
	}
	putchar('\n');
	return 0;
}
