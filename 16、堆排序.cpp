/*
 * ������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ����С����
 * @param int *a ����
 * @param int s �����
 * @param int m ���ݸ���
 * @return int �Ƿ���ɹ�
 */
int heapAdjust(int *a,int s,int m)
{
	int j,t;
	t = a[s];
	for(j=2*s;j<=m;j=j*2){
		if(j<m && a[j] < a[j+1]){
			j ++;
		}
		if(t >= a[j]){
			break;
		}
		a[s] = a[j];
		s = j;
	}
	a[s] = t;
	return 0;
}

/*
 * ������
 * @param int *a ����
 * @param int n ���ݸ���
 * @return int �Ƿ�����ɹ�
 */
int heapSort(int *a,int n)
{
	int t,i;
	for(i=n/2;i>0;i--){
		heapAdjust(a,i,n);
	}
	for(i=n;i>1;i--){
		t = a[i];
		a[i] = a[1];
		a[1] = t;
		heapAdjust(a,1,i-1);
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
	if(0 == heapSort(a,n)){
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
49 38 65 97 76 13 27 49
*/

