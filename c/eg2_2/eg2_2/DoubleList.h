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

void ListInitiate(DLNode ** head);//链表初始化；
int ListLength(DLNode *head);//返回链表长度；
int ListInsert(DLNode *head, int i, DataType x);//在某个位置i处插入数据；
int ListDelete(DLNode *head, int i, DataType *x);//删除i处的数据；
int ListGet(DLNode *head, int i, DataType *x);//获取某个位置i处的数据；
void DeleteList(DLNode **head);//清空链表；

//自定义
int ListDataDelete(DLNode *head, DataType x);//删除指定数字；

#endif