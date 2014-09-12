#include "SqList.h"

int main(int argc, char const *argv[])
{
	ElemType e;
	int i;
	SqList sList;

	sList.Insert(1,'a');
	sList.Insert(2,'b');
	sList.Insert(3,'c');
	sList.Insert(4,'d');
	sList.DisPlayList();
	sList.GetElem(2,e);
	cout << "第二个节点的值：" << e << endl;
	cout << "删除第二个节点：" << endl;
	sList.ListDelete(2,e);
	sList.DisPlayList();
	cout << "插入e作为第一个结点：" << endl;
	sList.Insert(1,'e');
	sList.DisPlayList();

	return 0;
}