#include "LinList.h"

/*
void ListInitiate(SLNODE ** head);//�����ʼ����
int ListLength(SLNODE *head);//���������ȣ�
int ListInsert(SLNODE *head, int i, DataType x);//��ĳ��λ��i���������ݣ�
int ListDelete(SLNODE *head, int i, DataType *x);//ɾ��i�������ݣ�
int ListGet(SLNODE *head, int i, DataType *x);//��ȡĳ��λ��i�������ݣ�
void DeleteList(SLNODE **head);//�������

void ListSort(SLNODE *head);//����������
*/

int main()
{
	SLNODE *head;//����ͷָ�������
	int i, x, num = 0;
	//head = (SLNODE*)malloc(sizeof(SLNODE));
	ListInitiate(&head);//��ʼ����ʹ����������ͷָ�룩��
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		if (ListInsert(head,i,num)==0)
		{
			printf("�������\n");
			getchar();
			return;
		}
	}
	if (ListDelete(head,4,&x)==0)
	{
		printf("ɾ������\n");
		getchar();
		return;
	}
	for ( i = 0; i < ListLength(head); i++)
	{
		if (ListGet(head, i, &x) == 0)
		{
			printf("ȡ������\n");
			getchar();
			return;
		}
		else
		{
			printf("%d      ", x);
		}
	}
	printf("\n�����\n");
	LinListInsert(head, 3);
	LinListSort(head);//�������⣻
	for (i = 0; i < ListLength(head); i++)
	{
		if (ListGet(head, i, &x) == 0)
		{
			printf("ȡ������\n");
			getchar();
			return;
		}
		else
		{
			printf("%d      ", x);
		}
	}
	DeleteList(&head);//����������

	getchar();
	return 0;
}