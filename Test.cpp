#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace family;
using namespace std;


TEST_CASE ("TEST ADD FATHER") {
    Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
	 .addFather("Terah", "e")
         .addFather("e", "f")
	 .addFather("f", "g")
	 .addFather("g", "h")
	 .addFather("h", "i");




            CHECK(T.relation("Avraham") == string("great-grandfather"));
            CHECK(T.relation("Terah") == string("great-great-grandfather"));
            CHECK(T.relation("Yaakov") == string("father"));
            CHECK(T.relation("Isaac") == string("grandfather"));
            CHECK(T.relation("e") == string("great-great-great-grandfather"));
            CHECK(T.relation("f") == string("great-great-great-great-grandfather"));
            CHECK(T.relation("g") == string("great-great-great-great-great-grandfather"));
            CHECK(T.relation("h") == string("great-great-great-great-great-great-grandfather"));
            CHECK(T.relation("i") == string("great-great-great-great-great-great-great-grandfather"));
            CHECK(T.find("father") == string("Yaakov"));
            CHECK(T.find("mother") == string("Rachel"));
            CHECK(T.find("grandfather") == string("Isaac"));
            CHECK(T.find("great-grandfather") == string("Avraham"));
            CHECK(T.find("great-great-grandfather") == string("Terah"));
            CHECK(T.find("great-great-great-grandfather") == string("e"));
            CHECK(T.find("great-great-great-great-grandfather") == string("f"));
            CHECK(T.find("great-great-great-great-great-grandfather") == string("g"));
            CHECK(T.find("great-great-great-great-great-great-grandfather") == string("h"));
            CHECK(T.find("great-great-great-great-great-great-great-grandfather") == string("i"));

}



TEST_CASE ("ADD MOTHER") {
   
     Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addMother("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addFather("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addMother("Yaakov", "Isaac")
	 .addFather("Yaakov", "Rivka")
	 .addMother("Isaac", "Avraham")
	 .addMother("Avraham", "Terah")
	 .addMother("Terah", "e")
         .addMother("e", "f")
	 .addMother("f", "g")
	 .addMother("g", "h")
	 .addMother("h", "i");


           CHECK(T.relation("Avraham") == string("great-grandmother"));
            CHECK(T.relation("Terah") == string("great-great-grandmother"));
            CHECK(T.relation("Yaakov") == string("mother"));
            CHECK(T.relation("Avraham") == string("great-grandmother"));
            CHECK(T.relation("Terah") == string("great-great-grandmother"));
            CHECK(T.relation("e") == string("great-great-great-grandmother"));
            CHECK(T.relation("f") == string("great-great-great-great-grandmother"));
            CHECK(T.relation("g") == string("great-great-great-great-great-grandmother"));
            CHECK(T.relation("h") == string("great-great-great-great-great-great-grandmother"));
            CHECK(T.relation("i") == string("great-great-great-great-great-great-great-grandmother"));
            CHECK(T.find("mother") == string("Yaakov"));
            CHECK(T.find("father") == string("Rachel"));
            CHECK(T.find("grandmother") == string("Isaac"));
            CHECK(T.find("great-grandmother") == string("Avraham"));
            CHECK(T.find("great-great-grandmother") == string("Terah"));
            CHECK(T.find("great-great-great-grandmother") == string("e"));
            CHECK(T.find("great-great-great-great-grandmother") == string("f"));
            CHECK(T.find("great-great-great-great-great-grandmother") == string("g"));
            CHECK(T.find("great-great-great-great-great-great-grandmother") == string("h"));
            CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("i"));

}



