#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>

#include "catch.hpp"
#include "documentparser.h"

using namespace std;

int runCatchTests(int argc, char* argv[]) {
    return Catch::Session().run();
}

int main(int argc, char *argv[])
{

    DocumentParser d(string("2008-questions.csv"));
    d.parse();
    return 0;
    /*
    if (std::string(argv[1]) == std::string("-t")) {
        return runCatchTests(argc, argv);
    } else {
        return 0;
    }
    */
}
