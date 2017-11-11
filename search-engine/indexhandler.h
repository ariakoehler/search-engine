#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <string>

#include "indexhandler.h"
#include "indexedterm.h"

class IndexHandler
{
private:
    //pointer to Index base class
    
public:
    IndexHandler(std::string = "hash");
    //adds object to index
    //searches index for object by key
    //writes index to disk
    //reads index from disk
};

#endif // INDEXHANDLER_H
