#define _CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct city
{
	int num;
	float gdp;
	int people;
	struct city *next;
}NODE;
NODE *creat()
{
	NODE *pnew, *head, *plast;
	int num, people;
	float gdp;
	head = (NODE*)malloc(sizeof(NODE));
	if (head==NULL)
	{
		printf("创建内存空间失败！\n");
		return (NULL);
	}
	head->next = NULL;
	plast = head;
	while (1)
	{
		printf("请输入序号，输入为0时退出：\n");
		scanf("%d", &num);
		if (num==0)
		{
			break;
		}
		printf("请输入GDP值\n");
		scanf("%f", &gdp);
		printf("请输入人口数\n");
		scanf("%d", &people);
		pnew = (NODE*)malloc(sizeof(NODE));
		if (pnew == NULL)
		{
			printf("创建内存空间失败！\n");
			return (NULL);
		}
		pnew->num = num;
		pnew->gdp = gdp;
		pnew->people = people;
		pnew->next = NULL;
		plast->next = pnew;
		plast = pnew;
	}
	return head;
}
void print(NODE *head)
{
	NODE *p = head->next;
	printf("节点信息如下：\n");
	printf("序号\tGDP\t人口\n");
	for (; p != NULL; p=p->next)
	{
		printf("%d\t%0.2f\t%d\n",p->num,p->gdp,p->people);
	}
}
void delelist(NODE *head, int number)
{
	NODE *p=head, *q=head->next;
	NODE *temp;
	while (q!=NULL&&q->num!=number)
	{
		p = q;
		q = q->next;
	}
	if (q==NULL)
	{
		printf("error!");
		return;
	}
	temp = p->next;
	p->next = temp->next;
	free(q);
}
void insertlist(NODE *head, int insert,NODE *pnew)
{
	int j=0;
	NODE *p;
	p = head;
	while (p!=NULL &&j<insert)
	{
		p = p->next;
		j++;
	}
	if (p==NULL)
	{
		printf("error!");
	}
	else
	{
		pnew->next = p->next;
		p->next = pnew;
	}

}
int main()
{
	NODE *list = creat();
	NODE *pnew;
	int number = 0;
	int insert = 0;
	int num, gdp,people;
	print(list);
	scanf("%d", &number);
	delelist(list, number);
	print(list);
	scanf("%d", &insert);
	scanf("%d%d%d", &num,&gdp,&people);
	pnew = (NODE*)malloc(sizeof(NODE));
	pnew->num = num;
	pnew->gdp = gdp;
	pnew->people = people;
	insertlist(list, insert,pnew );
	print(list);
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
union chr
{
	int num;
	char ch;
}CH;
//typedef union chr CH;
int main()
{
	printf("当输入大于127时退出！\n");
	while (1)
	{
		scanf("%d", &CH.num);
		if (CH.num>127)
		{
			break;
		}
		printf("%d的ch字符是%10c\n", CH.num, CH.ch);
	}
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct school
{
	char name[20];
	long num;
	char sex[20];
	char job;
	union 
	{
		char zhichen[20];
		int nianji;
	}p;
}person[3];
typedef struct school SCH;
int main()
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		printf("请输入第%d个人的姓名：\n",i+1);
		scanf("%s",&person[i].name);
		printf("请输入第%d个人的编号：\n", i + 1);
		scanf("%ld", &person[i].num);
		printf("请输入第%d个人的性别（男或者女）：\n", i + 1);
		scanf("%s", &person[i].sex);
		printf("请输入第%d个人的职业（t代表老师，s代表学生）：\n", i + 1);
		scanf("%s", &person[i].job);
		if (person[i].job=='t')
		{
			printf("请输入第%d个人的职称（教授、副教授、讲师）：\n", i + 1);
			scanf("%s", &person[i].p.zhichen);
		}
		else if (person[i].job == 's')
		{
			printf("请输入第%d个人的班级：\n", i + 1);
			scanf("%d", &person[i].p.nianji);
		}
		else
		{
			printf("error!");
			exit(1);
		}
	}
	for ( i = 0; i < 3; i++)
	{
		if (person[i].job == 't')
		{
			printf("姓名\t编号\t性别\t工作（t：老师，s：学生）\t职称或班级\n");
			printf("%s\t%ld\t%s\t%c\t\t%s\n",person[i].name,person[i].num,
				person[i].sex,person[i].job,person[i].p.zhichen);
		}
		else if (person[i].job == 's')
		{
			printf("姓名\t编号\t性别\t工作（t：老师，s：学生）\t职称或班级\n");
			printf("%s\t%ld\t%s\t%c\t\t%d\n", person[i].name, person[i].num,
				person[i].sex, person[i].job, person[i].p.nianji);
		}
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
	int  x = 0, y = 0;
	enum en
	{
		sum,
		minus,
		times
	}OP;
	OP = sum;
	printf("输入两个整数！:\n");
	scanf("%d%d", &x, &y);
	while (OP<=times)
	{
		switch (OP)
		{
		case sum:printf("%d+%d=%d\n", x, y, x + y); break;
		case minus:printf("%d*%d=%d\n", x, y, x * y); break;
		case times:printf("%d/%d=%d\n", x, y, x / y); break;
		}
		OP++;
	}
	system("pause");
	return 0;
}
*/
 /*结构体输入学生学号、姓名、三门课程成绩*/
/*
#include <stdio.h>
#include <stdlib.h>
struct student
{
	long num;
	char name[20];
	int class1;
	int class2;
	int class3;
}STU[2];
typedef struct student ST;
void print (ST *p);
int main()
{
	int i;

	for ( i = 0; i < 2; i++)
	{
		printf("请分别输入：学号、姓名、三门课程成绩\n");
		scanf("%ld%s%d%d%d",&STU[i].num,&STU[i].name,&STU[i].class1,
			&STU[i].class2, &STU[i].class3);
	}
	print(STU);
	system("pause");
	return 0;
}
void print (ST *p)
{
	int i;

	printf("学号\t姓名\t课程1\t课程2\t课程3\n");
	for ( i=0;i<2;i++,p++)
	{
		printf("%ld\t%s\t%d\t%d\t%d\n", p->num, p->name,
			p->class1, p->class2, p->class3);
	}
}
*/
//利用共用体输出ascii码
/*
#include <stdio.h>
union CH
{
	int num;
	char ch;
}EXCH;
int main()
{

while (1)
	{
		scanf("%c",&EXCH.ch);
		if (EXCH.ch== 'z')
		{
			break;
		}
		else
		{
			printf("\"%c\"对应的ascii值为：%d\n",EXCH.ch, EXCH.num);
			break;
		}
	}
	
	system("pause");
	return 0;
}
*/

#include <stdio.h>
#define N 2
struct COMP
{
	long num;
	char name[20];
	int base;
	int other;
}cp[N];
typedef struct COMP DATA;
void print(DATA *p);
void min(DATA *q);
int main()
{
	int i;
	for ( i = 0; i < N; i++)
	{
		printf("请分别输入第%d位职工编号、姓名、基本工资、职务工资\n",i+1);
		scanf("%ld%s%d%d",&cp[i].num,&cp[i].name,&cp[i].base,&cp[i].other);
	}
	min(cp);
	print(cp);
	system("pause");
	return 0;
}
void min(DATA *q)
{
	int i=0,temp=0,min=0,max=0;
	min = q[0].base + q[0].other;
	for ( i = 0; i < N-1; i++)//此处N一定要减一不然数组越界。
	{
		max = q[i + 1].base + q[i + 1].other;
		if (min>=max)
		{
			min = q[i + 1].base + q[i + 1].other;
		}
	}
	for ( i = 0; i < N; i++)
	{
		if (min==q[i].base + q[i].other)
		{
			printf("工资最低的是%d\n", min);
			printf("%ld\t\t%s\t%d\t\t%d\t\t%d\n", q[i].num, q[i].name,
				q[i].base, q[i].other, q[i].base + q[i].other);
		}
	}
	
	
}
void print(DATA *p)
{
	int i;
	printf("职工编号\t姓名\t基本工资\t职务工资\t总工资\n");
	for (i = 0; i < N; i++)
	{
		printf("%ld\t\t%s\t%d\t\t%d\t\t%d\n", p[i].num, p[i].name,
			p[i].base, p[i].other, p[i].base+p[i].other);
	}
}