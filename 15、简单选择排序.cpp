/*
 * ��ѡ������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ��ѡ������
 * @param int *a ����
 * @param int n ���ݸ���
 * @return int �Ƿ�����ɹ�
 */
int selectSort(int *a,int n)
{
	int i,min,t,j,s;
	for(i=1;i<n;i++){
		min = a[i];
		s = i;
		for(j=i+1;j<=n;j++){
			if(a[j] < min){
				min = a[j];
				s = j;
			}
		}
		t = a[i];
		a[i] = a[s];
		a[s] = t;
	}
	return 0;
}

int main()
{
	int n,i;
	int *a;
	printf("������Ԫ�ظ���:");
	scanf("%d",&n);
	a = (int*)malloc((n+1)*sizeof(int));
	if(a == NULL){
		return -1;
	}
	printf("������%d������:",n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("����ǰ:");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	if(0 == selectSort(a,n)){
		printf("�����:");
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		putchar('\n');
	}else{
		printf("����ʧ��!\n");
	}
	return 0;
}

/*
7
37 18 64 14 96 48 41
*/

