/********************************************
功能：合并链表、并排序输出、
日期：2018年4月27日 20:34:39
作者：周某人
版本：V1.0
**********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyStruct
{
	long num;
	int exam;
	struct MyStruct *nxet;
}NODE;
NODE *set();
void print(NODE *head);
NODE *insert(NODE *p1, NODE *p2);
NODE *dele(NODE *head, NODE *b);
NODE *link(NODE *p1, NODE *p2);
NODE *reserve(NODE *head);//链表翻转
void *sort(NODE *p);
void *exchange(NODE *head);
int main()
{
	NODE *a, *b, *c;
	a = set();
	b = set();
	c = insert(a, b);
	//print(c);
	//c = dele(a, b);
	//c = link(a, b);
	//sort(c);
	exchange(c);
	print(c);
	system("pause");
	return 0;
}
NODE *set()
{
	NODE *head, *p, *q;
	head = NULL;
	q = NULL;
	while (1)
	{
		p = (NODE*)malloc(sizeof(NODE));
		printf("请输入学号（输入0时退出！）：\n");
		scanf("%ld",&p->num);
		if (p->num==0)
		{
			break;
		}
		printf("请输入成绩：\n");
		scanf("%d", &p->exam);
		if (head==NULL)
		{
			head = p;
		}
		else
		{
			q->nxet = p;
		}
		q = p;
	}
	if (q!=NULL)
	{
		q->nxet = NULL;
	}
	return head;
}
void *exchange(NODE *head)
{
	if (head==NULL||head->nxet==NULL)//边界条件
	{
		return;
	}
	NODE *p1 , *p2 ;
	NODE *tall = NULL;

	while (head->nxet->nxet!=tall)
	{
		p1 = head;
		p2 = head->nxet;
		while (p2->nxet!=tall)
		{
			if (p2->num >= p2->nxet->num)
			{
				p1->nxet = p2->nxet;
				p2->nxet = p2->nxet->nxet;
				p1->nxet->nxet = p2;
				p2 = p1->nxet;
			}
			p1 = p1->nxet;
			p2 = p2->nxet;
		}
		tall = p2;
		
	}
	
}
NODE *insert(NODE *p1, NODE *p2)//插入链表
{
	NODE *head, *q;
	head = p1;
	q = head;
	p1 = p1->nxet;
	while (p1!=NULL)
	{
		q->nxet = p1;
		q = p1;
		p1 = p1->nxet;
	}
	if (p1==NULL)
	{
		q->nxet = p2;
		//p1 = p2;
		//p1 = p1->nxet;
	}
	return head;

	
	/*
	NODE *front = head;
	while (front != NULL)
	{
		front = front->nxet;
	}
		if (front == NULL)
		{
			printf("Error!\n");
		}
		else
		{
			add->nxet = front->nxet;
			front->nxet = add;
		}
	return front;
	*/
}
NODE *dele(NODE *head,NODE *b)//删除链表中相同的元素
{
	NODE *p = head, *q = head->nxet;
	int i = 0;
	while (q != NULL&&q->num != b->num)
	{
		p = q;
		q = q->nxet;
	}
	if (q == NULL)
	{
		printf("Error!\n");
	}
	else
	{
		p->nxet = NULL;
		p->nxet = q->nxet;
		free(q);
	}
	return p;
}
void print(NODE *head)//输出链表
{
	NODE *n = head;
	for ( ; n!= NULL; n=n->nxet)
	{
		printf("%ld\t%d\n",n->num,n->exam);
	}

}
void *sort(NODE *p)//单链表排序
{
	struct MyStruct
	{
		long num;
		int exam;
	}temp;
	NODE *F, *E;
	for (F = p; F != NULL; F = F->nxet)
	{
		for (E = F->nxet; E != NULL; E = E->nxet)
		{
			if (F->num > E->num)
			{
				temp.num = E->num;
				E->num = F->num;
				F->num = temp.num;
				temp.exam = E->exam;
				E->exam = F->exam;
				F->exam = temp.exam;
			}
		}
	}
}
NODE *reserve(NODE *head)//链表翻转
{
	if (head==NULL||head->nxet==NULL)
	{
		return;

	}
	NODE *p1, *p2, *p3;
	p1 = head;
	p2 = p1->nxet;
	p3 = p2->nxet;
	p1->nxet = NULL;
	while (p3!=NULL)
	{
		p2->nxet = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->nxet;
	}
	p2->nxet = p1;
	head = p2;
	return head;

}
NODE *link(NODE *p1, NODE *p2)//链表合并排序，只是对两个链表第一个元素比较大小排序。
{
	NODE *p, *head;
	if (p1->num < p2->num)
	{
		head = p = p1;
		p1 = p1->nxet;
	}
	else
	{
		head = p = p2;
		p2 = p2->nxet;
	}
	while ((p1 != NULL) && (p2 != NULL))
	{
		if (p1->num < p2->num)
		{
			p->nxet = p1;
			p = p1;
			p1 = p1->nxet;
		}
		else
		{
			p->nxet = p2;
			p = p2;
			p2 = p2->nxet;
		}
	}
	if (p1 != NULL)
		p->nxet = p1;
	else
		p->nxet = p2;

	return head;
}

/*
struct y_m_d
{
	int year;
	int month;
	int day;
};

int days(struct y_m_d date)
{
	int sum = date.day;
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	for (i = 1; i<date.month; i++)
	{
		sum += a[i];
	}
	if (date.month>2 && ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)) //若闰年，且晚于2月，加一天
		sum++;
	return sum;
}

int main()
{
	struct y_m_d date;
	int day_sum;
	printf("请输入年月日（以空格隔开）：");
	scanf("%d%d%d", &date.year, &date.month, &date.day);
	day_sum = days(date);
	printf("%d年%d月%d日是%d年的第%d天\n", date.year, 
		date.month, date.day, date.year, day_sum);
	system("pause");
	return 0;

}
*/
/*
typedef struct MyStruct
{
	int year;
	int month;
	int day;
}DATA;
int run(DATA *q);//判断闰年，并返回2月的天数。
int main()
{
	DATA *p;
	int num = 0;

	p = (DATA*)malloc(sizeof(DATA));
	printf("请输入年份，月份，日期：\n");
	scanf("%d,%d,%d",&p->year,&p->month,&p->day);
	if (p->month>12&&p->day>31)
	{
		printf("input error!\n");
		exit(1);
	}
	if (p->month==1)
		{
			num = p->day;
		}
	else if (p->month == 2)
		{
			num = (p->month * 31) + p->day;
		}
	else if (p->month == 3||p->month == 5||p->month == 7||
			p->month == 8||p->month == 10||p->month == 12)
		{
			num = ((p->month - 2) * 31) + run(p) + p->day;
		}
	else
		{
			num = ((p->month - 2) * 30) + run(p) + p->day;
		}

	printf("\n这是%d年-%d月-%d日，是%d的第%d天！\n",p->year,p->month,p->day,p->year,num);
	
	system("pause");
	return 0;
}

int run(DATA *p)
{
	int second = 0;
	if (p->year % 4 == 0 && p->year % 100 != 0 && p->year % 400 == 0)//判断闰年
	{
		second = 29;
	}
	else
	{
		second = 28;
	}
	return second;
}
*/