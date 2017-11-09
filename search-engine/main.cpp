#define CATCH_CONFIG_RUNNER
#define CSV_IO_NO_THREAD
#include <iostream>
#include <string>
#include "csv.h"
#include "catch.hpp"
#include "csvparser.h"
#include "documentparser.h"

using namespace std;

int runCatchTests(int argc, char* argv[]) {
    return Catch::Session().run();
}

int main(int argc, char *argv[])
{
    double ownerUserId;
    string  creationDate, title, body, code;
    int id, score;
    /*
    io::CSVReader<7, io::trim_chars<' '>, io::double_quote_escape<',','\"'>> in("2008-questions.csv");
    in.read_header(io::ignore_extra_column, "Id", "OwnerUserId", "CreationDate", "Score", "Title", "Body", "Code");
    in.read_row(id, ownerUserId, creationDate, score, title, body, code);
        cout << "ID: " << id << endl;
    while(in.read_row(id, ownerUserId, creationDate, score, title, body, code)){
        cout << "ID: " << id << endl;
    }
    */
    int x = 0;
    int i =  0;
    //                                   file, delimiter, first_line_is_header?
    CsvParser *csvparser = CsvParser_new("2008-questions.csv", ",", 1);
    CsvRow *row;
    const CsvRow *header = CsvParser_getHeader(csvparser);

    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return 1;
    }
    const char **headerFields = CsvParser_getFields(header);
    for (i = 0 ; i < CsvParser_getNumFields(header) ; i++) {
        printf("TITLE: %s\n", headerFields[i]);
    }
    while ((row = CsvParser_getRow(csvparser))) {
        const char **rowFields = CsvParser_getFields(row);
        id = atoi(rowFields[1]);
        ownerUserId = atof(rowFields[2]);
        creationDate = string(rowFields[3]);
        score = atoi(rowFields[4]);
        title = string(rowFields[5]);
        body = string(rowFields[6]);
        code = string(rowFields[7]);
        cout << "\nCreation Date: " << creationDate << endl << endl;
        CsvParser_destroy_row(row);
        x++;
    }
    CsvParser_destroy(csvparser);
    return 0;
    /*
    if (std::string(argv[1]) == std::string("-t")) {
        return runCatchTests(argc, argv);
    } else {
        return 0;
    }
    */
}
