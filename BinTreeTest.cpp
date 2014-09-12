#include "BinTree.h"

int main(int argc, char const *argv[])
{
    BTNode *p;
    BinTree b("A(B(D(,G),C(E,F))");

    cout << "二叉树：" << endl;
    b.DispBTNode(b.Getroot());
    cout << endl;

    cout << "二叉树的深度：" << b.BinTreeDepth(b.Getroot());
    cout << endl;
    cout << "二叉树先序遍历：" ;
    b.PreOrder(b.Getroot());
    cout << endl;
    cout << "二叉树中序遍历：" ;
    b.InOrder(b.Getroot());
    cout << endl;
    cout << "二叉树后序遍历：" ;
    b.PostOrder(b.Getroot());
    cout << endl;

    return 0;
}