#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H
#include <fstream>
#include <iostream>
#include <string>

class DocumentParser
{
    std::ifstream in;
public:
    DocumentParser();
    DocumentParser(std::string fileName);
    void parse();
};

#endif // DOCUMENTPARSER_H
