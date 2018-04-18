#define _CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
int main()
{
	system("pause");
	return 0;
}
*/
//第六章练习3输入一串字符串，删除其中的所有空格后输出，例如输入h e l l o输出为hello。

/*
#include <stdio.h>
#include <string.h>
#define N 1000
int strdel(char *);
int main()
{
	char a[N] = { NULL };
	int i=0;
	gets(a);
	i=strdel(a);
	puts(a);
	printf("其中包含空个数=%d\n", i);
	system("pause");
	return 0;
}
int strdel(char *p)
{
	char *s = p;//将实参赋值给S
	int i, j = 0,k=0, n = strlen(s);//指针数组中的字符长度
	for (i = 0; i < n; i++)
	{
		if (*(s+i)==' ')
		{
			k++;
			continue;
		}
		else
		{
			*(p+j) = *(s+i);//更新字符串数组p
			j++;
		}
	}
	*(p + j) = '\0';//赋值更新结束后增加数组结束符号。
	return k;
}
*/
//网上关于删除字符串中空格的源代码
/*
#include<stdio.h>
#include<string.h>
int strdel(char *s);
int main()
{
	char a[100];
	int n;
	gets(a);
	n = strdel(a);
	puts(a);
	printf("%d", n);
	system("pause");
	return 0;
}
int strdel(char *s)
{
	int i, j = 0, k = 0, n;
	char *p = s;
	n = strlen(s);
	for (i = 0; i<n; i++)
	{
		if (*(p + i) == ' ')
		{
			j++;
			continue;
		}
		else
		{
			*(s + k) = *(p + i);
			k++;
		}
	}
	*(s + k) = '\0';
	return j;
}
*/

