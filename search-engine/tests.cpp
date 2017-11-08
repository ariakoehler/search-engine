#include <iostream>

#include "catch.hpp"
#include "porter2_stemmer.h"
#include "hashtable.h"
#include "avltree.hpp"
#include "indexedterm.h"

using namespace std;

TEST_CASE("External Libraries") {

}

TEST_CASE("AVL Tree") {

}

TEST_CASE("Hash Table") {

}

TEST_CASE("Indexed Terms") {

    IndexedTerm test0(std::string("alito"));
    IndexedTerm test1(std::string("sotomayor"));
    IndexedTerm test2(std::string("kagan"));
    IndexedTerm test3(std::string("gorsuch"));
    IndexedTerm test4;


    SECTION("Constructor") {

        REQUIRE(test0.getTerm() == "alito");
        REQUIRE(test1.getTerm() == "sotomayor");
        REQUIRE(test2.getTerm() == "kagan");
        REQUIRE(test3.getTerm() == "gorsuch");
        REQUIRE(test4.getTerm() == "");

    }

    SECTION("Equality Operators") {

        REQUIRE(test0 == IndexedTerm("alito"));
        REQUIRE(test1 == IndexedTerm("sotomayor"));
        REQUIRE(test2 == IndexedTerm("kagan"));
        REQUIRE(test3 == IndexedTerm("gorsuch"));
        REQUIRE(test4 == IndexedTerm(""));

    }

    SECTION("Search with value return") {

    }

    SECTION("Addition Assignment") {

    }
}
