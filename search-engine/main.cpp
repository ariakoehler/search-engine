#define CATCH_CONFIG_RUNNER
#define CSV_IO_NO_THREAD
#include <iostream>
#include <string>
#include "catch.hpp"
#include "csvparser.h"
//Used csv parser found here https://sourceforge.net/projects/cccsvparser/
#include "documentparser.h"

using namespace std;

int runCatchTests(int argc, char* argv[]) {
    return Catch::Session().run();
}

int main(int argc, char *argv[])
{
    DocumentParser d;
    d.loadStopWords("../stop_words.txt");
    d.parse("../data/2008-questions.csv");
    cout << "Finished 2008" << endl;
    d.parse("../data/2009-questions.csv");
    cout << "Finished 2009" << endl;
    d.parse("../data/2010-questions.csv");
    cout << "Finished 2010" << endl;
    d.parse("../data/2011-questions.csv");
    cout << "Finished 2011" << endl;
    //d.parse("../data/2012-questions.csv");
    cout << "Finished 2012" << endl;
    //d.parse("../data/2013-questions.csv");
    cout << "Finished 2013" << endl;
    //d.parse("../data/2014-questions.csv");
    cout << "Finished 2014" << endl;
    //d.parse("../data/2015-questions.csv");
    cout << "Finished 2015" << endl;
    //d.parse("../data/2016-questions.csv");
    cout << "Finished 2016" << endl;
    return 0;
    /*
    if (std::string(argv[1]) == std::string("-t")) {
        return runCatchTests(argc, argv);
    } else {
        return 0;
    }
    */
}
