#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <string>
#include <utility>
#include <fstream>
#include <iostream>

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
    std::pair<IndexedTerm, bool> searchIndex(std::string); //searches index for object by key
    void writeToDisk(); //writes index to disk
    void readFromDisk();//reads index from disk
};

#endif // INDEXHANDLER_H
