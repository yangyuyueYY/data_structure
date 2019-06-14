/*
 * �����������Ļ�������������һ�����������������������������������ϲ�������ڵ������ǰ����㣻
 * ��������ڵ�������̽�㣻�����������������µĺ�̣������������ں����µ�ǰ��
 * ����ֵΪx�Ľ�㣻���£��������������������������
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
 * �������㷨
 * @param Tree p �����
 * @param Tree *pre ����ǰ�����
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
 * ���������������ͷ��㣬������
 * @param Tree *head ͷ���
 * @param Tree T ͷָ��
 * @return int �Ƿ���ӳɹ���0�ɹ���-1ʧ��
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
 * �����������������ϲ�������ڵ������ǰ�����
 * @param Tree p �����ҽ��
 * @return Tree Ŀ����
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
 * �����������������ϲ�������ڵ�������̽��
 * @param Tree p �����ҽ��
 * @return Tree Ŀ����
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
 * �����������������ϲ�������ڵ�������̽��
 * ��һ�������ĳ�����������µ����һ����㣬�������Ǹ������������µ����һ�����
 * ���ý���Ƿ�֧��㣬��p->ltag=0ʱ�����Ϊp->lchild;p->ltag=1ʱ�����Ϊp->rchild
 * ���ýڵ���Ҷ�ӽ�㣬��p->rchild=head������Ϊ���һ����㣬������һ����p->rchild���Ϊ����������������������һ�����
 * ��p->rchild������������Ϊp->rchild->child;������p=p->rchild���ظ�����
 ***********************************************
 * @param Tree p �����ҽ��
 * @param Tree head ͷ���
 * @return Tree Ŀ����
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
 * �����������������ϲ�������ڵ�ĺ���ǰ�����
 * ��һ�������ĳ�����������µĵ�һ����㣬�������Ǹ������ں����µĵ�һ�����
 * ���ý���Ƿ�֧��㣬��p->ltag=0ʱ��ǰ��Ϊp->lchild;p->ltag=1ʱ��ǰ��Ϊp->rchild
 * ���ýڵ���Ҷ�ӽ�㣬��p->lchild=head������Ϊ��һ����㣬������һ����p->lchild���Ϊ������������������ĵ�һ�����
 * ��p->lchild������������Ϊp->lchild->lchild;������p=p->lchild���ظ�����
 ***********************************************
 * @param Tree p �����ҽ��
 * @param Tree head ͷ���
 * @return Tree Ŀ����
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
 * ������������������ݹ飩
 * @param Tree T �����������
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
 * ������������������ݹ飩
 * @param Tree T �����������
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
 * �������ĺ���������ݹ飩
 * @param Tree T �����������
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
 * ����ֵΪx�Ľ��
 * @param Tree head ͷ���
 * @param char x ����������
 * @return Tree Ŀ���ַ
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
 * ���������������������������
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
 * ���������������������������
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
 * �������������������ĺ������
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
 * ���£������������������в�����pʹ���Ϊ���s���Һ���
 * @param Tree p ��������
 * @param Tree s λ�ý��
 * @return int �Ƿ���³ɹ���0��Ϊ��-1ʧ��
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
	printf("�������������������:");
	if(0 == createTree(&T)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
		return -1;
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	midDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	afterDisplay(T);
	putchar('\n');
	if(0 == inOrderThr(&head,T)){
		printf("�������ɹ�!\n");
	}else{
		printf("������ʧ��!\n");
		return -1;
	}
	getchar();
	printf("���������������:");
	scanf("%c",&x);
	p = search(head,x);
	printf("������ǰ�����Ϊ:");
	q = inPreNode(p);
	printf("%c\n",q->data);
	printf("�������̽��Ϊ:");
	q = inPostNode(p);
	printf("%c\n",q->data);
	printf("�������̽��Ϊ:");
	q = iprePostNode(p,head);
	printf("%c\n",q->data);
	printf("�����ǰ�����Ϊ:");
	q = ipostPreNode(p,head);
	printf("%c\n",q->data);
	printf("�������Ϊ:");
	preTreadDiasplay(head);
	putchar('\n');
	printf("�������Ϊ:");
	midTreadDiasplay(head);
	putchar('\n');
	printf("�������Ϊ:");
	afterTreadDiasplay(head);
	putchar('\n');
	return 0;
}

/*
ABC##DE#G##F###
*/