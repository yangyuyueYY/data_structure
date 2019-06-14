/*
 * 静态链表：初始化、插入、删除、更新、获取、定位、遍历、求长度
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char name[20];
	float score;
}Data;

typedef struct
{
	Data data;
	int next;
}Node;

typedef struct
{
	Node *node;
	int sl;
	int av;
	int size;
}StaticLink;

/*
 * 静态链表：初始化
 * @param StaticLink *L 静态链表首地址
 * @param int max 最大容量
 * @return int 是否初始化成功，0为成功，-1为失败
 */
int initStaticLink(StaticLink *L, int max)
{
	Node *node;
	int i;
	if(max < 0){
		printf("最大容量输入不合法\n");
		return -1;
	}
	node = (Node *)malloc(max * sizeof(Node));
	if(NULL == node){
		printf("空间分配失败\n");
		return -1;
	}
	node[0].next = -1;
	for(i=1;i<max;i++){
		strcpy(node[i].data.name,"");
		node[i].data.score = 0;
		node[i].next = i+1;
	}
	node[max-1].next = -1;
	L->node = node;
	L->sl = 0;
	L->av = 1;
	L->size = max;
	return 0;
}

/*
 * 静态链表：插入
 * @param StaticLink *L 静态链表首地址
 * @param int pos 插入位置
 * @param Data x 插入数据
 * @return int 是否插入成功，0为成功，-1为失败
 */
int insertStaticLink(StaticLink *L, int pos, Data x)
{
	int i = 0, j = L->sl, s = L->av;
	if(-1 == L->node[L->av].next){
		printf("静态链表已满\n");
		return -1;
	}
	while(i < pos-1 && j){
		j = L->node[j].next;
		i ++;
	}
	if(i > pos-1 || -1 == j){
		printf("位置不合法\n");
		return -1;
	}
	L->av = L->node[s].next;
	L->node[s].data = x;
	L->node[s].next = L->node[j].next;
	L->node[j].next = s;
	return 0;
}

/*
 * 静态链表：删除
 * @param StaticLink *L 静态链表首地址
 * @param int pos 删除位置
 * @param Data *x 删除数据
 * @return int 是否删除成功，0为成功，-1为失败
 */
int deleteStaticLink(StaticLink *L, int pos, Data *x)
{
	int i = 0, j = L->sl, s;
	if(-1 == L->node[j].next){
		printf("该线性链表为空\n");
		return -1;
	}
	while(i < pos-1 && L->node[j].next != -1){
		j = L->node[j].next;
		i ++;
	}
	if(i > pos-1 || -1 == L->node[j].next){
		printf("位置不合法\n");
		return -1;
	}
	s = L->node[j].next;
	*x = L->node[s].data;
	L->node[j].next = L->node[s].next;
	L->node[s].next = L->av;
	L->av = s;
	return 0;
}

/*
 * 静态链表：更新
 * @param StaticLink L 静态链表
 * @param int pos 更新位置
 * @param Data x 更新数据
 * @return int 是否更新成功，0为成功，-1为失败
 */
int updateStaticLink(StaticLink L, int pos, Data x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("该线性链表为空\n");
		return -1;
	}
	while(i < pos && j != -1){
		j = L.node[j].next;
		i ++;
	}
	if(i > pos || -1 == j){
		printf("位置不合法\n");
		return -1;
	}
	L.node[j].data = x;
	return 0;
}

/*
 * 静态链表：获取
 * @param StaticLink L 静态链表
 * @param int pos 获取位置
 * @param Data *x 获取数据
 * @return int 是否获取成功，0为成功，-1为失败
 */
int getDataStaticLink(StaticLink L, int pos, Data *x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("该线性链表为空\n");
		return -1;
	}
	while(i < pos && j != -1){
		j = L.node[j].next;
		i ++;
	}
	if(i > pos || -1 == j){
		printf("位置不合法\n");
		return -1;
	}
	*x = L.node[j].data;
	return 0;
}

/*
 * 静态链表：定位
 * @param StaticLink L 静态链表
 * @param int *pos 定位到位置
 * @param Data x 需定位数据
 * @return int 是否定位成功，0为成功，-1为失败
 */
int getPosStaticLink(StaticLink L, int *pos, Data x)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("该线性链表为空\n");
		return -1;
	}
	while((j != -1) && (strcmp(L.node[j].data.name,x.name) != 0 || fabs(L.node[j].data.score - x.score) > 1e-6)){
		j = L.node[j].next;
		i ++;
	}
	if(-1 == j){
		printf("该数据不存在\n");
		return -1;
	}
	*pos = i;
	return 0;
}

/*
 * 静态链表：遍历
 * @param StaticLink L 静态链表
 */
void displayStaticLink(StaticLink L)
{
	int i = 1, j = L.node[L.sl].next;
	if(-1 == j){
		printf("该线性链表为空\n");
		return;
	}
	while(j != -1){
		printf("%d  name:%s  score:%g\n",i,L.node[j].data.name,L.node[j].data.score);
		j = L.node[j].next;
		i ++;
	}
	return;
}

/*
 * 静态链表：取长
 * @param Staticnk L 静态链表
 * @param int *pos 长度
 * @return int 是否取长成功，0为成功，-1为失败
 */
int getLengthStaticLink(StaticLink L, int *pos)
{
	int i = 0, j = L.sl;
	if(-1 == L.node[j].next){
		printf("该线性链表为空\n");
		return -1;
	}
	while(L.node[j].next != -1){
		j = L.node[j].next;
		i ++;
	}
	*pos = i;
	return 0;
}

int main()
{
	StaticLink L;
	int i,pos,max;
	Data data;
	printf("静态链表：初始化、插入、删除、更新、获取、定位、遍历、求长度\n");
	printf("回车进入……\n");
	while(1){
		if('\n' == getchar()){
			system("cls");
		}
		printf("*********************************************\n");
		printf("     1--初始化      2--插入     3--删除      \n");  
		printf("     4--更新        5--获取     6--定位      \n");
		printf("     7--遍历        8--取长     0--退出      \n");
		printf("*********************************************\n");
		printf("请选择操作:");
		scanf("%d",&i);
		switch(i){
		case 1:
			printf("请输入容量：");
			scanf("%d",&max);
			if(0 == initStaticLink(&L,max)){
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
			if(0 == insertStaticLink(&L,pos,data)){
				printf("插入成功\n");
			}
			break;
		case 3:
			printf("请输入删除位置:");
			scanf("%d",&pos);
			if(0 == deleteStaticLink(&L,pos,&data)){
				printf("删除数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 4:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			printf("请输入更新位置:");
			scanf("%d",&pos);
			if(0 == updateStaticLink(L,pos,data)){
				printf("更新成功\n");
			}
			break;
		case 5:
			printf("请输入获取数据位置:");
			scanf("%d",&pos);
			if(0 == getDataStaticLink(L,pos,&data)){
				printf("该位置数据是:%s %g\n",data.name,data.score);
			}
			break;
		case 6:
			printf("请输入name:");
			scanf("%s",data.name);
			printf("请输入score:");
			scanf("%f",&data.score);
			if(0 == getPosStaticLink(L,&pos,data)){
				printf("该数据位置是:%d\n",pos);
			}
			break;
		case 7:
			printf("数据是:\n");
			displayStaticLink(L);
			break;
		case 8:
			if(0 == getLengthStaticLink(L,&pos)){
				printf("当前线性表长度为:%d\n",pos);
			}
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


