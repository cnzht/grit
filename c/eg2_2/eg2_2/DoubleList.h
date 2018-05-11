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
	DataType size;
	struct  Node *prior;
	struct Node * next;
}DLNode;

void ListInitiate(DLNode ** head);//�����ʼ����
int ListLength(DLNode *head);//���������ȣ�
int ListInsert(DLNode *head, int i, DataType x);//��ĳ��λ��i���������ݣ�
int ListDelete(DLNode *head, int i, DataType *x);//ɾ��i�������ݣ�
int ListGet(DLNode *head, int i, DataType *x);//��ȡĳ��λ��i�������ݣ�
void DeleteList(DLNode **head);//�������

//�Զ���
int ListDataDelete(DLNode *head, DataType x);//ɾ��ָ�����֣�

#endif