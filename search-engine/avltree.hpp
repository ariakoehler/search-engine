#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <queue>
#include <list>
#include <string>

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
                AVLNode<U> * rightPtr = nullptr, int nodeHeight = 1)
                : data(inputData), left(leftPtr), right(rightPtr),
                height(nodeHeight) {}

        void updateHeight() {
            //set height to be the max height of both children + 1
            height = std::max(getHeight(left), getHeight(right)) + 1;
        }
        int getHeight(const AVLNode<T> * arg) const {
            //returns 0 if pointer is null, its height if not
            if(arg == nullptr)
                return 0;
            else
                return arg->height;
        }

        friend class AVLTree;
    };

    AVLNode<T> * root;

    T& findMax(AVLNode<T>*&); //finds the maximum value in tree rooted at arg
    T& findMin(AVLNode<T>*&); //finds the minimum value in tree rooted at arg
    //gets height of tree rooted at arg
    void insert(const T &, AVLNode<T> *&); //inserts to tree rooted at arg
    //searches in tree rooted at arg
    //determines if arg is an element of tree rooted at arg
    void clear(AVLNode<T>*&); //clears tree rooted at arg
    //get balance of node
    //rebalance node
    std::ostream& print(std::ostream&, AVLNode<T> *) const;//print tree rooted at arg
    //case 1 rotation
    //case 4 rotation
    //case 2 rotation
    //case 3 rotation


public:
    AVLTree();
    AVLTree(const AVLTree<T>&); //copy constructor
    AVLTree<T>& operator =(const AVLTree<T>&); //overloaded assignment op
    ~AVLTree(); //destructor
    bool contains(const T &) const; //determines if arg is an element
    T& search(const T &); //searches for and returns arg
    void insert(const T &); //inserts arg
    bool isEmpty() const; //determines if tree is empty
    void makeEmpty(); //clears the tree
    T& findMax(); //finds the maximum value
    T& findMin();//finds the minimum value
    //stream insertion operator
    template <class U>
    friend std::ostream& operator <<(std::ostream&, const AVLTree<U>&);
};




//==============================
//CONSTRUCTORS AND RULE OF THREE
//==============================

template<class T>
AVLTree<T>::AVLTree() : root(nullptr) { }

/*
 * Copy constructor performs breadth-first traversal of
 * input tree, inserting each element to this tree
 */
template<class T>
AVLTree<T>::AVLTree(const AVLTree<T>& rhs) {
    //create a queue of node pointers
    //while queue not empty
        //pop to temp from queue
        //insert value popped to this tree
        //if left child not null, push to queue
        //if right child not null, push to queue
}


/*
 * Overloaded assignment op performs breadth-first traversal of
 * input tree, inserting each element to this tree
 */
template<class T>
AVLTree<T>& AVLTree<T>::operator =(const AVLTree<T>& rhs) {
    //check to see that input is a different object
    //performs copy constructor logic
    //returns reference to this
}


//destructor clears all obects from the tree
template<class T>
AVLTree<T>::~AVLTree() {
    //call clear function with root
    clear(root);
}



//===================
//GETTERS AND SETTERS
//===================

//returns max value
template<class T>
T& AVLTree<T>::findMax() {
    //call private max function with root pointer
    return findMax(root);
}


//returns max value of tree rooted at arg
template<class T>
T& AVLTree<T>::findMax(AVLNode<T> *& current) {
    //if right pointer is null, return this value
    if(current->right == nullptr)
        return current->data;

    //else recursive call with right pointer
    else
        return findMax(current->right);
}


//returns min value
template<class T>
T& AVLTree<T>::findMin() {
    //call private min function with root pointer
    return(findMin(root));
}


//returns min value of tree rooted at arg
template<class T>
T& AVLTree<T>::findMin(AVLNode<T> *& current) {
    //if left pointer is null, return this value
    if(current->left == nullptr)
        return current->data;

    //else recursive call with left pointer
    else
        return findMin(current->left);
}


//determines if tree is empty
template<class T>
bool AVLTree<T>::isEmpty() const {
    //returns true iff root is null
    return root == nullptr;
}


