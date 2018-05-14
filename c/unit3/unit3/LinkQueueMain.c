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
			printf("\n����д���\n");
			getchar();
			return;
		}
	}
	printf("��ͷ��");
	QueueGet(Queue, &x);
	printf("  %d\n", x);
	for ( i = 0; i < 10; i++)
	{
		if ((QueueNoEmpty(Queue)) == 0)
		{
			printf("\nԭ�ж���Ϊ�գ�\n");
			getchar();
			return;
		}
		else
		{
			if ((QueueDelete(&Queue,&x))==0)
			{
				printf("\n����Ϊ�գ�\n");
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