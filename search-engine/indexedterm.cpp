#include "indexedterm.h"

//============
//CONSTRUCTORS
//============

IndexedTerm::IndexedTerm(std::string termIndex) : term(termIndex) {}


//===================
//GETTERS AND SETTERS
//===================

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
