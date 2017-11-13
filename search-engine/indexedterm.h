#ifndef INDEXEDTERM_H
#define INDEXEDTERM_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

class IndexedTerm
{
private:
    std::string term;
    std::vector<std::pair<int, int>> idWithFrequency;
    std::pair<std::pair<int, int>, bool> search(int) const;//search for ID and return by reference

public:
    IndexedTerm(std::string = "");
    IndexedTerm(std::string, int, int);
    std::string getTerm() const; //get value of search term
    std::vector<std::pair<int, int>> getQuestionVector() const;
    std::pair<std::pair<int, int>&, bool> search(int); //search for ID and return by value
    bool operator==(const IndexedTerm&) const; //opertor == just checks keys; worries about internal data later
    void operator+=(const IndexedTerm&); //operator += appends ID or increases frequency with given ID
    bool operator>(const IndexedTerm&) const;
    bool operator<(const IndexedTerm&) const;
    friend std::ostream& operator <<(std::ostream&, IndexedTerm); //stream insertion operator prints term with contents of vector
};

#endif // INDEXEDTERM_H
