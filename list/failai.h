#ifndef FAILAI_H
#define FAILAI_H
#include "MyLib.h"
struct stud{
    string vardas,pavarde;
    vector<int>pazymiai;
    int egzaminas;

};
void Skaitymas(list<studentas> &temp,std::stringstream &temp2);
void outf(list<studentas> &temp);
void sukurtifaila(int filesize,int ndsk);
void isskaidymas(list<studentas> &studentai,int tipas);
void out_failo_sukurimas(list<studentas> &temp,string tipas);
void tipas2(list<studentas>&studentai);

#endif