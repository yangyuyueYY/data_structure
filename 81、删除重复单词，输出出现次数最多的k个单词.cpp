/*
 * 设键盘输入n个英语单词，输入格式为n,w1,w2,……,wn,其中n表示随后输入英文单词个数
 * 试编一程序，建立一个单向链表，实现：如果单词重复出现，则只在链表上保留一个
 * 链表结点还应有一个计数域，记录单词重复出现的个数，然后输出出现次数最多的前k个单词
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char word[20];
	int count;
}Data;

typedef struct node
{
	Data data;
	struct node *next;
}SqNode,*SqList;

/*
 * 链式存储线性表(带头结点)：初始化
 * @param SqList *L 指向线性表头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initSqlist(SqList *L)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	p->next = NULL;
	strcpy(p->data.word,"");
	p->data.count = 0;
	*L = p;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：插入
 * @param SqList L 线性表头指针
 * @param int pos 插入位置
 * @param Data data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertSqlist(SqList L, int pos, Data data)
{
	int i = 0;
	SqList p = L,q = NULL;
	while(i < pos-1 && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || NULL == p){
		printf("位置不合法\n");
		return -1;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：更新
 * @param SqList L 线性表头指针
 * @param int pos 更新位置
 * @param Data data 更新数据
 * @return int 更新是否成功，0为成功，-1为失败
 */
int updateSqlist(SqList L, int pos, Data data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		return -1;
	}
	p->data = data;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：获取
 * @param SqList L 线性表头指针
 * @param int pos 获取位置
 * @param Data *data 获取数据
 * @return int 获取是否成功，0为成功，-1为失败
 */
int getDataSqlist(SqList L, int pos, Data *data)
{
	int i = 0;
	SqList p = L;
	while(i < pos && p != NULL){
		i ++;
		p = p->next;
	}
	if(i > pos || NULL == p){
		return -1;
	}
	*data = p->data;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：定位
 * @param SqList L 线性表头指针
 * @param int *pos 定位到的位置
 * @param Data data 要定位的数据
 * @return int 定位是否成功，0为成功，-1为失败
 */
int getPosSqlist(SqList L, int *pos, Data data)
{
	int i = 0;
	SqList p = L;
	if(NULL == p){
		
	}
	while(p != NULL && (strcmp(data.word,p->data.word) != 0)){
		i ++;
		p = p->next;
	}
	if(p == NULL){
		return -1;
	}
	*pos = i;
	return 0;
}

/*
 * 链式存储线性表(带头结点)：遍历
 * @param SqList L 线性表头指针
 */
void displaySqlist(SqList L)
{
	int i = 0;
	SqList p = L->next;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		printf("%d  word:%s  count:%d\n", i+1, p->data.word, p->data.count);
		i ++;
		p = p->next;
	}
}

/*
 * 链式存储线性表(带头结点)：尾插
 * @param SqList L 线性表头指针
 * @param Data data 插入数据
 * @return int 插入是否成功，0为成功，-1为失败
 */
int insertTailSqlist(SqList L, Data data)
{
	SqList p = L,q = NULL;
	while(p->next != NULL){
		p = p->next;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * 取出现次数最多的k个
 * @param SqList L 线性表头指针
 * @param int n 数据个数
 * @param int k 提取数据个数
 * @return int 排序是否成功，0为成功，-1为失败
 */
int orderSqlist(SqList L, int n,int k)
{
	SqList p = L->next;
	if(k>n){
		printf("提取数据量不合法\n");
		return -1;
	}
	if(NULL == p){
		printf("线性表为空\n");
		return -1;
	}
	int i,j;
	Data a,b;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			getDataSqlist(L,i+1,&a);
			getDataSqlist(L,j+1,&b);
			if(a.count<b.count){
				updateSqlist(L, i+1, b);
				updateSqlist(L, j+1, a);
			}
		}
	}
	i = 0;
	while(p != NULL && i < k){
		printf("%d  word:%s  count:%d\n", i+1, p->data.word, p->data.count);
		i ++;
		p = p->next;
	}
	return 0;
}

int main()
{
	SqList L;
	initSqlist(&L);
	Data x;
	int n,i,p,k;
	printf("请输入数据个数:");
	scanf("%d",&n);
	printf("请输入%d个数据:",n);
	for(i=0;i<n;i++){
		scanf("%s",x.word);
		x.count = 1;
		if(getPosSqlist(L,&p,x) == -1){
			insertTailSqlist(L, x);
		}else{
			getDataSqlist(L,p,&x);
			x.count ++;
			updateSqlist(L, p, x);
		}
	}
	printf("构建成功!\n");
	printf("数据为:\n");
	displaySqlist(L);
	printf("请输入显示排名数量:");
	scanf("%d",&k);
	printf("提取中……\n");
	printf("提取后数据为:\n");
	orderSqlist(L,n,k);
	return 0;
}
