#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#define MaxQueueSize 100
typedef int DataType;

#include "LinkQueue.h"

typedef struct 
{
	DataType elem;
	DataType priority;
}Task;

int  main()
{
	LQueue myPQueue;
	FILE *fp;
	Task task;
	int i;

	if ((fp=fopen("task.dat","r"))==NULL)
	{
		printf("不能打开文件！");
		exit(1);
	}

	QueueInitiate(&myPQueue);
	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &task.elem, &task.priority);
		QueueAppend(&myPQueue,task.elem);
	}
	i = 1;
	printf("序号\t任务号\t优先级\n");
	while (QueueNoEmpty(myPQueue))
	{
		QueueDelete(&myPQueue,&task.elem);
		QueueDelete(&myPQueue, &task.priority);
		printf("%d         ", i);
		printf("%d         ", task.elem);
		printf("%d         \n", task.priority);
		i++;
	}
	getchar();
	getchar();
	return 0;
}