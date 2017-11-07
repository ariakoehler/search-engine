#ifndef INDEXEDTERM_H
#define INDEXEDTERM_H

#include <string>
#include <vector>
#include <utility>
#include <vector>

class IndexedTerm
{
private:
    std::string term;
    std::vector<std::pair<int, int>> idWithFrequency;

public:
    IndexedTerm(std::string = "");
    //operator += appends ID or increases frequency with given ID
    //stream insertion operator prints term with contents of
};

#endif // INDEXEDTERM_H
