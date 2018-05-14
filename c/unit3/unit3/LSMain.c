#include "SLStack.h"

/*
void LSStackInitiate(LSNode **);//链式堆栈初始化；
int LSStackNoEmpty(LSNode *);//判断为空否；
int LSStackPush(LSNode *, DataType);//入栈；
int LSStackPop(LSNode *, DataType *);//出栈；
int LSStackTop(LSNode *, DataType *);//取栈顶；
void Destroy(LSNode *);//释放内存；
*/

int main()
{
	LSNode *head;
	int i, x=0, y=0,size = 0;

	LSStackInitiate(&head);
	printf("输入堆栈长度：");
	scanf("%d",&size);
	for ( i = 0; i < size; i++)
	{
		if ((LSStackPush(head,i+1))==0)
		{
			printf("入栈错误！");
			getchar();
			return;
		}
	}
	printf("当前栈顶为：");
	if ((LSStackNoEmpty(head)) == 0)
	{
		printf("栈空！");
		getchar();
		return;
	}
	else
	{
		if ((LSStackTop(head, &x)) == 0)
		{
			printf("栈顶错误！");
			getchar();
			return;
		}
		else
		{
			printf("%d\n", x);
		}
	}
	printf("当前堆栈显示：\n");
	for (i = 0; i < size; i++)
	{
		if ((LSStackNoEmpty(head)) == 0)
		{
			printf("栈空！");
			getchar();
			return;
		}
		else
		{
			if ((LSStackPop(head, &y)) == 0)
			{
				printf("取出错误！");
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