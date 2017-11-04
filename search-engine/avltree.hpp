#ifndef AVLTREE_H
#define AVLTREE_H

#include "indexinterface.hpp"

/*
 * Implements an ordered index as a self-balancing AVL binary tree.
 *
 * Assumes that underlying data type has sensibly overloaded operator+
 * and operator==.
 */

template <class T> class AVLTree : public IndexInterface<T>
{
private:

    template<class T> class AVLNode
    {
    private:
        T data;
        AVLNode<T> * left;
        AVLNode<T> * right;
        int height;

    public:
        AVLNode(const T& inputData, AVLNode<T> * leftPtr = nullptr,
                AVLNode<T> * rightPtr = nullptr, int nodeHeight = 0)
                : data(inputData), left(leftPtr), right(rightPtr),
                height(nodeHeight) {}
    };

    AVLNode<T> * root;

    //finds the maximum value in tree rooted at arg
    //finds the minimum value in tree rooted at arg
    //gets height of tree rooted at arg
    //inserts to tree rooted at arg
    //removes values matching arg from tree rooted at arg
    //case 1 rotation
    //case 4 rotation
    //case 2 rotation
    //case 3 rotation


public:
    AVLTree();
    //copy constructor
    //overloaded assignment op
    //destructor
    //determines if arg is an element
    //searches for and returns arg
    //inserts arg
    //determines if tree is empty
    //clears the tree
    //removes element matching value of arg
    //finds the maximum value
    //finds the minimum value
};




//==============================
//CONSTRUCTORS AND RULE OF THREE
//==============================


//copy constructor


//overloaded assignment op


//destructor


//===================
//GETTERS AND SETTERS
//===================

//returns max value


//returns max value of tree rooted at arg


//returns min value


//returns min value of tree rooted at arg


//determines if tree is empty


//clears the tree



//=========
//SEARCHING
//=========

//determines if arg is an element


//searches for and returns arg




//=========
//INSERTING
//=========


//inserts arg


//inserts arg to tree rooted at arg



//========
//DELETING
//========


//removes element matching value of arg


//removes element matching value of arg from tree rooted at arg



//========
//ROTATING
//========

//case 1 rotation


//case 4 rotation


//case 2 rotation


//case 3 rotation

#endif // AVLTREE_H
