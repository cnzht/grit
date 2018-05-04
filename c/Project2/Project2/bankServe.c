#include "lead.h"

void welcome()//���뻶ӭ���溯�����壻
{
	printf("+ --------------------------------------------------------- +\n");
	printf("\n|                                                           |\n");
	printf("\n|              ��ӭʹ�á��������С����ư洢��ϵͳ           |\n");
	printf("\n|                                                           |\n");
	printf("\n+ --------------------------------------------------------- +\n");
}

void mainmenu()//��ʾ���˵��������壻
{
	int choice=1;
	if (readData())	maxAccount = -1;
	while (1)
	{
		printf("\n");
		printf("+ --------------------------------------------------------- +\n");
		printf("\n|                                                           |\n");
		printf("\n|         ���  ���밴1��         ����  ���밴2��           |\n");
		printf("\n|         ȡ��  ���밴3��         ����  ���밴4��           |\n");
		printf("\n|         ��ѯ  ���밴5��         �˳�  ���밴0��           |\n");
		printf("\n|                 ��ʾ�����˻���Ϣ���밴6��                 |\n");
		printf("\n|                                                           |\n");
		printf("\n+ --------------------------------------------------------- +\n");
		printf("����������ѡ��\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0: exit(0);
		case 1: deposit(); break;
		case 2:	openAccount(); break;
		case 3: withdraw(); break;
		case 4: closeAccount(); break;
		case 5: query(); break;
		case 6: queryall(); break;
		default: printf("��Чѡ���֧�ֵĶ�ܣ�\n"); break;
		}

	}
}

void dispAnAccount(int i)//��ʾָ��������飻
{
	printf("\n");
	printf("+-------+----------+--------+-------------+------+\n");
	printf("| %-5s | %-8s | %-6s | %-12s| %4s |\n", "�˻�", "����", "����", "���", "״̬");
	printf("+-------+----------+--------+-------------+------+\n");
	printf("| %5d | %-8s | %-6s | %12.2f| %4s |\n",
		rs[i].accNumber, rs[i].accName, "******"/*rs[i].accPWD*/, rs[i].balance,atoi(rs[i].flag) ? "����" : "����");
	printf("+-------+----------+--------+-------------+------+\n");
}

int creatAccNumber()//���̴�����ţ�
{
	if (maxAccount==-1)
	{
		return 10001;
	}
	else
	{
		return rs[maxAccount].accNumber + 1;
	}
}

void getaccName(char accName[])//�Ӽ��̻�ȡ�û�����
{
	printf("�����봢��������\n");
	scanf("%s",accName);
	while (1)
	{
		if (!checkInput(0,accName))
		{
			break;
		}
		printf("��������û������ȣ����������봢����������\n");
		scanf("%s",accName);
	}
}

void getaccPWD(char accPWD[])//�Ӽ��̻�ȡ���룻
{
	char ccaccPWD[100];
	int i = 1;
	while (i)
	{
		memset(ccaccPWD, 0, sizeof(ccaccPWD));
		printf("�����봢�����룺\n");
		scanf("%s", ccaccPWD);
		if (checkInput(1, ccaccPWD))
		{
			printf("����������볤�ȣ����������봢�����룡��\n");
			continue;
		}
		i = 0;
	}
	memcpy(accPWD, ccaccPWD, 7);
}

double getcash(int flag)//�Ӽ��̻�ȡ��
{
	char cash[100];
	double dcash = 0;
	int i=1;
	while (i)
	{
		memset(cash, 0, sizeof(cash));
		dcash = 0;
		switch (flag)
		{
		case 0: printf("���������\n"); break;
		case 1: printf("������ȡ���\n"); break;
		}
		scanf("%lf", &dcash);
		sprintf(cash, "%12.2f", dcash);
		if (checkInput(2,cash))
		{
			printf("��������\n");
			continue;
		}
		i = 0;
	}
	return dcash;
}

int checkInput(int flag,char *checkStr)//��������ʽ�Ƿ���ȷ��
{
	switch (flag)
	{
	case 0:if (strlen(checkStr) > 8) return 1; break;
	case 1:if (strlen(checkStr) > 6) return 1; break;
	case 2:if (strlen(checkStr) > 12) return 1; break;
	default:return 0;break;
	}
	return 0;
}

int getaccNumber(int flag)//�Ӽ��̻�ȡ�˻���ţ�
{
	int iaccNumber=0;
	printf("\n");
	switch (flag)
	{
	case 0: printf("������Ҫ�����ʺţ�"); break;
	case 1: printf("������Ҫȡ����ʺţ�"); break;
	case 2: printf("������Ҫ�������ʺţ�"); break;
	case 3: printf("������Ҫ��ѯ���ʺţ�"); break;
	}
	scanf("%d",&iaccNumber);
	return iaccNumber;
}

int  findAnAccount(int accNumber)//����ָ��λ�õ��˻���Ϣ��
{
	int weizhi = -1;
	int i;
	for ( i = 0; i <= maxAccount; i++)
	{
		if (rs[i].accNumber == accNumber)
		{
			weizhi = i;
			break;
		}
	}
	return weizhi;
}

int  writeData()//д���ļ�D�̸�Ŀ¼bank.txt��
{
	FILE *fp;
	int i;

	fp = fopen("D:\\bank.txt","w");
	if (fp==NULL)
	{
		return 1;
	}
	for ( i = 0; i <=maxAccount; i++)
	{
		fprintf(fp, "%-6d%-10s%-10s%12.2f%2s\n",  rs[i].accNumber,rs[i].accName,rs[i].accPWD,rs[i].balance,rs[i].flag);
	}
	fclose(fp);
	return 0;
}

int  readData()//��ȡ�ļ�D�̸�Ŀ¼bank.txt��
{
	FILE *fp;
	fp = fopen("D:\\bank.txt", "r");
	if (fp==NULL)
	{
		return 1;
	}
	int i = 0,ef;
	while (!feof(fp))
	{
		fscanf(fp, "%-6d%-10s%-10s%12.2f%2s\n", rs[i].accNumber,rs[i].accName, rs[i].accPWD, rs[i].balance, rs[i].flag);
		ef = fgetc(fp);
		if (ef==EOF)
		{
			break;
		}
		i++;
	}
	maxAccount = i - 1;
	fclose(fp);
	return 0;
}

void queryall()//��ʾ�����˻���Ϣ��
{
	int i;
	printf("\n");
	printf("+-------+----------+--------+-------------+------+\n");
	printf("| %-5s | %-8s | %-6s | %-12s| %4s |\n", "�˻�", "����", "����", "���", "״̬");
	for ( i = 0; i <=maxAccount; i++)
	{
		printf("+-------+----------+--------+-------------+------+\n");
		printf("| %5d | %-8s | %-6s | %12.2f| %4s |\n",
			rs[i].accNumber, rs[i].accName, "******"/*rs[i].accPWD*/, rs[i].balance, atoi(rs[i].flag) ? "����" : "����");
	}
	printf("+-------+----------+--------+-------------+------+\n");
	system("pause");
}

void  mypause()//��ͣ��
{
	printf("�����������...");
	fflush(stdin);
	getchar();
	return;
}