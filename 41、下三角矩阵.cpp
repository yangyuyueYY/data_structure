/*
 * ��д����n�����������Ǿ���A�����n�����������Ǿ�����㷨
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ��������ʾn�����������Ǿ���
 * @param int *a ����
 * @param int *n �������
 * @return int �Ƿ�ɹ���0�ɹ���1ʧ��
 */
int create(int *a,int *n)
{
	int m,i,j;
	printf("������������:");
	scanf("%d",n);
	m = (*n)*((*n)+1)/2+1;
	a = (int *)malloc(m*sizeof(int));
	printf("�밴��˳�����������Ǿ���:");
	for(i=0;i<m-1;i++){
		scanf("%d",&a[i]);
	}
	printf("����������������:");
	scanf("%d",&a[m-1]);
	printf("����Ϊ:\n");
	for(i=0;i<*n;i++){
		for(j=0;j<*n;j++){
			if(i >= j){
				printf("%d ",a[i*(i+1)/2+j]);
			}else{
				printf("%d ",a[m-1]);
			}
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,*a;
	create(a,&n);
	return 0;
}

/*
5
3 6 2 4 8 1 7 4 6 0 8 2 9 5 7
*/
