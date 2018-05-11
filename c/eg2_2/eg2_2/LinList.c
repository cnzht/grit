#include "LinList.h"

void ListInitiate(SLNODE ** head)//�����ʼ����
{
	if ((*head=(SLNODE*)malloc(sizeof(SLNODE)))==NULL)
	{
		exit(1);
	}
	(*head)->next = NULL;//ͷָ���ÿգ�
}
int ListLength(SLNODE *head)//���������ȣ�
{
	SLNODE *p=head;
	int i;//ͳ�������ȣ�

	for (i = 0; p->next!=NULL; i++)
	{
		p = p->next;
	}
	return i;
}
int ListInsert(SLNODE *head, int i, DataType x)//��ĳ��λ��i���������ݣ�
{
	SLNODE *p=head, *q;

	q = (SLNODE *)malloc(sizeof(SLNODE));
	int j = -1;

	while(p->next!=NULL&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j!=i-1)
	{
		printf("����λ������");
		return 0;//�����־λ������0�������λ�ô���
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;//�ɹ���־λ������1�������ɹ���
}
int ListDelete(SLNODE *head, int i, DataType *x)//ɾ��i�������ݣ�
{
	SLNODE *p = head, *q;//ָ��q�����ɾ��λ��

	q = (SLNODE *)malloc(sizeof(SLNODE));
	int j = -1;

	while(p->next != NULL&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("ɾ��λ������");
		return 0;//�����־λ������0�������λ�ô���
	}
	q = p->next;
	*x = q->data;//��ɾ���������أ�
	p->next = p->next->next;
	free(q);
	return 1;
}
int ListGet(SLNODE *head, int i, DataType *x)//��ȡĳ��λ��i�������ݣ�
{
	SLNODE *p = head;//ָ��q�����ɾ��λ��
	int j = -1;

	while(p->next != NULL&&j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("ȡ��λ������");
		return 0;//�����־λ������0�������λ�ô���
	}
	*x = p->data;
	return 1;
}
void DeleteList(SLNODE **head)//�������
{
	SLNODE *p, *q;

	//q = (SLNODE **)malloc(sizeof(SLNODE*));
	p = *head;
	for (; p->next!= NULL; )
	{
		q = p;
		p = p->next;//��������������������
		free(q);
	}
	*head = NULL;//ͷָ����Ϊ�գ�

}

void LinListInsert(SLNODE *head, DataType x)
{
	SLNODE *curr, *p, *q;

	curr = head->next;
	p = head;

	while ( curr!=NULL&&curr->data<=x)
	{
		p = curr;
		curr = curr->next;
	}
	if ((q=(SLNODE*)malloc(sizeof(SLNODE)))==NULL)
	{
		exit(1);
	}
	q->data = x;

	q->next = p->next;
	p->next = q;
}

void LinListSort(SLNODE *head)
{
	SLNODE *curr, *pre, *p, *q;

	p = head->next;
	head->next = NULL;
	
	while (p!=NULL)
	{
		curr = head->next;
		pre = head;

		while (curr!=NULL&&curr->data<=p->data)
		{
			pre = curr;
			pre = pre->next;
			curr = curr->next;
		}
		q = p;
		p = p->next;
		q->next = p->next;
		p->next = q;
	}
}