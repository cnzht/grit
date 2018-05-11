#include "LinList.h"

/*
void ListInitiate(SLNODE ** head);//链表初始化；
int ListLength(SLNODE *head);//返回链表长度；
int ListInsert(SLNODE *head, int i, DataType x);//在某个位置i处插入数据；
int ListDelete(SLNODE *head, int i, DataType *x);//删除i处的数据；
int ListGet(SLNODE *head, int i, DataType *x);//获取某个位置i处的数据；
void DeleteList(SLNODE **head);//清空链表；

void ListSort(SLNODE *head);//单链表排序；
*/

int main()
{
	SLNODE *head;//定义头指针变量；
	int i, x, num = 0;
	//head = (SLNODE*)malloc(sizeof(SLNODE));
	ListInitiate(&head);//初始化（使得这个链表带头指针）；
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		if (ListInsert(head,i,num)==0)
		{
			printf("插入错误！\n");
			getchar();
			return;
		}
	}
	if (ListDelete(head,4,&x)==0)
	{
		printf("删除错误！\n");
		getchar();
		return;
	}
	for ( i = 0; i < ListLength(head); i++)
	{
		if (ListGet(head, i, &x) == 0)
		{
			printf("取出错误！\n");
			getchar();
			return;
		}
		else
		{
			printf("%d      ", x);
		}
	}
	printf("\n排序后：\n");
	LinListInsert(head, 3);
	LinListSort(head);//排序问题；
	for (i = 0; i < ListLength(head); i++)
	{
		if (ListGet(head, i, &x) == 0)
		{
			printf("取出错误！\n");
			getchar();
			return;
		}
		else
		{
			printf("%d      ", x);
		}
	}
	DeleteList(&head);//最后清空链表；

	getchar();
	return 0;
}