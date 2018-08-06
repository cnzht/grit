#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>
int set[100] = { NULL };

void chaichar(char a[])//a表示输入字符串，set表示重复数，n表示数组长度。
{
	/*if (n==1)
	{
		printf("%d", n);
		printf("%d", a[n - 1]);
	}*/
	printf("%d", myatoi(a));
}

int myatoi(char * in)
{
	int ans = 0;
	for (int i = 0; in[i] != '\0'; i++)
	{
		if (in[i] - '0' >= 0 && in[i] - '0' <= 9)
		{
			ans = ans * 10 + in[i] - '0';
		}
		else if (!(i == 0 && (in[i] == '+' || in[i] == '-')))  //除了第一个字符可以是 + -号 其他位置其他符号不应出现
		{
			printf("error! input isn't a num!");
			return 0;
		}
	}
	if (in[0] == '-')  //判断是否为负数
	{
		ans = 0 - ans;
	}

	//检查是否越界
	char check[100];
	if (in[0] == '+')  //如果输入的第一个符号是正号 加入到check中 正数自己不会有+号
	{
		check[0] = '+';
		sprintf(check + 1, "%d", ans);
	}
	else
	{
		sprintf(check, "%d", ans);
	}
	if (strcmp(check, in) != 0) //比较得到的数字转换成的字符串 与 输入字符串是否有差别 有差别就是溢出了
	{
		printf("overflow!");
		return 0;
	}

	return ans;
}

void chaifen(char *str,int longstr)
{
	char *left;
	char *right;
	if (longstr==1)
	{
		left = str;
	}
	else if (longstr>=2&&longstr<=10)
	{
		for (int i = 0; i < longstr; i++)
		{

			for (int j = 0; j < longstr - i; j++)
			{
				left = str + i;
				right = str + j + i;
				printf("left=%s\nright=%s\n", left, right);
			}
			printf("\n");
		}
	}
}

int main()
{
	char a[10];
	scanf("%s", &a);
	chaifen(&a,strlen(a));
	chaichar(&a);
	getchar();
	getchar();
	return 0;

}