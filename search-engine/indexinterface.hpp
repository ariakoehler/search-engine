#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <iostream>
#include <utility>

template <class T>
class IndexInterface
{

public:
    IndexInterface() {}
    IndexInterface(const IndexInterface<T>&) {}
    IndexInterface<T>& operator =(const IndexInterface<T>&) {}
    virtual ~IndexInterface();
    virtual bool contains(const T&) const = 0;
    virtual std::pair<T,bool> search(const T&) = 0;
    virtual void insert(const T&) = 0;
    virtual bool isEmpty() const = 0;
    virtual void makeEmpty() = 0;
};

template<class T>
IndexInterface<T>::~IndexInterface() {}

#endif // INDEXINTERFACE_H
