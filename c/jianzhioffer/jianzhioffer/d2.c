#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>
int set[100] = { NULL };

void chaichar(char a[])//a��ʾ�����ַ�����set��ʾ�ظ�����n��ʾ���鳤�ȡ�
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
		else if (!(i == 0 && (in[i] == '+' || in[i] == '-')))  //���˵�һ���ַ������� + -�� ����λ���������Ų�Ӧ����
		{
			printf("error! input isn't a num!");
			return 0;
		}
	}
	if (in[0] == '-')  //�ж��Ƿ�Ϊ����
	{
		ans = 0 - ans;
	}

	//����Ƿ�Խ��
	char check[100];
	if (in[0] == '+')  //�������ĵ�һ������������ ���뵽check�� �����Լ�������+��
	{
		check[0] = '+';
		sprintf(check + 1, "%d", ans);
	}
	else
	{
		sprintf(check, "%d", ans);
	}
	if (strcmp(check, in) != 0) //�Ƚϵõ�������ת���ɵ��ַ��� �� �����ַ����Ƿ��в�� �в����������
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