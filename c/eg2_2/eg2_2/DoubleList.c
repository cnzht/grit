#include "DoubleList.h"

/*
void ListInitiate(DLNode ** head);//链表初始化；
int ListLength(DLNode *head);//返回链表长度；
int ListInsert(DLNode *head, int i, DataType x);//在某个位置i处插入数据；
int ListDelete(DLNode *head, int i, DataType *x);//删除i处的数据；
int ListGet(DLNode *head, int i, DataType *x);//获取某个位置i处的数据；
void DeleteList(DLNode **head);//清空链表；

//自定义
int ListDataDelete(DLNode *head, DataType x);//删除指定数字；
*/

void ListInitiate(DLNode ** head)//链表初始化；
{
	if ((*head=(DLNode*)malloc(sizeof(DLNode)))==NULL)
	{
		exit(0);
	}
	(*head)->prior = *head;
	(*head)->next = *head;
}
int ListLength(DLNode *head)//返回链表长度；//有问题。
{
	DLNode *p = head->next;
	int i = 0;

	while (p!=head)
	{
		i++;
		p = p->next;
	}
	return i;
}
int ListInsert(DLNode *head, int i, DataType x)//在某个位置i处插入数据；
{
	DLNode *p , *q;
	int j = 0;

	p = head->next;
	while (p!=head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i)
	{
		printf("插入位置错误！\n");
		return 0;
	}
	if((q = (DLNode*)malloc(sizeof(DLNode)))==NULL)exit(0);
	q->data = x;
	
	q->prior = p->prior;//画图理解；
	p->prior->next = q;
	q->next = p;
	p->prior = q;

	return 1;
}
int ListDelete(DLNode *head, int i, DataType *x)//删除i处的数据；
{
	DLNode *p = head->next;
	int j = 0;

	while (p != head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("删除位置错误！\n");
		return 0;
	}
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	*x = p->data;
	free(p);
	return 1;

}
int ListGet(DLNode *head, int i, DataType *x)//获取某个位置i处的数据；
{
	DLNode *p = head->next;
	int j = 0;

	while (p != head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("取出位置错误！\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
void DeleteList(DLNode **head)//清空链表；
{
	DLNode *p, *q;
	int i, n = ListLength(*head);

	p = *head;
	for ( i = 0; i < n; i++)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}
int ListDataDelete(DLNode *head, DataType x)
{
	DLNode *p=head;

	if (p->data==x)//如果是第一个元素就是要删除的元素；
	{
		head = p->next;//头指针直接指向下一个节点；
		//head->next = p->next;
		head->prior = NULL;
		free(p);
		return 1;
	}
	while (p)//如果上面条件不成立，则遍历所有元素；
	{
		if (p->data == x)
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			free(p);
		}
		return 1;
	}
	printf("没有找到要删除的值！\n");
	return 0;
}