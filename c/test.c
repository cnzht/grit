#include<stdio.h>
#include<string.h>
#pragma warning( disable : 4996)
int main()
{
	char cs[5][20];//定义一个二维字符数组，相当于5个一维字符数组。
	char st[20];//定义一个中间变量字符数组。
	int i,j,p;
	for ( i = 0; i < 5; i++)
	{
		gets(cs[i]);//赋值5个国家的名称。
	}
	printf("\n");
	for ( i = 0; i < 5; i++)
	{
		p = i;
		strcpy(st, cs[i]);//复制国家名到中间变量中。
		for ( j = i+1; j < 5; j++)
		{
			if (strcmp(cs[j],st)<0)//如果国家小于st。
			{
				p = j;//下标赋值。
				strcpy(st, cs[j]);//复制cs到st中
			}
		}
		if (p!=i)//如果不等则说明有更小的字符数组出现，互换st和cs
		{
			strcpy(st, cs[i]);
			strcpy(cs[i], cs[p]);
			strcpy(cs[p], st);
		}
		puts(cs[i]);
	}
	system("pause");
	return 0;
} 