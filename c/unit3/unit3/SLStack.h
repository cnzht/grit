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

void LSStackInitiate(LSNode **);//链式堆栈初始化；
int LSStackNoEmpty(LSNode *);//判断为空否；
int LSStackPush(LSNode *, DataType );//入栈；
int LSStackPop(LSNode *, DataType *);//出栈；
int LSStackTop(LSNode *, DataType *);//取栈顶；
void Destroy(LSNode *);//释放内存；

#endif 