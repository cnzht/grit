#include "LSQueue.h"

/*
void QueueInitiate(SeqQueue *);//初始化队列；
int QueueNoEmpty(SeqQueue);//判断队列是否为空；
int QueueAppend(SeqQueue *, DataType x);//入队；
int QueueDelete(SeqQueue *, DataType *x);//出队；
int QueueGet(SeqQueue, DataType *x);//取队头；
*/

void QueueInitiate(SeqQueue * Q)//初始化队列；
{
	Q->front = 0;
	Q->rear = 0;
	Q->count = 0;
}
int QueueNoEmpty(SeqQueue Q)//判断队列是否为空；
{
	if (Q.count==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int QueueAppend(SeqQueue * Q, DataType x)//入队；
{
	if (Q->count>0&&Q->rear==Q->front)
	{
		printf("队列已满！");
		return 0;
	}
	else
	{
		Q->queue[Q->rear]= x;
		Q->rear=(Q->rear+1)%MaxQueueSize ;//关键！！1~maxqueuesize；
		Q->count++;
		return 1;
	}
}
int QueueDelete(SeqQueue * Q, DataType *x)//出队；
{
	if (Q->count==0)
	{
		printf("队列已空！");
		return 0;
	}
	else
	{
		*x = Q->queue[Q->front];
		Q->front = (Q->front + 1) % MaxQueueSize;
		Q->count--;
		return 1;
	}
}
int QueueGet(SeqQueue Q, DataType *x)//取队头；
{
	if (Q.count == 0)
	{
		printf("队列已空！");
		return 0;
	}
	else
	{
		*x = Q.queue[Q.front];
		return 1;
	}
}