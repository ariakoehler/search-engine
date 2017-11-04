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
    virtual contains(const T&) = 0;
    virtual search(const T&) = 0;
    virtual insert(const T&) = 0;
    virtual isEmpty() = 0;
    virtual makeEmpty() = 0;
    virtual remove(const T&) =0;
};

#endif // INDEXINTERFACE_H
