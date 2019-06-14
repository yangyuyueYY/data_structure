/*
 * ֱ�Ӳ�������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ֱ�Ӳ�������
 * @param int *a ����
 * @param int n ���ݸ���
 * @return int �Ƿ�����ɹ�
 */
int straightSort(int *a,int n)
{
	int i,j;
	for(i=2;i<=n;i++){
		a[0] = a[i];
		for(j=i-1;j>=0;j--){
			if(a[j] > a[0]){
				a[j+1] = a[j];
			}else{
				a[j+1] = a[0];
				break;
			}
		}
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
	if(0 == straightSort(a,n)){
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
10
26 18 20 18 38 30 20 23 31 29
*/

