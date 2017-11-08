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
    IndexedTerm test2(std::string("kagan"), 453157, 25);
    IndexedTerm test3(std::string("gorsuch"), 8675309, 42);
    IndexedTerm test4;


    SECTION("Constructor") {

        REQUIRE(test0.getTerm() == "alito");
        REQUIRE(test1.getTerm() == "sotomayor");
        REQUIRE(test2.getTerm() == "kagan");
        REQUIRE(test3.getTerm() == "gorsuch");
        REQUIRE(test4.getTerm() == "");

        REQUIRE(test0.getQuestionVector().empty());
        REQUIRE(test1.getQuestionVector().empty());
        REQUIRE_FALSE(test2.getQuestionVector().empty());
        REQUIRE_FALSE(test3.getQuestionVector().empty());
        REQUIRE(test4.getQuestionVector().empty());

        REQUIRE(test2.getQuestionVector()[0].first == 453157);
        REQUIRE(test3.getQuestionVector()[0].first == 8675309);
        REQUIRE(test2.getQuestionVector()[0].second == 25);
        REQUIRE(test3.getQuestionVector()[0].second == 42);
    }


    SECTION("Equality Operators") {

        REQUIRE(test0 == IndexedTerm("alito"));
        REQUIRE(test1 == IndexedTerm("sotomayor"));
        REQUIRE(test2 == IndexedTerm("kagan"));
        REQUIRE(test3 == IndexedTerm("gorsuch"));
        REQUIRE(test4 == IndexedTerm(""));
    }


    SECTION("Addition Assignment") {



    }


    SECTION("Search with value return") {



    }

}
