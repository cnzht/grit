#define _CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
int main()
{
	system("pause");
	return 0;
}
*/
//��������ϰ3����һ���ַ�����ɾ�����е����пո���������������h e l l o���Ϊhello��

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
	printf("���а����ո���=%d\n", i);
	system("pause");
	return 0;
}
int strdel(char *p)
{
	char *s = p;//��ʵ�θ�ֵ��S
	int i, j = 0,k=0, n = strlen(s);//ָ�������е��ַ�����
	for (i = 0; i < n; i++)
	{
		if (*(s+i)==' ')
		{
			k++;
			continue;
		}
		else
		{
			*(p+j) = *(s+i);//�����ַ�������p
			j++;
		}
	}
	*(p + j) = '\0';//��ֵ���½�������������������š�
	return k;
}
*/
//���Ϲ���ɾ���ַ����пո��Դ����
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

//�����µ�4��,ʵ���ַ����ĵ���
//ʹ�õݹ�ķ�ʽ��  ***����������1234 ֻ��ʾ4 ������λͬ������ĸҲֻ��ʾ���һλ
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
	char tmp;//���ַ�����һ��Ԫ�ش洢��tmp�У�
	int n = strlen(p);
	tmp = *p;
	*p = *(p + n - 1);//���ַ��������һ���ַ���ֵ����һ����Ԫ�أ�
	*(p + n - 1) = '\0';//��������־���Ÿ�ֵ�����һ��Ԫ�أ�
	if (n>1)
	{
		daoxu(p + 1);
	}
	*(p + n - 1) = tmp;//�ٽ���һ��Ԫ�ظ�ֵ���µ���������һ��
}
*/
//�ڶ��з�ʽ��������
//���ֵ���ʽ
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
//��ͨ��������ʽ
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
	for ( i = 0; i < n/2; i++)//��Ϊ��˫�򽻻�������ֻ��Ҫѭ��n/2��
	{
		temp = *(p+i);//����һ��Ԫ�ظ�ֵ��temp
		*(p + i) = *(p + n - i - 1);//�����һ��Ԫ�ظ�ֵ����һ��Ԫ��
		*(p + n - i - 1) = temp;//����һ��Ԫ�ظ�ֵ�����һ��Ԫ��
	}
	*(p + n ) = '\0';//��ӽ�������
}
*/
/*
//ָ���������밢������������·�Ӣ����д
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
	printf("�����������С�����\n");
	scanf("%d%d", &rows, &cols);
	vi = (int **)malloc(rows*sizeof(int*));
	for (i = 0; i<rows; i++)
		vi[i] = (int*)malloc(cols*sizeof(int));
	printf("����������Ԫ��\n");
	for (i = 0; i<rows; i++)
	for (j = 0; j<cols; j++)
		scanf("%d", &vi[i][j]);
	printf("�����������Ԫ��\n");
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
//����ָ������������ά�������顣
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int **a, row, clow, i, j;
	printf("������������������\n");
	scanf("%d%d", &row, &clow);
	a = (int **)malloc(row*sizeof(int*));
	for ( i = 0; i < row; i++)
	{
		a[i] = (int *)malloc(clow*sizeof(int));
	}
	printf("���������飺\n");
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
//��һ��3*4�ľ�������
/*
#include <stdio.h>
int max(int **);
int min(int **);
int main()
{
	int a[3][4] = { NULL },i,j;
	int *p[3] = { a[0],a[1], a[2] };
	printf("������һ���������е����飺\n");
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
//����һ��ָ�����ά�����е����ֵ
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
	printf("%d ��=%d ��=%d", max,l-1,c);
}