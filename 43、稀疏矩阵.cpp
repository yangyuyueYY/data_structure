/*
 * ϡ��������Ԫ������������������չʾ��ת�ã�ԭʼ���Ż������˷�
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int v;
	int i;
	int j;
}Data;

typedef struct
{
	Data data[20];
	int mu;
	int nu;
	int tu;
}matrix;

/*
 * ����ϡ��������Ԫ���
 * @param matrix *q ��Ԫ����ַ
 * @return int �Ƿ񴴽��ɹ���0�ɹ���-1ʧ��
 */
int create(matrix *q)
{
	int i;
	printf("������ϡ���������:");
	scanf("%d",&q->mu);
	printf("������ϡ���������:");
	scanf("%d",&q->nu);
	printf("������ϡ������������:");
	scanf("%d",&q->tu);
	for(i=0;i<q->tu;i++){
		printf("������ϡ������%d��������(�����ꡢ�����ꡢ����):",i+1);
		scanf("%d%d%d",&q->data[i].i,&q->data[i].j,&q->data[i].v);
		if(q->data[i].i > q->mu - 1 || q->data[i].j > q->nu - 1){
			printf("���겻�Ϸ�!\n");
			return -1;
		}
	}
	return 0;
}

/*
 * չʾϡ��������Ԫ���
 * @param matrix q ��Ԫ���
 */
void display(matrix q)
{
	int i,j,t=0;
	for(i=0;i<q.mu;i++){
		for(j=0;j<q.nu;j++){
			if(q.data[t].i == i && q.data[t].j == j){
				printf("%d ",q.data[t].v);
				t ++;
			}else{
				printf("0 ");
			}
		}
		putchar('\n');
	}
}

/*
 * ϡ������ת�ã�ԭʼ��
 * @param matrix q ϡ��������Ԫ���
 * @param matrix *p ת�ú��ϡ��������Ԫ���
 * @return int �Ƿ�ת�óɹ���0�ɹ���-1ʧ��
 */
int contrary1(matrix q,matrix *p)
{
	int i,j,t=0;
	p->mu = q.nu;
	p->nu = q.mu;
	p->tu = q.tu;
	for(i=0;i<q.nu;i++){
		for(j=0;j<q.tu;j++){
			if(q.data[j].j == i){
				p->data[t].i = q.data[j].j;
				p->data[t].j = q.data[j].i;
				p->data[t].v = q.data[j].v;
				t ++;
			}
		}
	}
	return 0;
}

/*
 * ϡ������ת�ã��Ż���
 * @param matrix q ϡ��������Ԫ���
 * @param matrix *p ת�ú��ϡ��������Ԫ���
 * @return int �Ƿ�ת�óɹ���0�ɹ���-1ʧ��
 */
int contrary2(matrix q,matrix *p)
{
	int i,j,t=0;
	int *num,*cpot;
	num = (int *)malloc(q.nu*sizeof(int));
	cpot = (int *)malloc(q.nu*sizeof(int));
	p->mu = q.nu;
	p->nu = q.mu;
	p->tu = q.tu;
	for(i=0;i<q.nu;i++){
		num[i] = 0;
		cpot[i] = 0;
	}
	for(i=0;i<q.tu;i++){
		num[q.data[i].j] ++;
	}
	for(i=1;i<q.nu;i++){
		cpot[i] = cpot[i-1] + num[i-1];
	}
	for(i=0;i<q.tu;i++){
		j = q.data[i].j;
		t = cpot[j];
		p->data[t].i = q.data[i].j;
		p->data[t].j = q.data[i].i;
		p->data[t].v = q.data[i].v;
		cpot[j] ++;
	}
	return 0;
}

/*
 * ϡ�����ĳ˷�
 * @param matrix q ϡ��������Ԫ���
 * @param matrix p ϡ��������Ԫ���
 * @param matrix *S �˷����
 * @return int �Ƿ����ɹ���0�ɹ���-1ʧ��
 */
int multiple(matrix ta,matrix tb,matrix *tc){
	int p,q,i,j,k,r,t;
	int temp[20] = {0};
	int num[20],rpot[20];
	if(ta.nu != tb.mu){
		return -1;
	}
	tc->mu = ta.mu;
	tc->nu = tb.nu;
	if(ta.tu * tb.tu == 0){
		tc->tu = 0;
		return -1;
	}
	for(i=0;i<tb.mu;i++){
		num[i] = 0;
	}
	for(k=0;k<tb.tu;k++){
		i = tb.data[k].i;
		num[i] ++;
	}
	rpot[0] = 0;
	for(i=1;i<tb.mu;i++){
		rpot[i] = rpot[i-1] + num[i-1];
	}
	r = 0;
	p = 0;
	for(i=0;i<ta.mu;i++){
		for(j=0;j<tb.nu;j++){
			temp[j] = 0;
		}
		while(ta.data[p].i == i){
			k = ta.data[p].j;
			if(k < tb.mu-1){
				t = rpot[k+1];
			}else{
				t = tb.tu;
			}
			for(q=rpot[k];q<t;q++){
				j = tb.data[q].j;
				temp[j] += ta.data[p].v * tb.data[q].v;
			}
			p ++;
		}
		for(j=0;j<tb.nu;j++){
			if(temp[j]){
				tc->data[r].i = i;
				tc->data[r].j = j;
				tc->data[r].v = temp[j];
				r ++;
			}
		}
		tc->tu = r;
	}
	return 0;
}

int main()
{
	matrix *q,*p,*s;
	q = (matrix *)malloc(sizeof(matrix));
	if(NULL == q){
		printf("�ռ����ʧ��!\n");
		return -1;
	}
	p = (matrix *)malloc(sizeof(matrix));
	if(NULL == p){
		printf("�ռ����ʧ��!\n");
		return -1;
	}
	s = (matrix *)malloc(sizeof(matrix));
	if(NULL == s){
		printf("�ռ����ʧ��!\n");
		return -1;
	}
	if(0 == create(q)){
		printf("�����ɹ�\n");
	}else{
		printf("����ʧ��\n");
		return -1;
	}
	printf("��ϡ�����Ϊ:\n");
	display(*q);
	printf("��ͳ���ú󡭡�\n");
	contrary1(*q,p);
	display(*p);
	printf("�Ż����ú󡭡�\n");
	contrary2(*q,p);
	display(*p);
	printf("����������:\n");
	if(0 == create(q)){
		printf("�����ɹ�\n");
	}else{
		printf("����ʧ��\n");
		return -1;
	}
	if(0 == create(p)){
		printf("�����ɹ�\n");
	}else{
		printf("����ʧ��\n");
		return -1;
	}
	multiple(*q,*p,s);
	printf("���Ϊ:\n");
	display(*s);
	return 0;
}

/*
6
6
7
0 0 15
0 3 22
0 5 15
1 1 11
1 2 3
2 3 6
4 0 91
*/
