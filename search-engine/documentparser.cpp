
#include "documentparser.h"
using namespace std;
DocumentParser::DocumentParser(){

}
DocumentParser::DocumentParser(string fileName){
    in.open(fileName.c_str());
}
void DocumentParser::parse(){
    char c;
    string s;
    int i = 0;
    if(in.is_open()){

        while(in.get(c)){
            if(c == 10)
                break;
        }

        while(i < 30){
            //cout << c;
            c = in.peek();

            if(c == '\"'){
                getline(in, s, '\"');
            }
            else
                getline(in, s, ',') &&
            cout << s << endl;
            cout << "End of line" << endl;
            i++;
        }
    }
    in.close();
}
