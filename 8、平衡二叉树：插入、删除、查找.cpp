/*
 * ƽ������������롢ɾ��������
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
 * ƽ��������Ĳ���
 * @param Tree T ������
 * @param int k ����������
 * @param Tree *p ����·�����ʵ����һ�����
 * @param Tree *f ��ǰ���ʽ���˫��
 * @return int �Ƿ��ҵ���0�Ҳ�����1�ҵ�
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
 * LL�͵���
 * @param Tree *T�����
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
 * RR�͵���
 * @param Tree *T�����
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
 * LR�͵���
 * @param Tree *T�����
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
 * RL�͵���
 * @param Tree *T�����
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
 * ����
 * @param Tree *T �����
 * @param int *taller �߲�
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
 * �Ҵ���
 * @param Tree *T �����
 * @param int *taller �߲�
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
 * ƽ��������Ĳ���
 * @param Tree *T �����
 * @param Tree s ������
 * @param int *taller �߶Ȳ�
 * @return int �Ƿ����ɹ�
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
 * ƽ��������Ĺ���
 * @param Tree *T �����
 * @return int �Ƿ񹹽��ɹ� 
 */
int create(Tree *T)
{
	int n,i,k,taller;
	Tree s;
	*T = NULL;
	printf("����������:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("�������%d������:",i+1);
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
 * ������������������ݹ飩
 * @param Tree T �����������
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
 * ������������������ݹ飩
 * @param Tree T �����������
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
 * ɾ��������
 * @param Tree *p�����
 * @param int *taller �߶ȱ仯
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
 * ɾ���Ҵ�����
 * @param Tree *p �����
 * @param int *taller �߶Ȳ�
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
 * ɾ����㺯��
 * @param Tree q���
 * @param Tree *T q����������
 * @param int *taller �߶ȱ仯
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
 * ƽ���������ɾ��
 * @param Tree *T �����
 * @param int x ɾ������
 * @param int *taller �߶ȱ仯
 * @return int �Ƿ�ɾ���ɹ�
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
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	midDisplay(T);
	putchar('\n');
	printf("������ɾ������:");
	scanf("%d",&i);
	deleteTree(&T,i,&taller);
	printf("ɾ�����������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("ɾ�����������Ϊ:");
	midDisplay(T);
	putchar('\n');
	printf("�������������:");
	scanf("%d",&i);
	if(1 == search(T,i,&T,&p)){
		printf("���ݴ���!\n");
	}else{
		printf("���ݲ�����!\n");
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