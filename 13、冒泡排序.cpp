/*
 * ð������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ð������
 * @param int *a ����
 * @param int n ���ݸ���
 * @return int �Ƿ�����ɹ�
 */
int bubbleSort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
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
	if(0 == bubbleSort(a,n)){
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
8
23 14 18 25 3 27 19 25
*/

