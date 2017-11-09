#include <iostream>
#include <utility>
#include <vector>
#include <string>

#include "catch.hpp"
#include "porter2_stemmer.h"
#include "hashtable.hpp"
#include "avltree.hpp"
#include "indexedterm.h"

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
    test4.insert(std::string("quux"));
    test4.insert(std::string("baz"));
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

        REQUIRE(test0.contains(55));
        REQUIRE(test0.contains(40));
        REQUIRE(test0.contains(70));
        REQUIRE_FALSE(test0.contains(65));

        REQUIRE(test1.contains(8));
        REQUIRE(test1.contains(7));
        REQUIRE(test1.contains(12));
        REQUIRE(test1.contains(3));
        REQUIRE(test1.contains(20));
        REQUIRE_FALSE(test1.contains(9));

        REQUIRE_FALSE(test2.contains(6));

        REQUIRE(test3.contains(std::string("selected")));
        REQUIRE(test3.contains(std::string("drukqs")));
        REQUIRE(test3.contains(std::string("ccai2")));
        REQUIRE(test3.contains(std::string("syro")));
        REQUIRE(test3.contains(std::string("rdj")));
        REQUIRE_FALSE(test3.contains(std::string("")));

        REQUIRE(test4.contains(std::string("foo")));
        REQUIRE(test4.contains(std::string("quux")));
        REQUIRE(test4.contains(std::string("qux")));
        REQUIRE(test4.contains(std::string("bar")));
        REQUIRE(test4.contains(std::string("baz")));
        REQUIRE_FALSE(test4.contains(std::string("foobar")));

    }


    SECTION("Searching") {


        REQUIRE(test0.search(40).first == 40);
        REQUIRE(test0.search(40).second == true);
        REQUIRE(test0.search(85).first == 85);
        REQUIRE(test0.search(85).second == false);

        REQUIRE(test1.search(3).first == 3);
        REQUIRE(test1.search(3).second == true);
        REQUIRE(test1.search(80).first == 80);
        REQUIRE(test1.search(80).second == false);

        REQUIRE(test2.search(70).first == 70);
        REQUIRE(test2.search(70).second == false);

        REQUIRE(test3.search(std::string("drukqs")).first == std::string("drukqs"));
        REQUIRE(test3.search(std::string("drukqs")).second == true);
        REQUIRE(test3.search(std::string("melodiesfrommars")).first == std::string("melodiesfrommars"));
        REQUIRE(test3.search(std::string("melodiesfrommars")).second == false);

        REQUIRE(test5.search(std::string("foobar")).first == std::string("foobar"));
        REQUIRE(test5.search(std::string("foobar")).second == false);

    }


    SECTION("Complex Insertions") {

        /*
         * Print statements have been commented out and are principally for
         * checking test compliance manually, as AVLTree provides no public
         * interface for accessing members directly.
         */

//        cout << test1 << endl;
        test1.insert(1);
//        cout << test1 << endl;
        test1.insert(40);
//        cout << test1 << endl;

//        cout << test3 << endl;
        test3.insert(std::string("sergefenix"));
//        cout << test3 << endl;
        test3.insert(std::string("donkeyrhubarb"));
//        cout << test3 << endl;
    }


    SECTION("Copy Constructor and Assignment Op") {

        /*
         * Print statements have been commented out and are principally for
         * checking test compliance manually, as AVLTree provides no public
         * interface for accessing members directly.
         */

        AVLTree<std::string> copy3(test3);
//        cout << copy3 << endl;

        AVLTree<std::string> copy4 = test4;
//        cout << copy4 << endl;
    }
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


    SECTION("Addition Assignment and Searching with value return") {

        test0 += IndexedTerm(std::string("alito"), 58, 256);
        test0 += IndexedTerm(std::string("alito"), 58, 512);
        test0 += IndexedTerm(std::string("alito"), 512, 58);

        REQUIRE(test0.getQuestionVector()[0].first == 58);
        REQUIRE(test0.getQuestionVector()[0].second == 768);
        REQUIRE(test0.getQuestionVector()[1].first == 512);
        REQUIRE(test0.getQuestionVector()[1].second == 58);

        REQUIRE(test0.search(58).first.first == 58);
        REQUIRE(test0.search(58).first.second == 768);
        REQUIRE(test0.search(58).second);
        REQUIRE_FALSE(test0.search(75).second);

        test2 += IndexedTerm(std::string("kagan"), 812, 24);
        REQUIRE_THROWS(test2 += IndexedTerm(std::string("sotomayor"), 212, 420));

        REQUIRE(test2.getQuestionVector()[1].first == 812);
        REQUIRE(test2.getQuestionVector()[1].second == 24);

        REQUIRE(test2.search(453157).first.first == 453157);
        REQUIRE(test2.search(453157).first.second== 25);
        REQUIRE(test2.search(453157).second);

        test3 += IndexedTerm(std::string("gorsuch"), 67, 51);
        test3 += IndexedTerm(std::string("gorsuch"), 198354, 65);
        test3 += IndexedTerm(std::string("gorsuch"), 8675309, 47);

        REQUIRE(test3.getQuestionVector()[0].first == 8675309);
        REQUIRE(test3.getQuestionVector()[0].second == 89);
        REQUIRE(test3.getQuestionVector()[1].first == 67);
        REQUIRE(test3.getQuestionVector()[1].second == 51);
        REQUIRE(test3.getQuestionVector()[2].first == 198354);
        REQUIRE(test3.getQuestionVector()[2].second == 65);

        REQUIRE(test3.search(8675309).first.first == 8675309);
        REQUIRE(test3.search(8675309).first.second == 89);
        REQUIRE(test3.search(8675309).second);
        REQUIRE(test3.search(198354).first.first == 198354);
        REQUIRE(test3.search(198354).first.second == 65);
        REQUIRE(test3.search(198354).second);
        REQUIRE_FALSE(test3.search(9035768).second);

    }

}
