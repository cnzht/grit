#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int  fbnq(int z)
{
	int m = 0;
	if (z==1||z==2)
	{
		m = 1;
	}
	else
	{
		m = fbnq(z - 1) + fbnq(z - 2);
	}
	return m;
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	if ((n<39||n==39)&&n>1)
	{
		printf("%d\n", fbnq(n - 1));
	}
	else
	{
		printf("error");
	}
	getchar();
	getchar();
	return 0;
}