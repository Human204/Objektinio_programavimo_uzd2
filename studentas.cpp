#include "studentas.h"
#include<iostream>
Studentasc::Studentasc(const Studentasc &other){
  this->vardas=other.vardas;
  this->pavarde=other.pavarde;
  this->egz=other.egz;
  this->gal_vid=other.gal_vid;
  this->galutinis2=other.galutinis2;
  this->galutinis=other.galutinis;
  this->med=other.med;
  this->paz=other.paz;
  this->vid=other.vid;
}

Studentasc& Studentasc::operator=(Studentasc &other){
  if(this==&other){
    return *this;
  }
  else{
    this->vardas=other.vardas;
    this->pavarde=other.pavarde;
    this->egz=other.egz;
    this->gal_vid=other.gal_vid;
    this->galutinis2=other.galutinis2;
    this->galutinis=other.galutinis;
    this->med=other.med;
    this->paz=other.paz;
    this->vid=other.vid;
    return *this;
  }
}

Studentasc::Studentasc(Studentasc &&other){
  // cout<<"movec\n";
    vardas=other.vardas;
    pavarde=other.pavarde;
    egz=other.egz;
    gal_vid=other.gal_vid;
    galutinis2=other.galutinis2;
    galutinis=other.galutinis;
    med=other.med;
    cout<<"1"<<endl;
    // this->paz=other.paz;
    if(other.paz.size()!=0)
    paz=std::move(other.paz);
    vid=other.vid;
    cout<<"2\n";
    // other.vardas=nullptr;
    // other.pavarde=nullptr;
    // other.paz.clear();
    if(other.paz.size()!=0)paz=std::move(other.paz);
    // delete &other;
    cout<<"3\n";
}

Studentasc& Studentasc::operator=(Studentasc &&other){
  // cout<<"move\n";
  if(this==&other){
    return *this;
  }
  else{
    this->vardas=other.vardas;
    this->pavarde=other.pavarde;
    this->egz=other.egz;
    this->gal_vid=other.gal_vid;
    this->galutinis2=other.galutinis2;
    this->galutinis=other.galutinis;
    this->med=other.med;
    if(other.paz.size()!=0)
    this->paz=other.paz;
    this->vid=other.vid;
    // other.vardas=nullptr;
    // other.pavarde=nullptr;
    if(other.paz.size()!=0)this->paz=std::move(other.paz);
    return *this;
  }
}

vector<int>::iterator Studentasc::iterators(string &type){
    vector<int>::iterator it;
    if(type=="begin"){
        it=paz.begin();
    }
    else if(type=="end"){
        it=paz.end();
    }
    return it;
}

double Studentasc::mediana(){
double mm=paz.size();
  sort(paz.begin(),paz.end()-1);
  if(paz.size()%2!=0){med=paz.at((paz.size()/2));}
  else{
   med=(paz.at((paz.size()-1)/2)+paz.at(((paz.size()/2))))/2.0;
  }
  return med;
}

double Studentasc::vidurkis(){
    double paz_sum=0.0;
  double mm=paz.size();
  if(paz.size()==0){
    vid=0.0;
  }
  else{
    for(int i=0;i<mm;i++){
      paz_sum+=paz.at(i);
    }
    vid=paz_sum/(mm);
  }
  return vid;
}

void Studentasc::galutinio_skaiciavimai(string tipas){
    if(tipas=="vid"){
    galutinis=(vid*0.4+egz*0.6);
  }
  else if(tipas=="med"){
    galutinis=(med*0.4+egz*0.6);
  }
  else if(tipas=="failas"){
    galutinis=(vid*0.4+egz*0.6);
    galutinis2=(med*0.4+egz*0.6);
  }
}

Studentasc::Studentasc(std::stringstream& str,int &l){
    int temp_paz=0;
    str>>vardas>>pavarde;
      for(int i=0;i<l;i++){
      paz.reserve(l);
      str>>temp_paz;
      paz.push_back(temp_paz);
      temp_paz=0;
    }
    str>>egz;
    med=mediana();
    vid=vidurkis();
    paz.clear();
    galutinio_skaiciavimai("failas");
}

std::stringstream Studentasc::output_string(){
    std::stringstream str;
    str<<left<<setw(15)<<vardas<<setw(15)<<pavarde<<setw(16);
    str.precision(2);
    str<<std::fixed;
    str<<galutinis;
    return str;
}

ostream &operator<<(std::ostream &out, const Studentasc &to_print){
  out<<to_print.vardas<<" "<<to_print.pavarde<<" "<<to_print.galutinis<<endl;
  return out;
}

