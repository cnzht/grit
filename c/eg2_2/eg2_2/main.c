#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define Max_Size 100

typedef struct
{
	int num;
	char name[10];
	int sex;//男生为1，女生为0；
	int old;
	int size;
}Student;
Student myList[Max_Size];

int count;
int number();
void print(Student *L,int n);


int main()
{
	
	int i=0;
	int k = 0;

	while (1)
	{
		if (k==0)
		{
			count = -1;
		}
		k = number();//生成流水号
		myList[i].size = k;
		count++;
		myList[i].num = 2000001 + i;
		printf("学生姓名：（输入“0”退出！）");
		scanf("%s",&myList[i].name);
		if (strcmp(myList[i].name,"0")==0)
		{
			break;
		}
		printf("学生性别(男生为1，女生为0)：");
		scanf("%d", &myList[i].sex);
		if (myList[i].sex != 0 && myList[i].sex != 1)
		{
			printf("非法输入!");
			getchar();
			getchar();
			exit(1);
			return ;
		}
		printf("学生年龄：");
		scanf("%d", &myList[i].old);
		
		i++;
	}
	print(&myList,i);
	getchar();
	getchar();
	return 0;


}

int number()
{
	if (count==-1)
	{
		return 2000000;
	}
	else
	{
		return myList[count].size += 1;
	}
}

void print(Student *L,int n)
{
	int i;
	printf("+---------------------------------------+\n");
	printf("学号\t\t姓名\t性别\t年龄\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t\t%s\t%s\t%d\t%d\n", L[i].num, L[i].name, L[i].sex==1?"男":"女", L[i].old,L[i].size);
	}
	printf("+---------------------------------------+\n");
}
