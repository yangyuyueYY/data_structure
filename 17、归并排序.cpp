/*
 * �鲢����
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * �ϲ�������������
 * @param int *sr ԭʼ����
 * @param int *tr ��������
 * @param int s ԭʼ����ǰ�����
 * @param int m ԭʼ����ǰ���յ�
 * @param int t ԭʼ���к���յ�
 */
void merge(int *sr,int *tr,int s,int m,int t)
{
	int i,j,k;
	i = s;
	j = m+1;
	k = s;
	while(i<=m && j<=t){
		if(sr[i] <= sr[j]){
			tr[k] = sr[i];
			k++;
			i++;
		}else{
			tr[k] = sr[j];
			k++;
			j++;
		}
	}
	while(i<=m){
		tr[k] = sr[i];
		k ++;
		i ++;
	}
	while(j<=t){
		tr[k] = sr[j];
		k ++;
		j ++;
	}
}

/*
 * ��ԭʼ�������������������кϲ�
 * @param int *sr ԭʼ����
 * @param int *tr ��������
 * @param int n �����
 * @param int len �����г���
 */
void mergePass(int *sr,int *tr,int n,int len)
{
	int first=1,last;
	while(first + len <= n){
		last = first + len*2 - 1;
		if(last > n){
			last = n;
		}
		merge(sr,tr,first,first+len-1,last);
		first = last +1;
	}
	while(first <= n){
		tr[first] = sr[first];
		first ++;
	}
}

/*
 * �鲢����
 * @param int *a ����
 * @param int n Ԫ�ظ���
 */
void mergeSort(int *a,int n)
{
	int m = 1,i;
	int *tr;
	tr = (int *)malloc((1+n)*sizeof(int));
	while(m<=n){
		mergePass(a,tr,n,m);
		for(i=1;i<=n;i++){
			a[i] = tr[i];
		}
		m = 2*m;
	}
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
	mergeSort(a,n);
	printf("�����:");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}

/*
9
46 55 13 42 94 5 17 70 60
*/