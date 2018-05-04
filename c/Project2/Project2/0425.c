#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct RMB
{
	long num;
	char name[20];
	int base;
	int other;
	struct RMB *next;
};
typedef struct RMB DATA;
DATA *cerat();
DATA *end();
void print(DATA *p);
void delenode(DATA *p, int number);
void insertnode(DATA *p, int join);
int main()
{
	int flag=0;
	int number = 0;
	int join=0;
	printf("**************************\n");
	printf("输入1选择头插法\n");
	printf("输入2选择尾插法\n");
	printf("输入3选择插入编号\n");
	printf("输入4选择删除数据\n");
	printf("输入5选择显示数据\n");
	printf("输入0退出程序\n");
	printf("**************************\n");
	scanf("%d",&flag);
	while (flag!=0)
	{
		if (flag == 1)
		{
			print(end());
		}
		else if (flag == 2)
		{
			print(cerat());
		}
		else if (flag == 3)
		{
			printf("输入插入位置\n");
			scanf("%d", &number);
			insertnode(cerat(), number);
		}
		else if (flag == 4)
		{
			printf("输入删除位置\n");
			scanf("%d", &join);
			delenode(cerat(),join);
		}
		else if (flag == 5)
		{
			print(cerat());
		}
		else
		{
			printf("退出！谢谢使用！\n");
			system("pause");
			exit(1);
		}
		printf("**************************\n");
		printf("输入1选择头插法\n");
		printf("输入2选择尾插法\n");
		printf("输入3选择插入编号\n");
		printf("输入4选择删除数据\n");
		printf("输入5选择显示数据\n");
		printf("输入0退出程序\n");
		printf("**************************\n");
		scanf("%d", &flag);
	}
	system("pause");
	return 0;
}
DATA *cerat()//尾插法
{
	DATA *head, *pnew, *plast;
	head = NULL;
	plast = NULL;
	while (1)
	{
		pnew = (DATA*)malloc(sizeof(DATA));
		printf("输入序号：输入0时退出！\n");
		scanf("%ld",&pnew->num);
		if (pnew->num==0)
		{
			break;
		}
		printf("输入姓名：\n");
		scanf("%s", &pnew->name);
		printf("输入基本工资：\n");
		scanf("%d", &pnew->base);
		printf("输入绩效工资：\n");
		scanf("%d", &pnew->other);
		if (head==NULL)
		{
			head = pnew;
		}
		else
		{
			plast->next = pnew;
		}
		plast = pnew;
	}
	if (plast!=NULL)
	{
		plast->next = NULL;
	}
	return head;
}
DATA *end()
{
	DATA *head, *new;
	head = NULL;
	while (1)
	{
		new = (DATA*)malloc(sizeof(DATA));
		printf("输入序号：输入0时退出！\n");
		scanf("%ld", &new->num);
		if (new->num == 0)
		{
			break;
		}
		printf("输入姓名：\n");
		scanf("%s", &new->name);
		printf("输入基本工资：\n");
		scanf("%d", &new->base);
		printf("输入绩效工资：\n");
		scanf("%d", &new->other);
		new->next = head;
		head = new;
	}
	return head;
}
void delenode(DATA *head, int number)
{
	DATA *p = head, *q = head->next;
	while(q!=NULL&&q->num!=number)
	{
		p = q;
		q = q->next;
	}
	if (q==NULL)
	{
		printf("找不到需要删除的编号！\n");
	}
	p->next = NULL;
	p->next = q->next;
	free(q);
}
void insertnode(DATA *head, int join)
{
	DATA *p = head, *pnew;
	int j=0;
	pnew = (DATA*)malloc(sizeof(DATA));
	printf("输入序号：\n");
	scanf("%ld", &pnew->num);
	printf("输入姓名：\n");
	scanf("%s", &pnew->name);
	printf("输入基本工资：\n");
	scanf("%d", &pnew->base);
	printf("输入绩效工资：\n");
	scanf("%d", &pnew->other);
	while (p!=NULL&&j<join)
	{
		p = p->next;
		j++;
	}
	if (p==NULL)
	{
		printf("插入位置有误！\n");
	}
	else
	{
		pnew->next = p->next;
		p->next = pnew;
	}
}
void print(DATA *p)
{
	for ( ; p!= NULL; p = p->next)
	{
		printf("编号\t姓名\t基本工资\t绩效工资\n");
		printf("%ld\t%s\t\t%d\t\t%d\n", p->num, p->name, p->base, p->other);
	}
}