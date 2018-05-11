#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
	int i,p,q,n=0,m=0,sum=0;
	int **arry;

	printf("请输入行数：");
	scanf("%d",&n);//定义第一维动态数组长度；
	arry = (int**)malloc(n*sizeof(int*));
	printf("请输入列数：");
	scanf("%d", &m);//定义第二维动态数组长度；
	for ( i = 0; i < n; i++)
	{
		arry[i] = (int*)malloc(m*sizeof(int));
	}
	printf("请输入%dx%d的数组：\n",n,m);
	for ( p = 0; p < n; p++)
	{
		for (q = 0; q <m ; q++)
		{
			//arry[p][q] = p*q;
			scanf("%d", &arry[p][q]);
		}
	}
	printf("%dx%d的数组：\n", n, m);
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
	printf("\n这个%dx%d矩阵的对角线之和=%d\n", n, m, sum);
	for ( i = 0; i < n; i++)
	{
		free(arry[i]);
	}
	free(arry);
	system("pause");
	return 0;
}