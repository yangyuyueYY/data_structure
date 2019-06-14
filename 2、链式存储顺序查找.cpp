/*
 * ��ʽ�洢˳�����
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node,*Link;

/* 
 * ��ʼ��һ����ͷ��������
 * @param Link *L ͷָ��ָ��
 * @return int �Ƿ��ʼ���ɹ���0Ϊ�ɹ���-1���ɹ�
 */
int initLink(Link *L)
{
	Link p;
	p = (Link)malloc(sizeof(Node));
	if(p == NULL){
		return -1;
	}
	p->data = -1;
	p->next = NULL;
	*L = p;
	return 0;
}

/* 
 * β�庯��
 * @param Link Lͷָ��
 * @param int x ����������
 * @return int �Ƿ����ɹ���0�ɹ���-1ʧ��
 */
int insert(Link L,int x)
{
	Link p = L,q;
	while(p->next != NULL){
		p = p->next;
	}
	q = (Link)malloc(sizeof(Node));
	if(q == NULL){
		return -1;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * ��������
 * @param Link L ͷָ��
 */
void display(Link L)
{
	Link p = L->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

/* 
 * ���Һ���
 * @param Link L ͷָ��
 * @param int x ����������
 * @return int ����λ�ã��Ҳ�������-1
 */
int search(Link L,int x)
{
	Link p = L->next;
	int i = 1;
	while(p){
		if(p->data == x){
			return i;
		}else{
			p = p->next;
			i++;
		}
	}
	return -1;
}

int main()
{
	Link L;
	initLink(&L);
	int n,i,x,a;
	printf("���������ݸ���:");
	scanf("%d",&n);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insert(L,x);
	}
	printf("���Ա�Ϊ:");
	display(L);
	printf("���������������:");
	scanf("%d",&x);
	if((a=search(L,x)) == -1){
		printf("����%d������!\n",x);
	}else{
		printf("����%dλ��Ϊ%d!\n",x,a);
	}
	return 0;
}