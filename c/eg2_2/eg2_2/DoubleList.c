#include "DoubleList.h"

/*
void ListInitiate(DLNode ** head);//�����ʼ����
int ListLength(DLNode *head);//���������ȣ�
int ListInsert(DLNode *head, int i, DataType x);//��ĳ��λ��i���������ݣ�
int ListDelete(DLNode *head, int i, DataType *x);//ɾ��i�������ݣ�
int ListGet(DLNode *head, int i, DataType *x);//��ȡĳ��λ��i�������ݣ�
void DeleteList(DLNode **head);//�������

//�Զ���
int ListDataDelete(DLNode *head, DataType x);//ɾ��ָ�����֣�
*/

void ListInitiate(DLNode ** head)//�����ʼ����
{
	if ((*head=(DLNode*)malloc(sizeof(DLNode)))==NULL)
	{
		exit(0);
	}
	(*head)->prior = *head;
	(*head)->next = *head;
}
int ListLength(DLNode *head)//���������ȣ�//�����⡣
{
	DLNode *p = head->next;
	int i = 0;

	while (p!=head)
	{
		i++;
		p = p->next;
	}
	return i;
}
int ListInsert(DLNode *head, int i, DataType x)//��ĳ��λ��i���������ݣ�
{
	DLNode *p , *q;
	int j = 0;

	p = head->next;
	while (p!=head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i)
	{
		printf("����λ�ô���\n");
		return 0;
	}
	if((q = (DLNode*)malloc(sizeof(DLNode)))==NULL)exit(0);
	q->data = x;
	
	q->prior = p->prior;//��ͼ��⣻
	p->prior->next = q;
	q->next = p;
	p->prior = q;

	return 1;
}
int ListDelete(DLNode *head, int i, DataType *x)//ɾ��i�������ݣ�
{
	DLNode *p = head->next;
	int j = 0;

	while (p != head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("ɾ��λ�ô���\n");
		return 0;
	}
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	*x = p->data;
	free(p);
	return 1;

}
int ListGet(DLNode *head, int i, DataType *x)//��ȡĳ��λ��i�������ݣ�
{
	DLNode *p = head->next;
	int j = 0;

	while (p != head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("ȡ��λ�ô���\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
void DeleteList(DLNode **head)//�������
{
	DLNode *p, *q;
	int i, n = ListLength(*head);

	p = *head;
	for ( i = 0; i < n; i++)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}
int ListDataDelete(DLNode *head, DataType x)
{
	DLNode *p=head;

	if (p->data==x)//����ǵ�һ��Ԫ�ؾ���Ҫɾ����Ԫ�أ�
	{
		head = p->next;//ͷָ��ֱ��ָ����һ���ڵ㣻
		//head->next = p->next;
		head->prior = NULL;
		free(p);
		return 1;
	}
	while (p)//����������������������������Ԫ�أ�
	{
		if (p->data == x)
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			free(p);
		}
		return 1;
	}
	printf("û���ҵ�Ҫɾ����ֵ��\n");
	return 0;
}