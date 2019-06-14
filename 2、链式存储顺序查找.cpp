/*
 * 链式存储顺序查找
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node,*Link;

/* 
 * 初始化一个带头结点的链表
 * @param Link *L 头指针指针
 * @return int 是否初始化成功，0为成功，-1不成功
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
 * 尾插函数
 * @param Link L头指针
 * @param int x 待插入数据
 * @return int 是否插入成功，0成功，-1失败
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
 * 遍历函数
 * @param Link L 头指针
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
 * 查找函数
 * @param Link L 头指针
 * @param int x 带查找数据
 * @return int 数据位置，找不到返回-1
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
	printf("请输入数据个数:");
	scanf("%d",&n);
	printf("请输入%d个整数:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insert(L,x);
	}
	printf("线性表为:");
	display(L);
	printf("请输入待查找数据:");
	scanf("%d",&x);
	if((a=search(L,x)) == -1){
		printf("数据%d不存在!\n",x);
	}else{
		printf("数据%d位置为%d!\n",x,a);
	}
	return 0;
}