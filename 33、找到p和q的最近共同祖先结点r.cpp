/*
 * 设一棵二叉树的结点结构为(lchild,data,rchild)，root为指向该二叉树根结点的指针
 * p和q分别为指向该二叉树中任意两个结点的指针，试编写以算法ancestor(root,p,q,r)
 * 该算法找到p和q的最近共同祖先结点r
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

/* 
 * 递归创建二叉树的二叉链表结构
 * @param Tree *T 二叉树根结点指针
 * @return int 是否创建成功,0成功，-1失败
 */
int createTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#'){
		*T = NULL;
	}
	else{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
	return 0;
}

/*
 * 二叉树的先序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void preDisplay(Tree T)
{
	if(T){
		printf("\n%c:%p",T->data,T);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * 求结点的父结点
 * @param Tree T 根结点
 * @param Tree p 待查找结点
 * @param Tree *q 父结点
 * @return int 是否成功
 */ 
int parent(Tree T,Tree p,Tree *q)
{
	if(T){
		if(T->lchild == p || T->rchild == p){
			*q = T;
			return 0;
		}else{
			parent(T->lchild,p,q);
			parent(T->rchild,p,q);
		}
	}
	return 0;
}

/*
 * 求结点的所有祖先结点
 * @param Tree T 根结点
 * @param Tree p 待查找结点
 * @param Tree *q 祖先结点数组
 * @return int 是否成功
 */
int allAncestor(Tree T,Tree p,Tree *q)
{
	int i=0;
	Tree s = NULL;
	parent(T,p,&s);
	if(s == NULL){
		return -1;
	}else{
		while(s){
			q[i] = s;
			i ++;
			p = s;	
			s = NULL;
			parent(T,p,&s);
		}
	}
	return 0;
}

/*
 * 求最近共同祖先结点
 * @param Tree T 根结点
 * @param Tree p 第一个结点
 * @param Tree q 第二个结点
 * @param Tree *r 共同祖先结点
 * @return int 是否找到，0找到，-1找不到
 */
int ancestor(Tree T,Tree p,Tree q,Tree *r)
{
	Tree m[20],n[20];
	int i,j;
	for(i=0;i<20;i++){
		m[i] = NULL;
		n[i] = NULL;
	}
	allAncestor(T,p,m);
	allAncestor(T,q,n);
	for(i=0;i<20 && m[i]!=NULL;i++){
		for(j=0;j<20 && n[j]!=NULL;j++){
			if(m[i] == n[j]){
				*r = m[i];
				return 0;
			}
		}
	}
}

/*
 * 结点定位
 * @param Tree T 根结点
 * @param char x 数据
 * @param Tree *p地址
 */
int position(Tree T,char x,Tree *p)
{
	if(T){
		if(T->data == x){
			*p = T;
		}else{
			position(T->lchild,x,p);
			position(T->rchild,x,p);
		}
	}
	return 0;
}

int main()
{
	Tree T,p,q,r=NULL;
	char x,y;
	printf("请输入创建字符串:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	getchar();
	printf("请输入两结点:");
	scanf("%c%c",&x,&y);
	position(T,x,&p);
	position(T,y,&q);
	printf("%c:%p\n",x,p);
	printf("%c:%p\n",y,q);
	ancestor(T,p,q,&r);
	if(r == NULL){
		printf("无共同祖先!\n");
	}else{
		printf("最近共同祖先为%c!\n",r->data);
	}
	return 0;
}

/*
ABC##DE#G##F###
*/