#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H
#include <string>
#include <vector>
#include <set>
#include "porter2_stemmer.h"
class DocumentParser
{
    std::vector<std::string> stop_words;
    std::set<std::string> set_stop_words;
public:
    DocumentParser();
    void parse(std::string fileName);
    void loadStopWords(std::string fileName);
    void tagParse(std::string fileName);
    void questionLookup(int id);
    void parseString(int questionID, int flag, std::string str);
    bool checkStopWord(std::string str);
    void makeLower(std::string& str);
    void sendToIndex(std::string term, int questionID, int frequency);
};

#endif // DOCUMENTPARSER_H
