#ifndef LSSTACK_H
#define LSSTACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct node
{
	struct node *nex;
	DataType data;
}LSNode;

void LSStackInitiate(LSNode **);//��ʽ��ջ��ʼ����
int LSStackNoEmpty(LSNode *);//�ж�Ϊ�շ�
int LSStackPush(LSNode *, DataType );//��ջ��
int LSStackPop(LSNode *, DataType *);//��ջ��
int LSStackTop(LSNode *, DataType *);//ȡջ����
void Destroy(LSNode *);//�ͷ��ڴ棻

#endif 