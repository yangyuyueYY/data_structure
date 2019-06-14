/*
 * ��������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * һ�ο�������
 * @param int *a ����
 * @param int n ���ݸ���
 * @param int low ��λ
 * @param int high ��λ
 * @param int *count ������
 * @return int �Ƿ�����ɹ�
 */
int partition(int *a,int n,int low,int high,int *count)
{
	int i;
	a[0] = a[low];
	while(low < high){
		while(low < high && a[high] >= a[0]){
			high --;
		}
		a[low] = a[high];
		while(low < high && a[low] <= a[0]){
			low ++;
		}
		a[high] = a[low];
	}
	a[low] = a[0];
	printf("��%d�ο�������:",*count);
	(*count)++;
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return low;
}

/*
 * ��������
 * @param int *a ����
 * @param int n ���ݸ���
 * @param int low ��λ
 * @param int high ��λ
 * @param int *count ������
 * @return int �Ƿ�����ɹ�
 */ 
int fastSort(int *a,int n,int low,int high,int *count)
{
	int p;
	if(low < high){
		p = partition(a,n,low,high,count);
		fastSort(a,n,low,p-1,count);
		fastSort(a,n,p+1,high,count);
	}
	return 0;
}

int main()
{
	int n,i;
	int *a,count = 1;
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
	printf("�����:\n");
	if(0 == fastSort(a,n,1,n,&count)){
		
	}else{
		printf("����ʧ��!\n");
	}
	return 0;
}

/*
8
70 73 70 23 93 18 11 68
*/

