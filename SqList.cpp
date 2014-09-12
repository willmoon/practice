#include <iostream>
#include <cstdlib>
#include "SqList_functions.cpp"
using namespace std;

// const int MaxSize = 50;
typedef char ElemType;
// typedef struct 
// {
// 	ElemType data[MaxSize];
// 	int length;
// }SqList;

// extern void InitList(SqList* &L);

int main(int argc, char const *argv[])
{
	SqList* L;
	ElemType e;
	cout << "(1)初始化顺序表" << endl;
	InitList(L);
	return 0;
}