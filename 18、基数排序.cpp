/*
 * 基数排序
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int data;
	int next;
}Data;

/*
 * 基数排序
 * @param Data *a 数据链
 * @param int n 数据个数
 * @param int m 数据位数
 */
void  baseSort(Data *a,int n,int m)
{
	Data b[10],*c;
	int i,j,t,k,y,p;
	c = (Data *)malloc(n*sizeof(Data));
	for(i=0;i<10;i++){
		b[i].data = i;
	}
	t = 1;
	for(i=0;i<m;i++){
		for(j=0;j<10;j++){
			b[j].next = -1;
		}
		for(j=0;j<n;j++){
			p = b[(a[j].data/t)%10].next;
			if(p!=-1){
				while(a[p].next != -1){
					p = a[p].next;
				}
				a[j].next = a[p].next;
				a[p].next = j;
			}else{
				a[j].next = -1;
				b[(a[j].data/t)%10].next = j;
			}
		}
		y = 0;
		for(j=0;j<10;j++){
			k = b[j].next;
			while(k!=-1){
				c[y].data = a[k].data;
				c[y].next = -1;
				y ++;
				k = a[k].next;
			}
		}
		for(j=0;j<n;j++){
			a[j] = c[j];
			printf("%d ",a[j]);
		}
		putchar('\n');
		t = t * 10;
	}
}

int main()
{
	int n,i,m;
	Data *a;
	printf("请输入元素个数:");
	scanf("%d",&n);
	a = (Data*)malloc((n)*sizeof(Data));
	if(a == NULL){
		return -1;
	}
	printf("请输入元素位数:");
	scanf("%d",&m);
	printf("请输入%d个整数:",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].data);
		a[i].next = -1;
	}
	printf("排序前:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	printf("排序后:\n");
	baseSort(a,n,m);
	putchar('\n');
	return 0;
}

/*
8
3
027 114 253 809 916 357 483 009
*/
