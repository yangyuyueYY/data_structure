/*
 * ��������
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int data;
	int next;
}Data;

/*
 * ��������
 * @param Data *a ������
 * @param int n ���ݸ���
 * @param int m ����λ��
 */
void  baseSort(Data *a,int n,int m)
{
	Data b[10],*c;
	int i,j,t,k,y,p;
	c = (Data *)malloc(n*sizeof(Data));
	for(i=0;i<10;i++){
		b[i].data = i;
	}
	t = 1;
	for(i=0;i<m;i++){
		for(j=0;j<10;j++){
			b[j].next = -1;
		}
		for(j=0;j<n;j++){
			p = b[(a[j].data/t)%10].next;
			if(p!=-1){
				while(a[p].next != -1){
					p = a[p].next;
				}
				a[j].next = a[p].next;
				a[p].next = j;
			}else{
				a[j].next = -1;
				b[(a[j].data/t)%10].next = j;
			}
		}
		y = 0;
		for(j=0;j<10;j++){
			k = b[j].next;
			while(k!=-1){
				c[y].data = a[k].data;
				c[y].next = -1;
				y ++;
				k = a[k].next;
			}
		}
		for(j=0;j<n;j++){
			a[j] = c[j];
			printf("%d ",a[j]);
		}
		putchar('\n');
		t = t * 10;
	}
}

int main()
{
	int n,i,m;
	Data *a;
	printf("������Ԫ�ظ���:");
	scanf("%d",&n);
	a = (Data*)malloc((n)*sizeof(Data));
	if(a == NULL){
		return -1;
	}
	printf("������Ԫ��λ��:");
	scanf("%d",&m);
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].data);
		a[i].next = -1;
	}
	printf("����ǰ:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	printf("�����:\n");
	baseSort(a,n,m);
	putchar('\n');
	return 0;
}

/*
8
3
027 114 253 809 916 357 483 009
*/
