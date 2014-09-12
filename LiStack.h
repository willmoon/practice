#include <cstdlib>
#include <iostream>

using namespace std;

typedef char ElemType;

typedef struct linkNode
{
    ElemType data;
    struct linkNode *next;
} NodeType;

class LiStack
{
private:
    NodeType *head;
public:
    LiStack()
    {
        head = (NodeType *) malloc(sizeof(LiStack));
        head ->next = NULL;
    }

    ~LiStack()
    {
        NodeType *p = head ->next;
        while (p)
        {
            free(head);
            head = p;
            p = p ->next;
        }
    }

    int StackLength()
    {
        int i = 0;
        NodeType *p = head ->next;
        while (p != NULL)
        {
            i ++;
            p = p ->next;
        }
        return i;
    }

    int StackEmpty()
    {
        return (head ->next == NULL);
    }

    void Push(ElemType e)
    {
        NodeType *p = NULL;
        p = (NodeType *)malloc(sizeof(NodeType));
        p ->data = e;
        p ->next = head ->next;
        head ->next = p;
    }

    int Pop(ElemType& e)
    {
    	NodeType* p;
    	if (head ->next == NULL)
    	{
    		return 0;
    	}
    	p = head ->next;
    	head ->next = p ->next;
    	e = p ->data;
    	free(p);
    	return 1;
    }

    int GetTop(ElemType& e)
    {
    	if (head ->next == NULL)
    	{
    		return 0;
    	}
    	e = head ->next ->data;
    	return 1;
    }

    void DisPlayStack()
    {
    	NodeType* p = head ->next;
    	while(p!=NULL) 
    	{
    	    cout << p ->data << " ";
    	    p = p ->next;
    	}

    	cout << endl;
    }

};

