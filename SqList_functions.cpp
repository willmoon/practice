#include <iostream>
#include <cstdlib>
using namespace std;

const int MaxSize = 50;

typedef char EleType;
typedef struct 
{
	EleType data[MaxSize];
	int length;
}SqList;

void InitList(SqList* &L)
{
	L = (SqList* )malloc(sizeof(SqList));
	L ->length = 0;
}

void DestroyList(SqList* L)
{
	free(L);
}

bool ListEmpty(SqList* L)
{
	return(L->length == 0);
}

int ListLength(SqList* L)
{
	return(L->length);
}

void DisplayList(SqList* L)
{
	if (ListEmpty(L))
	{
		return;
	}

	for (int i = 0; i < L->length; ++i)
	{
		cout << L->data[i];
	}
	cout << endl;
}

int GetElement(SqList* L,int i,EleType& e)
{
	if (i < 1 || i > L->length)
	{
		return 0;
	}
	e = L ->data[i];
	return 1;
}

int LocateElement(SqList* L,EleType e)
{
	int i = 0;
	while(i < L ->length && L ->data[i] !=e)
		i++;
	if (i >= L ->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

int ListDelete(SqList* L,int i,EleType &e)
{
	if (i < 1 || i > L->length)
	{
		return 0;
	}

	e = L ->data[i -1];
	for (int k = i; k < L ->length; k ++)
	{
		L ->data[k - 1] = L ->data[k];
	}
	L ->length --;
	return 1;
}

int ListInsert(SqList* L,int i,EleType e)
{
	if (i < 1 || i > L->length + 1)
	{
		return 0;
	}
	for (int k = L ->length; k >= i; k --)
	{
		L ->data[k] = L->data[k - 1];
	} 
	L ->data[i -1] = e;
	L ->length ++;
	return 1;
}


