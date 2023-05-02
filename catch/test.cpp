#include "catch_amalgamated.hpp"
#include "../failai.h"
#include "../skaiciavimai.h"
#include "../studentas.h"
// #include "../main.cpp"
TEST_CASE("medianos skaiciavimas","[mediana]"){
    Studentasc a,b,c;
    for(int i=0;i<5;i++) a.InsertPaz(i);
    for(int i=0;i<1000;i++) b.InsertPaz(i);
    for(int i=0;i<3628800;i++) c.InsertPaz(i);
    REQUIRE(a.mediana()==2.0);
    REQUIRE(b.mediana()==499.5);
    REQUIRE(c.mediana()==1814399.5);
}
TEST_CASE("vidurkio skaiciavimas","[vidurkis]"){
    Studentasc a,b,c;
    for(int i=0;i<5;i++) a.InsertPaz(i);
    for(int i=0;i<1000;i++) b.InsertPaz(i);
    for(int i=0;i<3628800;i++) c.InsertPaz(i);
    REQUIRE(a.vidurkis()==2.0);
    REQUIRE(b.vidurkis()==499.5);
    REQUIRE(c.vidurkis()==1814399.5);
}
TEST_CASE("failu skaitymas","[failai]"){
    Timer t_vis;
    vector<Studentasc> studentas;
    std::stringstream input("1");
    std::streambuf* orig_cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
    ifstream fin("Stud1000000.txt");
    std::stringstream read;
    read<<fin.rdbuf();
    fin.close();
    REQUIRE_NOTHROW(Skaitymas(studentas,read,t_vis));
}