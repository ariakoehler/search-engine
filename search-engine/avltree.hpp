#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <queue>
#include <list>
#include <utility>
#include <string>

#include "indexinterface.hpp"

/**
 * Implements an ordered index as a self-balancing AVL binary tree.
 *
 * Assumes that underlying data type has sensibly overloaded
 * and operator==.
 *
 * Also assumes that any values passed in are unique or can have data
 * appended to them with operator+= without changing their ordering.
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

        void updateHeight(AVLNode<T>* arg) {
            if(arg != nullptr)
                arg->height = std::max(getHeight(arg->left), getHeight(arg->right)) + 1;
        }

        friend class AVLTree;
    };

    AVLNode<T> * root;

    T& findMax(AVLNode<T>*&); //finds the maximum value in tree rooted at arg
    T& findMin(AVLNode<T>*&); //finds the minimum value in tree rooted at arg
    void insert(const T &, AVLNode<T> *&); //inserts to tree rooted at arg
    std::pair<T,bool> search(const T&, AVLNode<T>*&); //searches in tree rooted at arg
    bool contains(const T &, AVLNode<T>*) const; //determines if arg is an element of tree rooted at arg
    void clear(AVLNode<T>*&); //clears tree rooted at arg
    int getBalance(AVLNode<T>*); //get balance of node
    void rebalance(T, AVLNode<T>*&); //rebalance node
    std::ostream& print(std::ostream&, AVLNode<T> *) const;//print tree rooted at arg
    void case1Rotation(AVLNode<T>*&); //case 1 rotation
    void case4Rotation(AVLNode<T>*&); //case 4 rotation
    void case2Rotation(AVLNode<T>*&); //case 2 rotation
    void case3Rotation(AVLNode<T>*&); //case 3 rotation


public:
    AVLTree();
    AVLTree(const AVLTree<T>&); //copy constructor
    AVLTree<T>& operator =(const AVLTree<T>&); //overloaded assignment op
    ~AVLTree(); //destructor
    bool contains(const T &) const; //determines if arg is an element
    std::pair<T,bool> search(const T &); //searches for and returns arg
    void insert(const T &); //inserts arg
    bool isEmpty() const; //determines if tree is empty
    void makeEmpty(); //clears the tree
    T& findMax(); //finds the maximum value
    T& findMin();//finds the minimum value

    template <class U>
    friend std::ostream& operator <<(std::ostream&, const AVLTree<U>&);     //stream insertion operator
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
AVLTree<T>::AVLTree(const AVLTree<T>& rhs) : IndexInterface<T>() {
    //initialize root to nullptr first
    root = nullptr;

    //create a queue of node pointers and push root
    std::queue<AVLNode<T>*> transferQueue;
    transferQueue.push(rhs.root);

    AVLNode<T>* temp;

    //while queue not empty
    while(!transferQueue.empty()) {
        //pop to temp from queue
        temp = transferQueue.front();
        transferQueue.pop();

        //insert value popped to this tree
        std::cout << temp->data << std::endl;
        insert(temp->data);

        //if right child not null, push to queue
        if(temp->right != nullptr)
            transferQueue.push(temp->right);

        //if left child not null, push to queue
        if(temp->left != nullptr)
            transferQueue.push(temp->left);
    }
}


/*
 * Overloaded assignment op performs breadth-first traversal of
 * input tree, inserting each element to this tree
 */
template<class T>
AVLTree<T>& AVLTree<T>::operator =(const AVLTree<T>& rhs) {
    //check to see that input is a different object
    if(&rhs != this) {
        //initialize root to nullptr first
        root = nullptr;

        //performs copy constructor logic
        std::queue<AVLNode<T>*> transferQueue;
        transferQueue.push(rhs.root);

        AVLNode<T>* temp;

        //while queue not empty
        while(!transferQueue.empty()) {
            //pop to temp from queue
            temp = transferQueue.front();
            transferQueue.pop();

            //insert value popped to this tree
            std::cout << temp->data << std::endl;
            insert(temp->data);

            //if right child not null, push to queue
            if(temp->right != nullptr)
                transferQueue.push(temp->right);

            //if left child not null, push to queue
            if(temp->left != nullptr)
                transferQueue.push(temp->left);
        }
    }

    //returns reference to this
    return *this;
}


