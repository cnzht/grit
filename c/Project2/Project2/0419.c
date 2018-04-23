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
	printf("\n��������ʱ��=%0.15f��\n", (double)t2_t1 /CLK_TCK);
	system("pause");
	return 0;
}
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//temp(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
			j--;
			if (i < j)
			{
				s[i++] = s[j];
			}
			while (i < j && s[i] <=x) // ���������ҵ�һ�����ڵ���x����  
			i++;
			if (i < j)
			{
				s[j--] = s[i];
			}
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ����
		quick_sort(s, i + 1, r);//�����i�Ѿ����ǵ��ڳ���ͷ��ֵ��left�ˣ�
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
			while (i < j&&p[j] >= x)//����x����׼���ұ��ҵ�һ��С��x��Ԫ�أ�
			{
				j--;
			}
			if (i < j)
			{
				p[i++] = p[j];//��������Ǹ�ֵ��ֵ����һ��������������ӣ�
			}
			while (i < j&&p[i] < x)//����x����׼���ұ��ҵ�һ������x��Ԫ�أ�
			{
				i++;
			}
			if (i < j)
			{
				p[j--] = p[i];//��������Ǹ�ֵ��ֵ����һ��������������ӣ�
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
	fastnum(a, l, r);//���Ӵ�С��˳������
	//reuse(a, l, r);//ʵ���������鵹��
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
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		fastnum(s, l, i - 1); // �ݹ����   
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
int reuse(int *p, int n, int m)//�������鵹��
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
//�ҳ�һ�������������ظ�����
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
