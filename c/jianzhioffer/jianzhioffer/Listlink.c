
#include <stdio.h>
#define MaxSzie 100

typedef int DataType;
typedef struct
{
	DataType list[MaxSzie];
	int size;
}SeqList;

void ListInit(SeqList *L)
{
	L->size = 0;
}

int ListLength(SeqList L)
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
{
	int j=0;

	if (i>=MaxSzie)
	{
		printf("error!");
		return 0;
	}
	else if (i<0||i>L->size)
	{
		printf("error!");
		return 0;
	}
	else
	{
		while (j<i)
		{
			j++;
		}
		if (j!=i)
		{
			printf("error!");
			return 0;
		}
		else
		{
			for ( j; j < L->size; j++)
			{
				L->list[j + 1] = L->list[j];
			}
			L->list[j] = x;
			L->size++;
			return 1;
		}
	}
}

int ListDelete(SeqList *L, int i, DataType *x)
{
	int j = 0;

	if (i>=MaxSzie)
	{
		printf("error!");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("error!");
		return 0;
	}
	else
	{
		while (j < i)
		{
			j++;
		}
		if (j != i)
		{
			printf("error!");
			return 0;
		}
		else
		{
			*x = L->list[j];
			for (j; j < L->size; j++)
			{
				L->list[j] = L->list[j + 1];
			}
			L->size--;
			return 1;
		}
	}
}

int ListGet(SeqList *L, int i, DataType *x)
{
	if (i<0||i>L->size-1)
	{
		printf("error!");
		return 0;
	}
	else
	{
		*x = L->list[i];
		return 1;
	}
}
//主函数
int main()
{
	SeqList mylist;
	int i, j,x;

	ListInit(&mylist);
	for ( i = 0; i < 10; i++)
	{
		if (ListInsert(&mylist, i, i + 1)==0)
		{
			printf("error!");
		}
	}
	if (ListDelete(&mylist,4,&x)==0)
	{
		printf("error!");

	}
	else
	{
		printf("Delete Number>>>%d\n", x);
	}
	for ( j = 0; j <ListLength(mylist); j++)
	{
		if (ListGet(&mylist,j,&x)==0)
		{
			printf("error!");
		}
		else
		{
			printf("%d    ",x);
		}
	}
	getchar();
	return 0;
}