template<class T>
AVLTree<T>::~AVLTree() {
    //call clear function with root
    clear(root);
    if(root != nullptr) {
        delete root;
        root = nullptr;
    }
}



//===================
//GETTERS AND SETTERS
//===================

/**
 * Returns the maximum value contained in the tree.
 */
template<class T>
T& AVLTree<T>::findMax() {
    //call private max function with root pointer
    return findMax(root);
}


/**
 * Privte interface for findMax method
 */
template<class T>
T& AVLTree<T>::findMax(AVLNode<T> *& current) {
    //if right pointer is null, return this value
    if(current->right == nullptr)
        return current->data;

    //else recursive call with right pointer
    else
        return findMax(current->right);
}


/**
 * Returns the minimum value contained in the tree.
 */
template<class T>
T& AVLTree<T>::findMin() {
    //call private min function with root pointer
    return(findMin(root));
}


/**
 * Privte interface for findMin method
 */
template<class T>
T& AVLTree<T>::findMin(AVLNode<T> *& current) {
    //if left pointer is null, return this value
    if(current->left == nullptr)
        return current->data;

    //else recursive call with left pointer
    else
        return findMin(current->left);
}


/**
 * Returns true if tree is empty, false if not.
 */
template<class T>
bool AVLTree<T>::isEmpty() const {
    //returns true iff root is null
    return root == nullptr;
}


/**
 *  Empties the tree and frees all allocated memory
 */
template<class T>
void AVLTree<T>::makeEmpty() {
    //calls private clear all function with root pointer
    clear(root);
    if(root != nullptr){
        delete root;
        root = nullptr;
    }
}


/*
 * Traverses tree, deleting each element as its recursive call is popped
 */
//clears tree rooted at arg
template<class T>
void AVLTree<T>::clear(AVLNode<T> *& current) {
    //if left not null, call recursively with left, then delete left
    if(current != nullptr) {
        if(current->left != nullptr){
            clear(current->left);
            delete current->left;
        }
        if(current->right != nullptr) {
            clear(current->right);
            delete current->right;
        }
    }
}


/*
 * Overloaded stream insertion operator prints each element according
 * to a preorder traversal.
 */
template<class T>
std::ostream& operator <<(std::ostream& os, const AVLTree<T>& tree) {
    //passes root pointer to print function
    tree.print(os, tree.root);
    return os;
}


/**
 * Private interface for stream insertion operator
 */
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

/**
 * Determines whether or not the passed argument is an element of the tree
 */
template<class T>
bool AVLTree<T>::contains(const T & arg) const {
    //return value of private function, passing root pointer
    return contains(arg, root);
}


/**
 * Private interface for contains method
 */
template<class T>
bool AVLTree<T>::contains(const T & arg, AVLNode<T> * current) const {
    //if this is null, return false
    if(current == nullptr)
        return false;

    //if this value is target, return true
    else if(current->data == arg)
        return true;

    //if target value less than this, call with left
    else if(arg < current->data)
        return contains(arg, current->left);

    //if target value greater than this, call with right
    else if(arg > current->data)
        return contains(arg, current->right);

    else {
        throw std::runtime_error("The relationship between your data and the "
                                 "data in the tree cannot be resolved.");
    }
}

/**
 * Searches for the passed value and returns that data from the tree if it is there.
 * If not, indicates with a false value.
 */
template<class T>
std::pair<T, bool> AVLTree<T>::search(const T & arg) {
    //return value of private function, passing root pointer
    return search(arg, root);
}


/**
 * Private interface for search method
 */

//searches for and returns arg in tree rooted at arg
template<class T>
std::pair<T, bool> AVLTree<T>::search(const T & arg, AVLNode<T> *& current) {
    if(current == nullptr)
        return std::pair<T, bool>(arg, false);

    //if value is target, return reference to value
    if(current->data == arg)
        return std::pair<T, bool>(current->data, true);

    //if target value less than this, recursive call
    else if(arg < current->data)
        return search(arg, current->left);

    //if target value greater than this
    else
        return search(arg, current->right);
}


