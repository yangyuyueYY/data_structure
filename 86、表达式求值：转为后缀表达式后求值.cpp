/*
 * ���ʽ��ֵ��תΪ��׺���ʽ����ֵ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *data;
	int top;
	int size;
}Stack;//˳��ջ

/*
 * ˳��ջ����ʼ��
 * @param Stack* q ˳��ջ�׵�ַ
 * @param int max ���������
 * @return int �Ƿ��ʼ���ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int initStack(Stack *q, int max)
{
	if(max < 0){
		printf("������������Ϸ�\n");
		return -1;
	}
	q->data = (char *)malloc(max * sizeof(char));
	if(NULL == q->data){
		printf("�ռ�����ʧ��\n");
		return -1;
	}
	q->top = 0;
	q->size = max;
	return 0;
}

/*
 * ˳��ջ���õ�ջ��
 * @param Stack q ˳��ջ
 * @param char *data ջ������
 * @return int �Ƿ��ȡ�ɹ���-1ʧ�ܣ�0�ɹ�
 */
int getTopStack(Stack q,char *data)
{
	if(q.top == 0){
		printf("ջΪ��!\n");
		return -1;
	}
	*data = q.data[q.top-1];
	return 0;
}

/*
 * ˳��ջ����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *q, char x)
{ 
	if(q->top == q->size){
		printf("ջ��!\n");
		return -1;
	}
	q->data[q->top++] = x;
	return 0;
}

/*
 * ˳��ջ����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @param char *x��ջ����
 * @return int �Ƿ��ջ�ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int popStack(Stack *q, char *x)
{ 
	if(q->top == 0){
		printf("ջ��!\n");
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * ˳��ջ������
 * @param Stack q ˳��ջ
 */
void displayStack(Stack q)
{ 
	int i;
	if(q.top == 0){
		printf("��˳���Ϊ��\n");
		return;
	}
	for(i=0;i<q.top;i++){
		printf("%c ",q.data[i]);
	}
	putchar('\n');
	return;
}

/*
 * �ж���������ȼ�
 * @param char m �����
 * @return int ���ȼ���0,1,2
 */
int judge(char m){
	if(m == '('){
		return 0;
	}
	if(m == '+' || m == '-'){
		return 1;
	}
	if(m == '*' || m == '/'){
		return 2;
	}
	if(m == '#'){
		return -1;
	}
	return -1;
}

/*
 * ��ԭ���ʽת��Ϊ��׺���ʽ
 * @param char *a ԭ���ʽ
 * @return int �Ƿ�ת���ɹ���0�ɹ���-1ʧ��
 */
int transform(char *a,char *b)
{
	int i,n,j=0;
	int x,y;
	char data;
	n = strlen(a);
	Stack q;
	initStack(&q, 20);
	pushStack(&q, '#');
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			b[j] = a[i];
			j ++;
		}else if(a[i] == '('){
			pushStack(&q, '(');
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			getTopStack(q,&data);
			x = judge(data);
			y = judge(a[i]);
			if(x < y){
				pushStack(&q, a[i]);
			}else{
				popStack(&q, &data);
				b[j] = data;
				j++;
				pushStack(&q, a[i]);
			}
		}else if(a[i] == ')'){
			popStack(&q, &data);
			while(data != '('){
				b[j] = data;
				j++;
				popStack(&q, &data);
			}
		}
	}
	getTopStack(q,&data);
	while(data != '#'){
		popStack(&q, &data);
		b[j] = data;
		j++;
	}	
	b[j-1] = '\0';
	return 0;
}

/*
 * ���ݺ�׺���ʽ��ֵ
 * @param char *a ��׺���ʽ
 * @return int ���ս��
 */
int calculate(char *a)
{
	Stack q;
	char data1,data2;
	initStack(&q, 20);
	int n,i,x;
	n = strlen(a);
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			pushStack(&q, a[i]);
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			popStack(&q, &data2);
			popStack(&q, &data1);
			if(a[i] == '+'){
				x = (data1 - '0') + (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '-'){
				x = (data1 - '0') - (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '*'){
				x = (data1 - '0') * (data2 - '0');
				pushStack(&q,x+'0');
			}else if(a[i] == '/'){
				x = (data1 - '0') / (data2 - '0');
				pushStack(&q,x+'0');
			}
		}
	}
	getTopStack(q,&data1);
	return data1-'0';
}

int main()
{
	char a[40],b[40];
	printf("������ԭ���ʽ:");
	scanf("%s",a);
	printf("ת���С���\n");
	transform(a,b);
	printf("ת����ĺ�׺���ʽΪ:");
	printf("%s\n",b);
	printf("������Ϊ:%d\n",calculate(b));
	return 0;
}
