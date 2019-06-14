/*
 * ��һ�ö������Ľ��ṹΪ(lchild,data,rchild)��rootΪָ��ö�����������ָ��
 * p��q�ֱ�Ϊָ��ö�������������������ָ�룬�Ա�д���㷨ancestor(root,p,q,r)
 * ���㷨�ҵ�p��q�������ͬ���Ƚ��r
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
 * �ݹ鴴���������Ķ�������ṹ
 * @param Tree *T �����������ָ��
 * @return int �Ƿ񴴽��ɹ�,0�ɹ���-1ʧ��
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
 * ������������������ݹ飩
 * @param Tree T �����������
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
 * ����ĸ����
 * @param Tree T �����
 * @param Tree p �����ҽ��
 * @param Tree *q �����
 * @return int �Ƿ�ɹ�
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
 * ������������Ƚ��
 * @param Tree T �����
 * @param Tree p �����ҽ��
 * @param Tree *q ���Ƚ������
 * @return int �Ƿ�ɹ�
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
 * �������ͬ���Ƚ��
 * @param Tree T �����
 * @param Tree p ��һ�����
 * @param Tree q �ڶ������
 * @param Tree *r ��ͬ���Ƚ��
 * @return int �Ƿ��ҵ���0�ҵ���-1�Ҳ���
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
 * ��㶨λ
 * @param Tree T �����
 * @param char x ����
 * @param Tree *p��ַ
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
	printf("�����봴���ַ���:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	getchar();
	printf("�����������:");
	scanf("%c%c",&x,&y);
	position(T,x,&p);
	position(T,y,&q);
	printf("%c:%p\n",x,p);
	printf("%c:%p\n",y,q);
	ancestor(T,p,q,&r);
	if(r == NULL){
		printf("�޹�ͬ����!\n");
	}else{
		printf("�����ͬ����Ϊ%c!\n",r->data);
	}
	return 0;
}

/*
ABC##DE#G##F###
*/