#include<stdio.h>
#include<string.h>
#pragma warning( disable : 4996)
int main()
{
	char cs[5][20];//����һ����ά�ַ����飬�൱��5��һά�ַ����顣
	char st[20];//����һ���м�����ַ����顣
	int i,j,p;
	for ( i = 0; i < 5; i++)
	{
		gets(cs[i]);//��ֵ5�����ҵ����ơ�
	}
	printf("\n");
	for ( i = 0; i < 5; i++)
	{
		p = i;
		strcpy(st, cs[i]);//���ƹ��������м�����С�
		for ( j = i+1; j < 5; j++)
		{
			if (strcmp(cs[j],st)<0)//�������С��st��
			{
				p = j;//�±긳ֵ��
				strcpy(st, cs[j]);//����cs��st��
			}
		}
		if (p!=i)//���������˵���и�С���ַ�������֣�����st��cs
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