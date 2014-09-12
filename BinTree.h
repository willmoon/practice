#include <cstdlib>
#include <iostream>

using namespace std;
const int MaxSize = 100;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *LChild;
    struct node *RChild;
} BTNode;

class BinTree
{
private:
    BTNode *root;

private:
    void DelTree(BTNode *p)
    {
        if (p != NULL)
        {
            DelTree(p ->LChild);
            DelTree(p ->RChild);
            free(p);
        }
    }
public:
    BinTree(const char *str)
    {
        BTNode *tempStack[MaxSize];
        BTNode *p = NULL;
        int top = -1;
        int k   = 0;
        int j   = 0;
        char ch = str[j];
        root = NULL;
        while (ch != '\0')
        {
            switch (ch)
            {
            case '(':
                top ++;
                tempStack[top] = p;
                k = 1;
                break;

            case ')':
                top --;
                break;

            case ',':
                k = 2;
                break;

            default :
                p = (BTNode *)malloc(sizeof(BTNode));
                p ->data = ch;
                p ->LChild = p ->RChild = NULL;
                if (root == NULL)
                {
                    root = p;
                }
                else
                {
                    switch (k)
                    {
                    case 1:
                        tempStack[top] ->LChild = p;
                        break;
                    case 2:
                        tempStack[top] ->RChild = p;
                        break;
                    }
                }
            }

            j ++;
            ch = str[j];
        }
    }

    ~BinTree()
    {
        if (root != NULL)
        {
            DelTree(root);
        }
    }

    BTNode *Getroot()
    {
        return (root);
    }

    BTNode *FindNode(BTNode *p, ElemType x)
    {
        BTNode *q;
        if (p == NULL)
        {
            return NULL;
        }
        else if (p ->data == x)
        {
            return p;
        }
        else
        {
            q = FindNode(p ->LChild, x);

            if (q != NULL)
            {
                return q;
            }
            else
            {
                return FindNode(q ->RChild, x);
            }
        }
    }

    int BinTreeDepth(BTNode *p)
    {
        int LChildDep = 0;
        int RChildDep = 0;

        if (p == NULL)
        {
            return 0;
        }
        else
        {
            LChildDep = BinTreeDepth(p -> LChild);
            RChildDep = BinTreeDepth(p -> RChild);
            return (LChildDep > RChildDep) ? (LChildDep + 1) : (RChildDep + 1);
        }
    }

    void DispBTNode(BTNode *p)
    {
        if (p != NULL)
        {
            cout << p ->data;
            if (p -> LChild != NULL || p ->RChild != NULL)
            {
                cout << "(";
                DispBTNode(p ->LChild);
                if (p -> RChild != NULL)
                {
                    cout << ",";
                }
                DispBTNode(p ->RChild);
                cout << ")";
            }
        }
    }


    void PreOrder(BTNode *p)
    {
        if (p != NULL)
        {
            cout << p ->data;
            PreOrder(p ->LChild);
            PreOrder(p ->RChild);
        }
    }

    void InOrder(BTNode *p)
    {
    	if (p != NULL)
    	{
    		InOrder(p ->LChild);
    		cout << p ->data;
    		InOrder(p ->RChild);
    	}
    }

    void PostOrder(BTNode *p)
    {
    	if (p != NULL)
    	{
    		PostOrder(p ->LChild);
    		PostOrder(p ->RChild);
    		cout << p ->data;
    	}
    }
};