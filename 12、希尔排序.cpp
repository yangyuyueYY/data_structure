/*
 * ϣ������
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ����Ϊd��һ��ϣ������
 * @param int *a ����
 * @param int n ���ݸ���
 * @param int d ����
 * @return int �Ƿ�����ɹ�
 */ 
int shellPass(int *a,int n,int d)
{
	int i,j,k;
	for(i=1;i<=d;i++){
		for(j=i+d;j<=n;j=j+d){
			a[0] = a[j];
			for(k=j-d;k>=0;k=k-d){
				if(a[k] > a[0]){
					a[k+d] = a[k];
				}else{
					a[k+d] = a[0];
					break;
				}
			}
			if(k<0){
				a[k+d] = a[0];
			}
		}
	}
	return 0;
}

/*
 * ϣ������
 * @param int *a ����
 * @param int n ���ݸ���
 * @param int *d ��������
 * @param int m ��������Ԫ�ظ���
 * @return int �Ƿ�����ɹ�
 */
int shellSort(int *a,int n,int *d,int m)
{
	int i,j;
	for(i=0;i<m;i++){
		printf("��%d��ϣ�����򣨲���Ϊ%d):",i+1,d[i]);
		shellPass(a,n,d[i]);
		for(j=1;j<=n;j++){
			printf("%d ",a[j]);
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	int n,i;
	int *a,d[3]={5,3,1};
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
	printf("ϣ������:\n");
	if(0 == shellSort(a,n,d,3)){
	}else{
		printf("����ʧ��!\n");
	}
	return 0;
}

/*
14
39 80 76 41 13 29 50 78 30 11 100 7 41 86
*/

