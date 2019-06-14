/*
 * 树的基本操作：创建孩子兄弟链表，先根遍历，后根遍历，层次遍历
 * 结点查找，结点插入，结点删除，求树的深度，凹入表显示，所有叶子结点的路径
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *fch,*nsib;
}CSNode,*CSTree;

typedef struct
{
	CSTree *data;
	int head;
	int rear;
	int size;
}Queue;//循环队列

typedef struct node1
{
	char data;
	struct node1 *next;
}Node,*Stack;

/*
 * 链栈：初始化
 * @param Stack *L 指向链栈头指针的指针
 * @return int 初始化是否成功，0为成功，-1为失败
 */
int initStack(Stack *L)
{
	*L = NULL;
	return 0;
}

/*
 * 链栈：判断栈空
 * @param Stack L 链栈头指针
 * @return int 链栈是否成功，0为空，1不为空
 */
int isEmptyStack(Stack L)
{
	if(L == NULL){
		return 0;
	}
	return 1;
}

/*
 * 链栈：得到栈顶
 * @param Stack L 链栈头指针
 * @param char *data 栈顶数据
 * @return int 是否获取成功，-1失败，0成功
 */
int getTopStack(Stack L,char *data)
{
	if(L == NULL){
		printf("栈为空!\n");
		return -1;
	}
	*data = L->data;
	return 0;
}

/*
 * 链栈：进栈
 * @param Stack *L 链栈头指针
 * @param char x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int pushStack(Stack *L, char x)
{ 
	Stack q;
	q = (Stack) malloc (sizeof(Node));
	if(NULL == q){
		printf("空间分配失败\n");
		return -1;
	}
	q->data = x;
	q->next = *L;
	*L = q;
	return 0;
}

/*
 * 链栈：出栈
 * @param Stack *L 链栈首地址
 * @param char *x出栈数据
 * @return int 是否出栈成功，-1为失败，0为成功
 */
int popStack(Stack *L, char *x)
{ 
	Stack p = *L;
	if(*L == NULL){
		printf("栈空!\n");
		return -1;
	}
	*x = p->data;
	*L = (*L)->next;
	free(p);
	return 0;
}

/*
 * 链栈：遍历
 * @param Stack L 链栈
 */
void displayStack(Stack L)
{
	char a[20],j;
	int i = 0;
	Stack p = L;
	if(NULL == p){
		printf("线性表为空\n");
	}
	while(p != NULL){
		a[i] = p->data;
		i ++;
		p = p->next;
	}
	for(j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}
	putchar('\n');
}

/*
 * 循环队列：初始化
 * @param Queue* q 循环队列首地址
 * @param int max 最大数据量
 * @return int 是否初始化成功，-1为失败，0为成功
 */
int initQueue(Queue *q, int max)
{
	if(max < 0){
		printf("最大数据量不合法\n");
		return -1;
	}
	q->data = (CSTree *)malloc(max * sizeof(CSTree));
	if(NULL == q->data){
		printf("空间申请失败\n");
		return -1;
	}
	q->head = 0;
	q->rear = 0;
	q->size = max;
	return 0;
}

/*
 * 循环队列：判断队空
 * @param Queue q 循环队列
 * @return int 是否队空，0为队空，1不为空
 */
int isEmptyQueue(Queue q)
{
	if(q.head == q.rear){
		return 0;
	}
	return 1;
}

/*
 * 顺序队列：得到队头
 * @param Queue q 顺序队列
 * @param CSTree *data 队头数据
 * @return int 是否获取成功，0成功，-1不成功
 */
int getHeadQueue(Queue q,CSTree *data)
{
	if(isEmptyQueue(q) == 0){
		return -1;
	}
	*data = q.data[q.head];
	return 0;
}

/*
 * 顺序队列：求队列长度
 * @param Queue q 顺序队列
 * @return int 队列长度
 */
int getLengthQueue(Queue q)
{
	return (q.rear+q.size-q.head)%q.size;
}

/*
 * 顺序队列：清空队列
 * @param Queue *q 顺序队列指针
 * @return int 是否清空成功，0成功，-1不成功
 */
int emptyQueue(Queue *q)
{
	q->rear = q->head;
	return 0;
}

