#ifndef FAILAI_H
#define FAILAI_H
#include "MyLib.h"
struct stud{
    string vardas,pavarde;
    vector<int>pazymiai;
    int egzaminas;

};
void Skaitymas(vector<studentas> &temp,std::stringstream &temp2);
void outf(vector<studentas> &temp);
void sukurtifaila(int filesize,int ndsk);
void isskaidymas(vector<studentas> &studentai,int tipas);
void out_failo_sukurimas(vector<studentas> &temp,string tipas);
void tipas2(vector <studentas> &studentai);
void tipas3(vector <studentas> &studentai);
bool paz_skirst(studentas &temp);
bool partition(studentas &temp);
void out_failo_sukurimas3(vector<studentas> &temp,string tipas,vector<studentas>::iterator it);

#endif