#include "lead.h"

/*void openAccount()//�������ڽṹ������������һ�������Ա����һ����������Ϣ��
{
	int accNumber;//�˺�
	char accName[9];//�˻���
	char accPWD[7];//�˻�����
	double cash;//�ֽ����
	//��ʼ��
	accNumber = 0;
	memset(accName, 0, sizeof(accName));
	memset(accPWD, 0, sizeof(accPWD));
	cash = 0;
	accNumber = creatAccNumber();
	getaccName(accName);
	getaccPWD(accPWD);
	//getaccNumber(accNumber);
	cash = getcash(0);

	maxAccount++;

	//����ֵ��ֵ���ṹ��������
	rs[maxAccount].accNumber = accNumber;
	strcpy(rs[maxAccount].accName, accName);
	strcpy(rs[maxAccount].accPWD, accPWD);
	rs[maxAccount].balance = cash;
	strcpy(rs[maxAccount].flag, "0");
	//ÿ��һ��������ʱ��������
	if (writeData())
	{
		printf("д�ļ�����");
		return;
	}
	dispAnAccount(maxAccount);
	printf("�����ɹ����󼪴������ϳԼ���\n");
	getchar();
}

void deposit()//���������ӵ����˻�������ϣ�
{
	int	accNumber = 0;
	int weizhi = -1;
	double cash = 0;
	accNumber = getaccNumber(0);
	weizhi = findAnAccount(accNumber);
	if (weizhi==-1)
	{
		printf("���޴��˻��������������...\n");
		getchar();
		return;
	}
	dispAnAccount(weizhi);
	if (strcmp(rs[weizhi].flag,"0")!=0)
	{
		printf("���˻��Ѿ����������ܴ������������...\n");
		getchar();
		return;
	}
	cash = getcash(0);
	rs[weizhi].balance += cash;

	if (writeData())
	{
		printf("д�ļ�����");
		return;
	}

	dispAnAccount(weizhi);
	printf("���ɹ�����������������˵�...\n");
	getchar();
}
void withdraw()//ȡ��Ӹ��˻�������Ͽ۳�ȡ���
{
	;
}
void query()//��ѯ����ѯĳ�˻���Ϣ��
{
	;
}

void closeAccount()//�����������˻����˻�״̬��Ϊ1���˻������Ϊ0��
{
	;
}*/
//dxj,2013-9-2
//��bankServe.h��Ӧ��ʵ���ļ�
void openAccount()//����
{
	int accNumber;       // �˺�
	char accName[9];   // ����
	char accPWD[7];    // ����
	double  cash;     // ������
	accNumber = 0;
	memset(accName, 0, sizeof(accName));
	memset(accPWD, 0, sizeof(accPWD));
	cash = 0;
	accNumber = creatAccNumber();
	getaccName(accName);
	getaccPWD(accPWD);
	cash = getcash(0);

	maxAccount++;      //�ʻ�������

	rs[maxAccount].accNumber = accNumber;
	strcpy(rs[maxAccount].accName, accName);
	strcpy(rs[maxAccount].accPWD, accPWD);
	rs[maxAccount].balance = cash;
	strcpy(rs[maxAccount].flag, "0");
	//ÿ��һ��������ʱ��������
	if (writeData())
	{
		printf("д�ļ�����");
		return;
	}
	dispAnAccount(maxAccount);  //��ʾ�ʻ���Ϣ
	printf("�����ɹ�����������������˵�...\n");
	getchar();
	getchar();
}

void deposit()   //���
{
	int accNumber = 0;
	int accountPosition = -1; //�ʻ��������е�λ��
	double cash = 0;         //������

	accNumber = getaccNumber(0);//��ȡ�ʺ�
	//���Ҹ��ʻ�
	accountPosition = findAnAccount(accNumber);
	if (accountPosition == -1)
	{
		printf("���޴��ʻ��������������...");
		getchar();
		return;
	}//endif

	//��ʾ�ʻ���Ϣ
	dispAnAccount(accountPosition);
	if (strcmp(rs[accountPosition].flag, "0") != 0)
	{
		printf("���ʻ��Ѿ����������ܴ������������...");
		getchar();
		return;
	}

	//�õ������
	cash = getcash(0);
	rs[accountPosition].balance += cash;
	//��������
	if (writeData())
	{
		printf("д�ļ�����");
		return;
	}
	dispAnAccount(accountPosition);
	printf("���ɹ�����������������˵�...");
	getchar();
	getchar();
}//enddeposit()

