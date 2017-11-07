#include "documentparser.h"
using namespace std;
DocumentParser::DocumentParser(){

}
DocumentParser::DocumentParser(string fileName){
    in.open(fileName.c_str());
}
void DocumentParser::parse(){
    char c;
    int i = 0;
    if(in.is_open()){
        while(in.get(c) && i < 1000){
            if(c == 10)
                return;
            cout << c;
            i++;
        }
    }
    in.close();
}
