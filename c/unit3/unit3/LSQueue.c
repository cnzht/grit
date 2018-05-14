#include "LSQueue.h"

/*
void QueueInitiate(SeqQueue *);//��ʼ�����У�
int QueueNoEmpty(SeqQueue);//�ж϶����Ƿ�Ϊ�գ�
int QueueAppend(SeqQueue *, DataType x);//��ӣ�
int QueueDelete(SeqQueue *, DataType *x);//���ӣ�
int QueueGet(SeqQueue, DataType *x);//ȡ��ͷ��
*/

void QueueInitiate(SeqQueue * Q)//��ʼ�����У�
{
	Q->front = 0;
	Q->rear = 0;
	Q->count = 0;
}
int QueueNoEmpty(SeqQueue Q)//�ж϶����Ƿ�Ϊ�գ�
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
int QueueAppend(SeqQueue * Q, DataType x)//��ӣ�
{
	if (Q->count>0&&Q->rear==Q->front)
	{
		printf("����������");
		return 0;
	}
	else
	{
		Q->queue[Q->rear]= x;
		Q->rear=(Q->rear+1)%MaxQueueSize ;//�ؼ�����1~maxqueuesize��
		Q->count++;
		return 1;
	}
}
int QueueDelete(SeqQueue * Q, DataType *x)//���ӣ�
{
	if (Q->count==0)
	{
		printf("�����ѿգ�");
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
int QueueGet(SeqQueue Q, DataType *x)//ȡ��ͷ��
{
	if (Q.count == 0)
	{
		printf("�����ѿգ�");
		return 0;
	}
	else
	{
		*x = Q.queue[Q.front];
		return 1;
	}
}