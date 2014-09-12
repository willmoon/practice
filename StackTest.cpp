#include "LiStack.h"

int main(int argc, char const *argv[])
{
	ElemType e;
	LiStack s;

	s.Push('a');
	s.Push('b');
	s.Push('c');
	s.Push('d');

	s.GetTop(e);
	cout << "栈顶元素：" << e << endl;

	while(!s.StackEmpty()) 
	{
	    s.Pop(e);
	    cout << e << " ";
	}
	cout << endl;
	return 0;
}