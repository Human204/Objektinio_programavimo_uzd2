#include "MyLib.h"
#include "skaiciavimai.h"
#include "studentas.h"


bool palygintivardus(Studentasc& a, Studentasc& b){
  string a_vardas=a.getVardas(),a_pavarde=a.getPavarde(),b_vardas=b.getVardas(),b_pavarde=b.getPavarde();
  return tie(a_vardas,a_pavarde)<tie(b_vardas,b_pavarde);
}
bool palygintigalutinius(Studentasc& a,Studentasc& b){
  return a.getGal()>b.getGal();
}
bool palygintigalutiniusalt(Studentasc& a,Studentasc& b){
  return a.getGal()<b.getGal();
}