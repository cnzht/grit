#include "SLStack.h"

/*
void LSStackInitiate(LSNode **);//��ʽ��ջ��ʼ����
int LSStackNoEmpty(LSNode *);//�ж�Ϊ�շ�
int LSStackPush(LSNode *, DataType);//��ջ��
int LSStackPop(LSNode *, DataType *);//��ջ��
int LSStackTop(LSNode *, DataType *);//ȡջ����
void Destroy(LSNode *);//�ͷ��ڴ棻
*/

void LSStackInitiate(LSNode **head)//��ʽ��ջ��ʼ����
{
	if ((*head=(LSNode*)malloc(sizeof(LSNode)))==NULL)
	{
		exit(1);
	}
	else
	{
		(*head)->nex = NULL;
	}
}
int LSStackNoEmpty(LSNode *head)//�ж�Ϊ�շ�
{
	if (head->nex==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int LSStackPush(LSNode *head, DataType x)//��ջ��
{
	LSNode *pre;

	if ((pre=(LSNode *)malloc(sizeof(LSNode)))==NULL)
	{
		printf("�ڴ治�㣡");
		return 0;
	}
	else
	{
		pre->data = x;
		pre->nex = head->nex;
		head->nex = pre;
		return 1;
	}
}
int LSStackPop(LSNode *head, DataType *x)//��ջ��
{
	LSNode *pre=head->nex;

	if (pre == NULL)
	{
		printf("��ջ�ѿգ�");
		return 0;
	}
	else
	{
		*x = pre->data;
		head->nex = pre->nex;
		free(pre);
		return 1;
	}
}
int LSStackTop(LSNode *head, DataType *x)//ȡջ����
{
	LSNode *pre=head->nex;

	if (pre == NULL)
	{
		printf("��ջ�ѿգ�");
		return 0;
	}
	else
	{
		*x = pre->data;
		return 1;
	}
}
void Destroy(LSNode *head)//�ͷ��ڴ棻
{
	LSNode *pre, *temp;

	pre = head;
	while (pre!=NULL)
	{
		temp = pre;
		pre = pre->nex;
		free(temp);
	}
}