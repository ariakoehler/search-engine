#ifndef INDEXEDTERM_H
#define INDEXEDTERM_H

#include <string>
#include <vector>
#include <utility>
#include <vector>
#include <algorithm>

class IndexedTerm
{
private:
    std::string term;
    std::vector<std::pair<int, int>> idWithFrequency;
    //search for ID and return by reference

public:
    IndexedTerm(std::string = "");
    //search for ID and return by value
    //opertor == just checks keys; worries about internal data later
    //operator += appends ID or increases frequency with given ID
    //stream insertion operator prints term with contents of
};

#endif // INDEXEDTERM_H
