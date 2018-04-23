#define _CRT_SECURE_NO_WARNINGS
/*
#define DEBUG
#include <stdio.h>
#include <time.h>
double t2_t1;
void quick_sort(int s[], int l, int r);
int fastswap(int , int , int);
void temp(int, int);
void xx(int *, int, int);
int main()
{
	int n, m;
	int a[10] = { 10, 25, 7, 5, 10, 54, 75, 14, 15,74 };
	int left = 0;
	int i;
	int right = 10-1;
	n=clock(NULL);
	#ifdef DEBUG
	fastswap(a, left, right);
	#else
	quick_sort(a, right, left);
	#endif
	for ( i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
		printf("  ");

		
	}
	m=clock(NULL);
	t2_t1 = m - n;
	printf("\n程序运行时间=%0.15f秒\n", (double)t2_t1 /CLK_TCK);
	system("pause");
	return 0;
}
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//temp(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
			j--;
			if (i < j)
			{
				s[i++] = s[j];
			}
			while (i < j && s[i] <=x) // 从左向右找第一个大于等于x的数  
			i++;
			if (i < j)
			{
				s[j--] = s[i];
			}
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用
		quick_sort(s, i + 1, r);//这里的i已经不是等于程序开头赋值的left了；
	}
}
void temp(int n, int m)
{
	int temp;
	if (n>m)
	{
		temp = m;
		m = n;
		n = temp;
	}
}

int fastswap(int p[], int left, int right)
{
	if (left < right)
	{	
		int i = left, j = right;
		int x = p[left];
		while (i < j)
		{
			while (i < j&&p[j] >= x)//遍历x（基准）右边找到一个小于x的元素；
			{
				j--;
			}
			if (i < j)
			{
				p[i++] = p[j];//将上面的那个值赋值给第一个数，并向右填坑；
			}
			while (i < j&&p[i] < x)//遍历x（基准）右边找到一个大于x的元素；
			{
				i++;
			}
			if (i < j)
			{
				p[j--] = p[i];//将上面的那个值赋值给第一个数，并向左填坑；
			}
		}
		p[i] = x;
		fastswap(p, left, i - 1);
		fastswap(p, i+1, right);

	}
}
*/
/*
#include <stdio.h>
int fastnum(int, int, int);
int reuse(int*, int, int);
int  main()
{
	int a[10] = {6,3,4,5,2,18,1,2,4,5};
	int l = 0, r = 10 - 1,i;
	fastnum(a, l, r);//按从打到小的顺序排序
	//reuse(a, l, r);//实现整形数组倒序
	for ( i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	system("pause");
	return 0;
}
/*
int fastnum(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		fastnum(s, l, i - 1); // 递归调用   
		fastnum(s, i + 1, r);
	}
	return s;
}
int fastnum(int p[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		int base = p[l];
		while (i < j)
		{

			while (i < j&&p[j] < base)
			{
				j--;
			}
			if (i < j)
			{
				p[i++] = p[j];
			}
			while (i < j&&p[i] >= base)
			{
				i++;
			}
			if (i < j)
			{
				p[j--] = p[i];
			}
			p[i] = base;
			fastnum(p, l, i - 1);
			fastnum(p, i + 1, r);
		}
	}
	return p;
}
int reuse(int *p, int n, int m)//整形数组倒序
{
	while (n < m)
	{
		int temp = *(p + n);
		*(p + n) = *(p + m);
		*(p + m) = temp;
		n++;
		m--;
	}
	return p;
}
*/
//找出一个整形数组中重复的数
#include<stdio.h>
int main()
{
	int a[6]={ 1, 2, 3, 4, 4, 5 },i;
	for ( i = 0; i < 6; i++)
	{
		if (a[i]==a[i+1])
		{
			printf("%d",a[i+1]);
		}
	}
	system("pause");
	return 0;
}
