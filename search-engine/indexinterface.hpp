#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

template <class T>
class IndexInterface
{

public:
    IndexInterface() {}
    IndexInterface(const IndexInterface<T>&) {}
    IndexInterface<T>& operator =(const IndexInterface<T>&) {}
    virtual ~IndexInterface();
    virtual bool contains(const T&) const = 0;
    virtual T& search(const T&) = 0;
    virtual void insert(const T&) = 0;
    virtual bool isEmpty() const = 0;
    virtual void makeEmpty() = 0;
    virtual void remove(const T&) =0;
};

#endif // INDEXINTERFACE_H
