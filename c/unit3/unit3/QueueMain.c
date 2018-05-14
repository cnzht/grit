#include "LSQueue.h"

/*
void QueueInitiate(SeqQueue *);//初始化队列；
int QueueNoEmpty(SeqQueue);//判断队列是否为空；
int QueueAppend(SeqQueue *, DataType x);//入队；
int QueueDelete(SeqQueue *, DataType *x);//出队；
int QueueGet(SeqQueue, DataType *x);//取队头；
*/

int main()
{
	SeqQueue duilie;
	int i, x;

	QueueInitiate(&duilie);
	for ( i = 0; i < MaxQueueSize; i++)
	{
		if ((QueueAppend(&duilie, i + 1)) == 0)
		{
			printf("入队问题!");
			getchar();
			return;
		}
	}
	printf("队头:");
	if ((QueueNoEmpty(duilie))==0)
	{
		printf("队列为空!");
		getchar();
		return;
	}
	else
	{
		if ((QueueGet(duilie,&x))==0)
		{
			printf("队列为空!");
			getchar();
			return;
		}
		else
		{
			printf("%d\n", x);
		}
	}
	printf("\n队列如下:\n");
	for ( i = 0; i < MaxQueueSize; i++)
	{
		if ((QueueNoEmpty(duilie)) == 0)
		{
			printf("队列为空!");
			getchar();
			return;
		}
		else
		{
			if ((QueueDelete(&duilie,&x))==0)
			{
				printf("取出问题!");
				getchar();
				return;
			}
			else
			{
				printf("%d  ", x);
			}
		}
	}
	getchar();
	getchar();
	return 0;

}