/*
 * 分块查找
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int num;
	int max;
}Data;

/*
 * 分块查找
 * @param Data *L 数据块
 * @parma int n 数据块个数
 * @param int x 待查找数据
 * @param int *pos 数据存放块内部位置
 * @return int 数据块编号,找不到为-1
 */
int search(Data *L,int n,int x,int *pos)
{
	int i,j;
	for(i=0;i<n;i++){
		if(L[i].max >= x){
			break;
		}
	}
	if(i == n){
		return -1;
	}
	for(j=0;j<L[i].num;j++)
	{
		if(L[i].data[j] == x){
			*pos = j+1;
			return i+1;	
		}
	}
	return -1;
}

int main()
{
	int n,i,m,max,j,pos,x,a;
	int *data;
	Data *L;
	printf("请输入块数:");
	scanf("%d",&n);
	L = (Data *)malloc(n*sizeof(Data));
	for(i=0;i<n;i++){
		printf("请输入第%d块元素个数及最大值:",i+1);
		scanf("%d%d",&m,&max);
		data = (int *)malloc(sizeof(int));
		L[i].max = max;
		L[i].num = m;
		printf("请输入第%d块的%d个数据",i+1,m);
		for(j=0;j<m;j++){
			scanf("%d",&data[j]);
		}
		L[i].data = data;
	}
	printf("数据为:");
	for(i=0;i<n;i++){
		printf("第%d块:最大值:%d\n",i+1,L[i].max);
		for(j=0;j<L[i].num;j++){
			printf("%d ",L[i].data[j]);
		}
		putchar('\n');
	}
	printf("请输入待查找数据:");
	scanf("%d",&x);
	if((a=search(L,n,x,&pos)) == -1){
		printf("数据%d不存在!\n",x);
	}else{
		printf("数据%d在第%d块的第%d个位置!\n",x,a,pos);
	}
	return 0;
}

/*
3
3 5
3 5 4
4 10
8 6 7 9
3 15
14 12 13
*/