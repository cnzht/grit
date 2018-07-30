#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int digui(int);
int main()
{
	time_t start, end;
	time_t s, e;
	int i;

	s = clock();
	start = time(NULL);
	for ( i = 0; i < 30; i++)
	{
		printf("%d   ",digui(i));
	}
	end = time(NULL);
	e = clock();
	printf("\n%.5f",difftime(end,start));
	printf("\n%.5f", (double)(end-start)/CLK_TCK);
	getchar();
	getchar();
	return 0;
}
int digui(int n)
{
	if (n==0)
	{
		return 0;
	}
	else if (n==1)
	{
		return 1;
	}
	else
	{
		return digui(n - 1) + digui(n - 2);
	}
}