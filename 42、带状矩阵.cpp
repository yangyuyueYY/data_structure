/*
 * ��д����n�����ʹ�״����A�����n�����ʹ�״�ƾ�����㷨
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ��������ʾn�����ͶԳƾ���
 * @param int *a ����
 * @param int *n �������
 * @return int �Ƿ�ɹ���0�ɹ���1ʧ��
 */
int create(int *a,int n)
{
	int i,j,w;
	printf("������������:");
	scanf("%d",&n);
	printf("������������:");
	scanf("%d",&w);
	a = (int *)malloc(n*w*sizeof(int));
	printf("�������״����:");
	for(i=0;i<n;i++){
		for(j=0;j<w;j++){
			scanf("%d",a+i*w+j);
		}
	}
	printf("����Ϊ:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<i-(w-1)/2 || j>i+(w-1)/2){
				printf("0 ");
			}else{
				printf("%d ",*(a+i*w+j-i+1));
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,*a;
	create(a,n);
	return 0;
}

/*
5
3
0 1 2
3 4 5
6 7 8
9 1 2
3 4 0
*/
