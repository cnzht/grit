#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef char DataType;
typedef struct 
{
	DataType data;
	char lChild;
	char rChild;
}PTree;

void CreatPTree(PTree *);
void Print(PTree *);

int main()
{
	PTree tree;

	CreatPTree(&tree);
	Print(&tree);
	getchar();
	getchar();
	return 0;
}

void CreatPTree(PTree * T)
{
	DataType ch;

	scanf("%c", &ch);
	if (ch=='#')
	{
		T = NULL;
	}
	else
	{
		T = (PTree *)malloc(sizeof(PTree));
		if (!T)
		{
			exit(1);
		}
		else
		{
			T->data = ch;
			CreatPTree(&T->lChild);
			CreatPTree(&T->rChild);
		}
	}
}

void Print(PTree * T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		Print(T->lChild);
		Print(T->rChild);
	}

}
