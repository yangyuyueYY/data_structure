/*
 * ˳��洢˳�����
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ���Һ���
 * @param int* data �������Ա�
 * @param int n ���ݸ���
 * @param int x ����������
 * @return int ����λ�ã��Ҳ�������-1
 */
int search(int *data, int n, int x)
{
	int i;
	for(i=0;i<n;i++){
		if(data[i] == x){
			return i+1;
		}
	}
	return -1;
}

int main()
{
	int *data,n,i,x,a;
	printf("���������ݸ���:");
	scanf("%d",&n);
	data = (int *)malloc(n*sizeof(int));
	printf("������%d������:",n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("���Ա�Ϊ:");
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	putchar('\n');
	printf("���������������:");
	scanf("%d",&x);
	if((a=search(data,n,x)) == -1){
		printf("����%d������!\n",x);
	}else{
		printf("����%dλ��Ϊ%d!\n",x,a);
	}
	return 0;
}