/*
 * 线索二叉树的基本操作：建立一棵中序线索二叉树；在中序线索二叉树上查找任意节点的中序前驱结点；
 * 查找任意节点的中序后继结点；查找任意结点在先序下的后继；查找任意结点在后序下的前驱
 * 查找值为x的结点；更新；先序遍历；中序遍历；后序遍历
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	int ltag,rtag;
	struct node *lchild,*rchild;
}Node,*Tree;

/*
 * 线索化算法
 * @param Tree p 根结点
 * @param Tree *pre 中序前驱结点
 */
void inTreading(Tree p,Tree *pre)
{
	if(p){
		inTreading(p->lchild,pre);
		if(p->lchild == NULL){
			p->ltag = 1;
			p->lchild = *pre;
		}else{
			p->ltag = 0;
		}
		if((*pre)->rchild == NULL){
			(*pre)->rtag = 1;
			(*pre)->rchild = p;
		}else{
			(*pre)->rtag = 0;
		}
		*pre = p;
		inTreading(p->rchild,pre);
	}
}

/*
 * 给线索二叉树添加头结点，线索化
 * @param Tree *head 头结点
 * @param Tree T 头指针
 * @return int 是否添加成功，0成功，-1失败
 */
int inOrderThr(Tree *head,Tree T)
{
	Tree p;
	*head = (Tree)malloc(sizeof(Node));
	if((*head) == NULL){
		return -1;
	}
	(*head)->data = ' ';
	(*head)->lchild = T;
	(*head)->ltag = 0;
	(*head)->rchild = *head;
	(*head)->rtag = 1;
	if(T == NULL){
		(*head)->lchild = *head;
	}else{
		p = *head;
		inTreading(T,&p);
		p->rchild = *head;
		p->rtag = 1;
		(*head)->rchild = p;
	}
	return 0;
}

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
 * 在中序线索二叉树上查找任意节点的中序前驱结点
 * @param Tree p 待查找结点
 * @return Tree 目标结点
 */
Tree inPreNode(Tree p)
{
	Tree pre;
	pre = p->lchild;
	if(p->ltag == 0){
		while(pre->rtag == 0){
			pre = pre->rchild;
		}
	}
	return pre;
}

/*
 * 在中序线索二叉树上查找任意节点的中序后继结点
 * @param Tree p 待查找结点
 * @return Tree 目标结点
 */
Tree inPostNode(Tree p)
{
	Tree post;
	post = p->rchild;
	if(p->rtag == 0){
		while(post->ltag == 0){
			post = post->lchild;
		}
	}
	return post;
}

/*
 * 在中序线索二叉树上查找任意节点的先序后继结点
 * 若一个结点是某子树在中序下的最后一个结点，则它必是该子树在先序下的最后一个结点
 * 若该结点是分支结点，当p->ltag=0时，后继为p->lchild;p->ltag=1时，后继为p->rchild
 * 若该节点是叶子结点，当p->rchild=head，则其为最后一个结点，否则，其一定是p->rchild结点为根的左子树中序遍历的最后一个结点
 * 若p->rchild有右子树，则为p->rchild->child;否则，让p=p->rchild，重复操作
 ***********************************************
 * @param Tree p 待查找结点
 * @param Tree head 头结点
 * @return Tree 目标结点
 */
Tree iprePostNode(Tree p,Tree head)
{
	Tree post;
	if(p->ltag == 0){
		post = p->lchild;
	}else{
		post = p;
		while(post->rtag == 1 && post->rchild != head){
			post = post->rchild;
		}
		post = post->rchild;
	}
	return post;
}

/*
 * 在中序线索二叉树上查找任意节点的后序前驱结点
 * 若一个结点是某子树在中序下的第一个结点，则它必是该子树在后序下的第一个结点
 * 若该结点是分支结点，当p->ltag=0时，前驱为p->lchild;p->ltag=1时，前驱为p->rchild
 * 若该节点是叶子结点，当p->lchild=head，则其为第一个结点，否则，其一定是p->lchild结点为根的右子树中序遍历的第一个结点
 * 若p->lchild有左子树，则为p->lchild->lchild;否则，让p=p->lchild，重复操作
 ***********************************************
 * @param Tree p 待查找结点
 * @param Tree head 头结点
 * @return Tree 目标结点
 */
