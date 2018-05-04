#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct2
{
	int km1, km2, km3;
	float aver;
};

struct MyStruct1
{
	long num;
	char name[20];
	struct MyStruct2 exam;
};
typedef struct MyStruct1 STU;
STU *input(STU *, int);
void print(STU *,int);
void sort(STU *,int,int);
int main()
{
	
	int n = 0;
	STU *s, *v;
	printf("请输入学生人数：\n");
	scanf("%d",&n);
	s = (STU*)malloc(n*sizeof(STU));//需要分配学生个数！
	if (!s)
		exit(0);
	v = input(s,n);
	printf("原始列表：\n");
	print(v, n);
	sort(v,0,n);
	printf("排序列表：\n");
	print(v,n);
	//free(s);
	system("pause");
	return 0;
}
STU *input(STU *s,int n)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		printf("请分别输入学号、姓名、科目1分数、科目2分数、科目3分数(用空格隔开！)\n");
		scanf("%ld%s%d%d%d",&s[i].num,&s[i].name,&s[i].exam.km1,&s[i].exam.km2,&s[i].exam.km3);
		s[i].exam.aver = (s[i].exam.km1 + s[i].exam.km2 + s[i].exam.km3) / 3;
	}
	return s;
}
//结构体排序

/*
void sort(STU *s, int n) 
{
	STU temp;
	int i,j;
	for ( i = 0; i <n ; i++)
	{
		for ( j = 0; j < n-1-i; j++)
		{
			if (s[j].exam.aver < s[j+1].exam.aver)
			{
				temp = s[j + 1];
				s[j + 1] = s[j];
				s[j] = temp;
			}
		}
	}
}
*/
void sort(STU *s, int l,int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = l, j = r;
		STU x = s[l];
		while (i < j)
		{
			while (i < j && s[j].exam.aver >= x.exam.aver) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i].exam.aver < x.exam.aver) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		sort(s, l, i - 1); // 递归调用   
		sort(s, i + 1, r);
	}
}


void print(STU *s, int n)
{
	int i;

	printf("%学号\t姓名\t科目1\t科目2\t科目3\t平均分\n");
	for ( i = 0; i < n; i++)
	{
		printf("%ld\t%s\t%d\t%d\t%d\t%.2f\n",s[i].num, s[i].name,s[i].exam.km1, s[i].exam.km2, s[i].exam.km3,s[i].exam.aver);
	}
}