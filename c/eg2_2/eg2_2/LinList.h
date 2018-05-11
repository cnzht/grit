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

void ListInitiate(SLNODE ** head);//链表初始化；
int ListLength(SLNODE *head);//返回链表长度；
int ListInsert(SLNODE *head, int i, DataType x);//在某个位置i处插入数据；
int ListDelete(SLNODE *head, int i, DataType *x);//删除i处的数据；
int ListGet(SLNODE *head, int i, DataType *x);//获取某个位置i处的数据；
void DeleteList(SLNODE **head);//清空链表；

void LinListInsert(SLNODE *head,DataType x);//单链表插入；
void LinListSort(SLNODE *head);//单链表排序；
#endif