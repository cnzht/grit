/*β�巨����������ʵ�ֲ����ɾ������*/
/*
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
	DATA *list;
	int flag = 0;
	int number = 0;
	int join = 0;
	int way = 0;
	printf("ѡ��β�巨��ͷ�巨\n");
	scanf("%d", &way);
	if (way==1)
	{
		list = cerat();
	}
	else
	{
		list = end();
	}
	printf("**************************\n");
	printf("����1ѡ����ʾ����\n");
	printf("����2ѡ�������\n");
	printf("����3ѡ��ɾ������\n");
	printf("����0�˳�����\n");
	printf("**************************\n");
	scanf("%d", &flag);
	while (flag != 0)
	{
		if (flag == 1)
		{
			print(list);
		}
		else if (flag == 2)
		{
			printf("�������λ��\n");
			scanf("%d", &number);
			insertnode(list, number);
		}
		else if (flag == 3)
		{
			printf("����ɾ��λ��\n");
			scanf("%d", &join);
			delenode(list, join);
		}
		else
		{
			printf("�˳���ллʹ�ã�\n");
			system("pause");
			exit(1);
		}
		printf("**************************\n");
		printf("����1ѡ����ʾ����\n");
		printf("����2ѡ�������\n");
		printf("����3ѡ��ɾ������\n");
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
		scanf("%ld", &pnew->num);
		if (pnew->num == 0)
		{
			break;
		}
		printf("����������\n");
		scanf("%s", &pnew->name);
		printf("����������ʣ�\n");
		scanf("%d", &pnew->base);
		printf("���뼨Ч���ʣ�\n");
		scanf("%d", &pnew->other);
		if (head == NULL)
		{
			head = pnew;
		}
		else
		{
			plast->next = pnew;
		}
		plast = pnew;
	}
	if (plast != NULL)
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
	while (q != NULL&&q->num != number)
	{
		p = q;
		q = q->next;
	}
	if (q == NULL)
	{
		printf("�Ҳ�����Ҫɾ���ı�ţ�\n");
		return;
	}
	p->next = NULL;
	p->next = q->next;
	free(q);
}
void insertnode(DATA *head, int join)
{
	DATA *p = head, *pnew;
	int j = 0;
	pnew = (DATA*)malloc(sizeof(DATA));
	printf("������ţ�\n");
	scanf("%ld", &pnew->num);
	printf("����������\n");
	scanf("%s", &pnew->name);
	printf("����������ʣ�\n");
	scanf("%d", &pnew->base);
	printf("���뼨Ч���ʣ�\n");
	scanf("%d", &pnew->other);
	while (p != NULL&&j<join)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
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
	for (; p != NULL; p = p->next)
	{
		printf("���\t����\t��������\t��Ч����\n");
		printf("%ld\t%s\t\t%d\t\t%d\n", p->num, p->name, p->base, p->other);
	}
}
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyStruct
{
	int data;
	struct MyStruct *next;
}NODE;
NODE *end();
NODE *front();
void dele(NODE *head, int i);
void insert(NODE *head, int i);
void print(NODE *head);
void sort(NODE *head);
int main()
{
	NODE *list = front();
	int n;

	scanf("%d",&n);
	insert(list,n);
	print(list);
	system("pause");
	return 0;
}
NODE *end()/*β�巨*/
{
	NODE *head, *pnew, *plast;

	head = (NODE*)malloc(sizeof(NODE));
	if (head==NULL)
	{
		printf("Set ERROR!\n");
	}
	head = NULL;
	plast = NULL;
	while (1)
	{
		pnew = (NODE*)malloc(sizeof(NODE));
		printf("(β�巨)�������ݣ�������0�˳���\n");
		scanf("%d", &pnew->data);
		if (pnew->data==0)
		{
			break;
		}
		if (head==NULL)
		{
			head = pnew;
		}
		else
		{
			plast->next=pnew;
		}
		plast = pnew;
	}
	if (plast!=NULL)
	{
		plast->next = NULL;
	}
	return head;
}
NODE *front()/*ͷ�巨*/
{
	NODE *head, *c;
	head = (NODE*)malloc(sizeof(NODE));
	if (head==NULL)
	{
		printf("Set ERROR!\n");
	}
	head = NULL;
	while (1)
	{
		c = (NODE*)malloc(sizeof(NODE));
		if (c == NULL)
		{
			printf("Set ERROR!\n");
		}
		printf("��ͷ�巨���������ݣ�������0�˳���\n");
		scanf("%d", &c->data);
		if (c->data == 0)
		{
			break;
		}
		c->next = head;
		head = c;
		
	}
	return head;
}
void dele(NODE *head, int i)/*ɾ��*/
{
	NODE *p = head, *q = head->next;
	while (q != NULL&&q->data!=i)
	{
		p = q;
		q = q->next;
	}
	if (q==NULL)
	{
		printf("error!\n");
	}
	p->next = NULL;
	p->next = q->next;
	free(q);
}
void insert(NODE *head, int i)/*����*/
{
	NODE *p = head;
	NODE *pnew;
	int n=0;
	while (p!=NULL&&n<i)
	{
		p=p->next;
		n++;
	}
	if (p==NULL)
	{
		printf("error!\n");
	}
	pnew = (NODE*)malloc(sizeof(NODE));
	printf("��������:\n");
	scanf("%d", &pnew->data);
	pnew->next = p->next;
	p->next = pnew;
	
}
void print(NODE *head)/*�������*/
{
	for (  ; head!=NULL;head=head->next)
	{
		printf("������������:\n");
		printf("%d\n",head->data);
	}
}
void sort(NODE *head)/*����*/
//������
{
	NODE *p = head;
	NODE *temp = NULL;
	int i=0;

	for (; p != NULL;p=p->next,i++)
	{
		if (p[i].data<p[i+1].data)
		{
			strcpy(p[i].data,p[i + 1].data);
			p[i] = p[i + 1];
		}
	}
}
