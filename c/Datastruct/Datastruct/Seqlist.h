#ifndef SEQLIST_H
#define SEQLIST_H
#define MAX_SIZE 100

typedef int DATATYPE;
typedef struct 
{
	DATATYPE list[MAX_SIZE];
	int size;
}Seqlist;

void Listinit(Seqlist *L);//�ṹ���ʼ����
DATATYPE Listlength(Seqlist L);//��ǰԪ�ظ���������
DATATYPE Listinsert(Seqlist *L ,int i, DATATYPE x);//��ԭ����λ��iǰ����x������
DATATYPE Listget(Seqlist L, int i, DATATYPE *x);//ȡ�����е�i��λ�����ݵĺ�����
DATATYPE dele(Seqlist *L, int i, DATATYPE *x);//ɾ�������е�i��λ�õ����ݺ�����

#endif