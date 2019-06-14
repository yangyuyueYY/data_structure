/*
 * 平衡二叉树：插入、删除、查找
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	int bf;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

/* 
 * 平衡二叉树的查找
 * @param Tree T 二叉树
 * @param int k 待查找数据
 * @param Tree *p 查找路径访问的最后一个结点
 * @param Tree *f 当前访问结点的双亲
 * @return int 是否找到，0找不到，1找到
 */
int search(Tree T,int k,Tree *p,Tree *f)
{
	if(NULL == T){
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
 * LL型调整
 * @param Tree *T根结点
 */
void LL_Rotate(Tree *T)
{
	Tree p;
	p = (*T)->lchild;
	(*T)->lchild = p->rchild;
	p->rchild = *T;
	(*T)->bf = 0;
	p->bf = 0;
	*T = p;
}

/*
 * RR型调整
 * @param Tree *T根结点
 */
void RR_Rotate(Tree *T)
{
	Tree p;
	p = (*T)->rchild;
	(*T)->rchild = p->lchild;
	p->lchild = *T;
	(*T)->bf = 0;
	p->bf = 0;
	*T = p;
}

/*
 * LR型调整
 * @param Tree *T根结点
 */
void LR_Rotate(Tree *T)
{
	Tree p1,p2;
	p1 = (*T)->lchild;
	p2 = p1->rchild;
	p1->rchild = p2->lchild;
	(*T)->lchild = p2->rchild;
	p2->lchild = p1;
	p2->rchild = *T;
	if(p2->bf == 1){
		(*T)->bf = -1;
		p1->bf = 0;
	}else if(p2->bf == 0){
		(*T)->bf = 0;
		p1->bf = 0;
	}else{
		(*T)->bf = 0;
		p1->bf = 1;
	}
	p2->bf = 0;
	*T = p2;
}

/*
 * RL型调整
 * @param Tree *T根结点
 */
void RL_Rotate(Tree *T)
{
	Tree p1,p2;
	p1 = (*T)->rchild;
	p2 = p1->lchild;
	p1->lchild = p2->rchild;
	(*T)->rchild = p2->lchild;
	p2->rchild = p1;
	p2->lchild = *T;
	if(p2->bf == -1){
		(*T)->bf = 1;
		p1->bf = 0;
	}else if(p2->bf == 0){
		(*T)->bf = 0;
		p1->bf = 0;
	}else{
		(*T)->bf = 0;
		p1->bf = -1;
	}
	p2->bf = 0;
	*T = p2;
}

/*
 * 左处理
 * @param Tree *T 根结点
 * @param int *taller 高差
 */
void insLeftProcess(Tree *T,int *taller)
{
	Tree p;
	if((*T)->bf == 0){
		(*T)->bf = 1;
		*taller = 1;
	}else if((*T)->bf == -1){
		(*T)->bf = 0;
		*taller = 0;
	}else{
		p = (*T)->lchild;
		if(p->bf == 1){
			LL_Rotate(T);
		}else if(p->bf == -1){
			LR_Rotate(T);
		}
		*taller = 0;
	}
}

/*
 * 右处理
 * @param Tree *T 根结点
 * @param int *taller 高差
 */
void insRightProcess(Tree *T,int *taller)
{
	Tree p;
	if((*T)->bf == 0){
		(*T)->bf = -1;
		*taller = 1;
	}else if((*T)->bf == 1){
		(*T)->bf = 0;
		*taller = 0;
	}else{
		p = (*T)->rchild;
		if(p->bf == -1){
			RR_Rotate(T);
		}else if(p->bf == 1){
			RL_Rotate(T);
		}
		*taller = 0;
	}
}

/*
 * 平衡二叉树的插入
 * @param Tree *T 根结点
 * @param Tree s 插入结点
 * @param int *taller 高度差
 * @return int 是否插入成功
 */
int insert(Tree *T,Tree s,int *taller)
{
	if((*T) == NULL){
		s->lchild = NULL;
		s->rchild = NULL;
		s->bf = 0;
		*T = s;
		*taller = 1;
	}else if(s->data == (*T)->data){
		*taller = 0;
		return 0;
	}else if(s->data < (*T)->data){
		if(insert(&(*T)->lchild,s,taller) == 0){
			return 0;
		}
		if(*taller == 1){
			insLeftProcess(T,taller);
		}
	}else{
		if(insert(&(*T)->rchild,s,taller) == 0){
			return 0;
		}
		if(*taller == 1){
			insRightProcess(T,taller);
		}
	}
	return 1;
}

/*
 * 平衡二叉树的构造
 * @param Tree *T 根结点
 * @return int 是否构建成功 
 */
int create(Tree *T)
{
	int n,i,k,taller;
	Tree s;
	*T = NULL;
	printf("请输入结点数:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("请输入第%d个数据:",i+1);
		scanf("%d",&k);
		s = (Tree)malloc(sizeof(Node));
		if(s == NULL){
			return -1;
		}
		s->bf = 0;
		s->lchild = NULL;
		s->rchild = NULL;
		s->data = k;
		if(0 == insert(T,s,&taller)){
			return -1;
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
		printf("%d ",T->data);
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
		printf("%d ",T->data);
		midDisplay(T->rchild);
	}
}

/*
 * 删除左处理函数
 * @param Tree *p根结点
 * @param int *taller 高度变化
 */
void delLeftProcess(Tree *p,int *taller)
{
	Tree p1,p2;
	if((*p)->bf == 1){
		(*p)->bf = 0;
		*taller = 1;
	}else if((*p)->bf == 0){
		(*p)->bf = -1;
		*taller = 0;
	}else{
		p1 = (*p)->rchild;
		if(p1->bf == 0){
			(*p)->rchild = p1->lchild;
			p1->lchild = *p;
			p1->bf = 1;
			(*p)->bf = -1;
			*p = p1;
			*taller = 0;
		}else if(p1->bf == -1){
			(*p)->rchild = p1->lchild;
			p1->lchild = *p;
			(*p)->bf = 0;
			p1->bf = 0;
			*p = p1;
			*taller = 1;
		}else{
			p2 = p1->lchild;
			p1->lchild = p2->rchild;
			p2->rchild = p1;
			(*p)->rchild = p2->lchild;
			p2->lchild = *p;
			if(p2->bf == 0){
				(*p)->bf = 0;
				p1->bf = 0;
			}else if(p2->bf == -1){
				(*p)->bf = 1;
				p1->bf = 0;
			}else{
				(*p)->bf = 0;
				p1->bf = -1;
			}
			p2->bf = 0;
			*p = p2;
			*taller =1;
		}
	}
}

/*
 * 删除右处理函数
 * @param Tree *p 根结点
 * @param int *taller 高度差
 */
void delRightProcess(Tree *p,int *taller)
{
	Tree p1,p2;
	if((*p)->bf == -1){
		(*p)->bf = 0;
		*taller = -1;
	}else if((*p)->bf == 0){
		(*p)->bf = 1;
		*taller = 0;
	}else{
		p1 = (*p)->lchild;
		if(p1->bf == 0){
			(*p)->lchild = p1->rchild;
			p1->rchild = *p;
			p1->bf = -1;
			(*p)->bf = 1;
			*p = p1;
			*taller = 0;
		}else if(p1->bf == 1){
			(*p)->lchild = p1->rchild;
			p1->rchild = *p;
			(*p)->bf = 0;
			p1->bf = 0;
			*p = p1;
			*taller = 1;
		}else{
			p2 = p1->rchild;
			p1->rchild = p2->lchild;
			p2->lchild = p1;
			(*p)->lchild = p2->rchild;
			p2->rchild = *p;
			if(p2->bf == 0){
				(*p)->bf = 0;
				p1->bf = 0;
			}else if(p2->bf == 1){
				(*p)->bf = -1;
				p1->bf = 0;
			}else{
				(*p)->bf = 0;
				p1->bf = 1;
			}
			p2->bf = 0;
			*p = p2;
			*taller = 1;
		}
	}
}

/*
 * 删除结点函数
 * @param Tree q结点
 * @param Tree *T q的左子树根
 * @param int *taller 高度变化
 */
void del(Tree q,Tree *T,int *taller)
{
	if((*T)->rchild == NULL){
		q->data = (*T)->data;
		q = *T;
		*T = (*T)->lchild;
		delete q;
		*taller = 1;
	}else{
		del(q,&(*T)->rchild,taller);
		if(*taller == 1){
			delRightProcess(T,taller);
		}
	}
}

/* 
 * 平衡二叉树的删除
 * @param Tree *T 根结点
 * @param int x 删除数据
 * @param int *taller 高度变化
 * @return int 是否删除成功
 */
int deleteTree(Tree *T,int x,int *taller)
{
	int k;
	Tree q;
	if((*T)==NULL){
		return 0;
	}else if(x<(*T)->data){
		k = deleteTree(&(*T)->lchild,x,taller);
		if(*taller == 1){
			delLeftProcess(T,taller);
			return k;
		}
	}else if(x>(*T)->data){
		k = deleteTree(&(*T)->rchild,x,taller);
		if(*taller == 1){
			delRightProcess(T,taller);
			return k;
		}
	}else{
		q = *T;
		if((*T)->rchild == NULL){
			*T = (*T)->lchild;
			delete q;
			*taller = 1;
		}else if((*T)->lchild == NULL){
			*T = (*T)->rchild;
			delete q;
			*taller = 1;
		}else{
			del(q,&q->lchild,taller);
			if(*taller == 1){
				delLeftProcess(&q,taller);
			}
			*T = q;
		}		
	}
	return 1;
}

int main()
{
	Tree T,p=NULL;
	int i=0,taller;
	if(0 == create(&T)){
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
	printf("请输入删除数据:");
	scanf("%d",&i);
	deleteTree(&T,i,&taller);
	printf("删除后先序遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("删除后中序遍历为:");
	midDisplay(T);
	putchar('\n');
	printf("请输入查找数据:");
	scanf("%d",&i);
	if(1 == search(T,i,&T,&p)){
		printf("数据存在!\n");
	}else{
		printf("数据不存在!\n");
	}
	return 0;
}

/*
7
13
24
37
90
53
28
98
*/