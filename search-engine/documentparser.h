#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H
#include <string>
#include <vector>
#include <set>
#include "porter2_stemmer.h"
class DocumentParser
{
    std::set<std::string> set_stop_words;
    bool checkStopWord(std::string str);
    void parseString(int questionID, int flag, std::string str);
    void sendToIndex(std::string term, int questionID, int frequency);
    std::string findDocument(int id);
public:
    DocumentParser();
    void parse(std::string fileName);
    void loadStopWords(std::string fileName);
    void tagParse(std::string fileName);
    std::vector<std::string> questionLookup(int lookupID);
};

#endif // DOCUMENTPARSER_H
