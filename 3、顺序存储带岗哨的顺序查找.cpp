/*
 * ˳��洢�����ڵ�˳�����
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * ���Һ���
 * @param int* data �������Ա�
 * @param int n ���ݸ���
 * @param int x ����������
 * @return int ����λ�ã��Ҳ�������0
 */
int search(int *data, int n, int x)
{
	data[0] = x;
	while(1){
		if(data[n] == x){
			return n;
		}else{
			n --;
		}
	}
}

int main()
{
	int *data,n,i,x,a;
	printf("���������ݸ���:");
	scanf("%d",&n);
	data = (int *)malloc((n+1)*sizeof(int));
	printf("������%d������:",n);
	for(i=1;i<=n;i++){
		scanf("%d",&data[i]);
	}
	printf("���Ա�Ϊ:");
	for(i=1;i<=n;i++){
		printf("%d ",data[i]);
	}
	putchar('\n');
	printf("���������������:");
	scanf("%d",&x);
	if((a=search(data,n,x)) == 0){
		printf("����%d������!\n",x);
	}else{
		printf("����%dλ��Ϊ%d!\n",x,a);
	}
	return 0;
}