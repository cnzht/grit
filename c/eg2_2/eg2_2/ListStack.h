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

void StackInitiate(SeqStack *);//��ʼ��ջ��
int StackNoEmpty(SeqStack);//�жϷǿ�ջ��
int StackPush(SeqStack *, DataType);//ѹ��������ջ��
int StackPop(SeqStack *, DataType *);//ȡ�����ݳ�ջ��
int StackTop(SeqStack , DataType *);//ȡ��ջ�����ݣ�


#endif