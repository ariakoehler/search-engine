#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <string>

#include "indexinterface.hpp"
#include "indexedterm.h"
#include "avltree.hpp"
#include "hashtable.hpp"

class IndexHandler
{
private:
    IndexInterface<IndexedTerm> * documentIndex; //pointer to Index base class
    
public:
    IndexHandler(std::string = "hash");
    ~IndexHandler();
    void addToIndex(std::string, int, int); //adds object to index
    IndexInterface<IndexedTerm> * getIndex();
    //searches index for object by key
    //writes index to disk
    //reads index from disk
};

#endif // INDEXHANDLER_H
