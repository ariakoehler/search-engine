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

//gets value of search term
std::string IndexedTerm::getTerm() {
    return term;
}


std::vector<std::pair<int, int>> IndexedTerm::getQuestionVector() {
    return idWithFrequency;
}


//search for ID and return by reference
    //find ID value (std::find_if)
    //return pair with ID paired frequency and boolean


//search for ID and return by reference
    //identical logic to other search, but returns by value




//=========
//OPERATORS
//=========

/**
 * Equality operator checks keys (terms) for equality
 */
bool IndexedTerm::operator ==(const IndexedTerm& rhs) {
    return term == rhs.term;
}


/**
 * Addition Assignment Operator adds question ID to list if it isn't there,
 * if it is present, adds frequency
 */
    //first, check to make sure keys are the same, if not, throw big, scary error because something is seriously wrong
    //searches in vector for ID and returns reference
    //if search was successful, add frequency to that pair
    //if search was unsuccessful, add ID with frequency to vector


/**
 * Stream Insertion Operator prints term followed by question ID's with frequencies
 */
