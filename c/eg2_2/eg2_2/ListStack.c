#include "ListStack.h"

/*
void StackInitiate(SeqStack *);//��ʼ��ջ��
int StackNoEmpty(SeqStack);//�жϷǿ�ջ��
int StackPush(SeqStack *, DataType);//ѹ��������ջ��
int StackPop(SeqStack *, DataType *);//ȡ�����ݳ�ջ��
int StackTop(SeqStack, DataType *);//ȡ��ջ�����ݣ�
*/

void StackInitiate(SeqStack *S)//��ʼ��ջ��
{
	S->top = 0;
}
int StackNoEmpty(SeqStack S)//�жϷǿ�ջ��
{
	if (S.top>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int StackPush(SeqStack * S, DataType x)//ѹ��������ջ��
{
	if (S->top>=MaxStackSize)
	{
		printf("��ջ������");
		return 0;
	}
	else
	{
		S->stack[S->top] = x;
		S->top++;
		return 1;
	}
	
}
int StackPop(SeqStack * S, DataType *x)//ȡ�����ݳ�ջ��
{
	if (S->top<=0)
	{
		printf("��ջ�ѿգ�");
		return 0;
	}
	else
	{
		S->top--;
		*x = S->stack[S->top];
		return 1;
	}
}
int StackTop(SeqStack S, DataType *x)//ȡ��ջ�����ݣ�
{
	if (S.top <= 0)
	{
		printf("��ջ�ѿգ�");
		return 0;
	}
	else
	{
		*x = S.stack[S.top - 1];
		return 1;
	}
}