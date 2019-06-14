/*
 * 树的基本操作：创建孩子链表及关系展示
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int child;
	struct node *next;
}CTNode,*ChildPtr;

typedef struct
{
	char data;
	ChildPtr link;
}CTbox;

typedef struct
{
	CTbox *nodes;
	int n;
	int r;
}ChildList;

/*
 * 创建孩子链表
 * @param ChildList *T 孩子链表指针
 * @return int 是否创建成功，0成功，-1失败
 */
int createTree(ChildList *T)
{
	int n,i,t,j,k;
	char father,child;
	char a[20];
	ChildPtr s,p;
	printf("请输入结点数:");
	scanf("%d",&n);
	T->n = n;
	T->nodes = (CTbox *)malloc(n * sizeof(CTbox));
	if(T->nodes == NULL){
		return -1;
	}
	T->r = 0;
	printf("请输入%d个结点数据:",n);
	scanf("%s",a);
	for(i=0;i<n;i++){
		T->nodes[i].data = a[i];
		T->nodes[i].link = NULL;
	}
	printf("请按格式(双亲，孩子)输入%d个分支(从上到下，从左到右):\n",n-1);
	for(i=0;i<n-1;i++){
		getchar();
		printf("第%d条边:",i+1);
		scanf("%c,%c",&father,&child);
		for(j=0;j<n;j++){
			if(T->nodes[j].data == father){
				break;
			}
		}
		if(j == n){
			return -1;
		}
		for(k=j;k<n;k++){
			if(T->nodes[k].data == child){
				break;
			}
		}
		if(k == n){
			return -1;
		}
		p = T->nodes[j].link;
		s = (ChildPtr)malloc(sizeof(CTNode));
		if(s == NULL){
			return -1;
		}
		s->child = k;
		s->next = NULL;
		if(p == NULL){
			T->nodes[j].link = s;
		}else{
			while(p->next){
				p = p->next;
			}
			p->next = s;
		}
	}
	return 0;
}

/*
 * 关系展示
 * @param ChildList T 孩子链表
 */
void display(ChildList T)
{
	int i;
	ChildPtr p;
	for(i=0;i<T.n;i++){
		printf("%c",T.nodes[i].data);
		p = T.nodes[i].link;
		while(p){
			printf("--%c",T.nodes[p->child].data);
			p = p->next;
		}
		putchar('\n');
	}
}

int main()
{
	ChildList T;
	createTree(&T);
	printf("关系展示:\n");
	display(T);
	return 0;
}
/*
9
abcdefghi
a,b
a,c
b,d
b,e
c,f
e,g
e,h
e,i
*/