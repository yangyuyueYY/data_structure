/*
 * 二叉排序树的查找、 插入、构造、删除
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

/* 
 * 二叉排序树的查找
 * @param Tree T 二叉树
 * @param int k 待查找数据
 * @param Tree *p 查找路径访问的最后一个结点
 * @param Tree *f 当前访问结点的双亲
 * @return int 是否找到，0找不到，1找到
 */
int search(Tree T,int k,Tree *p,Tree *f)
{
	if(T == NULL){
		*p = *f;
		return 0;
	}
	if(T->data == k){
		*p = T;
		return 1;
	}
	if(T->data < k){
		return search(T->lchild,k,p,&T);
	}else{
		return search(T->rchild,k,p,&T);
	}
}

/*
 * 二叉排序树的插入
 * @param Tree *T 二叉树
 * @param int k 待插入数据
 * @return int 是否插入成功
 */
int insert(Tree *T,int k)
{
	Tree s;
	if(*T == NULL){
		s = (Tree)malloc(sizeof(Node));
		if(s == NULL){
			return -1;
		}
		s->data = k;
		s->lchild = NULL;
		s->rchild = NULL;
		*T = s;
		return 0;
	}
	if((*T)->data < k){
		return insert(&((*T)->rchild),k);
	}else{
		return insert(&((*T)->lchild),k);
	}
}

/*
 * 二叉排序树的构造
 * @param Tree *T 二叉树
 * @return int 是否构造成功
 */
int create(Tree *T)
{
	int n,i,k;
	*T = NULL;
	printf("请输入数据个数:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("请输入第%d个数据:",i+1);
		scanf("%d",&k);
		if(-1 == insert(T,k)){
			return -1;
		}
	}
	return 0;
}

/*
 * 删除二叉排序树中某一个结点
 * @param Tree *p 待删结点
 * @return int 是否删除成功
 */
int del(Tree *p)
{
	Tree q,s;
	if((*p)->rchild == NULL){
		q = *p;
		*p = (*p)->lchild;
		free(q);
		return 0;
	}
	if((*p)->lchild == NULL){
		q = *p;
		*p = (*p)->rchild;
		free(q);
		return 0;
	}
	q = *p;
	s = (*p)->lchild;
	while(s->rchild){
		q = s;
		s = s->rchild;
	}
	(*p)->data = s->data;
	if(q != *p){
		q->rchild = s->lchild;
	}else{
		q->lchild = s->lchild;
	}
	free(s);
	return 0;
}

/*
 * 二叉排序树的删除
 * @param Tree *T 二叉树
 * @param int k 待删除数据
 * @return int 是否删除成功
 */
int deleteTree(Tree *T,int k)
{
	if(*T == NULL){
		return -1;
	}
	if((*T)->data == k){
		del(T);
		return 0;
	}
	if((*T)->data > k){
		return deleteTree(&(*T)->lchild,k);
	}else{
		return deleteTree(&(*T)->rchild,k);
	}
}

/*
 * 二叉树的先序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%d ",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

int main()
{
	Tree T;
	int i=0;
	if(0 == create(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("请输入删除数据:");
	scanf("%d",&i);
	deleteTree(&T,i);
	printf("删除后先序遍历为:");
	preDisplay(T);
	putchar('\n');
	return 0;
}

/*
12
50
30
20
10
25
23
40
35
80
90
85
88
20
*/