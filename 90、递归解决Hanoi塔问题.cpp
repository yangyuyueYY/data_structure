/*
 * �ݹ���Hanoi������
 */
#include <stdio.h>

/*
 * �ƶ�������
 * @param char a Դ��
 * @param int n �̺�
 * @param char b Ŀ����
 * @return int �Ƿ��ƶ��ɹ�,0Ϊ�ɹ���-1Ϊʧ��
 */
int move(char a,int n,char b)
{
	printf("��%c�̵�%d�����Ƶ�%c��\n",a,n,b);
	return 0;
}

/*
 * Hanoi���ݹ麯��
 * @param int n ����
 * @param char a Դ��
 * @param char b ������
 * @param char c Ŀ����
 * @return int �Ƿ�ɹ���0�ɹ���-1ʧ��
 */
int hanoi(int n,char a,char b,char c)
{
	if(n == 1){
		move(a,1,c);
		return 0;
	}else{
		hanoi(n-1,a,c,b);
		move(a,n,c);
		hanoi(n-1,b,a,c);
	}
}

int main()
{
	int n;
	printf("����������:");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	return 0;
}