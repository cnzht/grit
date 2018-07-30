#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findnumber();
int paixu();
int maopaopaixu();

int main()
{
	int i = 0, j = 0;
	int shuzu[3][3] = { NULL };
	int number = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &shuzu[i][j]);
		}
	}
	//paixu(&shuzu);
	maopaopaixu(&shuzu);
	printf("please input every number:");
	/*for ( i = 0; i < 9; i++)
	{
	printf("%d\n", *(*shuzu + i));
	}*/
	scanf("%d", &number);
	findnumber(&shuzu, number);
	getchar();
	getchar();
	return 0;
}
int maopaopaixu(int **sz) //Ã°ÅÝÅÅÐò
{
	int i = 0, j = 0, temp = 0;
	int finally[3][3] = { NULL };
	int count = -1;
	for ( i = 0; i < 9-1; i++)
	{
		for (j = 0; j < 9 - 1 - i; j++)
		{
			if (*(sz+i)>*(sz+i+1))
			{
				temp = *(sz + i + 1);
				*(sz + i + 1) = *(sz + i);
				*(sz + i) = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			count++;
			finally[i][j] = *(sz + count);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", finally[i][j]);
		}
		printf("\n");
	}
	/*for (int m = 0; m < 9; m++)
	{
		printf("%d", *(sz + m));
	}*/
}

/*
int paixu(int **sz) //¶þ·Ö·¨ÅÅÐò
{
	int del = -1, mid = 0, left = 0, right = 9 - 1;
	mid = *(sz + left);
	while (left<right)
	{
		while (left<right && *(sz + right) >= mid)
		{
			right--;
		}
		if (left<right)
		{
			*(sz + (left++)) = *(sz + right);
		}
		while (left<right && *(sz + right) <= mid)
		{
			left++;
		}
		if (left<right)
		{
			*(sz + (right--)) = *(sz + left);
		}
	}
	*(sz + left) = mid;
	for (int i = 0; i < 9; i++)
	{
		printf("%d", *(sz + i));
	}
}
*/
int findnumber(int **sz, int n)
{5
	for (int i = 0; i < 9; i++)
	{
		if (*(sz + i) == n)
		{
			printf("yes!");
			break;
		}
		else if (i<9)
		{
			continue;
		}
		else
		{
			printf("no!");
			break;
		}
	}
}