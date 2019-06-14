/*
 * 双亲表示法作为树的存储结构，编写求树的高度的算法
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char data;
	int parent;
}Node;

typedef struct
{
	Node *node;
	int n;
	int r;
}Tree;

/*
 * 求树的深度
 * @param Tree T 树
 * @return int 树的深度
 */
int depth(Tree T)
{
	int i,max = 1,d,j;
	for(i=T.n;i>0;i--){
		d = 1;
		j = i;
		while(T.node[j].parent > 0){
			d ++;
			j = T.node[j].parent;
		}
		if(d > max){
			max = d;
		}
	}
	return max;
}

int main()
{
	int n,i;
	Tree T;
	printf("请输入结点数:");
	scanf("%d",&n);
	T.node = (Node *)malloc((n+1)*sizeof(Node));
	if(T.node == NULL){
		return -1;
	}
	T.n = n;
	T.r = 0;
	for(i=1;i<=n;i++){
		getchar();
		printf("请输入第%d个结点数据及父结点编号:",i);
		scanf("%c%d",&T.node[i].data,&T.node[i].parent);
	}
	printf("创建成功!\n");
	for(i=1;i<=n;i++){
		printf("%c %d\n",T.node[i].data,T.node[i].parent);
	}
	printf("树的深度为:%d\n",depth(T));
	return 0;
}
/*
9
a 0
b 1
c 1
d 2
e 2
f 3
g 5
h 5
i 5
*/
