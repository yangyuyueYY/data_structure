/* 
 * �Ա�дһ���㷨����һ���ô�ͷ���ĵ��������ʾ�Ķ���ʽ�ֽ����������ʽ
 * ʹ����������ʽ�ֱ�������ָ�����ż��ָ���Ҫ����ԭ����Ľ��洢�ռ�
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
 * ���Ա�(��ͷ���)����ʼ��
 * @param SqList *L ָ�����Ա�ͷָ���ָ��
 * @return int ��ʼ���Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int initSqlist(SqList *L)
{
	SqList p = (SqList) malloc (sizeof(SqNode));
	if(NULL == p){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	p->next = NULL;
	p->data.coef = 0;
	p->data.exp = -100;
	*L = p;
	return 0;
}

/*
 * ���Ա�(��ͷ���)������
 * @param SqList L ���Ա�ͷָ��
 * @param int pos ����λ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
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
		printf("λ�ò��Ϸ�\n");
		return -1;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * һԪ����ʽ��Ӧ�ã�����
 * @param SqList L ���Ա�ͷָ��
 */
void displaySqlist(SqList L)
{
	SqList p = L->next;
	if(NULL == p){
		printf("���Ա�Ϊ��\n");
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
 * һԪ����ʽ��Ӧ�ã�����
 * @param SqList L ���Ա�ͷָ��
 * @param Data x ����������
 * @return int �Ƿ����ɹ���0Ϊ�ɹ���-1Ϊʧ��
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
			if(fabs(q->data.coef + x.coef) <1e-6){
				p->next = q->next;
				free(q);
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
 * ��ʽ�洢���Ա�(��ͷ���)��β��
 * @param SqList L ���Ա�ͷָ��
 * @param Data data ��������
 * @return int �����Ƿ�ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int insertTailSqlist(SqList L, Data data)
{
	SqList p = L,q = NULL;
	while(p->next != NULL){
		p = p->next;
	}
	q = (SqList) malloc (sizeof(SqNode));
	if(NULL == q){
		printf("�ռ����ʧ��\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * һԪ����ʽ��Ӧ�ã�����
 * @param SqList L ���Ա�ͷָ��
 * @return int �Ƿ񴴽��ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int createPolyn(SqList L)
{
	int flag;
	Data data;
	printf("������һԪ����ʽ�ĸ���ϵ����ָ��:\n");
	do{
		printf("���������ϵ����ָ��:");
		scanf("%f%d",&data.coef,&data.exp);
		printf("��ѡ���Ƿ������1Ϊ������0Ϊ����:");
		scanf("%d",&flag);
		if(insertPolyn(L,data) < 0){
			return -1;
		}
	}while(flag);
	return 0;
}

/*
 * ����ָ�����һԪ����ʽ
 * @param SqList L1 ԭ���Ա�ͷָ��
 * @param SqList L2 ���ָ������ʽ
 * @param SqList L3 ż��ָ������ʽ
 * @return int �Ƿ��ֳɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int dividePolyn(SqList L1,SqList L2,SqList L3)
{
	SqList p = L1->next,q,p2 = L2,p3 = L3;
	while(p){
		if(p->data.exp % 2 == 0){
			p3->next = p;
			q = p->next;
			p3 = p;
			p3->next = NULL;
			p = q;
		}else{
			p2->next = p;
			q = p->next;
			p2 = p;
			p2->next = NULL;
			p = q;
		}
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
		printf("�����ɹ�!\n");
	}
	printf("L1Ϊ:");
	displaySqlist(L1);
	printf("����С���\n");
	dividePolyn(L1,L2,L3);
	printf("��ζ���ʽ��:");
	displaySqlist(L2);
	printf("ż�ζ���ʽ��:");
	displaySqlist(L3);
	return 0;
}

/*
-4.3 5
1
7 10
1
2.1 0
1
3 2
0
*/