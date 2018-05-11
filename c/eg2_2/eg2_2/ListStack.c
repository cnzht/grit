#include "ListStack.h"

/*
void StackInitiate(SeqStack *);//初始化栈；
int StackNoEmpty(SeqStack);//判断非控栈；
int StackPush(SeqStack *, DataType);//压入数据入栈；
int StackPop(SeqStack *, DataType *);//取出数据出栈；
int StackTop(SeqStack, DataType *);//取出栈顶数据；
*/

void StackInitiate(SeqStack *S)//初始化栈；
{
	S->top = 0;
}
int StackNoEmpty(SeqStack S)//判断非控栈；
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
int StackPush(SeqStack * S, DataType x)//压入数据入栈；
{
	if (S->top>=MaxStackSize)
	{
		printf("堆栈已满！");
		return 0;
	}
	else
	{
		S->stack[S->top] = x;
		S->top++;
		return 1;
	}
	
}
int StackPop(SeqStack * S, DataType *x)//取出数据出栈；
{
	if (S->top<=0)
	{
		printf("堆栈已空！");
		return 0;
	}
	else
	{
		S->top--;
		*x = S->stack[S->top];
		return 1;
	}
}
int StackTop(SeqStack S, DataType *x)//取出栈顶数据；
{
	if (S.top <= 0)
	{
		printf("堆栈已空！");
		return 0;
	}
	else
	{
		*x = S.stack[S.top - 1];
		return 1;
	}
}