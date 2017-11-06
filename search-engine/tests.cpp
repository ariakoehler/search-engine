#include <iostream>

#include "catch.hpp"
#include "porter2_stemmer.h"
#include "hashtable.hpp"
#include "avltree.hpp"

using namespace std;

TEST_CASE("External Libraries") {

}

TEST_CASE("AVL Tree") {


    AVLTree<int> test0;
    AVLTree<int> test1;
    AVLTree<int> test2;
    AVLTree<std::string> test3;
    AVLTree<std::string> test4;
    AVLTree<std::string> test5;


    SECTION("isEmpty") {
        REQUIRE(test0.isEmpty());
        REQUIRE(test1.isEmpty());
        REQUIRE(test2.isEmpty());
        REQUIRE(test3.isEmpty());
        REQUIRE(test4.isEmpty());
        REQUIRE(test5.isEmpty());
    }

    SECTION("Simple Insertions") {

        test0.insert(55);
        cout << test0 << endl;

    }


    SECTION("Getters and Setters") {

    }


}


TEST_CASE("Hash Table") {

}
