#include "LinList.h"

void ListInitiate(SLNODE ** head)//链表初始化；
{
	if ((*head=(SLNODE*)malloc(sizeof(SLNODE)))==NULL)
	{
		exit(1);
	}
	(*head)->next = NULL;//头指针置空；
}
int ListLength(SLNODE *head)//返回链表长度；
{
	SLNODE *p=head;
	int i;//统计链表长度；

	for (i = 0; p->next!=NULL; i++)
	{
		p = p->next;
	}
	return i;
}
int ListInsert(SLNODE *head, int i, DataType x)//在某个位置i处插入数据；
{
	SLNODE *p=head, *q;

	q = (SLNODE *)malloc(sizeof(SLNODE));
	int j = -1;

	while(p->next!=NULL&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j!=i-1)
	{
		printf("插入位置有误！");
		return 0;//错误标志位，返回0代表插入位置错误；
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;//成功标志位，返回1代表插入成功；
}
int ListDelete(SLNODE *head, int i, DataType *x)//删除i处的数据；
{
	SLNODE *p = head, *q;//指针q代表带删除位；

	q = (SLNODE *)malloc(sizeof(SLNODE));
	int j = -1;

	while(p->next != NULL&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("删除位置有误！");
		return 0;//错误标志位，返回0代表插入位置错误；
	}
	q = p->next;
	*x = q->data;//将删除的数返回；
	p->next = p->next->next;
	free(q);
	return 1;
}
int ListGet(SLNODE *head, int i, DataType *x)//获取某个位置i处的数据；
{
	SLNODE *p = head;//指针q代表带删除位；
	int j = -1;

	while(p->next != NULL&&j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("取出位置有误！");
		return 0;//错误标志位，返回0代表插入位置错误；
	}
	*x = p->data;
	return 1;
}
void DeleteList(SLNODE **head)//清空链表；
{
	SLNODE *p, *q;

	//q = (SLNODE **)malloc(sizeof(SLNODE*));
	p = *head;
	for (; p->next!= NULL; )
	{
		q = p;
		p = p->next;//如果不放在这里，将断链；
		free(q);
	}
	*head = NULL;//头指针置为空；

}

void LinListInsert(SLNODE *head, DataType x)
{
	SLNODE *curr, *p, *q;

	curr = head->next;
	p = head;

	while ( curr!=NULL&&curr->data<=x)
	{
		p = curr;
		curr = curr->next;
	}
	if ((q=(SLNODE*)malloc(sizeof(SLNODE)))==NULL)
	{
		exit(1);
	}
	q->data = x;

	q->next = p->next;
	p->next = q;
}

void LinListSort(SLNODE *head)
{
	SLNODE *curr, *pre, *p, *q;

	p = head->next;
	head->next = NULL;
	
	while (p!=NULL)
	{
		curr = head->next;
		pre = head;

		while (curr!=NULL&&curr->data<=p->data)
		{
			pre = curr;
			pre = pre->next;
			curr = curr->next;
		}
		q = p;
		p = p->next;
		q->next = p->next;
		p->next = q;
	}
}