#include "indexedterm.h"

//============
//CONSTRUCTORS
//============

IndexedTerm::IndexedTerm(std::string termIndex) : term(termIndex) {}


IndexedTerm::IndexedTerm(std::string word, int questionID, int frequency) {
    term = word;
    idWithFrequency.push_back(std::pair<int, int>(questionID, frequency));
}


//===================
//GETTERS AND SETTERS
//===================

/**
 * Gets value of search term
 */
std::string IndexedTerm::getTerm() const {
    return term;
}


/**
 * Returns vector of pairs, formatted as (questionID, number of occurences)
 */
std::vector<std::pair<int, int> > IndexedTerm::getQuestionVector() const {
    return idWithFrequency;
}


/**
 * Searches for ID and returns ID with frequency by reference
 */
std::pair<std::pair<int, int>&, bool> IndexedTerm::search(int soughtID) {
    //find ID value (std::find_if)
    auto result = std::find_if(idWithFrequency.begin(), idWithFrequency.end(),
                 [soughtID](std::pair<int, int>& a){ return a.first == soughtID; });

    //return pair with ID paired frequency and boolean
    if(result != idWithFrequency.end())
        return std::pair<std::pair<int, int>&, bool>(*result, true);
    else
        return std::pair<std::pair<int, int>&, bool>(*result, false);
}


/*
 * Search for ID and return by value
 */
std::pair<std::pair<int, int>, bool> IndexedTerm::search(int soughtID) const {
    //find ID value (std::find_if)
    auto result = std::find_if(idWithFrequency.begin(), idWithFrequency.end(),
                 [soughtID](std::pair<int, int> a){ return a.first == soughtID; });

    //return pair with ID paired frequency and boolean
    if(result != idWithFrequency.end())
        return std::pair<std::pair<int, int>, bool>(*result, true);
    else
        return std::pair<std::pair<int, int>, bool>(*result, false);
}



//=========
//OPERATORS
//=========

/**
 * Equality operator checks keys (terms) for equality
 */
bool IndexedTerm::operator ==(const IndexedTerm& rhs) const {
    return term == rhs.term;
}


/**
 * Addition Assignment Operator adds question ID to list if it isn't there,
 * if it is present, adds frequency
 */
void IndexedTerm::operator +=(const IndexedTerm& rhs) {
    /*
     * First, check to make sure keys are the same.
     * If not, throw big, scary error because
     * something is seriously wrong.
     */
    if(term != rhs.term)
        throw std::invalid_argument("Keys mismatched when trying to append Question ID data.");

    //searches in vector for ID and returns reference
    std::pair<std::pair<int, int>&, bool> questionID = search(rhs.getQuestionVector()[0].first);

    //if search was successful, add frequency to that pair
    if(questionID.second)
        questionID.first.second += rhs.getQuestionVector()[0].second;

    //if search was unsuccessful, add ID with frequency to vector
    else
        idWithFrequency.push_back(rhs.getQuestionVector()[0]);
}


/**
 * Stream Insertion Operator prints term followed by question ID's with frequencies
 */