/*
 * 顺序队列：进队列
 * @param Queue *q 顺序队列首地址
 * @param CSTree x插入数据
 * @return int 是否插入成功，-1为失败，0为成功
 */
int enQueue(Queue *q, CSTree x)
{ 
	if((q->rear+1)%q->size == q->head){
		printf("队列已满!\n");
		return -1;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % q->size;
	return 0;
}

/*
 * 顺序队列：出队列
 * @param Queue *q 顺序队列首地址
 * @param CSTree *x出队列数据
 * @return int 是否出队列成功，-1为失败，0为成功
 */
int deQueue(Queue *q, CSTree *x)
{ 
	if(isEmptyQueue(*q) == 0){
		return -1;
	}
	*x = q->data[q->head];
	q->head = (q->head + 1) % q->size;
	return 0;
}

/*
 * 创建孩子兄弟链表
 * @param CSTree *T 根结点指针
 * @return int 是否创建成功，0成功，-1失败
 */
int create(CSTree *T)
{
	char fa,ch;
	Queue Q;
	CSTree p,s,r;
	initQueue(&Q,20);
	*T = NULL;
	printf("请输入边（父，子）:");
	scanf("%c,%c",&fa,&ch);
	while(ch != '#'){
		p = (CSTree)malloc(sizeof(CSNode));
		if(p == NULL){
			return -1;
		}
		p->data = ch;
		p->fch = NULL;
		p->nsib = NULL;
		enQueue(&Q,p);
		if(fa == '#'){
			*T = p;
		}else{
			getHeadQueue(Q,&s);
			while(s->data != fa){
				deQueue(&Q, &s);
				getHeadQueue(Q,&s);
			}
			if(s->fch == NULL){
				s->fch = p;
				r = p;
			}else{
				r->nsib = p;
				r = p;
			}
		}
		getchar();
		scanf("%c,%c",&fa,&ch);
	}
	return 0;
}

/*
 * 先根遍历
 * @param CSTree T 根结点
 */
void preDisplay(CSTree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->fch);
		preDisplay(T->nsib);
	}
}

/*
 * 遍历地址
 * @param CSTree T 根结点
 */
void display(CSTree T)
{
	if(T){
		printf("%c:%p\n",T->data,T);
		display(T->fch);
		display(T->nsib);
	}
}

/*
 * 后根遍历
 * @param CSTree T 根结点
 */
void postDisplay(CSTree T)
{
	if(T){
		postDisplay(T->fch);
		printf("%c",T->data);
		postDisplay(T->nsib);
	}
}

/*
 * 结点查找
 * @param CSTree T 根结点
 * @param char x 待查找数据
 * @param CSTree *p 结点地址
 */
void search(CSTree T,char x,CSTree *p)
{
	if(T){
		if(T->data == x){
			*p = T;
		}else{
			search(T->fch,x,p);
			search(T->nsib,x,p);
		}
	}
}

/*
 * 结点插入
 * @param CSTree *T 根结点指针
 * @param char fa 父结点
 * @param char ch 待插入结点
 * @return int 是否插入成功，0成功，-1失败
 */
int insert(CSTree *T,char fa,char ch)
{
	CSTree p = NULL,s;
	search(*T,fa,&p);
	if(p){
		s = (CSTree)malloc(sizeof(CSNode));
		if(s == NULL){
			return -1;
		}
		s->data = ch;
		s->fch = NULL;
		s->nsib = NULL;
		if(p->fch == NULL){
			p->fch = s;
		}else{
			p = p->fch;
			while(p->nsib){
				p = p->nsib;
			}
			p->nsib = s;
		}
		return 0;
	}
	return -1;
}

/*
 * 层次遍历
 * @param CSTree T 根结点
 */
void levelDisplay(CSTree T)
{
	Queue Q;
	initQueue(&Q,20);
	CSTree p,q;
	p = T;
	while(p){
		printf("%c",p->data);
		if(p->fch){
			enQueue(&Q,p->fch);
			q = p->fch;
			while(q->nsib){
				enQueue(&Q,q->nsib);
				q = q->nsib;
			}
		}
		p = NULL;
		deQueue(&Q,&p);
	}
}

