#include <stdio.h>//系统库函数在前；
#include <string.h>
#include <malloc.h>
typedef int DATATYPE;//先定义再使用；
#include "Seqlist.h"//自定义库函数在后；

void Listinit(Seqlist *L)//结构体初始化；
{
	L->size=0;//初始化元素个数；
}
DATATYPE Listlength(Seqlist L)//求当前元素个数函数；
{	
	return L.size;
}
DATATYPE Listinsert(Seqlist *L, int i, DATATYPE x)//在原数组位置i前插入x函数；
{
	int j;
	if (L->size>=MAX_SIZE)
	{
		printf("数组已满无法插入！");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("插入位置i不合法！");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
		{
			L->list[j] = L->list[j - 1];
		}
		L->list[i] = x;
		L->size++;
		return 1;
	}
}
DATATYPE Listget(Seqlist L, int i, DATATYPE *x)//取数组中第i个位置数据的函数；
{
	if (i<0 || i>L.size-1)
	{
		printf("插入位置i不合法！");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
DATATYPE dele(Seqlist *L, int i, DATATYPE *x)
{
	int j;
	if (L->size<=0)
	{
		printf("数组中没有可以删除的元素！");
		return 0;
	}
	else if (i>L->size-1||i<0)
	{
		printf("删除位置i不合法！");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for ( j = i; j < L->size-1; j++)
		{
			L->list[j] = L->list[j+1];
		}
		L->size--;
		return 1;
	}
}