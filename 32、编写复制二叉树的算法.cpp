/*
 * 编写复制二叉树的算法
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
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * 二叉树复制
 * param Tree T1 源二叉树
 * param Tree *T2 目标二叉树
 * return int 是否复制成功，0成功，-1失败
 */
int copy(Tree T1,Tree *T2)
{
	if(T1 == NULL){
		*T2 = NULL;
		return 0;
	}
	*T2 = (Tree)malloc(sizeof(Node));
	if(*T2 == NULL){
		return -1;
	}
	(*T2)->data = T1->data;
	copy(T1->lchild,&(*T2)->lchild);
	copy(T1->rchild,&(*T2)->rchild);
	return 0;
}

int main()
{
	Tree T1,T2;
	printf("请输入创建字符串:");
	if(0 == createTree(&T1)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T1);
	putchar('\n');
	if(0 == copy(T1,&T2)){
		printf("复制成功!\n");
	}else{
		printf("复制失败!\n");
		return -1;
	}
	printf("先序遍历为:");
	preDisplay(T2);
	putchar('\n');
}

/*
ABC##DE#G##F###
*/