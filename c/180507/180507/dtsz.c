#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
	int i,p,q,n=0,m=0,sum=0;
	int **arry;

	printf("������������");
	scanf("%d",&n);//�����һά��̬���鳤�ȣ�
	arry = (int**)malloc(n*sizeof(int*));
	printf("������������");
	scanf("%d", &m);//����ڶ�ά��̬���鳤�ȣ�
	for ( i = 0; i < n; i++)
	{
		arry[i] = (int*)malloc(m*sizeof(int));
	}
	printf("������%dx%d�����飺\n",n,m);
	for ( p = 0; p < n; p++)
	{
		for (q = 0; q <m ; q++)
		{
			//arry[p][q] = p*q;
			scanf("%d", &arry[p][q]);
		}
	}
	printf("%dx%d�����飺\n", n, m);
	for (p = 0; p < n; p++)
	{
		for (q = 0; q < m ; q++)
		{
			printf("%3d",arry[p][q]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		sum += arry[i][i];
	}
	printf("\n���%dx%d����ĶԽ���֮��=%d\n", n, m, sum);
	for ( i = 0; i < n; i++)
	{
		free(arry[i]);
	}
	free(arry);
	system("pause");
	return 0;
}