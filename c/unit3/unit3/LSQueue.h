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


void QueueInitiate(SeqQueue *);//��ʼ�����У�
int QueueNoEmpty(SeqQueue);//�ж϶����Ƿ�Ϊ�գ�
int QueueAppend(SeqQueue *, DataType );//��ӣ�
int QueueDelete(SeqQueue *, DataType *);//���ӣ�
int QueueGet(SeqQueue, DataType *);//ȡ��ͷ��

#endif