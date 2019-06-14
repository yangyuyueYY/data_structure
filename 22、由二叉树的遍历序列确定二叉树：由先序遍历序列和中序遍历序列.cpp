/*
 * 由二叉树的遍历序列确定二叉树：由先序遍历序列和中序遍历序列
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
 * 由二叉树的遍历序列确定二叉树：由先序遍历序列和中序遍历序列
 * @param Tree *T 二叉树根节点指针
 * @param char *pre 前序遍历序列
 * @param char *ino 中序遍历序列
 * @param int ps 前序序列起点
 * @param int is 中序遍历起点
 * @param int n 节点数
 * @return int 是否创建成功，0为成功，-1为失败
 */
int createTree(Tree *T,char *pre,char *ino,int ps,int is,int n)
{
	int k,i;
	Tree p;
	if(n == 0){
		*T = NULL;
	}else{
		for(i=0;i<n;i++){
			if(ino[is+i] == pre[ps]){
				k = is+i;
				break;
			}
		}
		if(i == n){
			*T = NULL;
		}else{
			*T = (Tree)malloc(sizeof(Node));
			if(NULL == *T){
				return -1;
			}
			(*T)->data = pre[ps];
			if(k == is){
				(*T)->lchild = NULL;
			}else{
				createTree(&(*T)->lchild,pre,ino,ps+1,is,k-is);
			}
			if(k == is+n-1){
				(*T)->rchild = NULL;
			}else{
				createTree(&(*T)->rchild,pre,ino,ps+1+(k-is),k+1,n-k+is-1);
			}
		}
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
 * 二叉树的中序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void midDisplay(Tree T)
{
	if(T){
		midDisplay(T->lchild);
		printf("%c",T->data);
		midDisplay(T->rchild);
	}
}

int main()
{
	Tree T;
	int n;
	char a[20],b[20];
	printf("请输入先序遍历序列:");
	scanf("%s",a);
	printf("请输入中序遍历序列:");
	scanf("%s",b);
	n = strlen(a);
	if(0 == createTree(&T,a,b,0,0,n)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("中序遍历为:");
	midDisplay(T);
	putchar('\n');
	return 0;
}

/*
ABDECF
DBEACF
*/
