#include "LinkQueue.h"

/*void QueueInitiate(LQueue *);
int QueueNoEmpty(LQueue);
int QueueAppend(LQueue *, DataType);
int QueueDelete(LQueue *, DataType *);
void QueueGet(LQueue Q, DataType * x);
void QueueDstory(LQueue *);*/

int main()
{
	LQueue Queue;
	int i, x;

	QueueInitiate(&Queue);
	for ( i = 0; i < 10; i++)
	{
		if ((QueueAppend(&Queue, i + 1)) == 0)
		{
			printf("\n入队列错误！\n");
			getchar();
			return;
		}
	}
	printf("队头：");
	QueueGet(Queue, &x);
	printf("  %d\n", x);
	for ( i = 0; i < 10; i++)
	{
		if ((QueueNoEmpty(Queue)) == 0)
		{
			printf("\n原有队列为空！\n");
			getchar();
			return;
		}
		else
		{
			if ((QueueDelete(&Queue,&x))==0)
			{
				printf("\n队列为空！\n");
				getchar();
				return;
			}
			else
			{
				printf("%d  ", x);
			}
		}
	}
	QueueDstory(&Queue);
	getchar();
	getchar();
	return 0;
}