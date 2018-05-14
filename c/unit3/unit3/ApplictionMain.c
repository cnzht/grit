//该程序是队列和堆栈的应用，判断一段字符是否是“回文”；
//2018年5月14日 17:19:02；
//作者：周某人；
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
		if (QueueDelete(&myQueue, &x) == 1&&LSStackPop(&myStack,&y)&&x!=y)//利用队列先进先出，和堆栈先进后出的原理，分别对比输入输出元素是否相等；
		{
			printf("%d不是回文！\n", str);
			getchar();
			return;
		}
	}
	if (QueueNoEmpty(myQueue)||LSStackNoEmpty(&myStack))
	{
		printf("%d不是回文！\n",str);
	}
	else
	{
		printf("%d是回文！\n", str);
	}
}

int main()
{
	int str1[] = { 1,2,3,4,3,2,1 }, str2[] = {1,2,3,4,5,6,7};

	HuiWen(str1);
	HuiWen(str2);

}