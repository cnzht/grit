#include "ListStack.h"

/*
void StackInitiate(SeqStack *);//初始化栈；
int StackNoEmpty(SeqStack);//判断非控栈；
int StackPush(SeqStack *, DataType);//压入数据入栈；
int StackPop(SeqStack *, DataType *);//取出数据出栈；
int StackTop(SeqStack, DataType *);//取出栈顶数据；
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
			printf("入栈错误！");
			getchar();
			return;
		}
	}
	
	for ( i = 0; i < MaxStackSize; i++)
	{
		printf("当前栈顶数据为：");
		if (StackTop(stack, &x) == 0)
		{
			printf("该栈已空");
			return;
		}
		else
		{
			printf("%d\n", x);
		}
		printf("当前取出数据为：");
		if ((StackNoEmpty(stack)) == 0)
		{
			printf("该栈已空");
			return;
		}
		else
		{
			if ((StackPop(&stack,&x))==0)
			{
				printf("该栈已空");
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