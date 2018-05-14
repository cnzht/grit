//�ó����Ƕ��кͶ�ջ��Ӧ�ã��ж�һ���ַ��Ƿ��ǡ����ġ���
//2018��5��14�� 17:19:02��
//���ߣ���ĳ�ˣ�
#include <stdio.h>
#include <string.h>
#include "LSQueue.h"
#include "SLStack.h"

void HuiWen(int *str)
{
	SeqQueue myQueue;
	LSNode myStack;
	int x, y;
	int i, length;

	length = 7;
	QueueInitiate(&myQueue);
	LSStackInitiate(&myStack);
	for ( i = 0; i < length; i++)
	{
		QueueAppend(&myQueue, str[i]);
		LSStackPush(&myStack, str[i]);
	}
	while (QueueNoEmpty(myQueue)==1&&LSStackNoEmpty(&myStack)==1)
	{
		if (QueueDelete(&myQueue, &x) == 1&&LSStackPop(&myStack,&y)&&x!=y)//���ö����Ƚ��ȳ����Ͷ�ջ�Ƚ������ԭ���ֱ�Ա��������Ԫ���Ƿ���ȣ�
		{
			printf("%d���ǻ��ģ�\n", str);
			getchar();
			return;
		}
	}
	if (QueueNoEmpty(myQueue)||LSStackNoEmpty(&myStack))
	{
		printf("%d���ǻ��ģ�\n",str);
	}
	else
	{
		printf("%d�ǻ��ģ�\n", str);
	}
}

int main()
{
	int str1[] = { 1,2,3,4,3,2,1 }, str2[] = {1,2,3,4,5,6,7};

	HuiWen(str1);
	HuiWen(str2);

}