/*
 * �ؼ��ּ���Ϊ{19,01,23,14,55,68,11,82,36},��ϣ���Ϊ11����ϣ����H(key)=key mod 11
 * �ֱ�������̽�ⷨ������̽�ⷨ�����ͻ�������ϣ�����������ҳɹ�����Ҳ��ɹ���ASL
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * ����̽�ⷨ:�����ϣ��
 * @param int *data ����
 * @param int n ���ݸ���
 * @param int *hash ��ϣ��
 * @param int m ��ϣ���
 * @return int �Ƿ񹹽��ɹ�
 */
int createHash1(int *data,int n,int *hash,int m)
{
	int i,j;
	for(i=0;i<m;i++){
		hash[i] = 0;
	}
	for(i=0;i<n;i++){
		j = data[i] % m;
		if(hash[j] == 0){
			hash[j] = data[i];
		}else{
			j = (j+1)%m;
			while(hash[j] != 0){
				j = (j+1)%m;
			}
			hash[j] = data[i];
		}
	}
	return 0;
}

/*
 * ����̽�ⷨ:��������
 * @param int *hash ��ϣ��
 * @param int m ��ϣ����
 * @param int x ����������
 * @return int �����±�,�Ҳ�������-1
 */
int search1(int *hash,int m,int x)
{
	int i;
	i = x % m;
	if(hash[i] == x){
		return i;
	}
	i = (i+1) % m;
	while(hash[i] != x && i != x%m){
		i = (i+1)%m;
	}
	if(hash[i] == x){
		return i;
	}
	return -1;
}

/*
 * ����̽�ⷨ��������ҳɹ�ʱ��ASL
 * @param int *hash ��ϣ��
 * @param int m ��ϣ�����ݸ���
 * @return int ���ҳɹ�ʱASL����
 */
int successASL1(int *hash,int m)
{
	int i,sum = 0,k;
	for(i=0;i<m;i++){
		if(hash[i] != 0){
			k = hash[i] % m;
			sum += (i+m-k+1) % m;
		}
	}
	return sum;
}

/*
 * ����̽�ⷨ��������Ҳ��ɹ�ʱ��ASL
 * @param int *hash ��ϣ��
 * @param int m ��ϣ�����ݸ���
 * @return int ���ҳɹ�ʱASL����
 */
int unsuccessASL1(int *hash,int m)
{
	int i,sum = 0,j,k;
	for(i=0;i<m;i++){
		j = 0;
		k = i;
		while(hash[k] != 0){
			j ++;
			k = (k+1)%m;
		}
		sum += j;
	}
	return sum;
}

/*
 * ����̽�ⷨ:�����ϣ��
 * @param int *data ����
 * @param int n ���ݸ���
 * @param int *hash ��ϣ��
 * @param int m ��ϣ���
 * @return int �Ƿ񹹽��ɹ�
 */
int createHash2(int *data,int n,int *hash,int m)
{
	int i,j,t,k,y=1;
	for(i=0;i<m;i++){
		hash[i] = 0;
	}
	for(i=0;i<n;i++){
		t = 1;
		y = 1;
		j = data[i] % m;
		if(hash[j] == 0){
			hash[j] = data[i];
		}else{
			k = j+t;
			t *= -1;
			if(k >= m){
				k = j;
			}
			while(hash[k] != 0){
				k = j+t;
				if(k<0 || k>=m){
					k = j;
				}
				t *= -1;
				if(t>0){
					y++;
					t = y*y;
				}
			}
			hash[k] = data[i];
		}
	}
	return 0;
}

/*
 * ����̽�ⷨ:��������
 * @param int *hash ��ϣ��
 * @param int m ��ϣ����
 * @param int x ����������
 * @return int �����±�,�Ҳ�������-1
 */