Tree ipostPreNode(Tree p,Tree head)
{
	Tree pre;
	if(p->rtag == 0){
		pre = p->rchild;
	}else{
		pre = p;
		while(pre->ltag == 1 && pre->lchild != head){
			pre = pre->lchild;
		}
		pre = pre->lchild;
	}
	return pre;
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

/*
 * 二叉树的后序遍历（递归）
 * @param Tree T 二叉树根结点
 */
void afterDisplay(Tree T)
{
	if(T){
		afterDisplay(T->lchild);
		afterDisplay(T->rchild);
		printf("%c",T->data);
	}
}

/*
 * 查找值为x的结点
 * @param Tree head 头结点
 * @param char x 待查找数据
 * @return Tree 目标地址
 */
Tree search(Tree head,char x)
{
	Tree p = head->lchild;
	while(p->ltag == 0 && p != head){
		p = p->lchild;
	}
	while(p != head && p->data != x){
		p = inPostNode(p);
	}
	return p;
}

/*
 * 基于中序线索二叉树的先序遍历
 * @param Tree head
 */
void preTreadDiasplay(Tree head)
{
	Tree p = head->lchild;
	while(p != head){
		printf("%c",p->data);
		p = iprePostNode(p,head);
	}
}

/*
 * 基于中序线索二叉树的中序遍历
 * @param Tree head
 */
void midTreadDiasplay(Tree head)
{
	Tree p = head->lchild;
	while(p->ltag == 0){
		p = p->lchild;
	}
	while(p != head){
		printf("%c",p->data);
		p = inPostNode(p);
	}
}

/*
 * 基于中序线索二叉树的后序遍历
 * @param Tree head
 */
void afterTreadDiasplay(Tree head)
{
	Tree p = head->lchild;
	char a[20];
	int i=0,j;
	while(p != head){
		a[i] = p->data;
		i ++;
		p = ipostPreNode(p,head);
	}
	for(j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}
}

/*
 * 更新：在中序线索二叉树中插入结点p使其成为结点s的右孩子
 * @param Tree p 待插入结点
 * @param Tree s 位置结点
 * @return int 是否更新成功，0成为，-1失败
 */
int insertThrRight(Tree p,Tree s)
{
	Tree w;
	p->lchild = s->lchild;
	p->ltag = s->ltag;
	p->rchild = s->rchild;
	p->rtag = s->rtag;
	s->rchild = p;
	s->rtag = 0;
	if(p->rtag == 0){
		w = inPostNode(p);
		w->lchild = p;
	}
	return 0;
}

int main()
{
	Tree T,head,p,q;
	char x;
	printf("请输入二叉树创建序列:");
	if(0 == createTree(&T)){
		printf("创建成功!\n");
	}else{
		printf("创建失败!\n");
		return -1;
	}
	printf("先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("中序遍历为:");
	midDisplay(T);
	putchar('\n');
	printf("后序遍历为:");
	afterDisplay(T);
	putchar('\n');
	if(0 == inOrderThr(&head,T)){
		printf("线索化成功!\n");
	}else{
		printf("线索化失败!\n");
		return -1;
	}
	getchar();
	printf("请输入待查找数据:");
	scanf("%c",&x);
	p = search(head,x);
	printf("其中序前驱结点为:");
	q = inPreNode(p);
	printf("%c\n",q->data);
	printf("其中序后继结点为:");
	q = inPostNode(p);
	printf("%c\n",q->data);
	printf("其先序后继结点为:");
	q = iprePostNode(p,head);
	printf("%c\n",q->data);
	printf("其后序前驱结点为:");
	q = ipostPreNode(p,head);
	printf("%c\n",q->data);
	printf("先序遍历为:");
	preTreadDiasplay(head);
	putchar('\n');
	printf("中序遍历为:");
	midTreadDiasplay(head);
	putchar('\n');
	printf("后序遍历为:");
	afterTreadDiasplay(head);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/