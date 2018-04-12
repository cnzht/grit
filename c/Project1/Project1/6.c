//2018年4月12日 16:29:18
//函数嵌套使用的调用练习
/*
#include<stdio.h>
int main()
{
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int fact(int p,int n)
{
	int sqrt(int);
	int i ;
	int sum = 1;
	for ( i = 1; i < sqrt(p); i++)
	{
		sum *= i;
	}
	return sum/n;
}
int sqrt(int q)
{
	return q*q;
}
int main()
{	
	printf("%d\n",fact(2,2));
	system("pause");
	return 0;
}
*/
//关于函数递归的练习
/*
#include<stdio.h>
int func(int n)
{
	long sum = 1;
	if (n==0||n==1)
	{
		sum = 1;//递归结束条件
	}
	else
	{
		sum = n*func(n - 1);//递归
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);	
	printf("%ld\n", func(n));
	system("pause");
	return 0;
}
*/
//斐波那契函数练习，利用递归方法来解决
/*
#include<stdio.h>
#include<time.h>
int F(int n)
{
	int fact = n;
	if (fact==1||fact==2)
	{
		fact = 1;
	}
	else if (fact>2)
	{
		fact = F(n - 1) + F(n - 2);
	}
	return fact;
}
int main()
{
	int n;
	time_t t1, t2;
	double t2_t1;
	t1 = clock();//启动时间
	scanf_s("%d", &n);
	printf("%d\n", F(n));
	t2 = clock();//结束时间
	t2_t1 = (double)(t2 - t1) / CLOCKS_PER_SEC;//两个时间的差
	printf("运行该程序需要花费：%fs\n", t2_t1);
	system("pause");
	return 0;
}
*/
//对一个一维数组排序
/*
#include<stdio.h>
#include<time.h>
int a[5] = { 1,2,3,4,5 };
void paixu(int);
void oldstr(int);
double t2_t1;
int main()
 {
	time_t t1, t2;
	t1 = clock();
	printf("原数组：\n");
	oldstr(5);
	printf("\n现数组：\n");
	paixu(5);
	t2 = clock();
	t2_t1 = (double)((t2 - t1) / CLOCKS_PER_SEC);
	printf("\n运行时间：%fs\n", t2_t1);
	system("pause");
	return 0;
}
void paixu(int n)
{
	int  i, j;
	int temp = 0;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n-i-1; j++)
		{
			if (a[j]<a[j+1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
			
		}
	}
	for ( i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}
}
void oldstr(int n)
{
	int i=0;
	while (i<n)
	{
		printf("%3d", a[i]);
		i++;
	}
}
*/
//调试两层循环
/*
#include<stdio.h>
int main()
{
	int i, j;
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j <5-i-1; j++)
		{
			printf("外层循环");
			printf("i=%3dj=%3d\n", j, i);
		}
		printf("外层循环");
		printf("i=%3dj=%3d\n", j, i);
	}
	system("pause");
	return 0;
}
*/
//关于静态变量和局部变量的练习，关于auto和static的区别

/*
#include<stdio.h>
int main()
{
	int a = 2;
	static b = 3;
	int i;
	for ( i = 0; i < 3; i++)
	{
		a++;
		b++;
		printf("%3da=%3db=%3d\n", a + b,a,b);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int sum(int a)
{
	int b = 2;
	static c = 3;
	b++;
	c++;
	return (a + b + c);
}
int main()
{
	int i;
	int a = 2;
	for ( i = 0; i < 3; i++)
	{
		printf("%d\n", sum(a));
	}
	system("pause");
	return 0;
}
*/
//打印1到n的阶乘，使用静态变量的方法
/*
#include<stdio.h>
int jiechen()
{

	static long long mul=1;
	static int  sum = 1;
	mul *= sum;
	sum++;
	return mul;
}
int main()
{
	int n;
	int i=0;
	scanf_s("%d", &n);
	while (i!=n)
	{
		printf("%d的阶乘=%lld\n", i+1,jiechen());
		i++;
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%3d%3d%3d", sizeof(long),sizeof(long long ),sizeof(long long unsigned));
	system("pause");
	return 0;
}
*/