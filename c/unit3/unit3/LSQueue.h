#ifndef LSQUEUE_H
#define _CRT_SECURE_NO_WARNINGS
#define MaxQueueSize 6

#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct queue
{
	DataType queue[MaxQueueSize];
	int front;
	int rear;
	int count;
}SeqQueue;


void QueueInitiate(SeqQueue *);//初始化队列；
int QueueNoEmpty(SeqQueue);//判断队列是否为空；
int QueueAppend(SeqQueue *, DataType );//入队；
int QueueDelete(SeqQueue *, DataType *);//出队；
int QueueGet(SeqQueue, DataType *);//取队头；

#endif