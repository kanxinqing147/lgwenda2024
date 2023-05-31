#ifndef _SQLIST_H_
#define _SQLIST_H_

#define MaxSize 50
#define ElemType int

typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

extern bool ListInsert(SqList &L, int i, ElemType e);
extern bool ListDelete(SqList &L, int i, ElemType &e);
extern int LocateElem(SqList L, ElemType e);
extern void PrintList(SqList L);

#endif
