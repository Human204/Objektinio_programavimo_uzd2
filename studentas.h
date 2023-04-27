#ifndef STUDENTAS_H
#define STUDENTAS_H

// #include<iostream>
// #include<fstream>
// #include<ostream>
#include "MyLib.h"
using std::ostream;
class Humanc{
        private:
    string vardas,pavarde;
    public:
        Humanc(){vardas="";pavarde="";}
        inline string getVardas() const {return vardas;}
        inline string getPavarde() const {return pavarde;}
        inline void readvarpav(std::istream& in){in>>vardas>>pavarde;}
        inline void setVardas(string temp){vardas=temp;}
        inline void setPavarde(string temp){pavarde=temp;}
        virtual void f()=0;
        ~Humanc(){
            vardas="";
            pavarde="";
        }
    
};
class Studentasc:public Humanc{
private:
    vector<int> paz;
    int egz;
    double vid;
    double med;
    double galutinis;
    double galutinis2;
    double gal_vid;
public:
    Studentasc():egz(0),vid(0.0),med(0.0),galutinis(0.0),galutinis2(0.0),gal_vid(0.0),Humanc(){}
    Studentasc(std::stringstream& str,int &l);
    Studentasc(const Studentasc &other);
    Studentasc(Studentasc &&other);
    
    // getteriai
    
    inline double getGal() const{return galutinis;}

    // setteriai
    inline void galbalas(double temp) {galutinis=temp;}
    inline void setEgz(int &e){egz=e;}
    inline void InsertPaz(int &p){paz.push_back(p);}
    inline void RemovePaz(){paz.pop_back();}
    
    void readAll(std::stringstream &str);
    inline void readEgz(std::istream& in){in>>egz;}
    vector<int>::iterator iterators(string &type);
    double mediana();
    double vidurkis();
    void galutinio_skaiciavimai(string tipas);
    Studentasc& operator=(Studentasc &other);
    Studentasc& operator=(Studentasc &&other);
    friend ostream &operator<<(ostream &out,const Studentasc &to_print);
    std::stringstream output_string();
    virtual void f(){egz=egz;}
    // destruktorius
    ~Studentasc(){
        paz.clear();
    }
    


};

#endif