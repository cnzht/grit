//dxj,2014-9-2,
//���ڷ����Ժ�����˵����ͷ�ļ�
#ifndef BANKSERVE_H //������������ָ�ͷ�ļ��İ�ȫ��֤
#define BANKSERVE_H
void welcome();
void mainmenu();
int  findAnAccount();
void dispAnAccount();
int  creatAccNumber();
int  readData();
int  writeData();
int  checkInput(int flag, char *checkStr);
//���¼����û��������롢�������ʽ�Ƿ�Ϸ�
void queryall();  //��ʾ�����ʻ�
void getaccName(char accName[]); //�õ�����¼��Ļ���
void getaccPWD(char accPWD[]);   //�õ�����¼�������
double getcash(); //�õ�����¼��Ľ��
int getaccNumber(int flag);      //�õ�����¼����ʺ�
int  readData();
int  writeData();
void  mypause();
#endif