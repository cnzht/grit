#define MaxSzie 5
#include "DoubleList.h"

int main()
{
	DLNode *head;
	int i, x, num, size = 0, count = 0, dele = 0;

	/*
	void ListInitiate(DLNode ** head);//链表初始化；
	int ListLength(DLNode *head);//返回链表长度；
	int ListInsert(DLNode *head, int i, DataType x);//在某个位置i处插入数据；
	int ListDelete(DLNode *head, int i, DataType *x);//删除i处的数据；
	int ListGet(DLNode *head, int i, DataType *x);//获取某个位置i处的数据；
	void DeleteList(DLNode **head);//清空链表；

	int ListDataDelete(DLNode *head, DataType x);//删除指定数字；
	*/
	ListInitiate(&head);
	for ( i = 0; i < MaxSzie; i++)
	{
		scanf("%d",&num);
		if ((ListInsert(head, i, num)) == 0)
		{
			printf("插入错误！\n");
			getchar();
			return;
		}
		size++;
	}
	head->size = size;
	if ((ListDelete(head,1,&x))==0)
	{
		printf("位置删除错误！\n");
		getchar();
		return;
	}
	else
	{
		count++;
	}
	for (i = 0; i < MaxSzie - count; i++)
	{
		if ((ListGet(head, i, &x)) == 0)
		{
			printf("取出错误！\n");
			getchar();
			return;
		}
		else
		{
			printf("%d       ", x);
		}
	}
	printf("\n");
	printf("输入要删除的值：");
	scanf("%d",&dele);
	if ((ListDataDelete(head, dele)) == 0)
	{
		printf("error!");
		return;
	}
	else
	{
		count++;
	}
	for (i = 0; i < MaxSzie-count; i++)
	{
		if (( ListGet(head,i,&x)) == 0)
		{
			printf("取出错误！\n");
			getchar();
			return;
		}
		else
		{
			printf("%d       ", x);
		}
	}
	DeleteList(&head);
	getchar();
	getchar();
	return 0;
}