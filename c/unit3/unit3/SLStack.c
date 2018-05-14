#include "SLStack.h"

/*
void LSStackInitiate(LSNode **);//Á´Ê½¶ÑÕ»³õÊ¼»¯£»
int LSStackNoEmpty(LSNode *);//ÅÐ¶ÏÎª¿Õ·ñ£»
int LSStackPush(LSNode *, DataType);//ÈëÕ»£»
int LSStackPop(LSNode *, DataType *);//³öÕ»£»
int LSStackTop(LSNode *, DataType *);//È¡Õ»¶¥£»
void Destroy(LSNode *);//ÊÍ·ÅÄÚ´æ£»
*/

void LSStackInitiate(LSNode **head)//Á´Ê½¶ÑÕ»³õÊ¼»¯£»
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
int LSStackNoEmpty(LSNode *head)//ÅÐ¶ÏÎª¿Õ·ñ£»
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
int LSStackPush(LSNode *head, DataType x)//ÈëÕ»£»
{
	LSNode *pre;

	if ((pre=(LSNode *)malloc(sizeof(LSNode)))==NULL)
	{
		printf("ÄÚ´æ²»×ã£¡");
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
int LSStackPop(LSNode *head, DataType *x)//³öÕ»£»
{
	LSNode *pre=head->nex;

	if (pre == NULL)
	{
		printf("¶ÑÕ»ÒÑ¿Õ£¡");
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
int LSStackTop(LSNode *head, DataType *x)//È¡Õ»¶¥£»
{
	LSNode *pre=head->nex;

	if (pre == NULL)
	{
		printf("¶ÑÕ»ÒÑ¿Õ£¡");
		return 0;
	}
	else
	{
		*x = pre->data;
		return 1;
	}
}
void Destroy(LSNode *head)//ÊÍ·ÅÄÚ´æ£»
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