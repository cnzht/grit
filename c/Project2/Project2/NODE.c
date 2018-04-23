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
		printf("\t\t**请输入1、2、3、4选择相应操作**\n");
		printf("\t\t**请输入1：显示链表节点**\n");
		printf("\t\t**请输入2：删除链表节点**\n");
		printf("\t\t**请输入3：插入链表**\n");
		printf("\t\t**请输入4:退出**\n");
		printf("\t\t*****************************************\n");
		scanf("%d", &choice);
		if (choice == 4)//退出
		{
			break;
		}
		else if (choice == 1)//显示
		{
			print(list);
		}
		else if (choice == 2)//删除
		{
			printf("输入要删除的学号\n");
			scanf("%d", &number);
			delelist(list, number);
		}
		else if (choice == 3)//插入
		{
			printf("请输入要插入的位置\n");
			scanf("%d", &location);
			pNEW = (NODE*)malloc(sizeof(NODE));
			if (pNEW == 0)
			{
				printf("创建节点失败！\n");
				continue;
			}
			printf("请输入要节点插入学生学号和成绩！\n");
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
void print(NODE *head)//1、显示链表信息
{
	NODE *p;
	printf("链表节点信息如下\n");
	printf("学号\t分数\t\n");
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%d\t%.2f\n", p->num, p->score);
	}
}
void delelist(NODE *head, int number)//2、删除链表中的某一个节点
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
		printf("所要删除的节点不存在！\n");
		return;
	}
	temp = p->next;
	p->next = temp->next;
	free(q);
}

void insertlist(NODE *head, int i, NODE *pNEW)//3、插入链表中的某一个节点
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
		printf("插入的i太大\n");
	}
	else
	{
		pNEW->next = p->next;
		p->next = pNEW;
	}
}
NODE *cerate()//创建一个链表
{
	NODE *head, *pNEW, *pLAST;
	int num, score;
	head = (NODE*)malloc(sizeof(NODE));
	if (head == 0)
	{
		printf("创建失败！\n");
		return (NULL);
	}
	head->next = NULL;
	pLAST = head;
	while (1)
	{
		printf("请输入学生学号，当学号为0时退出\n");
		scanf("%d", &num);
		if (num == 0) break;
		printf("请输入学生成绩\n");
		scanf("%d", &score);
		pNEW = (NODE*)malloc(sizeof(NODE));
		if (pNEW == 0)
		{
			printf("创建失败！\n");
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