TEST_CASE ("Test RELETION") {
     Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
	 .addFather("Terah", "e")
         .addFather("e", "f")
	 .addFather("f", "g")
	 .addFather("g", "h")
	 .addFather("h", "i");


            CHECK(T.relation("Rachel") == string("mother"));
            CHECK(T.relation("Rachel") == string("mother"));
            CHECK(T.relation("Yaakov") == string("father"));
            CHECK(T.relation("Isaac") == string("grandfather"));
            CHECK(T.relation("Avraham") == string("great-grandfather"));
            CHECK(T.relation("Terah") == string("great-great-grandfather"));
            CHECK(T.relation("e") == string("great-great-great-grandfather"));
            CHECK(T.relation("f") == string("great-great-great-great-grandfather"));
            CHECK(T.relation("g") == string("great-great-great-great-great-grandfather"));
            CHECK(T.relation("h") == string("great-great-great-great-great-great-grandfather"));
            CHECK(T.relation("i") == string("great-great-great-great-great-great-great-grandfather"));
            CHECK(T.relation("o") == string("unrelated"));
            CHECK(T.relation("m") == string("unrelated"));
            CHECK(T.relation("n") == string("unrelated"));
            CHECK(T.relation("t") == string("unrelated"));
            CHECK(T.relation("r") == string("unrelated"));
            CHECK(T.relation("l") == string("unrelated"));
            CHECK(T.relation("p") == string("unrelated"));
            CHECK(T.relation("w") == string("unrelated"));

}

TEST_CASE (" TEST FIND") {
    Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
	 .addFather("Terah", "e")
         .addFather("e", "f")
	 .addFather("f", "g")
	 .addFather("g", "h")
	 .addFather("h", "i");

            CHECK(T.find("me") == string("Yosef"));
            CHECK(T.find("father") == string("Yaakov"));
            CHECK(T.find("mother") == string("Rachel"));
            CHECK(T.find("grandfather") == string("Isaac"));
            CHECK(T.find("grandmother") == string("Rivka"));
            CHECK(T.find("great-grandfather") == string("Avraham"));
            CHECK(T.find("great-great-grandfather") == string("Terah"));
            CHECK(T.find("great-great-great-grandfather") == string("e"));
            CHECK(T.find("great-great-great-great-grandfather") == string("f"));
            CHECK(T.find("great-great-great-great-great-grandfather") == string("g"));
            CHECK(T.find("great-great-great-great-great-great-grandfather") == string("h"));
            CHECK(T.find("great-great-great-great-great-great-great-grandfather") == string("i"));

            CHECK_THROWS(T.find("m"));
            CHECK_THROWS(T.find("l"));
            CHECK_THROWS(T.find("u"));
            CHECK_THROWS(T.find("ancle"));
            CHECK_THROWS(T.find("h"));
            CHECK_THROWS(T.find("f"));
            CHECK_THROWS(T.find("yes"));
            CHECK_THROWS(T.find("y"));
            CHECK_THROWS(T.find("hey"));
            CHECK_THROWS(T.find("op"));
            CHECK_THROWS(T.find("8"));
            CHECK_THROWS(T.find("7ey"));
            CHECK_THROWS(T.find("lp"));
}
TEST_CASE ("TEST DELETE") {
     Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah")
	 .addFather("Terah", "e")
         .addFather("e", "f")
	 .addFather("f", "g")
	 .addFather("g", "h")
	 .addFather("h", "i");

    T.remove("Terah");
            CHECK(T.relation("e") == "unrelated");
            CHECK(T.relation("f") == "unrelated");
            CHECK(T.relation("g") == "unrelated");
            CHECK(T.relation("h") == "unrelated");
            CHECK(T.relation("i") == "unrelated");
            CHECK(T.find("father") == string("Yaakov"));
            CHECK(T.find("mother") == string("Rachel"));
            CHECK_THROWS(T.find("e"));
            CHECK_THROWS(T.find("f"));
            CHECK_THROWS(T.find("9"));
            CHECK_THROWS(T.find("0"));

    T.remove("Yaakov");
            CHECK(T.relation("Isaac")== "unrelated");
            CHECK(T.relation("Avraham")== "unrelated");
            CHECK(T.relation("Rivka")== "unrelated");
            CHECK(T.relation("Terah")== "unrelated");
            CHECK_THROWS(T.find("Avraham"));
            CHECK_THROWS(T.find("Rivka"));
    T.remove("Rachel");
            CHECK(T.relation("Rivka")== "unrelated");
            CHECK(T.relation("Yaakov")== "unrelated");
            CHECK(T.relation("Isaac")== "unrelated");
            CHECK(T.relation("Terah")== "unrelated");
            CHECK_THROWS(T.find("Avraham"));
            CHECK_THROWS(T.find("Rivka"));
            CHECK_THROWS(T.find("Rivka"));
            CHECK_THROWS(T.find("Terah"));
            CHECK_THROWS(T.find("g"));
            CHECK_THROWS(T.find("i"));

}