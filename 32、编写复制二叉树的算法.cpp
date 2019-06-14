/*
 * ��д���ƶ��������㷨
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
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * ����������
 * param Tree T1 Դ������
 * param Tree *T2 Ŀ�������
 * return int �Ƿ��Ƴɹ���0�ɹ���-1ʧ��
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
	printf("�����봴���ַ���:");
	if(0 == createTree(&T1)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T1);
	putchar('\n');
	if(0 == copy(T1,&T2)){
		printf("���Ƴɹ�!\n");
	}else{
		printf("����ʧ��!\n");
		return -1;
	}
	printf("�������Ϊ:");
	preDisplay(T2);
	putchar('\n');
}

/*
ABC##DE#G##F###
*/