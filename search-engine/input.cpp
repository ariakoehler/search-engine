#include "input.h"
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
input::input()
{

    string initalQuery;
    cout << "Enter a query" << endl;
    getline(cin,initalQuery);
    initalQuery += ' ';
    for(int i = 0; i < initalQuery.length(); i++){ //loops through setting entire string to lowercase to avoid case issues
        initalQuery[i] = tolower(initalQuery[i]);
    }

    parseWords(initalQuery);

}
void input::parseWords(string &s){
    string Words = s.substr(0,s.find(' '));
    int notFlag = 0;
    if (Words == "and"){
        andOrFlag = 1;//sets andOr flag to and position (1)
    }
    while(s.length() != 0){
    if(s == ""){
        break;
    }
    Words = s.substr(0,s.find(' '));
    s.erase(0,s.find(' ') + 1);
    if(Words == "not"){
        notFlag =1;
    }
    if(Words == "and" || Words == "not" || Words == "or"){
        continue;
    }
    if(Words[0] == '['){
        Words += " ";
        Words += bracket(s);
        Words.erase(0,1);
    }
    if(notFlag == 1){
        if(Words != "")
        notWords.push_back(Words);
    } else {
        if(Words != "")
        andOrWords.push_back(Words);
    }

    }
    cout << "AND/OR" << endl;
    for(int i = 0; i < andOrWords.size(); i++){
        cout << andOrWords[i] << endl;
    }
    cout << "NOT" << endl;
    for(int i = 0; i < notWords.size(); i++){
        cout << notWords[i] << endl;
    }

}
string input::bracket(string &s){

    string secondWord = s.substr(0,s.find(']'));
    s.erase(0,s.find(']') + 1);
    return secondWord;
}
vector<string> input::getTermVector(){
    return andOrWords;
}
vector<string> input::getNotTermVector(){
    return notWords;
}

//stemming in the query
//brackets
//return vector or and/or with int determining if and or or
//return notVector