//第六章第4题,实现字符串的倒序。
//使用递归的方式。  ***问题是输入1234 只显示4 输入四位同样的字母也只显示最后一位
/*
#include <stdio.h>
#include <string.h>
void daoxu(char *);
int main()
{
	char a[1000] = { NULL };
	gets(a);
	daoxu(a);
	puts(a);
	system("pause");
	return 0;
}
void daoxu(char *p)
{
	char tmp;//将字符串第一个元素存储到tmp中；
	int n = strlen(p);
	tmp = *p;
	*p = *(p + n - 1);//将字符串中最后一个字符赋值给第一数组元素；
	*(p + n - 1) = '\0';//将结束标志符号赋值给最后一个元素；
	if (n>1)
	{
		daoxu(p + 1);
	}
	*(p + n - 1) = tmp;//再将第一个元素赋值给新的数组的最后一个
}
*/
//第二中方式遍历排序
//数字倒序方式
/*
#include <stdio.h>
int main()
{
	int i = 12375;
	int temp = 0;
	while (i != 0)
	{
		temp = temp * 10 + i % 10;
		i /=10;
	}
	printf("%d",temp);
	system("pause");
	return 0;
}
*/
//普通遍历倒序方式
/*
#include <stdio.h>
#include <string.h>
void reserve(char*);
int main()
{
	char a[1000] = { NULL };
	gets(a);
	reserve(a);
	puts(a);
	system("pause");
	return 0;
}
void reserve(char* p)
{	
	char temp;
	int n = strlen(p),i;
	for ( i = 0; i < n/2; i++)//因为是双向交换，所以只需要循环n/2次
	{
		temp = *(p+i);//将第一个元素赋值给temp
		*(p + i) = *(p + n - i - 1);//将最后一个元素赋值给第一个元素
		*(p + n - i - 1) = temp;//将第一个元素赋值给最后一个元素
	}
	*(p + n ) = '\0';//添加结束符号
}
*/
/*
//指正数组输入阿拉伯数字输出月份英文缩写
#include <stdio.h>
int main()
{
	char *a[] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sept", "oct", "nov", "dec" };
	int n=0;
	scanf("%d", &n);
	if (n>=1&&n<=12)
	{
		printf("%s\n", *(a + n - 1));
	}
	else
	{
		exit(1);
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
	int **vi, rows, cols, i, j;
	printf("请输入数组行、列数\n");
	scanf("%d%d", &rows, &cols);
	vi = (int **)malloc(rows*sizeof(int*));
	for (i = 0; i<rows; i++)
		vi[i] = (int*)malloc(cols*sizeof(int));
	printf("请输入数组元素\n");
	for (i = 0; i<rows; i++)
	for (j = 0; j<cols; j++)
		scanf("%d", &vi[i][j]);
	printf("以下输出数组元素\n");
	for (i = 0; i<rows; i++)
	{
		for (j = 0; j<cols; j++)
			printf("%d\t", vi[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
*/
//二级指针输入和输出二维整形数组。
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int **a, row, clow, i, j;
	printf("请输入行数和列数：\n");
	scanf("%d%d", &row, &clow);
	a = (int **)malloc(row*sizeof(int*));
	for ( i = 0; i < row; i++)
	{
		a[i] = (int *)malloc(clow*sizeof(int));
	}
	printf("请输入数组：\n");
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < clow; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < clow; j++)
		{
			printf("%d", a[i][j]);
			printf("  ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[2][3] = { 10, 20, 30, 40, 50, 60 };
	int *p[3] = {a[0],a[1]};
	int **pp = p;
	int i, j;
	for ( i = 0; i < 2; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			printf("%d",pp[i][j]);
			printf("  ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
*/
//对一个3*4的矩阵排序。
/*
#include <stdio.h>
int max(int **);
int min(int **);
int main()
{
	int a[3][4] = { NULL },i,j;
	int *p[3] = { a[0],a[1], a[2] };
	printf("请输入一个三行四列的数组：\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("max=%d\nmin=%d\n",max(p),min(p));
	system("pause");
	return 0;
}
int  max(int **pp)
{
	int i, j,max=0,min=0;
	max = **pp;
	min = **pp;
	for ( i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (max<pp[i][j])
			{
				max = pp[i][j];
			}
			if (min>pp[i][j])
			{
				min = pp[i][j];
			}

		}
	}
	return max;
}
int  min(int **pp)
{
	int i, j, max = 0, min = 0;
	max = **pp;
	min = **pp;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (min>pp[i][j])
			{
				min = pp[i][j];
			}

		}
	}
	return min;
}
*/
//网上一级指针求二维数组中的最大值
/*
# include <stdio.h>

int main()
{
	int a[5][5];
	int *pa, i, n, m;
	int max, c;
	pa = &a[0][0]; //@#1
	scanf("%d%d", &n, &m);
	for (i = 0; i < n * m; pa = (i % m == m - 1 ? &a[(i + 1) / m][0] : pa + 1), i++) //@#2
		scanf("%d", pa);
	pa = &a[0][0]; //@#3
	max = a[0][0]; //@#4
	c = 0;
	for (i = 0; i < n * m; i++)
	{
		if (max < *(pa + i + (i / m) * (5 - m))) //@#5
		{
			max = *(pa + i + (i / m) * (5 - m)); //@#6
			c = i;
		}
	}
	printf("%d\n", max);
	printf("%d %d\n", c / m, c%m);
	system("pause");
	return 0;
}
*/

#include <stdio.h>
void max(int(*p)[6],int ,int );
int main()
{
	int a[6][6] = { NULL };
	int row, clow, i, j;
	scanf("%d%d", &row, &clow);
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < clow; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	max(a, row, clow);
	system("pause");
	return 0;
}
void max(int(*p)[6], int row, int clow)
{
	int i, j,c=0,l=0;
	int max = (*p)[0];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < clow; j++)
		{
			if (max<(*p)[j])
			{
				max = (*p)[j];
				c = j;
			}
		}
		p++;
		l++;
	}
	printf("%d 行=%d 列=%d", max,l-1,c);
}