/*
 * 删除整棵树
 * @param CSTree T 根结点
 */
void deleteTree(CSTree T)
{
	if(T){
		deleteTree(T->fch);
		deleteTree(T->nsib);
		free(T);
	}
}

/*
 * 删除结点
 * @param CSTree *T 根结点指针
 * @param char fa 父结点
 * @param char ch 待删除结点
 * @return int 是否删除成功，0成功，-1失败
*/
int deleteNode(CSTree *T,char fa,char ch)
{
	CSTree p = NULL,q = NULL,s;
	if(fa == '#'){
		deleteTree(*T);
		*T = NULL;
		return 0;
	}
	search(*T,fa,&p);
	search(*T,ch,&q);
	if(p == NULL){
		printf("fa地址失效!");
		return -1;
	}
	if(q == NULL){
		printf("ch地址失效!");
		return -1;
	}
	if(p->fch == q){
		p->fch = q->nsib;
		q->nsib = NULL;
		deleteTree(q);
		return 0;
	}else{
		s = p->fch;
		while(s->nsib != q && s->nsib != NULL){
			s = s->nsib;
		}
		if(s->nsib == NULL){
			printf("非父子关系!\n");
			return -1;
		}else{
			s->nsib = q->nsib;
			q->nsib = NULL;
			deleteTree(q);
			return 0;
		}
	}
}

/*
 * 求树的深度
 * @param CSTree T 根结点
 * @return int 树的深度
 */
int depth(CSTree T)
{
	int h1,h2;
	if(T == NULL){
		return 0;
	}else{
		h1 = depth(T->fch);
		h2 = depth(T->nsib);
		if(h1+1 >= h2){
			return h1+1;
		}else{
			return h2;
		}
	}
}

/*
 * 树的凹入表显示
 * @param CSTree T 根结点
 * @param int level 层数
 */
void aoruDisplay(CSTree T,int level)
{
	int i,k;
	if(T){
		for(i=1;i<level;i++){
			putchar(' ');
		}
		printf("%c",T->data);
		putchar('+');
		for(k=i;k<70;k++){
			putchar('-');
		}
		putchar('\n');
		aoruDisplay(T->fch,level+4);
		aoruDisplay(T->nsib,level);
	}
}

/*
 * 求树所有叶子结点的路径
 * @param CSTree T 根结点
 * @param Stack *s 栈
 */
void allTreePath(CSTree T,Stack *s)
{
	char a;
	while(T){
		pushStack(s,T->data);
		if(T->fch == NULL){
			displayStack(*s);
		}else{
			allTreePath(T->fch,s);
		}
		popStack(s,&a);
		T = T->nsib;
	}
}

int main()
{
	CSTree T,p;
	char fa,ch;
	char x;
	Stack s;
	initStack(&s);
	create(&T);
	printf("先根遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("后根遍历为:");
	postDisplay(T);
	putchar('\n');
	printf("层次遍历为:");
	levelDisplay(T);
	putchar('\n');
	printf("各结点地址是:\n");
	display(T);
	printf("请输入待查找结点:");
	getchar();
	scanf("%c",&x);
	search(T,x,&p);
	printf("%c的地址为%p\n",x,p);
	getchar();
	printf("请输入待插入结点及其父结点:");
	scanf("%c,%c",&ch,&fa);
	if(0 == insert(&T,fa,ch)){
		printf("插入成功!\n");
	}else{
		printf("插入失败!\n");
	}
	printf("先根遍历为:");
	preDisplay(T);
	putchar('\n');
	getchar();
	printf("请输入待删除结点及其父结点:");
	scanf("%c,%c",&ch,&fa);
	if(0 == deleteNode(&T,fa,ch)){
		printf("删除成功!\n");
	}else{
		printf("删除失败!\n");
	}
	printf("先根遍历为:");
	preDisplay(T);
	putchar('\n');
	printf("树的深度为:%d\n",depth(T));
	printf("凹入表为:\n");
	aoruDisplay(T,1);
	printf("所有叶子结点路径为:\n");
	allTreePath(T,&s);
	return 0;
}

/*
#,a
a,b
a,c
b,d
b,e
c,f
e,g
e,h
e,i
i,#
g
j,c
j,c
*/