void withdraw()  //ȡ��
{
	int accNumber, i;
	char accPWD[7];    // ȡ��ʱ��Ҫ��֤����
	int accountPosition;//�ʻ��������е�λ��
	double cash;//ȡ����
	//��ʼ��
	accNumber = 0;
	accountPosition = -1;
	cash = 0;
	accNumber = getaccNumber(1);//"1"Ϊ��ȡȡ���ʺ�
	//���Ҹ��ʻ�
	accountPosition = findAnAccount(accNumber);
	if (accountPosition == -1)
	{
		printf("���޴��ʻ��������������...\n");
		getchar();
		getchar();
		return;
	}//endif

	for (i = 0; i<3; i++)//�������λ��������û�����
	{
		getaccPWD(accPWD);
		//��֤����
		if (strcmp(rs[accountPosition].accPWD, accPWD) == 0)
			break;//������ȷ���˳���֤
		else{
			if (i<2) printf("���벻��ȷ�����������룡");
			else {
				printf("���벻��ȷ�������������...\n");
				getchar();
				return;
			}
		}//endelse
	}//endfor

	if (strcmp(rs[accountPosition].flag, "0") != 0)
	{
		printf("���ʻ��Ѿ�����������ȡ������������...");
		getchar();
		return;
	}
	dispAnAccount(accountPosition);//��ʾ�ʻ���Ϣ

	cash = getcash(1);//"1"Ϊ�õ�ȡ����
	if (cash>rs[accountPosition].balance)
	{
		printf("ȡ������ʻ�������͸֧!�����������...\n");
		getchar();
		getchar();
		return;
	}
	rs[accountPosition].balance = rs[accountPosition].balance - cash;

	//��������
	if (writeData())
	{
		printf("д�ļ�����");
		return;
	}
	dispAnAccount(accountPosition);
	printf("ȡ��ɹ�����������������˵�...");

	getchar();
	getchar();
}


void query()    //��ѯ
{
	int choice, i;
	int accNumber;
	char accPWD[7];
	char accName[9];   // ����
	int accountPosition;//�ʻ��������е�λ��

	//��ʼ������
	accNumber = 0;
	memset(accName, 0, sizeof(accName));//�����ʼ��
	memset(accPWD, 0, sizeof(accPWD));
	accountPosition = -1;
	printf("\n");
	printf("+--------------------------+\n");
	printf("|    ���ʺŲ�ѯ  �밴1     |\n");
	printf("|    ��������ѯ  �밴2     |\n");
	printf("+--------------------------+\n");
	printf("����������ѡ��");
	scanf("%d", &choice);
	if (choice == 1)
	{
		accNumber = getaccNumber(3);//"3"Ϊ��ȡ��ѯ�ʺ�
		accountPosition = findAnAccount(accNumber);
		if (accountPosition == -1)
		{
			printf("���޴��ʻ��������������...");
			fflush(stdin);
			getchar();
			return;
		}
		getaccPWD(accPWD);
		if (strcmp(rs[accountPosition].accPWD, accPWD) != 0)
		{
			printf("�������! �����������...");
			fflush(stdin);
			getchar();
			return;
		}


		dispAnAccount(accountPosition);
	}
	else if (choice == 2)
	{
		getaccName(accName);
		for (i = 0; i <= maxAccount; i++)
		{
			if (strcmp(rs[i].accName, accName) == 0)
			{
				accountPosition = i;
				break;
			}
		}
		if (accountPosition == -1)
		{
			printf("���޴˴������������������...");
			fflush(stdin);
			getchar();
			return;
		}

		getaccPWD(accPWD);
		if (strcmp(rs[accountPosition].accPWD, accPWD) != 0)
		{
			printf("�������! �����������...");
			fflush(stdin);
			getchar();
			return;
		}
		dispAnAccount(accountPosition);
	}
	else printf("��Чѡ��");
}

void closeAccount()//����
{
	char userAnswer;
	int i = 0, accNumber = 0;
	char accPWD[7];
	double balance;
	int accountPosition;  //�ʻ��������е�λ��
	memset(accPWD, 0, sizeof(accPWD));
	accountPosition = -1;
	accNumber = getaccNumber(2); //����"2"Ϊ��ȡ�����ʺ�
	accountPosition = findAnAccount(accNumber);
	if (accountPosition == -1)
	{
		printf("���޴��ʻ���");
		mypause();
		return;
	}
	while (i<3)
	{
		getaccPWD(accPWD);
		i++;
		if (!strcmp(rs[accountPosition].accPWD, accPWD)) break;
		printf("�������! ");
	}
	if (i == 3)
	{
		printf("\n3�������������! ����ϵͳ���˵�...");
		return;
	}

	dispAnAccount(accountPosition);
	if (strcmp(rs[accountPosition].flag, "0") != 0)
	{
		printf("���ʻ��Ѿ������������ظ�����! ");
		mypause();
		return;
	}
	printf("ȷ�Ͻ��ʻ�%d������[y������nȡ��]", rs[accountPosition].accNumber);
	fflush(stdin);
	scanf("%c", &userAnswer);
	if (userAnswer == 'y' || userAnswer == 'Y')
	{
		balance = rs[accountPosition].balance;
		printf("���ʻ��������:%8.2f,��ȷ��ȡ����\n", balance);
		printf("�����������...");
		fflush(stdin);
		getchar();
		rs[accountPosition].balance = 0;
		strcpy(rs[accountPosition].flag, "1");
		if (writeData()) //��������
		{
			printf("д�ļ�����");
			return;
		}
		dispAnAccount(accountPosition);
		printf("�����ɹ�! ");
		mypause();
		return;
	}
	else if (userAnswer == 'n' || userAnswer == 'N')
	{
		printf("ȡ������! ");
		mypause();
		return;
	}
	else  printf("��Чѡ��");
	mypause();
}
