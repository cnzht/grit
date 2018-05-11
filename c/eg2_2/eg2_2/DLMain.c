#define MaxSzie 5
#include "DoubleList.h"

int main()
{
	DLNode *head;
	int i, x, num, size = 0, count = 0, dele = 0;

	/*
	void ListInitiate(DLNode ** head);//�����ʼ����
	int ListLength(DLNode *head);//���������ȣ�
	int ListInsert(DLNode *head, int i, DataType x);//��ĳ��λ��i���������ݣ�
	int ListDelete(DLNode *head, int i, DataType *x);//ɾ��i�������ݣ�
	int ListGet(DLNode *head, int i, DataType *x);//��ȡĳ��λ��i�������ݣ�
	void DeleteList(DLNode **head);//�������

	int ListDataDelete(DLNode *head, DataType x);//ɾ��ָ�����֣�
	*/
	ListInitiate(&head);
	for ( i = 0; i < MaxSzie; i++)
	{
		scanf("%d",&num);
		if ((ListInsert(head, i, num)) == 0)
		{
			printf("�������\n");
			getchar();
			return;
		}
		size++;
	}
	head->size = size;
	if ((ListDelete(head,1,&x))==0)
	{
		printf("λ��ɾ������\n");
		getchar();
		return;
	}
	else
	{
		count++;
	}
	for (i = 0; i < MaxSzie - count; i++)
	{
		if ((ListGet(head, i, &x)) == 0)
		{
			printf("ȡ������\n");
			getchar();
			return;
		}
		else
		{
			printf("%d       ", x);
		}
	}
	printf("\n");
	printf("����Ҫɾ����ֵ��");
	scanf("%d",&dele);
	if ((ListDataDelete(head, dele)) == 0)
	{
		printf("error!");
		return;
	}
	else
	{
		count++;
	}
	for (i = 0; i < MaxSzie-count; i++)
	{
		if (( ListGet(head,i,&x)) == 0)
		{
			printf("ȡ������\n");
			getchar();
			return;
		}
		else
		{
			printf("%d       ", x);
		}
	}
	DeleteList(&head);
	getchar();
	getchar();
	return 0;
}