int search2(int *hash,int m,int x)
{
	int i,t,y=1,k;
	i = x % m;
	if(hash[i] == x){
		return i;
	}
	t = 1;
	k = i+t;
	t *= -1;
	if(k>=m){
		k = i;
	}
	while(hash[k] != x && y < sqrt(m)){
		k = i+t;
		t *= -1;
		if(t > 0){
			y ++;
			t = y*y;
		}
		if(k < 0 || k>= m){
			k = i;
		}
	}
	if(hash[k] == x){
		return k;
	}
	return -1;
}

/*
 * ����̽�ⷨ��������ҳɹ�ʱ��ASL
 * @param int *hash ��ϣ��
 * @param int m ��ϣ�����ݸ���
 * @return int ���ҳɹ�ʱASL����
 */
int successASL2(int *hash,int m)
{
	int i,sum = 0,k,d,s;
	for(i=0;i<m;i++){
		if(hash[i] != 0){
			k = hash[i] % m;
			d = k-i;
			if(d >= 0){
				s = (int)sqrt(d);
				s = s * 2 + 1;
			}else{
				s = (int)sqrt(-d);
				s = s*2 ;
			}
			sum += s;
		}
	}
	return sum;
}

/*
 * ����̽�ⷨ��������Ҳ��ɹ�ʱ��ASL
 * @param int *hash ��ϣ��
 * @param int m ��ϣ�����ݸ���
 * @return int ���ҳɹ�ʱASL����
 */
int unsuccessASL2(int *hash,int m)
{
	int i,sum = 0,j,k,t,y;
	for(i=0;i<m;i++){
		k = i;
		j = 0;
		t = 1;
		y = 1;
		while(hash[k] != 0 && y <= sqrt(m)){
			j ++;
			k = i + t;
			if(k<0 || k>= m){
				j --;
				k = i;
			}
			t *= -1;
			if(t>0){
				y ++;
				t = y*y;
			}
		}
		sum += j;
	}
	return sum;
}

int main()
{
	int i,m,n,*data,*hash,k;
	printf("���������ݸ���:");
	scanf("%d",&n);
	data = (int *)malloc(n*sizeof(int));
	if(data == NULL){
		return -1;
	}
	printf("������%d������:");
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("�������ϣ����:");
	scanf("%d",&m);
	hash = (int *)malloc(m*sizeof(int));
	if(hash == NULL){
		return -1;
	}
	printf("����Ϊ:");
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	printf("\n****************����̽�ⷨ*********************");
	printf("\n��ϣ��Ϊ:");
	if(0 == createHash1(data,n,hash,m)){
		for(i=0;i<m;i++){
			printf("%d ",hash[i]);
		}
		putchar('\n');
	}else{
		printf("����ʧ�ܣ�\n");
	}
	printf("���������������:");
	scanf("%d",&k);
	if((k = search1(hash,m,k)) != -1){
		printf("�������±�Ϊ:%d\n",k);
	}else{
		printf("�����ݲ�����!\n");
	}
	printf("���ҳɹ���ASL= %d/%d\n",successASL1(hash,m),n);
	printf("���Ҳ��ɹ���ASL= %d/%d\n",unsuccessASL1(hash,m),m);
	printf("*************************************************\n\n\n");
	printf("******************����̽�ⷨ*********************\n");
	printf("��ϣ��Ϊ:");
	if(0 == createHash2(data,n,hash,m)){
		for(i=0;i<m;i++){
			printf("%d ",hash[i]);
		}
		putchar('\n');
	}else{
		printf("����ʧ�ܣ�\n");
	}
	printf("���������������:");
	scanf("%d",&k);
	if((k = search2(hash,m,k)) != -1){
		printf("�������±�Ϊ:%d\n",k);
	}else{
		printf("�����ݲ�����!\n");
	}
	printf("���ҳɹ���ASL= %d/%d\n",successASL2(hash,m),n);
	printf("���Ҳ��ɹ���ASL= %d/%d\n",unsuccessASL2(hash,m),m);
	printf("*************************************************\n");
	return 0;
}

/*
9
19 1 23 14 55 68 11 82 36
11
23
11
*/
