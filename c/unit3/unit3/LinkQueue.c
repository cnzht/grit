#include "LinkQueue.h"

void QueueInitiate(LQueue * Q)//��ʼ����
{
	Q->rear = NULL;
	Q->front = NULL;
}
int QueueNoEmpty(LQueue Q)//�ж���ʽ�����Ƿ�Ϊ�գ�
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
int QueueAppend(LQueue * Q, DataType x)//���Ӷ���Ԫ�أ�
{
	LQNode *p;

	if ((p=(LQNode*)malloc(sizeof(LQNode)))==NULL)
	{
		printf("�ڴ治�㣬�޷����䣡");
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
int QueueDelete(LQueue * Q, DataType * x)//ȡ������Ԫ�أ�
{
	LQNode *p;

	if ((p = (LQNode*)malloc(sizeof(LQNode))) == NULL)
	{
		printf("�ڴ治�㣬�޷����䣡");
		return 0;
	}
	else
	{
		*x = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if (Q->front==p)//��ֻ��һ��Ԫ�ص�����£�
		{
			Q->rear = Q->front;
		}
		free(p);
		return 1;
	}
}
int QueueGet(LQueue Q, DataType * x)//ȡ����ͷ��
{
	if (Q.front==NULL)
	{
		printf("�����ѿգ���Ԫ��ȡ��");
		return 0;
	}
	else
	{
		*x = Q.front->data;
		return 1;
	}
}
void QueueDstory(LQueue * Q)//ɾ�����У�
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