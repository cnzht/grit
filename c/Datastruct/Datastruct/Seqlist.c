#include <stdio.h>//ϵͳ�⺯����ǰ��
#include <string.h>
#include <malloc.h>
typedef int DATATYPE;//�ȶ�����ʹ�ã�
#include "Seqlist.h"//�Զ���⺯���ں�

void Listinit(Seqlist *L)//�ṹ���ʼ����
{
	L->size=0;//��ʼ��Ԫ�ظ�����
}
DATATYPE Listlength(Seqlist L)//��ǰԪ�ظ���������
{	
	return L.size;
}
DATATYPE Listinsert(Seqlist *L, int i, DATATYPE x)//��ԭ����λ��iǰ����x������
{
	int j;
	if (L->size>=MAX_SIZE)
	{
		printf("���������޷����룡");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("����λ��i���Ϸ���");
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
DATATYPE Listget(Seqlist L, int i, DATATYPE *x)//ȡ�����е�i��λ�����ݵĺ�����
{
	if (i<0 || i>L.size-1)
	{
		printf("����λ��i���Ϸ���");
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
		printf("������û�п���ɾ����Ԫ�أ�");
		return 0;
	}
	else if (i>L->size-1||i<0)
	{
		printf("ɾ��λ��i���Ϸ���");
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