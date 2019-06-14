/*
 * 关键字集合为{19,01,23,14,55,68,11,82,36},哈希表表长为11，哈希函数H(key)=key mod 11
 * 分别用线性探测法、二次探测法处理冲突，构造哈希表，并给出查找成功与查找不成功的ASL
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * 线性探测法:构造哈希表
 * @param int *data 数据
 * @param int n 数据个数
 * @param int *hash 哈希表
 * @param int m 哈希表表长
 * @return int 是否构建成功
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
 * 线性探测法:查找数据
 * @param int *hash 哈希表
 * @param int m 哈希表长度
 * @param int x 待查找数据
 * @return int 数据下标,找不到返回-1
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
 * 线性探测法：计算查找成功时的ASL
 * @param int *hash 哈希表
 * @param int m 哈希表数据个数
 * @return int 查找成功时ASL分子
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
 * 线性探测法：计算查找不成功时的ASL
 * @param int *hash 哈希表
 * @param int m 哈希表数据个数
 * @return int 查找成功时ASL分子
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
 * 二次探测法:构造哈希表
 * @param int *data 数据
 * @param int n 数据个数
 * @param int *hash 哈希表
 * @param int m 哈希表表长
 * @return int 是否构建成功
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
 * 二次探测法:查找数据
 * @param int *hash 哈希表
 * @param int m 哈希表长度
 * @param int x 待查找数据
 * @return int 数据下标,找不到返回-1
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
 * 二次探测法：计算查找成功时的ASL
 * @param int *hash 哈希表
 * @param int m 哈希表数据个数
 * @return int 查找成功时ASL分子
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
 * 二次探测法：计算查找不成功时的ASL
 * @param int *hash 哈希表
 * @param int m 哈希表数据个数
 * @return int 查找成功时ASL分子
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
	printf("请输入数据个数:");
	scanf("%d",&n);
	data = (int *)malloc(n*sizeof(int));
	if(data == NULL){
		return -1;
	}
	printf("请输入%d个数据:");
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("请输入哈希表长度:");
	scanf("%d",&m);
	hash = (int *)malloc(m*sizeof(int));
	if(hash == NULL){
		return -1;
	}
	printf("数据为:");
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	printf("\n****************线性探测法*********************");
	printf("\n哈希表为:");
	if(0 == createHash1(data,n,hash,m)){
		for(i=0;i<m;i++){
			printf("%d ",hash[i]);
		}
		putchar('\n');
	}else{
		printf("构造失败！\n");
	}
	printf("请输入待查找数据:");
	scanf("%d",&k);
	if((k = search1(hash,m,k)) != -1){
		printf("该数据下标为:%d\n",k);
	}else{
		printf("该数据不存在!\n");
	}
	printf("查找成功的ASL= %d/%d\n",successASL1(hash,m),n);
	printf("查找不成功的ASL= %d/%d\n",unsuccessASL1(hash,m),m);
	printf("*************************************************\n\n\n");
	printf("******************二次探测法*********************\n");
	printf("哈希表为:");
	if(0 == createHash2(data,n,hash,m)){
		for(i=0;i<m;i++){
			printf("%d ",hash[i]);
		}
		putchar('\n');
	}else{
		printf("构造失败！\n");
	}
	printf("请输入待查找数据:");
	scanf("%d",&k);
	if((k = search2(hash,m,k)) != -1){
		printf("该数据下标为:%d\n",k);
	}else{
		printf("该数据不存在!\n");
	}
	printf("查找成功的ASL= %d/%d\n",successASL2(hash,m),n);
	printf("查找不成功的ASL= %d/%d\n",unsuccessASL2(hash,m),m);
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
