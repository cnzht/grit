#include "lead.h"
void  main()
{
	char userName[8];
	char userPWD[7];
	int i;
	welcome();
	for ( i = 0; i < 3; i++)
	{
		printf("�����������û�����(��%d��)\n",i+1);
		scanf("%s",userName);
		printf("�������������룺(��%d��)\n",i+1);
		scanf("%s", userPWD);
		if ((strcmp(userName,"admin")==0)&&(strcmp(userPWD,"123456")==0))
		{
			mainmenu();
			break;
		}
		else
		{
			if (i<2)
			{
				printf("�û����������������������!��(��%d��)\n",i+1);
				
			}
			else
			{
				printf("%d�λ������꣬�û���������������˳�ϵͳ��", i + 1);
				exit(1);
			}
		}
	}
	system("pause");
}