//=========
//INSERTING
//=========

/*
 * NOTE TO SELF:
 *
 * MAKE SURE TO PASS ALL POINTERS BY REFERENCE
 * OTHERWISE NONE OF THIS WORKS.
 */

/**
 * Determines where a passed value should be inserted into the tree
 * and inserts there.
 */
template<class T>
void AVLTree<T>::insert(const T & arg) {
    //create list of strings, indicating directions taken when traversing list
    std::list<std::string> treeTrace;

    //call private function with root pointer
    insert(arg, root);
}


/**
 * Private interface for insertion method
 */
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
        rebalance(arg, current);
        current->updateHeight();
    }

    //if value greater than node
    else if(arg < current->data) {
        //call recursively with left pointer
        insert(arg, current->left);

        //rebalance current and set height
        rebalance(arg, current);
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

/**
 * Gets the balance (difference in child heights) of node passed as argument
 */
template <class T>
int AVLTree<T>::getBalance(AVLNode<T> * balancingNode) {
    //returns height of right - height of right
    return balancingNode->getHeight(balancingNode->right) -
            balancingNode->getHeight(balancingNode->left);
}


/**
 * Determines whether or not a node is imbalanced and, if so,
 * rebalances the node with the appropriate rotation
 */
template <class T>
void AVLTree<T>::rebalance(T arg, AVLNode<T> *& current) {
    //get balance of node
    int bal = getBalance(current);

    //if balance less than -1
    if(bal < -1) {
        //if left of left of current is arg, case 1
        if(arg < current->left->data)
            case1Rotation(current);

        //if right of left of current is arg, case 2
        else if(arg > current->left->data)
            case2Rotation(current);
    }

    //if balance greater than 1
    else if(bal > 1) {
        //if left of right of current is arg, case 3
        if(arg < current->right->data)
            case3Rotation(current);

        //if right of right of current is arg, case 4
        else if(arg > current->right->data)
            case4Rotation(current);
    }
}


/**
 * Case 1 rotation, when inserted node is in left subtree of left child
 */
template <class T>
void AVLTree<T>::case1Rotation(AVLNode<T> *& topNode) {
    //get pointer to left child (LC)
    AVLNode<T>* leftChild = topNode->left;

    //make temp pointer to LR
    AVLNode<T>* temp = topNode->left->right;

    //make LC point to root node on the right
    leftChild->right = topNode;

    //make root pointer point to LC
    topNode = leftChild;

    //make root's right node's left pointer go to temp
    leftChild->right->left = temp;

    //make sure heights are updated
    topNode->updateHeight(leftChild->right);
    topNode->updateHeight(leftChild->left);
}


/**
 * Case 4 rotation, when inserted node is in right subtree of right child
 */
template <class T>
void AVLTree<T>::case4Rotation(AVLNode<T> *& topNode) {
    //get pointer to right child (RC)
    AVLNode<T>* rightChild = topNode->right;

    //make temp pointer to RL
    AVLNode<T>* temp = topNode->right->left;

    //make RC point to root node on the left
    rightChild->left = topNode;

    //make root pointer point to RC
    topNode = rightChild;

    //make root's left node's right pointer go to temp
    rightChild->left->right = temp;

    //make sure heights are updated
    topNode->updateHeight(rightChild->right);
    topNode->updateHeight(rightChild->left);
}


/**
 * Case 2 rotation, when inserted node is in right subtree of left child
 */
template <class T>
void AVLTree<T>::case2Rotation(AVLNode<T> *& topNode) {
    //case 4 rotation on root's left pointer
    case4Rotation(topNode->left);

    //case 1 rotation on root pointer
    case1Rotation(topNode);
}


/**
 * Case 3 rotation, when inserted node is in left subtree of right child
 */
template <class T>
void AVLTree<T>::case3Rotation(AVLNode<T> *& topNode) {
    //case 1 rotation on root's right pointer
    case1Rotation(topNode->right);

    //case 4 rotation on root pointer
    case4Rotation(topNode);
}


#endif // AVLTREE_H
