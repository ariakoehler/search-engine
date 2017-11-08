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
    IndexedTerm(std::string, int, int);
    std::string getTerm(); //get value of search term
    std::vector<std::pair<int, int>> getQuestionVector();
    std::pair<std::pair<int, int>, bool> search(int); //search for ID and return by value
    bool operator==(const IndexedTerm&); //opertor == just checks keys; worries about internal data later
    void operator+=(const IndexedTerm&); //operator += appends ID or increases frequency with given ID
    //stream insertion operator prints term with contents of
};

#endif // INDEXEDTERM_H