//clears the tree
template<class T>
void AVLTree<T>::makeEmpty() {
    //calls private clear all function with root pointer
    clear(root);
}

/*
 * Traverses tree, deleting each element as its recursive call is popped
 */
//clears tree rooted at arg
template<class T>
void AVLTree<T>::clear(AVLNode<T> *& current) {
    //if left not null, call recursively with left, then delete left
    if(current != nullptr) {
        clear(current->left);
        clear(current->right);
        delete current;
    }
}


//overloaded stream insertion operator
template<class T>
std::ostream& operator <<(std::ostream& os, const AVLTree<T>& tree) {
    //passes root pointer to print function
    tree.print(os, tree.root);
    return os;
}


//prints each element in preorder traversal
template<class T>
std::ostream& AVLTree<T>::print(std::ostream & os, AVLNode<T> * current) const {
    //if not null
    if(current != nullptr) {
        //stream insert node data (followed by height for debugging purposes)
        os << current->data << ' ' << current->height << std::endl;

        //call print with left pointer
        print(os, current->left);

        //call print with right pointer
        print(os, current->right);
    }

    //return ostream object
    return os;
}


//=========
//SEARCHING
//=========

//determines if arg is an element
template<class T>
bool AVLTree<T>::contains(const T & arg) const {
    //return value of private function, passing root pointer
}


//determines if arg is an element of tree rooted at arg
    //if this is null, return false
    //if this value is target, return true
    //else, if target value less than this, call with left
    //else, if target value greater than this, call with right


//searches for and returns arg
template<class T>
T& AVLTree<T>::search(const T & arg) {
    //return value of private function, passing root pointer
}


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

/*
 * NOTE TO SELF:
 *
 * MAKE SURE TO PASS ALL POINTERS BY REFERENCE
 * OTHERWISE NONE OF THIS WORKS.
 */


//inserts arg
template<class T>
void AVLTree<T>::insert(const T & arg) {
    //create list of strings, indicating directions taken when traversing list
    std::list<std::string> treeTrace;

    //call private function with root pointer
    insert(arg, root);
}


//inserts arg to tree rooted at arg (with tree trace list and iterator as parms)
template<class T>
void AVLTree<T>::insert(const T & arg, AVLNode<T> *& current) {
    //if current is null, assign current to pointer
    if(current == nullptr)
        current = new AVLNode<T>(arg);

    //if node equal to value, append data to this element
    else if(current->data == arg)
        current->data += arg;

    //if value greater than node
    else if(arg > current->data) {
        //call recursively with right pointer
        insert(arg, current->right);

        //rebalance current and set height
        current->updateHeight();
    }

    //if value greater than node
    else if(arg < current->data) {
        //call recursively with left pointer
        insert(arg, current->left);

        //rebalance current and set height
        current->updateHeight();
    }
}


//========
//ROTATING
//========

/*
 * NOTE TO SELF:
 *
 * MAKE SURE TO PASS ALL POINTERS BY REFERENCE
 * OTHERWISE NONE OF THIS WORKS.
 */


/*
 * Returns true if chiled nodes have height difference of more than one
 */
//check for imbalance at node
    //if no children, return false


//rebalance node
    //if left and left, call case 1 with this node
    //if left and right, call case 2 with this node
    //if right and left, call case 3 with this node
    //if right and right, call case 4 with this node


//case 1 rotation
    //get pointer to left child (LC)
    //get pointer to LR grandchild
    //make temp pointer to LR
    //make LC point to root node on the right
    //make root pointer point to LC
    //make root's right node's left pointer go to temp


//case 4 rotation
    //get pointer to right child (RC)
    //get pointer to RL grandchild
    //make temp pointer to RL
    //make RC point to root node on the left
    //make root pointer point to RC
    //make root's left node's right pointer go to temp


//case 2 rotation
    //case 4 rotation on root's left pointer
    //case 1 rotation on root pointer


//case 3 rotation
    //case 1 rotation on root's right pointer
    //case 4 rotation on root pointer


#endif // AVLTREE_H
