#include "indexhandler.h"


IndexHandler::IndexHandler(std::string indexType) {
    //instantiate object of type specified by argument
    if(indexType == "avl")
        documentIndex = new AVLTree<IndexedTerm>;

    /*
    else if(indexType == "hash")
        documentIndex = new HashTable<IndexedTerm>;
    */

    else
        throw std::invalid_argument("That type of index has not been constructed yet.");
}


IndexHandler::~IndexHandler() {
    delete documentIndex;
}


/**
 * Adds an object with the specified term, question ID, and frequency to the index.
 */
void IndexHandler::addToIndex(std::string term, int questionId, int frequency) {

    //create object according to specifications and insert to index
    IndexedTerm newTerm(term, questionId, frequency);
    documentIndex->insert(newTerm);
}


/**
 * For debugging; delete later
 */
IndexInterface<IndexedTerm> *IndexHandler::getIndex() {
    return documentIndex;
}

/**
 * Searches the index for the specified term.
 */
std::pair<IndexedTerm, bool> IndexHandler::searchIndex(std::string toBeFound) {
    //create object according to term and return results of index search
    return documentIndex->search(IndexedTerm(toBeFound));
}


/**
 * Writes the index to a persistent file location in disk
 */
void IndexHandler::writeToDisk() {

    std::string fileName("../index.txt");
    std::ofstream fileOut;

    fileOut.open(fileName.c_str(), std::ios::out);

    //don't forget to check if open and close afterwards
    if(!fileOut.is_open())
        throw std::runtime_error("Failed to open file for persisting index past runtime.");

    //level-order traversal using queue
    std::queue<IndexedTerm> outputQueue;
    IndexedTerm temp;

    //each visit to a node has it being printed to file
}


/**
 * Reads the index from a persistent file location in disk
 */
    //until end of file
        //read in term
            //until new line, read in ID and frequency
            //insert new term to index
