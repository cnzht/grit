#define _CRT_SECURE_NO_WARNINGS
//2018年4月16日 09:53:06
//关于指针的学习，指针运算，指针关系，数组指针，字符数组指针等
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
int main()
{
	int temp = 0;
	int a = -3;
	int b = 9;
	int *p = &a;
	int *q = &b;
	if (a<b)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
	printf("a=%d\nb=%d\np=%d\nq=%d\n%d\n%o\n%o", a, b, *p, *q,&p-&q,&p,&q);
	system("pause");
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	short *p, *q;
	p = (short *)0x2002;
	q = (short *)0x2008;
	printf("%d\n%d\n%d\n%d\n", q - p,sizeof(int),sizeof(unsigned long),sizeof(short));
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
#include<time.h>
int main()
{
	double t2_t1=0;
	int *p;
	int i;
	int a[10] = { 0 };
	time_t t1,t2;
	t1 = time(NULL);
	p = a;
	for ( i = 0; i < 10; i++)
	{
		*(a + i) = 2 * (i + 1);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%3d", *(a+i));
	}
	t2 = time(NULL);
	t2_t1 = t2 - t1;
	printf("\n%lf", t2_t1 / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int *p, i = 0;
	for (p = a; p < a + 10; p++,i++)//对p所指向的地址进行自增运算。
	{
		*p = 2*(i + 1);
	}
	for ( p = a; p < a+10; p++)
	{
		printf("%3d", *p);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	char a[] = "hello world", b[20], *p, *q;
	p = a;
	q = b;
	for ( ; *p!='\0'; p++,q++)
	{
		*q = *p;
	}
	*q = '\0';
	printf("%s\n%s\n", a,b);
	system("pause");
	return 0;
}
*/
/*

#include<stdio.h>
int main()
{
	char s[50], *p = s;
	gets(p);
	while (*p!='\0')
	{
		p++;
	}
	printf("%d\n", p - s);
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int i;
	char a[] = "china", b[] = "janpan", c[] = "hongkong";
	char *p[4] = {a,b,c,NULL};
	for ( i=0; p[i]!=NULL; i++)
	{
		printf("%s\n", p[i]);
	}
	system("pause");
	return 0;
}
*/
/*
#include<string.h>
#include<stdio.h>
int main()
{
	char *name[] = { "meiguo", "hongkong", "guangdong", "zhongguo" }, *p[] = {NULL};
	char *temp;
	int i, j;
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4-i-1; j++)
		{
			if (strcmp(name[j], name[j+1])>0)
			{
				temp = name[j + 1];
				name[j + 1] = name[j];
				name[j] = temp;
			}
		}
	}
	for ( i = 0; i < 4; i++)
	{
		printf("%s%20d\n",name[i],name[i]-name);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int i, j, a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int *p[2] = { a[0], a[1] }, **pp = p;
	for ( i = 0; i <2; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			printf("a[%d][%d]=%d\n", i, j, pp[i][j]);
		}
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	char *a[] = { "xinjiang", "sichuan", "hubei", "hebei", "ganshu",NULL };
	char **p = a;
	while ( *p!=NULL)
	{
		printf("%s\n",*p++);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int  a[2][3] = {1,2,3,4,5,6};
	int (*p)[3] = a;
	int i, j;
	for  (i = 0; i <2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\n", (*p)[j]);
		}
		p++;
	}
	system("pause");
	return 0;
}
*/
//2018年4月17日 11:07:27
/*
#include<stdio.h>
void swap(int * n,int* m )
{	
	int temp;
	temp = *n;
	*n = *m;
	*m = temp;
	printf("%d,%d", *n, *m);

}
int main()
{
	int a = 3, b = 6;
	swap(&a, &b);
	system("pause");
	return 0;
}
*/

/*
#include<stdio.h>
void input(int *ch,int n);
int  min(int *ch ,int n);
int main()
{
	int a[10],i;
	input(&a,10);
	for ( i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n%3d", min(a, 10));
	system("pause");
	return 0;
}
void input(int *ch, int n)
{
	int i;
	for ( i = 0; i < n; i++,ch++)
	{
		scanf("%d",ch);
	}
}
int  min(int *ch, int n)
{
	int min = *ch, i;
	for ( i = 0; i < n; i++)
	{
		if (ch[i]<min)
		{
			min = ch[i];
		}
	}
	return min;
}
*/
//通过指针函数，返回指针变量，显示第几个星期的第几天是这个月的第几天。
/*
#include<stdio.h>
int * wkdy(int , int );
int main()
{
	int wk = 0, dy = 0;
	do{
		printf("enter wk:1-5 dy:1-7 \n");
		scanf("%d %d",&wk,&dy);
	} while (wk<1 || wk>5 || dy<1 || dy>7);
	printf("%d",*wkdy(wk,dy) );
	system("pause");
	return 0;
}
int * wkdy(int n  , int m ) 
{
	static int wkdy[5][7] = { { 1, 2, 3, 4, 5, 6, 7 }, { 8, 9, 10, 11, 12, 13, 14 },
	{ 15, 16, 17, 18, 19, 20, 21 }, { 22, 23, 24, 25, 26, 27, 28 }, { 29, 30, 31, -1 } };
	return &wkdy[n - 1][m - 1];
}
*/
/*
#include<stdio.h>
int(*funp) (int, int );
int fun(int, int);
int main()
{
	int a = 0, b = 0;
	funp = fun;
	scanf("%d %d", &a, &b);
	printf("a*b=%d", (*funp)(a, b));
	system("pause");
	return 0;
}

int fun(int a, int b)
{
	return a*b;
}
*/
//通过函数指针调用函数。
/*
#include<stdio.h>
void process (int, int,int (*fun)(int , int ));
int min(int, int);
int max(int, int);
int sum(int, int);
int main()
{
	int i, a = 0, b = 0;
	printf("请输入a，b数字，第一次会求出最大值，第二次会求出最小值，第三次会求出和\n");
	scanf("%d %d", &a, &b);
	process(a, b, max);
	process(a, b, min);
	process(a, b, sum);
	system("pause");
	return 0;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a , int b )
{
	return a > b ? a : b;
}
int sum(int a, int b)
{
	return a + b;
}
void process(int a, int b, int(*fun)(int , int ))
{
	int result = 0;
	result = (*fun)(a, b);
	printf("%d\n", result);
}
*/
//动态内存分配练习
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p, i;
	p = (int *)malloc(5 * sizeof(int));
	if (p==NULL)
	{
		printf("分配内存失败！\n");
		exit(1);
	}
	printf("请输入5个成绩：\n");
	for ( i = 0; i < 5; i++)
	{
		scanf("%d",p+i);
	}
	printf("不合格的成绩是：\n");
	for (i = 0; i < 5; i++)
	{
		if (*(p+i)<60)
		{
			printf("%d\n", *(p + i));
		}
	}
	free(p);
	system("pause");
	return 0;
}
*/
//练习题1：给一个数组赋值
/*
#include<stdio.h>
int main()
{	
	int i, a[10] = { 0 }, *p;
	p = a;
	for ( i = 0; i <10; i++)
	{
		a[i] = 2 * (i + 1);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%3d", *(p + i));
	}
	system("pause");
	return 0;
}
*/
//从键盘输入的一个大写字符串改写成小写字符并显示出来，其中大写转小写用lower（）函数实现。
/*
#include<stdio.h>
void lower(char *);
int main()
{
	char a = '\0';
	scanf("%c", &a);
	lower(&a);
	system("pause");
	return 0;
}
void lower(char *p)
{
	if (*p>='A'&&*p<='Z')
	{
		*p += 32;
		printf("%c\n", *p);
	}
	else
	{
		exit(1);
	}
}
*/
