#ifndef SEQLIST_H
#define SEQLIST_H
#define MAX_SIZE 100

typedef int DATATYPE;
typedef struct 
{
	DATATYPE list[MAX_SIZE];
	int size;
}Seqlist;

void Listinit(Seqlist *L);//结构体初始化；
DATATYPE Listlength(Seqlist L);//求当前元素个数函数；
DATATYPE Listinsert(Seqlist *L ,int i, DATATYPE x);//在原数组位置i前插入x函数；
DATATYPE Listget(Seqlist L, int i, DATATYPE *x);//取数组中第i个位置数据的函数；
DATATYPE dele(Seqlist *L, int i, DATATYPE *x);//删除数组中第i个位置的数据函数；

#endif