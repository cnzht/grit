#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef int DATATYPE;
#include "Seqlist.h"

/*
int main()
{
	Seqlist mylist;
	int i, x,y, n=0;
	int *arry;

	printf("������������鳤�ȣ�");
	scanf("%d",&n);
	arry = (int*)malloc(n*sizeof(int));
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &arry[i]);
	}
	

	Listinit(&mylist);
	for (  i = 0; i < n; i++)
	{
		if (Listinsert(&mylist,i,arry[i])==0)
		{
			printf("error!\n");
			getchar();
			return;
		}
	}

	n = Listlength(mylist);

	printf("������ɾ��λ��:");
	scanf("%d", &i);
	if (dele(&mylist,i,&y)==0)
	{
		printf("����");
		getchar();
		getchar();
		return;
	}
	for ( i = 0; i < n; i++)
	{
		if (Listget(mylist, i, &x) == 0)
		{
			printf("error!\n");
			getchar();
			return;
		}
		else
		{
			printf("%3d", x);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
*/

void main(void)//2018��5��8�� 17:00:04
{
	Seqlist mylist;
	int i=0, x;

	Listinit(&mylist);
	for ( i = 0; i < 10; i++)
	{
		if (Listinsert(&mylist, i, i+1) == 0)
		{
			printf("����");
			getchar();
			getchar();
			return;
		}
	}
	printf("������ɾ��λ��:");
	scanf("%d", &i);
	if (dele(&mylist, i, &x) == 0)
	{
		printf("����");
		getchar();
		return;
	}
	for (i = 0; i < Listlength(mylist); i++)
	{
		if (Listget(mylist, i, &x) == 0)
		{
			printf("error!\n");
			getchar();
			return;
		}
		else
		{
			printf("%3d", x);
		}
	}
	printf("\n");
	getchar();
	getchar();

}