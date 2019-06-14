/*
 * 一元多项式的应用：插入、创建、加法、乘法、显示
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	float coef;
	int exp;
}Data;

typedef struct node
{
	Data data;
	struct node *next;
}SqNode,*SqList;

/*
 * 线性表(带头结点)：初始化
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
	p->data.coef = 0;
	p->data.exp = -100;
	*L = p;
	return 0;
}

/*
 * 线性表(带头结点)：插入
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
 * 一元多项式的应用：遍历
 * @param SqList L 线性表头指针
 */
void displaySqlist(SqList L)
{
	SqList p = L->next;
	if(NULL == p){
		printf("线性表为空\n");
	}
	if(p->data.exp == 1){
		if(fabs(p->data.coef-1)<1e-6){
			printf("x");
		}else{
			printf("%gx",p->data.coef);
		}
	}else{
		if(fabs(p->data.coef-1)<1e-6){
			printf("x^%d",p->data.exp);
		}else{
			printf("%gx^%d", p->data.coef,p->data.exp);
		}
	}
	p = p->next;
	while(p != NULL){
		if(p->data.coef > 0){
			if(p->data.exp == 1){
				if(fabs(p->data.coef-1)<1e-6){
					printf("+x");
				}else{
					printf("+%gx", p->data.coef);
				}
			}
			else{
				if(fabs(p->data.coef-1)<1e-6){
					printf("+x^%d",p->data.exp);
				}else{
					printf("+%gx^%d", p->data.coef,p->data.exp);
				}
			}
		}else if(p->data.coef < 0){
			if(p->data.exp == 1){
				if(fabs(p->data.coef-1)<1e-6){
					printf("x");
				}else{
					printf("%gx", p->data.coef);
				}
			}else{
				if(fabs(p->data.coef-1)<1e-6){
					printf("x^%d",p->data.exp);
				}else{
					printf("%gx^%d", p->data.coef,p->data.exp);
				}
			}
		}
		p = p->next;
	}
	printf("\n");
}

/*
 * 一元多项式的应用：插入
 * @param SqList L 线性表头指针
 * @param Data x 待插入数据
 * @return int 是否插入成功，0为成功，-1为失败
 */
int insertPolyn(SqList L,Data x)
{
	SqList p = L,q = L->next,s;
	while(p){
		if(q && x.exp>p->data.exp && x.exp<q->data.exp){
			s = (SqList)malloc(sizeof(SqNode));
			s->data = x;
			s->next = q;
			p->next = s;
			return 0;
		}else if(q && x.exp==p->data.exp){
			if(fabs(q->data.coef+x.coef)<1e-6){
				p->next = q->next;
				delete q;
				return 0;
			}
			else{
				q->data.coef = x.coef + q->data.coef;
				return 0;
			}
		}else if(q==NULL && x.exp>p->data.exp){
			s = (SqList)malloc(sizeof(SqNode));
			s->data = x;
			s->next = p->next;
			p->next = s;
			return 0;
		}else{
			p = q;
			q = q->next;
		}
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
 * 一元多项式的应用：创建
 * @param SqList L 线性表头指针
 * @return int 是否创建成功，0为成功，-1为失败
 */
int createPolyn(SqList L)
{
	int flag;
	Data data;
	printf("请输入一元多项式的各项系数和指数:\n");
	do{
		printf("请输入项的系数和指数:");
		scanf("%f%d",&data.coef,&data.exp);
		printf("请选择是否继续，1为继续，0为结束:");
		scanf("%d",&flag);
		if(insertPolyn(L,data) < 0){
			return -1;
		}
	}while(flag);
	return 0;
}

/*
 * 一元多项式的应用：加法
 * @param SqList L1 线性表一头指针
 * @param SqList L2 线性表二头指针
 * @param SqList L3 线性表三头指针
 * @return int 是否计算成功，0为成功，-1为失败
 */
int addPolyn(SqList L1,SqList L2,SqList L3)
{
	SqList pa = L1->next,pb = L2->next;
	Data data;
	if(L1->next == NULL){
		L3 = L2;
		return 0;
	}
	if(L2->next == NULL){
		L3 = L1;
		return 0;
	}
	while(pa && pb){
		if(pa->data.exp < pb->data.exp){
			insertTailSqlist(L3, pa->data);
			pa = pa->next;
		}else if(pa->data.exp > pb->data.exp){
			insertTailSqlist(L3, pb->data);
			pb = pb->next;
		}else{
			if(fabs(pa->data.coef + pb->data.coef)>1e-6){
				data.coef = pa->data.coef + pb->data.coef;
				data.exp = pa->data.exp;
				insertTailSqlist(L3,data);
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	while(pa){
		insertTailSqlist(L3,pa->data);
		pa = pa->next;
	}
	while(pb){
		insertTailSqlist(L3,pb->data);
		pb = pb->next;
	}
	return 0;
}

/*
 * 一元多项式的应用：乘法
 * @param SqList L1 线性表一头指针
 * @param SqList L2 线性表二头指针
 * @param SqList L3 线性表三头指针
 * @return int 是否计算成功，0为成功，-1为失败
 */
int mulPolyn(SqList L1,SqList L2,SqList L3)
{
	SqList pa = L1->next,pb;
	Data data;
	if(L1->next == NULL || L2->next == NULL){
		return 0;
	}
	while(pa){
		pb = L2->next;
		while(pb){
			data.coef = pa->data.coef * pb->data.coef;
			data.exp = pa->data.exp + pb->data.exp;
			if(fabs(data.coef)>1e-6){
				insertPolyn(L3,data);
			}
			pb = pb->next;
		}
		pa = pa->next;
	}
	return 0;
}

int main()
{
	SqList L1,L2,L3;
	initSqlist(&L1);
	initSqlist(&L2);
	initSqlist(&L3);
	if(createPolyn(L1) == 0){
		printf("创建成功!\n");
	}
	if(createPolyn(L2) == 0){
		printf("创建成功!\n");
	}
	printf("L1为:");
	displaySqlist(L1);
	printf("L2为:");
	displaySqlist(L2);
	printf("加法中……\n");
	addPolyn(L1,L2,L3);
	printf("和为:");
	displaySqlist(L3);
	initSqlist(&L3);
	printf("乘法中……\n");
	mulPolyn(L1,L2,L3);
	printf("积为:");
	displaySqlist(L3);
	return 0;
}

/*
-4.3 5
1
7 10
1
2.1 0
0
4.3 5
1
3 2
0
*/