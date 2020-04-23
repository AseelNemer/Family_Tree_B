#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace family;
using namespace std;


TEST_CASE ("ADD FATHER") {
    Tree test("uriel");
    test.addFather("uriel", "shimon");
    Tree test2("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    test2.addFather("Yosef", "Yaakov");   // Tells the tree that the father of Yosef is Yaakov.
    test2.addFather("Yaakov", "shlof");
    test2.addFather("shlof", "yFather");
    test2.addFather("yFather", "1Father");
    test2.addFather("1Father", "2Father");
    test2.addFather("2Father", "3Father");
    test2.addFather("3Father", "4Father");
    test.addFather("shimon", "tt");
    test.addFather("tt", "tt2");
    test.addFather("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandfather"));
            CHECK(test.relation("tt2") == string("great-grandfather"));
            CHECK(test.relation("tt3") == string("great-great-grandfather"));
            CHECK(test.relation("shimon") == string("father"));
            CHECK(test2.relation("Yaakov") == string("father"));
            CHECK(test2.relation("shlof") == string("grandfather"));
            CHECK(test2.relation("yFather") == string("great-grandfather"));
            CHECK(test2.relation("1Father") == string("great-great-grandfather"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandfather"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandfather"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandfather"));
            CHECK(test.find("father") == string("shimon"));
            CHECK(test2.find("father") == string("Yaakov"));
            CHECK(test2.find("grandfather") == string("shlof"));
            CHECK(test2.find("great-grandfather") == string("yFather"));
            CHECK(test2.find("great-great-grandfather") == string("1Father"));
            CHECK(test2.find("great-great-great-grandfather") == string("2Father"));
            CHECK(test2.find("great-great-great-great-grandfather") == string("3Father"));
            CHECK(test2.find("great-great-great-great-great-grandfather") == string("4Father"));

}



TEST_CASE ("ADD MOTHER") {
    Tree test("uriel");
    test.addMother("uriel", "shimon");
    Tree test2("Yosef");
    test2.addMother("Yosef", "Yaakov");
    test2.addMother("Yaakov", "shlof");
    test2.addMother("shlof", "yFather");
    test2.addMother("yFather", "1Father");
    test2.addMother("1Father", "2Father");
    test2.addMother("2Father", "3Father");
    test2.addMother("3Father", "4Father");
    test.addMother("shimon", "tt");
    test.addMother("tt", "tt2");
    test.addMother("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandmother"));
            CHECK(test.relation("tt2") == string("great-grandmother"));
            CHECK(test.relation("tt3") == string("great-great-grandmother"));
            CHECK(test.relation("shimon") == string("mother"));
            CHECK(test2.relation("Yaakov") == string("mother"));
            CHECK(test2.relation("shlof") == string("grandmother"));
            CHECK(test2.relation("yFather") == string("great-grandmother"));
            CHECK(test2.relation("1Father") == string("great-great-grandmother"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandmother"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandmother"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandmother"));
            CHECK(test.find("mother") == string("shimon"));
            CHECK(test2.find("mother") == string("Yaakov"));
            CHECK(test2.find("grandmother") == string("shlof"));
            CHECK(test2.find("great-grandmother") == string("yFather"));
            CHECK(test2.find("great-great-grandmother") == string("1Father"));
            CHECK(test2.find("great-great-great-grandmother") == string("2Father"));
            CHECK(test2.find("great-great-great-great-grandmother") == string("3Father"));
            CHECK(test2.find("great-great-great-great-great-grandmother") == string("4Father"));

}



TEST_CASE ("RELETION") {
    Tree test("uriel");
    test.addMother("uriel", "shimon");
    Tree test2("Yosef");
    test2.addMother("Yosef", "Yaakov");
    test2.addMother("Yaakov", "shlof");
    test2.addMother("shlof", "yFather");
    test2.addMother("yFather", "1Father");
    test2.addMother("1Father", "2Father");
    test2.addMother("2Father", "3Father");
    test2.addMother("3Father", "4Father");
    test.addMother("shimon", "tt");
    test.addMother("tt", "tt2");
    test.addMother("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandmother"));
            CHECK(test.relation("tt2") == string("great-grandmother"));
            CHECK(test.relation("tt3") == string("great-great-grandmother"));
            CHECK(test.relation("shimon") == string("mother"));
            CHECK(test2.relation("Yaakov") == string("mother"));
            CHECK(test2.relation("shlof") == string("grandmother"));
            CHECK(test2.relation("yFather") == string("great-grandmother"));
            CHECK(test2.relation("1Father") == string("great-great-grandmother"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandmother"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandmother"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandmother"));
            CHECK(test.relation("1") == string("unrelated"));
            CHECK(test2.relation("yaakov") == string("unrelated"));
            CHECK(test2.relation("1father") == string("unrelated"));
            CHECK(test2.relation("4") == string("unrelated"));
            CHECK(test2.relation("2father") == string("unrelated"));
            CHECK(test2.relation("6") == string("unrelated"));
            CHECK(test2.relation("7mother") == string("unrelated"));
            CHECK(test2.relation("8") == string("unrelated"));

}

TEST_CASE ("find") {
    Tree test("yair");
    Tree test2("ori");
    test2.addMother("ori", "dafna");
    test2.addMother("dafna","yona");
    test2.addFather("ori","fredi");
    test2.addFather("fredi","albert");
    test2.addMother("fredi", "lusi");
    test2.addFather("dafna", "ezra");
    test.addMother("yair", "ester");
    test.addMother("ester", "ren");
    test.addFather("yair", "michael");
    test.addMother("michael", "mami");
    test.addFather("ester", "albert");
    test.addFather("michael","shimon");

            CHECK(test.find("son") == string("yair"));
            CHECK(test.find("father") == string("michael"));
            CHECK(test.find("mother") == string("ester"));
            CHECK(test.find("grandfather") == string("shimon"));
            CHECK(test.find("grandmother") == string("mami"));
            CHECK(test2.find("son") == string("ori"));
            CHECK(test2.find("father") == string("fredi"));
            CHECK(test2.find("mother") == string("dafna"));
            CHECK(test2.find("grandfather") == string("albert"));
            CHECK(test2.find("grandmother") == string("lusi"));
            CHECK(test.find("aa") == string("The tree cannot handle the aa relation"));
            CHECK(test.find("boy") == string("The tree cannot handle the boy relation"));
            CHECK(test.find("Yair") == string("The tree cannot handle the Yair relation"));
            CHECK(test.find("shi") == string("The tree cannot handle the shi relation"));
            CHECK(test.find("nod") == string("The tree cannot handle the nod relation"));
            CHECK(test2.find("abergel") == string("The tree cannot handle the abergel relation"));
            CHECK(test2.find("yes") == string("The tree cannot handle the yes relation"));
            CHECK(test2.find("nice") == string("The tree cannot handle the nice relation"));
            CHECK(test2.find("lama") == string("The tree cannot handle the lama relation"));
            CHECK(test2.find("kaha") == string("The tree cannot handle the kaha relation"));
}
TEST_CASE ("delete") {
    Tree semama("yair");
    Tree elia("ori");
    Tree goldis("shlomo");
    elia.addMother("ori", "dafna");
    elia.addMother("dafna", "yona");
    elia.addFather("ori", "fredi");
    elia.addFather("fredi", "albert");
    elia.addMother("fredi", "lusi");
    elia.addFather("dafna", "ezra");
    semama.addMother("yair", "ester");
    semama.addMother("ester", "ren");
    semama.addFather("yair", "michael");
    semama.addMother("michael", "mami");
    semama.addFather("ester", "albert");
    semama.addFather("michael", "shimon");
    elia.remove("ori");
            CHECK(elia.relation("ori") == "unrelated");
            CHECK(elia.relation("fredi") == "unrelated");
            CHECK(elia.relation("dafna") == "unrelated");
            CHECK(elia.relation("ezra") == "unrelated");
            CHECK(elia.relation("yona") == "unrelated");
            CHECK(elia.relation("lusi") == "unrelated");
            CHECK(elia.relation("albert") == "unrelated");
            CHECK(elia.find("son") == "The tree cannot handle the son relation");
            CHECK(elia.find("father") == "The tree cannot handle the father relation");
            CHECK(elia.find("mother") == "The tree cannot handle the mother relation");
            CHECK(elia.find("grandfather") == "The tree cannot handle the grandfather relation");
            CHECK(elia.find("grandmother") == "The tree cannot handle the grandmother relation");
    semama.remove("ester");
            CHECK(semama.relation("ester")== "unrelated");
            CHECK(semama.relation("ren")== "unrelated");
            CHECK(semama.relation("albert")== "unrelated");
            CHECK(semama.relation("yair")== "me");
    semama.remove("yair");
            CHECK(semama.relation("yair")== "unrelated");
            CHECK(semama.relation("michael")== "unrelated");
            CHECK(semama.relation("mami")== "unrelated");
            CHECK(semama.relation("shimon")== "unrelated");
            CHECK(semama.find("son") == "The tree cannot handle the son relation");
            CHECK(semama.find("father") == "The tree cannot handle the father relation");
            CHECK(semama.find("mother") == "The tree cannot handle the mother relation");
            CHECK(semama.find("grandfather") == "The tree cannot handle the grandfather relation");
            CHECK(semama.find("grandmother") == "The tree cannot handle the grandmother relation");

}