#define _CRT_SECURE_NO_WARNINGS
#ifndef LINLIST_H
#define LINLIST_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node * next;
}SLNODE;

void ListInitiate(SLNODE ** head);//�����ʼ����
int ListLength(SLNODE *head);//���������ȣ�
int ListInsert(SLNODE *head, int i, DataType x);//��ĳ��λ��i���������ݣ�
int ListDelete(SLNODE *head, int i, DataType *x);//ɾ��i�������ݣ�
int ListGet(SLNODE *head, int i, DataType *x);//��ȡĳ��λ��i�������ݣ�
void DeleteList(SLNODE **head);//�������

void LinListInsert(SLNODE *head,DataType x);//��������룻
void LinListSort(SLNODE *head);//����������
#endif