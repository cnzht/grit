#include "LSQueue.h"

/*
void QueueInitiate(SeqQueue *);//��ʼ�����У�
int QueueNoEmpty(SeqQueue);//�ж϶����Ƿ�Ϊ�գ�
int QueueAppend(SeqQueue *, DataType x);//��ӣ�
int QueueDelete(SeqQueue *, DataType *x);//���ӣ�
int QueueGet(SeqQueue, DataType *x);//ȡ��ͷ��
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
			printf("�������!");
			getchar();
			return;
		}
	}
	printf("��ͷ:");
	if ((QueueNoEmpty(duilie))==0)
	{
		printf("����Ϊ��!");
		getchar();
		return;
	}
	else
	{
		if ((QueueGet(duilie,&x))==0)
		{
			printf("����Ϊ��!");
			getchar();
			return;
		}
		else
		{
			printf("%d\n", x);
		}
	}
	printf("\n��������:\n");
	for ( i = 0; i < MaxQueueSize; i++)
	{
		if ((QueueNoEmpty(duilie)) == 0)
		{
			printf("����Ϊ��!");
			getchar();
			return;
		}
		else
		{
			if ((QueueDelete(&duilie,&x))==0)
			{
				printf("ȡ������!");
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