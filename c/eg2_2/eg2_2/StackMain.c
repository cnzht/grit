#include "ListStack.h"

/*
void StackInitiate(SeqStack *);//��ʼ��ջ��
int StackNoEmpty(SeqStack);//�жϷǿ�ջ��
int StackPush(SeqStack *, DataType);//ѹ��������ջ��
int StackPop(SeqStack *, DataType *);//ȡ�����ݳ�ջ��
int StackTop(SeqStack, DataType *);//ȡ��ջ�����ݣ�
*/

int main()
{
	SeqStack stack;
	int i, x;

	StackInitiate(&stack);
	for ( i = 0; i < MaxStackSize; i++)
	{
		if ((StackPush(&stack, i + 1)) == 0)
		{
			printf("��ջ����");
			getchar();
			return;
		}
	}
	
	for ( i = 0; i < MaxStackSize; i++)
	{
		printf("��ǰջ������Ϊ��");
		if (StackTop(stack, &x) == 0)
		{
			printf("��ջ�ѿ�");
			return;
		}
		else
		{
			printf("%d\n", x);
		}
		printf("��ǰȡ������Ϊ��");
		if ((StackNoEmpty(stack)) == 0)
		{
			printf("��ջ�ѿ�");
			return;
		}
		else
		{
			if ((StackPop(&stack,&x))==0)
			{
				printf("��ջ�ѿ�");
				return;
			}
			else
			{
				printf("%d  \n", x);
			}
		}
		
	}

	getchar();
	return 0;
}