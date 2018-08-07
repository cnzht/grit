#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

typedef struct node{
	DATATYPE date;
	int size;
	struct node *next;
}SLNODE;

void ListInit(SLNODE **head)
{
	if ((*head = (SLNODE*)malloc(sizeof(SLNODE))) == NULL)
	{
		printf("error!\n");
		return 0;
	}
	(*head)->next = NULL;
}
int ListLength(SLNODE *head)
{
	SLNODE *p;
	int j=0;

	p = head;
	while (p->next!=NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}
int ListInsert(SLNODE *head, int i, DATATYPE x)
{
	SLNODE *p, *q;
	int j=-1;

	p = head;
	q = (SLNODE *)malloc(sizeof(SLNODE));
	while (p->next!=NULL&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j!=i-1)
	{
		printf("²åÈëÎ»ÖÃÓÐÎó£¡\n");
		return 0;
	}
	p->date = x;
	q->next = p->next;
	p->next = q;
	return 1;
}
void Print(SLNODE *head,int n)	
{
	SLNODE *p = head;

	for (int i = 0; i < n; i++,p=p->next)
	{
		printf("%d    \n", p->date);
	}
}
void NxPrint(SLNODE *head)
{
	SLNODE *pre=NULL,*next=NULL;
	while (head->next!=NULL)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	while (pre!=NULL)
	{
		printf("%d", pre->date);
		pre = pre->next;
	}
}
void Destroy(SLNODE *head)
{
	SLNODE *p, *q;
	p = head;
	q = (SLNODE *)malloc(sizeof(SLNODE));

	while (p->next!=NULL)
	{
		q = p->next;
		p = q;
		free(q);
	}
}
int main()
{
	SLNODE *mylist;
	int i, x;

	ListInit(&mylist);
	for ( i = 0; i < 10; i++)
	{
		ListInsert(mylist, i, i + 1);
	}
	Print(mylist, ListLength(mylist));
	NxPrint(mylist);
	//Destroy(mylist);
	getchar();
	return 0;
}