#include "documentparser.h"
#include "csvparser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <strings.h>
DocumentParser::DocumentParser(){
}

void DocumentParser::loadStopWords(std::string fileName){
    std::ifstream stopWords;
    std::string buffer;
    stopWords.open(fileName);
    if(stopWords.is_open()){
        while(stopWords >> buffer)
            this->set_stop_words.insert(buffer);
    }
    else
        std::cout << "File cannot be opened" << std::endl;
    stopWords.close();
}
void DocumentParser::parse(std::string fileName){
    //variables for each field
    double ownerUserId;
    std::string creationDate, title, body, code;
    int id, score;
    int i = 0;
    //                                   file, delimiter, first_line_is_header?
    CsvParser *csvparser = CsvParser_new(fileName.c_str(), ",", 1);
    CsvRow *row;
    const CsvRow *header = CsvParser_getHeader(csvparser);
    //checks if header exists, always should with these .csv files
    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return;
    }
    //assigns headers, might be useful?
    const char **headerFields = CsvParser_getFields(header);
    for (i = 0 ; i < CsvParser_getNumFields(header) ; i++) {
        //printf("TITLE: %s\n", headerFields[i]);
    }
    //gets next question and breaks it up
    while ((row = CsvParser_getRow(csvparser))) {
        const char **rowFields = CsvParser_getFields(row);
        //assigns each field to proper variable, ignoring dummy field
        id = atoi(rowFields[1]);
        ownerUserId = atof(rowFields[2]);
        creationDate = std::string(rowFields[3]);
        score = atoi(rowFields[4]);
        title = std::string(rowFields[5]);
        body = std::string(rowFields[6]);
        code = std::string(rowFields[7]);
        //std::cout << "TITLE" << std::endl;
        parseString(id, 0, title);
        //std::cout << "BODY" << std::endl;
        parseString(id, 1, body);
        //std::cout << "CODE" << std::endl;
        parseString(id, 1, code);
        CsvParser_destroy_row(row);
    }
    CsvParser_destroy(csvparser);
}

void DocumentParser::parseString(int questionID, int flag, std::string str){
    std::string buffer, twoWords = "";
    std::string prev = "";
    std::stringstream input(str);
    while(std::getline(input, buffer, ' ')){
        if(!checkStopWord(buffer)){
            Porter2Stemmer::trim(buffer);
            Porter2Stemmer::stem(buffer);   //stems and trims word
            if(buffer != "" && buffer.length() < 20){
                //creates double word for later lookup
                twoWords = prev + " " + buffer;
                //std::cout << "Current word: " << buffer << std::endl;
                //std::cout << "Double word: " << twoWords << std::endl;

                //title content
                if(flag == 0){
                    sendToIndex(buffer, questionID, 3);
                    if(prev != "")
                        sendToIndex(twoWords, questionID, 3);
                }
                //body content
                else if(flag == 1){
                    sendToIndex(buffer, questionID, 1);
                    if(prev != "")
                        sendToIndex(twoWords, questionID, 1);
                }
                prev = buffer;
            }
        }
    }
}
//Checks if str is a stop word according to the file
bool DocumentParser::checkStopWord(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    std::set<std::string>::iterator it = set_stop_words.find(str);
    if(it != set_stop_words.end())
        return true;
    return false;
}

void DocumentParser::sendToIndex(std::string term, int questionID, int frequency){

}

void DocumentParser::tagParse(std::string fileName){
    int id, i = 0;
    std::string tag;
    //                                   file, delimiter, first_line_is_header?
    CsvParser *csvparser = CsvParser_new(fileName.c_str(), ",", 1);
    CsvRow *row;
    const CsvRow *header = CsvParser_getHeader(csvparser);
    //checks if header exists, always should with these .csv files
    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return;
    }
    //assigns headers, might be useful?
    const char **headerFields = CsvParser_getFields(header);
    for (i = 0 ; i < CsvParser_getNumFields(header) ; i++) {
        //printf("TITLE: %s\n", headerFields[i]);
    }
    //gets next question and breaks it up
    while ((row = CsvParser_getRow(csvparser))) {
        const char **rowFields = CsvParser_getFields(row);
        //assigns each field to proper variable, ignoring dummy field
        id = atoi(rowFields[1]);
        tag = rowFields[2];
        Porter2Stemmer::trim(tag);
        Porter2Stemmer::stem(tag);
        sendToIndex(tag, id, 10);
    }
    CsvParser_destroy(csvparser);
}
//tag parsing
//question lookup based on ID
std::vector<std::string> DocumentParser::questionLookup(int lookupID){
    int id, i = 0;
    std::vector<std::string> vec;
    std::string fileName = findDocument(id);
    //                                   file, delimiter, first_line_is_header?
    CsvParser *csvparser = CsvParser_new(fileName.c_str(), ",", 1);
    CsvRow *row;
    const CsvRow *header = CsvParser_getHeader(csvparser);
    //checks if header exists, always should with these .csv files
    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return vec;
    }
    //assigns headers, might be useful?
    const char **headerFields = CsvParser_getFields(header);
    for (i = 0 ; i < CsvParser_getNumFields(header) ; i++) {
        //printf("TITLE: %s\n", headerFields[i]);
    }
    //gets next question and breaks it up
    while ((row = CsvParser_getRow(csvparser))) {
        const char **rowFields = CsvParser_getFields(row);
        //assigns each field to proper variable, ignoring dummy field
        id = atoi(rowFields[1]);
        if(id == lookupID){
            for(int i = 1; i <= 7; i++)
                vec.push_back(std::string(rowFields[i]));
            return vec;
        }
    }
}

std::string DocumentParser::findDocument(int id){
    if(id >= 80 && id <= 404290)
        return "2008-questions.csv";
    else if(id >= 404430 && id <= 2274530)
        return "2009-questions.csv";
    else if(id >= 1987570 && id <= 4572720)
        return "2010-questions.csv";
    else if(id >= 4572790 && id <= 8691130)
        return "2011-questions.csv";
    //not finished
    else if(id >= 404430 && id <= 2274530)
        return "2012-questions.csv";
    else if(id >= 404430 && id <= 2274530)
        return "2013-questions.csv";
    else if(id >= 404430 && id <= 2274530)
        return "2014-questions.csv";
    else if(id >= 404430 && id <= 2274530)
        return "2015-questions.csv";
    else
        return "2016-questions.csv";
}
