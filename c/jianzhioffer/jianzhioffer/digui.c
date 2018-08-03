#include "OftenInclude.h"
int func(int );
int main() //Ö÷º¯Êý
{
	printf("%d", func(5));
	getchar();
	getchar();
	return 0;
}
int func(int n)
{
	int m = 1;
	if (n == 0 || n == 1)
	{
		m = 1;
	}
	else//
	{
		m = n*func(n - 1);
	}
	return m;
}