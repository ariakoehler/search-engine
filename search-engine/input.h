#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <vector>

using namespace std;

class input
{
private:

    int andOrFlag = 0; //determines if terms are and/or togehter, 0 for or 1 for and
    vector<string> andOrWords; //holds all words to search
    vector<string> notWords; //holds all words not to be searched for
    void parseWords(string &); //parses the querey to single words
    string bracket(string &);


public:
    input();

    vector<string> getTermVector();
    vector<string> getNotTermVector();

};

#endif // INPUT_H
