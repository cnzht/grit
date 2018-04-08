//计算sum=2的方的阶乘+3的方的阶乘
#include<stdio.h>
int sqrt(int x)
{
	int jc(int);
	int z = 0;
	z = x*x;
	return jc(z);
}
int jc(int z)
{
	int i;
	int j = 1; 
	for ( i = 1; i <= z; i++)
	{
		j *= i;
	}
	return j;
}
int main()
{
	int sum=0;
	int i;
	for ( i = 2; i <= 3; i++)
	{
		sum += sqrt(i);
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
