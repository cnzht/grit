#define _CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
struct birthday
{
	int day;
	int month;
	int years;
};
struct stdudent
{
	char num[15];
	char name[20];
	struct birthday data;
	char adrr[30];
};

int main()
{
	struct stdudent stu1;
	struct stdudent stu2;
	
	int i = 0;
	while (i < 3)
	{
		printf("������ѧ�š���������ַ\n");
		scanf("%s %s %s", &stu1.num, &stu1.name, &stu1.adrr);
		printf("�����������е��ա��¡���\n");
		scanf("%d %d %d", &stu1.data.day, &stu1.data.month, &stu1.data.years);
		stu2 = stu1;
		printf("stu1=%s\n%s\n%s\n%d/%d/%d\n", stu1.num, stu1.name,
			stu1.adrr, stu1.data.day, stu1.data.month, stu1.data.years);
		printf("stu2=%s\n%s\n%s\n%d/%d/%d\n", stu2.num, stu2.name,
			stu2.adrr, stu2.data.day, stu2.data.month, stu2.data.years);
		i++;
	}
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
struct student
{
	int  num;//ѧ��
	char name[20];//����
	float score;//����
};
typedef struct student STU;
int main()
{
	STU array[] = { { 201, "zhoutian", 100 }, { 202, "zhangsan", 87.5 }, 
	{ 203, "lier", 69.6 }, { 204, "litianyu", 89.6 }, { 205, "cuier", 69.8 } };
	STU temp;
	int i, j;
	for ( i = 0; i < 5; i++)
	{	
		for ( j = 0; j < 5-i; j++)
		{
			if (array[j].score<array[j+1].score)
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
	for ( i = 0; i < 5; i++)
	{
		printf("��ţ�[%d]\n%d\n%s\n%.2f\n\n",i+1,
			array[i].num,array[i].name,array[i].score);
	}
	system("pause");
	return 0;
}
*/
//�ýṹ��ָ��ָ�����
/*
#include <stdio.h>
struct student
{
	int  num;//ѧ��
	char name[20];//����
	float score;//����
};
typedef struct student STU;
void print(STU *p)
{
	printf("ѧ��\t����\t����\n");
	printf("%d\t%s\t%0.2f\n", p->num, p->name, p->score);
}
void sort(STU array[])
{
	int i, j;
	STU temp;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 - i; j++)
		{
			if (array[j].score<array[j + 1].score)
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main()
{
	STU array[] = { { 201, "zhoutian", 100 }, { 202, "zhangsan", 87.5 },
	{ 203, "lier", 69.6 }, { 204, "litianyu", 89.6 }, { 205, "cuier", 69.8 } };
	int i;
	printf("����ǰ���飺\n");
	for ( i = 0; i < 5; i++)
	{
		print(&array[i]);

	}
	sort(array);
	printf("��������飺\n");
	for (i = 0; i < 5; i++)
	{
		print(&array[i]);

	}
	system("pause");
	return 0;
}
*/

