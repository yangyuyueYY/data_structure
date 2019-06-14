/*
 * ���ʽ��ֵ��ֱ����ֵ
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
 * ˳��ջ���ж�ջ��
 * @param Stack q ˳��ջ
 * @return int �Ƿ�Ϊ�գ�1��Ϊ�գ�0Ϊ��
 */
int isEmptyStack(Stack q)
{
	if(q.top == 0){
		return 0;
	}
	return 1;
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
 * ���ʽ����
 * @param char *a ���ʽ
 * @return int ���ռ���ֵ
 */
int calculate(char *a)
{
	int n,i,x,y;
	char top,t1,t2,t,data,result;
	int tn;
	Stack s1,s2;
	n = strlen(a);
	initStack(&s1,20);
	initStack(&s2,20);
	pushStack(&s2, '#');
	for(i=0;i<n;i++){
		if(a[i] <= '9' && a[i] >= '0'){
			pushStack(&s1, a[i]);
		}else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			getTopStack(s2,&top);
			x = judge(top);
			y = judge(a[i]);
			if(x < y){
				pushStack(&s2, a[i]);
			}else{
				popStack(&s2, &top);
				popStack(&s1, &t2);
				popStack(&s1, &t1);
				if(top == '+'){
					tn = (t1-'0') + (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '-'){
					tn = (t1-'0') - (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '*'){
					tn = (t1-'0') * (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(top == '/'){
					tn = (t1-'0') / (t2-'0');
					pushStack(&s1, tn+'0');
				}
				pushStack(&s2, a[i]);
			}
		}else if(a[i] == '('){
			pushStack(&s2, a[i]);
		}else if(a[i] == ')'){
			popStack(&s2, &data);
			while(data != '('){
				popStack(&s1, &t2);
				popStack(&s1, &t1);
				if(data == '+'){
					tn = (t1-'0') + (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '-'){
					tn = (t1-'0') - (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '*'){
					tn = (t1-'0') * (t2-'0');
					pushStack(&s1, tn+'0');
				}else if(data == '/'){
					tn = (t1-'0') / (t2-'0');
					pushStack(&s1, tn+'0');
				}
				popStack(&s2, &data);
			}
		}
	}
	popStack(&s2, &data);
	while(data != '#'){
		popStack(&s1, &t2);
		popStack(&s1, &t1);
		if(data == '+'){
			tn = (t1-'0') + (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '-'){
			tn = (t1-'0') - (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '*'){
			tn = (t1-'0') * (t2-'0');
			pushStack(&s1, tn+'0');
		}else if(data == '/'){
			tn = (t1-'0') / (t2-'0');
			pushStack(&s1, tn+'0');
		}
		popStack(&s2, &data);
	}
	popStack(&s1,&result);
	return result-'0';
}

int main()
{
	char a[40];
	printf("��������ʽ:");
	scanf("%s",a);
	printf("���ʽ���Ϊ:%d\n",calculate(a));
	return 0;
}
