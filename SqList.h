#include <cstdlib>
#include <iostream>

using namespace std;

typedef char ElemType;
const int MaxSize = 50;

class SqList
{
private:
    ElemType *pElem;
    int length;
public:
    SqList()
    {
        pElem  = (ElemType *)malloc(MaxSize);
        length = 0;
    }

    ~SqList()
    {
        free(pElem);
    }

    int ListEmpty()
    {
        return (length == 0);
    }

    int ListLength()
    {
        return length;
    }

    void DisPlayList()
    {
        if (ListEmpty())
        {
            cout << "EMPTY...";
        }
        for (int i = 0; i < length; ++i)
        {
            cout << *(pElem + i) << " ";
        }
        cout << endl;
    }

    int GetElem(int i, ElemType &e)
    {
        if (i < 1 || i > length)
        {
            return 0;
        }
        e = pElem[i - 1];
        return 1;
    }

    int LocateElem(ElemType e)
    {
        int i = 0;
        while (i < length && *(pElem + i) != e)
            i ++;
        if (i >= length)
        {
            return 0;
        }
        return i + 1;
    }

    int Insert(int i, ElemType e)
    {
        if (i < 1 || i > length + 1)
        {
            return 0;
        }

        for (int k = length; k > i - 1; k --)
        {
            *(pElem + k) = *(pElem + k - 1);
        }

        *(pElem + i - 1) = e;
        length ++;
        return 1;
    }

    int ListDelete(int i, ElemType &e)
    {
        if (i < 1 || i > length)
        {
        	cout << "out of range..." << endl;
            return 0;
        }

        e = *(pElem + i - 1);
        for (int k = i - 1; k < length; ++k)
        {
            *(pElem + k) = *(pElem + k + 1);
        }

        length --;
        return 1;
    }
};