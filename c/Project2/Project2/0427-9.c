#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main()
{
	FILE *fp;
	int i = 42;
	char ch;
	fp = fopen("d:\\file.txt", "w+");
	if (fp==NULL)
	{
		printf("�򿪴���������룡\n");
		getchar();
		exit(1);
	}
	else
	{
		fprintf(fp, "%s\n", "xxxxxxxxxxxxxxx��");
		fputs("****************\n",fp);
		
		fputc("\n*\n",fp);
		fclose(fp);
	}
	while ((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	system("pause");
	return 0;
}
*/
int main()
{
	FILE *fr, *fw;
	int a=520;
	float b;
	char ch;
	char *s = "student zhou!";

	fr = fopen("d:\\file.txt", "w+");
	fw = fopen("d:\\file2.txt", "w+");
	if (fr==NULL||fw==NULL)
	{
		printf("ERROR!");
		exit(1);
	}
	//д�����ݵ�file1.txt
	fprintf(fr, "%s", s);
	fputc(':\n',fr);
	fprintf(fr, "%d\n", a);
	fputs("********************************\n", fr);
	//��ȡ�ļ�file1.txt��file2.txt
	rewind(fr);
	ch = fgetc(fr);
	while (ch!=EOF)
	{
		fputc(ch, fw);
		ch = fgetc(fr);
	}
	fputs("\n��Դ��file1.txt\n", fw);

	//���³�������ʾ����

	fseek(fr, 15, SEEK_SET);
	for (int i = 0; i < 3; i++)
	{
		ch = fgetc(fr);
		putchar(ch);
	}
	printf("\n");
	fclose(fr);
	fclose(fw);
	system("pause");
	return 0;
}