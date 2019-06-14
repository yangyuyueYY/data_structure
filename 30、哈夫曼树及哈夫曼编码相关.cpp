/*
 * 哈夫曼树及哈夫曼编码相关：已知n个字符的权值，生成一棵哈夫曼树；求叶子结点的哈夫曼编码
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char data;
	int weight;
	int parent;
	int lch,rch;
}Node;

typedef char ** code;

/*
 * 挑选结点构造树
 * @param Node *ht 结点数组
 * @param int n 结点个数
 * @param int *s1 左孩子编号
 * @param int *s2 右孩子编号
 */
void select(Node *ht,int n,int *s1,int *s2)
{
	int i,min;
	min = 100;
	for(i=1;i<2*n;i++){
		if(ht[i].parent == 0 && ht[i].weight < min && ht[i].weight != 0){
			*s1 = i;
			min = ht[i].weight;
		}
	}
	min = 100;
	for(i=1;i<2*n;i++){
		if(ht[i].parent == 0 && ht[i].weight < min && ht[i].weight != 0 && i != (*s1)){
			*s2 = i;
			min = ht[i].weight;
		}
	}
}

/*
 * 生成一棵哈夫曼树
 * @param int *w 权重数组
 * @param char *d 数据数组
 * @param int n 结点数
 * @param Node *ht 结点数组
 * @return int 是否生成成功，0成功，-1失败
 */
int huffTree(int *w,char *d,int n,Node *ht)
{
	int i,s1,s2;
	for(i=1;i<2*n;i++)
	{
		if(i>=1 && i<=n){
			ht[i].data = d[i-1];
			ht[i].weight = w[i-1];
		}else{
			ht[i].data = '#';
			ht[i].weight = 0;
		}
		ht[i].parent = 0;
		ht[i].lch = 0;
		ht[i].rch = 0;
	}
	for(i=n+1;i<2*n;i++)
	{
		select(ht,n,&s1,&s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].lch = s1;
		ht[i].rch = s2;
		ht[s1].parent = i;
		ht[s2].parent = i;
	}
	return 0;
}

/*
 * 求叶子结点的哈夫曼编码
 * @param code *hcd 哈夫曼编码字符串数组
 * @param Node *ht 哈夫曼树数组
 * @param int n 结点个数
 */
void huffCode(code *hcd,Node *ht,int n)
{
	char *cd;
	int i,start,f,c;
	*hcd = (code)calloc(n+1,sizeof(char *));
	cd = (char *)calloc(n,sizeof(char));
	for(i=1;i<=n;i++){
		cd[n-1] = '\0';
		start = n-1;
		c = i;
		f = ht[c].parent;
		while(f != 0){
			if(ht[f].lch == c){
				cd[--start] = '0';
			}else{
				cd[--start] = '1';
			}
			c = f;
			f = ht[f].parent;
		}
		(*hcd)[i] = (char*)malloc((n-start)*sizeof(char));
		strcpy((*hcd)[i],&cd[start]);
	}
}

int main()
{
	int *w,n,i;
	char d[20];
	Node *ht;
	code hcd;
	printf("请输入数据字符串:");
	scanf("%s",d);
	n = strlen(d);
	ht = (Node *)malloc(2*n*sizeof(Node));
	w = (int *)calloc(n,sizeof(int));
	printf("请输入%d个数据的权重:",n);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	if(0 == huffTree(w,d,n,ht)){
		printf("哈夫曼树构造成功!\n");
	}else{
		printf("哈夫曼树构造失败!\n");
	}
	for(i=1;i<2*n;i++){
		printf("%c %d %d %d %d\n",ht[i].data,ht[i].weight,ht[i].parent,ht[i].lch,ht[i].rch);
	}
	printf("叶子结点哈夫曼编码为:\n");
	huffCode(&hcd,ht,n);
	for(i=1;i<=n;i++){
		printf("%c:%s\n",ht[i].data,hcd[i]);
	}
	return 0;
}

/*
ABCDSTUV
5 29 7 8 14 23 3 11
*/

