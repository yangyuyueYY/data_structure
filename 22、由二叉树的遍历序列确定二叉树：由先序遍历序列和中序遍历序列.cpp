/*
 * �ɶ������ı�������ȷ����������������������к������������
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
    struct node *lchild;
	struct node *rchild;
}Node,*Tree;

/*
 * �ɶ������ı�������ȷ����������������������к������������
 * @param Tree *T ���������ڵ�ָ��
 * @param char *pre ǰ���������
 * @param char *ino �����������
 * @param int ps ǰ���������
 * @param int is ����������
 * @param int n �ڵ���
 * @return int �Ƿ񴴽��ɹ���0Ϊ�ɹ���-1Ϊʧ��
 */
int createTree(Tree *T,char *pre,char *ino,int ps,int is,int n)
{
	int k,i;
	Tree p;
	if(n == 0){
		*T = NULL;
	}else{
		for(i=0;i<n;i++){
			if(ino[is+i] == pre[ps]){
				k = is+i;
				break;
			}
		}
		if(i == n){
			*T = NULL;
		}else{
			*T = (Tree)malloc(sizeof(Node));
			if(NULL == *T){
				return -1;
			}
			(*T)->data = pre[ps];
			if(k == is){
				(*T)->lchild = NULL;
			}else{
				createTree(&(*T)->lchild,pre,ino,ps+1,is,k-is);
			}
			if(k == is+n-1){
				(*T)->rchild = NULL;
			}else{
				createTree(&(*T)->rchild,pre,ino,ps+1+(k-is),k+1,n-k+is-1);
			}
		}
	}
	return 0;
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void preDisplay(Tree T)
{
	if(T){
		printf("%c",T->data);
		preDisplay(T->lchild);
		preDisplay(T->rchild);
	}
}

/*
 * ������������������ݹ飩
 * @param Tree T �����������
 */
void midDisplay(Tree T)
{
	if(T){
		midDisplay(T->lchild);
		printf("%c",T->data);
		midDisplay(T->rchild);
	}
}

int main()
{
	Tree T;
	int n;
	char a[20],b[20];
	printf("�����������������:");
	scanf("%s",a);
	printf("�����������������:");
	scanf("%s",b);
	n = strlen(a);
	if(0 == createTree(&T,a,b,0,0,n)){
		printf("�����ɹ�!\n");
	}else{
		printf("����ʧ��!\n");
	}
	printf("�������Ϊ:");
	preDisplay(T);
	putchar('\n');
	printf("�������Ϊ:");
	midDisplay(T);
	putchar('\n');
	return 0;
}

/*
ABDECF
DBEACF
*/
