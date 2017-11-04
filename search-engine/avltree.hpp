#ifndef AVLTREE_H
#define AVLTREE_H

#include "indexinterface.hpp"

template <class T>
class AVLTree : public IndexInterface<T>
{
private:
    template<class T>
    class AVLNode
    {
    private:
        T data;
        AVLNode<T> * left;
        AVLNode<T> * right;
        int height;

    public:
        AVLNode(const T& inputData, AVLNode * leftPtr = nullptr,
                AVLNode * rightPtr = nullptr, int nodeHeight = 0)
                : data(inputData), left(leftPtr), right(rightPtr),
                height(nodeHeight) {}
    };

    AVLNode<T> * root;


public:
    AVLTree();
};

#endif // AVLTREE_H
