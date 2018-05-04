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
	printf("����1ѡ��ͷ�巨\n");
	printf("����2ѡ��β�巨\n");
	printf("����3ѡ�������\n");
	printf("����4ѡ��ɾ������\n");
	printf("����5ѡ����ʾ����\n");
	printf("����0�˳�����\n");
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
			printf("�������λ��\n");
			scanf("%d", &number);
			insertnode(cerat(), number);
		}
		else if (flag == 4)
		{
			printf("����ɾ��λ��\n");
			scanf("%d", &join);
			delenode(cerat(),join);
		}
		else if (flag == 5)
		{
			print(cerat());
		}
		else
		{
			printf("�˳���ллʹ�ã�\n");
			system("pause");
			exit(1);
		}
		printf("**************************\n");
		printf("����1ѡ��ͷ�巨\n");
		printf("����2ѡ��β�巨\n");
		printf("����3ѡ�������\n");
		printf("����4ѡ��ɾ������\n");
		printf("����5ѡ����ʾ����\n");
		printf("����0�˳�����\n");
		printf("**************************\n");
		scanf("%d", &flag);
	}
	system("pause");
	return 0;
}
DATA *cerat()//β�巨
{
	DATA *head, *pnew, *plast;
	head = NULL;
	plast = NULL;
	while (1)
	{
		pnew = (DATA*)malloc(sizeof(DATA));
		printf("������ţ�����0ʱ�˳���\n");
		scanf("%ld",&pnew->num);
		if (pnew->num==0)
		{
			break;
		}
		printf("����������\n");
		scanf("%s", &pnew->name);
		printf("����������ʣ�\n");
		scanf("%d", &pnew->base);
		printf("���뼨Ч���ʣ�\n");
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
		printf("������ţ�����0ʱ�˳���\n");
		scanf("%ld", &new->num);
		if (new->num == 0)
		{
			break;
		}
		printf("����������\n");
		scanf("%s", &new->name);
		printf("����������ʣ�\n");
		scanf("%d", &new->base);
		printf("���뼨Ч���ʣ�\n");
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
		printf("�Ҳ�����Ҫɾ���ı�ţ�\n");
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
	printf("������ţ�\n");
	scanf("%ld", &pnew->num);
	printf("����������\n");
	scanf("%s", &pnew->name);
	printf("����������ʣ�\n");
	scanf("%d", &pnew->base);
	printf("���뼨Ч���ʣ�\n");
	scanf("%d", &pnew->other);
	while (p!=NULL&&j<join)
	{
		p = p->next;
		j++;
	}
	if (p==NULL)
	{
		printf("����λ������\n");
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
		printf("���\t����\t��������\t��Ч����\n");
		printf("%ld\t%s\t\t%d\t\t%d\n", p->num, p->name, p->base, p->other);
	}
}