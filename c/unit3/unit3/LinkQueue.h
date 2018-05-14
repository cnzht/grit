#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct queue 
{
	DataType data;
	struct queue *next;
}LQNode;
typedef struct 
{
	LQNode *front;
	LQNode *rear;
}LQueue;

void QueueInitiate(LQueue *);
int QueueNoEmpty(LQueue);
int QueueAppend(LQueue *,DataType );
int QueueDelete(LQueue *, DataType *);
int QueueGet(LQueue Q, DataType * x);
void QueueDstory(LQueue *);

#endif