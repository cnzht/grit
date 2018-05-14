#include "SLStack.h"

/*
void LSStackInitiate(LSNode **);//��ʽ��ջ��ʼ����
int LSStackNoEmpty(LSNode *);//�ж�Ϊ�շ�
int LSStackPush(LSNode *, DataType);//��ջ��
int LSStackPop(LSNode *, DataType *);//��ջ��
int LSStackTop(LSNode *, DataType *);//ȡջ����
void Destroy(LSNode *);//�ͷ��ڴ棻
*/

int main()
{
	LSNode *head;
	int i, x=0, y=0,size = 0;

	LSStackInitiate(&head);
	printf("�����ջ���ȣ�");
	scanf("%d",&size);
	for ( i = 0; i < size; i++)
	{
		if ((LSStackPush(head,i+1))==0)
		{
			printf("��ջ����");
			getchar();
			return;
		}
	}
	printf("��ǰջ��Ϊ��");
	if ((LSStackNoEmpty(head)) == 0)
	{
		printf("ջ�գ�");
		getchar();
		return;
	}
	else
	{
		if ((LSStackTop(head, &x)) == 0)
		{
			printf("ջ������");
			getchar();
			return;
		}
		else
		{
			printf("%d\n", x);
		}
	}
	printf("��ǰ��ջ��ʾ��\n");
	for (i = 0; i < size; i++)
	{
		if ((LSStackNoEmpty(head)) == 0)
		{
			printf("ջ�գ�");
			getchar();
			return;
		}
		else
		{
			if ((LSStackPop(head, &y)) == 0)
			{
				printf("ȡ������");
				getchar();
				return;
			}
			else
			{
				printf("%d\n", y);
			}
		}
	}
	Destroy(head);
	getchar();
	getchar();
	return 0;
}