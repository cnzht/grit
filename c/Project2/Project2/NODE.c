#include <stdio.h>
#include <string.h>
struct student
{
	int num;
	float score;
	struct student *next;
};
typedef struct student NODE;
void print(NODE *);
void delelist(NODE *head, int number);
void insertlist(NODE *head, int i, NODE *pNEW);
NODE *cerate();
void print(NODE *head);

int main()
{
	NODE *list, *pNEW;
	int number = 0, score, location, choice;
	list = cerate();
	while (1)
	{
		printf("\t\t*****************************************\n");
		printf("\t\t**������1��2��3��4ѡ����Ӧ����**\n");
		printf("\t\t**������1����ʾ����ڵ�**\n");
		printf("\t\t**������2��ɾ������ڵ�**\n");
		printf("\t\t**������3����������**\n");
		printf("\t\t**������4:�˳�**\n");
		printf("\t\t*****************************************\n");
		scanf("%d", &choice);
		if (choice == 4)//�˳�
		{
			break;
		}
		else if (choice == 1)//��ʾ
		{
			print(list);
		}
		else if (choice == 2)//ɾ��
		{
			printf("����Ҫɾ����ѧ��\n");
			scanf("%d", &number);
			delelist(list, number);
		}
		else if (choice == 3)//����
		{
			printf("������Ҫ�����λ��\n");
			scanf("%d", &location);
			pNEW = (NODE*)malloc(sizeof(NODE));
			if (pNEW == 0)
			{
				printf("�����ڵ�ʧ�ܣ�\n");
				continue;
			}
			printf("������Ҫ�ڵ����ѧ��ѧ�źͳɼ���\n");
			scanf("%d %d", &number, &score);
			pNEW->num = number;
			pNEW->score = score;
			insertlist(list, location, pNEW);
		}
		else
		{
			printf("error!\n");
			continue;
		}
	}
	system("pause");
	return 0;
}
void print(NODE *head)//1����ʾ������Ϣ
{
	NODE *p;
	printf("����ڵ���Ϣ����\n");
	printf("ѧ��\t����\t\n");
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%d\t%.2f\n", p->num, p->score);
	}
}
void delelist(NODE *head, int number)//2��ɾ�������е�ĳһ���ڵ�
{
	NODE *p = head, *q = head->next;
	NODE *temp;
	while (q != NULL&&q->num != number)
	{
		p = q;
		q = q->next;
	}
	if (q == NULL)
	{
		printf("��Ҫɾ���Ľڵ㲻���ڣ�\n");
		return;
	}
	temp = p->next;
	p->next = temp->next;
	free(q);
}

void insertlist(NODE *head, int i, NODE *pNEW)//3�����������е�ĳһ���ڵ�
{
	int j = 0;
	NODE *p;
	p = head;
	while (p != NULL&&j<i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		printf("�����i̫��\n");
	}
	else
	{
		pNEW->next = p->next;
		p->next = pNEW;
	}
}
NODE *cerate()//����һ������
{
	NODE *head, *pNEW, *pLAST;
	int num, score;
	head = (NODE*)malloc(sizeof(NODE));
	if (head == 0)
	{
		printf("����ʧ�ܣ�\n");
		return (NULL);
	}
	head->next = NULL;
	pLAST = head;
	while (1)
	{
		printf("������ѧ��ѧ�ţ���ѧ��Ϊ0ʱ�˳�\n");
		scanf("%d", &num);
		if (num == 0) break;
		printf("������ѧ���ɼ�\n");
		scanf("%d", &score);
		pNEW = (NODE*)malloc(sizeof(NODE));
		if (pNEW == 0)
		{
			printf("����ʧ�ܣ�\n");
			return (NULL);
		}
		pNEW->num = num;
		pNEW->score = score;
		pNEW->next = NULL;
		pLAST->next = pNEW;
		pLAST = pNEW;
	}
	return head;
}
