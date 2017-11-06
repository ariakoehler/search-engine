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

    test0.insert(55);
    test0.insert(40);
    test0.insert(70);

    test1.insert(8);
    test1.insert(7);
    test1.insert(12);
    test1.insert(3);
    test1.insert(20);

    test3.insert(std::string("rdj"));
    test3.insert(std::string("syro"));
    test3.insert(std::string("ccai2"));
    test3.insert(std::string("drukqs"));
    test3.insert(std::string("selected"));

    test4.insert(std::string("foo"));
    test4.insert(std::string("bar"));
    test4.insert(std::string("baz"));
    test4.insert(std::string("quux"));
    test4.insert(std::string("qux"));



    SECTION("isEmpty") {
        REQUIRE_FALSE(test0.isEmpty());
        REQUIRE_FALSE(test1.isEmpty());
        REQUIRE(test2.isEmpty());
        REQUIRE_FALSE(test3.isEmpty());
        REQUIRE_FALSE(test4.isEmpty());
        REQUIRE(test5.isEmpty());
    }


    SECTION("Get maxes and mins") {

        REQUIRE(test0.findMax() == 70);
        REQUIRE(test0.findMin() == 40);

        REQUIRE(test1.findMax() == 20);
        REQUIRE(test1.findMin() == 3);

        REQUIRE(test3.findMax() == std::string("syro"));
        REQUIRE(test3.findMin() == std::string("ccai2"));

        REQUIRE(test4.findMax() == std::string("qux"));
        REQUIRE(test4.findMin() == std::string("bar"));

    }


    SECTION("Make Empty") {
        test0.makeEmpty();
        REQUIRE(test0.isEmpty());

        test1.makeEmpty();
        REQUIRE(test1.isEmpty());

        test2.makeEmpty();
        REQUIRE(test2.isEmpty());

        test3.makeEmpty();
        REQUIRE(test3.isEmpty());

        test4.makeEmpty();
        REQUIRE(test4.isEmpty());

        test5.makeEmpty();
        REQUIRE(test5.isEmpty());
    }


    SECTION("Check for Membership") {

    }

}


TEST_CASE("Hash Table") {


}
