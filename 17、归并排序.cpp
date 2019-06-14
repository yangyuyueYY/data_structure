/*
 * 归并排序
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 合并相邻两个序列
 * @param int *sr 原始序列
 * @param int *tr 生成序列
 * @param int s 原始序列前半起点
 * @param int m 原始序列前半终点
 * @param int t 原始序列后半终点
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
 * 将原始序列中两个相邻子序列合并
 * @param int *sr 原始序列
 * @param int *tr 生成序列
 * @param int n 起点标号
 * @param int len 子序列长度
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
 * 归并排序
 * @param int *a 序列
 * @param int n 元素个数
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
	printf("请输入元素个数:");
	scanf("%d",&n);
	a = (int*)malloc((n+1)*sizeof(int));
	if(a == NULL){
		return -1;
	}
	printf("请输入%d个整数:",n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("排序前:");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	mergeSort(a,n);
	printf("排序后:");
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