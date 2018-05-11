#ifndef LISTSTACK_H
#define LISTSTACK_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#define MaxStackSize 100
typedef int DataType;

typedef struct
{
	DataType stack[MaxStackSize];
	int top;
}SeqStack;

void StackInitiate(SeqStack *);//初始化栈；
int StackNoEmpty(SeqStack);//判断非控栈；
int StackPush(SeqStack *, DataType);//压入数据入栈；
int StackPop(SeqStack *, DataType *);//取出数据出栈；
int StackTop(SeqStack , DataType *);//取出栈顶数据；


#endif