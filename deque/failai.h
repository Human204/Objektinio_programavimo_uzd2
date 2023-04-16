#ifndef FAILAI_H
#define FAILAI_H
#include "MyLib.h"
struct stud{
    string vardas,pavarde;
    vector<int>pazymiai;
    int egzaminas;

};
void Skaitymas(deque<studentas> &temp,std::stringstream &temp2);
void outf(deque <studentas> &temp);
void sukurtifaila(int filesize,int ndsk);
void isskaidymas(deque<studentas> &studentai,int tipas);
void out_failo_sukurimas(deque<studentas> &temp,string tipas);
void tipas2(deque <studentas> &studentai);

#endif