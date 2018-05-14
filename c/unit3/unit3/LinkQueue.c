#include "LinkQueue.h"

void QueueInitiate(LQueue * Q)//初始化；
{
	Q->rear = NULL;
	Q->front = NULL;
}
int QueueNoEmpty(LQueue Q)//判断链式队列是否为空；
{
	if (Q.front==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int QueueAppend(LQueue * Q, DataType x)//增加队列元素；
{
	LQNode *p;

	if ((p=(LQNode*)malloc(sizeof(LQNode)))==NULL)
	{
		printf("内存不足，无法分配！");
		return 0;
	}

		p->data = x;
		p->next = NULL;
		if (Q->rear!=NULL)
		{
			Q->rear->next = p;
		}
		Q->rear = p;
		if (Q->front==NULL)
		{
			Q->front = p;
		}
		return 1;
}
int QueueDelete(LQueue * Q, DataType * x)//取出队列元素；
{
	LQNode *p;

	if ((p = (LQNode*)malloc(sizeof(LQNode))) == NULL)
	{
		printf("内存不足，无法分配！");
		return 0;
	}
	else
	{
		*x = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if (Q->front==p)//若只有一个元素的情况下；
		{
			Q->rear = Q->front;
		}
		free(p);
		return 1;
	}
}
int QueueGet(LQueue Q, DataType * x)//取队列头；
{
	if (Q.front==NULL)
	{
		printf("队列已空，无元素取出");
		return 0;
	}
	else
	{
		*x = Q.front->data;
		return 1;
	}
}
void QueueDstory(LQueue * Q)//删除队列；
{
	LQNode *p, *q;

	p = Q->front;
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}