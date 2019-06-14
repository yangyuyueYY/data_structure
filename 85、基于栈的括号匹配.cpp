/*
 * ����ջ������ƥ��
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
 * ˳��ջ����ջ
 * @param Stack *q ˳��ջ�׵�ַ
 * @param char x��������
 * @return int �Ƿ����ɹ���-1Ϊʧ�ܣ�0Ϊ�ɹ�
 */
int pushStack(Stack *q, char x)
{ 
	if(q->top == q->size){
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
		return -1;
	}
	*x = q->data[--q->top];
	return 0;
}

/*
 * �ж������Ƿ�ƥ��
 * @param char *a ���жϱ��ʽ
 * @return int �Ƿ�ƥ�䣬0Ϊ��ƥ�䣬1Ϊƥ��
 */
int match(char *a)
{ 
	Stack q;
	initStack(&q,20);
	char x;
	int i;
	int n = strlen(a);
	for(i=0;i<n;i++){
		switch(a[i]){
			case '(':
			case '[':
			case '{':
				pushStack(&q, a[i]);
				break;
			case ')':
				popStack(&q,&x);
				if(x != '('){
					return 0;
				}
				break;
			case ']':
				popStack(&q,&x);
				if(x != '['){
					return 0;
				}
				break;
			case '}':
				popStack(&q,&x);
				if(x != '{'){
					return 0;
				}
				break;
		}
		i++;
	}
	if(isEmptyStack(q) == 0){
		return 1;
	}
	return 0;
}

int main()
{	
	char a[40];
	printf("��������ʽ:");
	scanf("%s",a);
	if(match(a) == 0){
		printf("���Ų�ƥ��!\n");
	}else{
		printf("����ƥ��!\n");
	}
	return 0;
}
