/*
 * 单向循环链表（带头指针）：初始化，插入，删除，遍历
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct node
{
	Data data;
	struct node *next;
}CNode,* CList;

/*
 * 单向循环链表（带头指针）：初始化
 * @param CList *L 头指针指针
 * @return int 是否初始化成功，0为成功，-1为失败
 */
int initCNode(CList *L)
{
	CList p = (CList) malloc (sizeof(CNode));
	if(NULL == p){
		printf("空间分配失败\n");
		return -1;
	}
	strcpy(p->data.name,"");
	p->data.score = 0;
	*L = p;
	p->next = *L;
	return 0;
}

/*
 * 单向循环链表（带头指针）：插入
 * @param CList L 头指针
 * @param int pos 插入位置
 * @param Data data 插入数据
 * @return int 是否插入成功，0为成功，-1为失败
 */
int insertCNode(CList L, int pos, Data data)
{
	int i = 0;
	CList p = L,q;
	while(i < pos-1 && p->next != L){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next == L)){
		printf("位置不合法\n");
		return -1;
	}
	q = (CList)malloc(sizeof(CNode));
	if(NULL == q){
		printf("空间申请失败\n");
		return -1;
	}
	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * 单向循环链表（带头指针）：删除
 * @param CList L 头指针
 * @param int pos 删除位置
 * @param Data *data 删除数据
 * @return int 是否删除成功，0为成功，-1为失败
 */
int deleteCNode(CList L, int pos, Data *data)
{
	int i = 0;
	CList p = L,q;
	if(L->next == L){
		printf("该链表为空\n");
		return -1;
	}
	while(i < pos-1 && p->next->next != L){
		i ++;
		p = p->next;
	}
	if(i > pos-1 || (i < pos-1 && p->next->next == L)){
		printf("位置不合法\n");
		return -1;
	}
	q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);
	return 0;
}

/*
 * 单向循环链表（带头指针）：遍历
 * @param CList L 头指针
 */
void displayCNode(CList L)
{
	int i = 0;
	CList p = L->next;
	if(L->next == L){
		printf("该链表为空\n");
		return;
	}
	while(p != L){
		printf("%d  name:%s  score:%g\n",i+1,p->data.name,p->data.score);
		p = p->next;
		i ++;
	}
	return;
}

int main()
{
	CList L;
	int i,pos;
	Data data;
	printf("单向循环链表（带头指针）：初始化，插入，删除，遍历\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--初始化      2--插入     3--删除      \n");  
		printf("     4--遍历        0--退出                  \n");
		printf("*********************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			if(0 == initCNode(&L)){
				printf("初始化成功\n");
			}
			break;
		case 2:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			printf("请输入插入位置:");
			scanf("%d",&pos);
			if(0 == insertCNode(L,pos,data)){
				printf("插入成功\n");
			}
			break;
		case 3:
			printf("请输入删除位置:");
			scanf("%d",&pos);
			if(0 == deleteCNode(L,pos,&data)){
				printf("删除数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("数据是:\n");
			displayCNode(L);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("操作选择失败，请重新输入\n");
		}
		getchar();
	}
	return 0;
}
