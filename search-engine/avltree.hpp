#ifndef AVLTREE_H
#define AVLTREE_H

#include <queue>

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

    template<class U> class AVLNode
    {
    private:
        U data;                 //contains data payload
        AVLNode<U> * left;      //points to left subtree
        AVLNode<U> * right;     //points to right subtree
        int height;             //indicates

    public:
        AVLNode(const U& inputData, AVLNode<U> * leftPtr = nullptr,
                AVLNode<U> * rightPtr = nullptr, int nodeHeight = 0)
                : data(inputData), left(leftPtr), right(rightPtr),
                height(nodeHeight) {}

        void updateHeight() {
            //set height to be the max height of both children + 1
        }
    };

    AVLNode<T> * root;

    //finds the maximum value in tree rooted at arg
    //finds the minimum value in tree rooted at arg
    //gets height of tree rooted at arg
    //inserts to tree rooted at arg
    //searches in tree rooted at arg
    //determines if arg is an element of tree rooted at arg
    //clears tree rooted at arg
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
    //finds the maximum value
    //finds the minimum value
};




//==============================
//CONSTRUCTORS AND RULE OF THREE
//==============================

/*
 * perform breadth-first traversal of input tree, inserting each element to this tree
 */
//copy constructor
    //create a queue of node pointers
    //while queue not empty
        //pop to temp from queue
        //insert value popped to this tree
        //if left child not null, push to queue
        //if right child not null, push to queue


/*
 * perform breadth-first traversal of input tree, inserting each element to this tree
 */
//overloaded assignment op
    //check to see that input is a different object
    //performs copy constructor logic
    //returns reference to this


//destructor
    //call clear function


//===================
//GETTERS AND SETTERS
//===================

//returns max value
    //call private max function with root pointer


//returns max value of tree rooted at arg
    //if right pointer is null, return this value
    //else recursive call with right pointer


//returns min value
    //call private min function with root pointer


//returns min value of tree rooted at arg
    //if left pointer is null, return this value
    //else recursive call with left pointer


//determines if tree is empty
    //returns true iff root is null


//clears the tree
    //calls private clear all function with root pointer
    //delete root

/*
 * Traverses tree, deleting each element as its recursive call is popped
 */
//clears tree rooted at arg
    //if left not null, call recursively with left, then delete left
    //if right not null, call recursively with left, then delete right



//=========
//SEARCHING
//=========

//determines if arg is an element
    //return value of private function, passing root pointer


//determines if arg is an element of tree rooted at arg
    //if this value is target, return true
    //else, if target value less than this
        //if left not null, call with left
        //if left is null, return false
    //else, if target value greater than this
        //if right not null, call with right
        //if right is null, return false


//searches for and returns arg
    //return value of private function, passing root pointer


//searches for and returns arg in tree rooted at arg
    //if value is target, return reference to value
    //else, if target value less than this
        //if left not null, call with left
        //if left is null, return SOME FLAG VALUE

    //else, if target value greater than this
        //if right not null, call with right
        //if right is null, return SOME FLAG VALUE


//=========
//INSERTING
//=========


//inserts arg
    //call private function with root pointer


//inserts arg to tree rooted at arg
    //if node equal to value, append data to this element
    //if value greater than node
        //if right node not null, call recursively with right pointer
        //else if right node null, make new node, assign right to new
        //FIGURE OUT INSERTION LOGIC

    //if value greater than node
        //if left node not null, call recursively with left pointer
        //else if left node null, make new node, assign left to new
        //FIGURE OUT INSERTION LOGIC



//========
//ROTATING
//========

//case 1 rotation


//case 4 rotation


//case 2 rotation


//case 3 rotation


#endif // AVLTREE_H
