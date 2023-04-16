#include "MyLib.h"
#include "skaiciavimai.h"

void vidurkis(studentas &temp){
  double paz_sum=0.0;
  double mm=temp.paz.size();
  list<int>::iterator iterator=temp.paz.begin();
  if(temp.paz.size()==0){
    temp.vid=0.0;
  }
  else{
    for(int i=0;i<mm;i++){
      paz_sum+=*iterator;
      iterator++;
    }
    temp.vid=paz_sum/(mm);
  }
}

void mediana(studentas &temp){
  double mm=temp.paz.size(),tempmed1,tempmed2;
  temp.paz.sort();
  list<int>::iterator iterator=temp.paz.begin();
  if(temp.paz.size()%2!=0)
  {
    int i2=temp.paz.size()/2,i=0;
    while(true){
      i++;
      iterator++;
      if(i==i2){
        temp.med=*iterator;
        // cout<<temp.med<<endl;
        break;
      }
    }
    
  }
  else{
   while(true){
      int i2=((temp.paz.size()-1)/2),i3=((temp.paz.size())/2),i=0;
      i++;
      iterator++;
      if(i==i2){
        tempmed1=*iterator;
        iterator++;
        tempmed2=*iterator;
        break;
      }
    }
    temp.med=(tempmed1+tempmed2)/2.0;
  }
}

void galutinis(studentas &temp,string tipas){
  if(tipas=="vid"){
    temp.galutinis=(temp.vid*0.4+temp.egz*0.6);
  }
  else if(tipas=="med"){
    temp.galutinis=(temp.med*0.4+temp.egz*0.6);
  }
  else if(tipas=="failas"){
    temp.galutinis=(temp.vid*0.4+temp.egz*0.6);
    temp.galutinis2=(temp.med*0.4+temp.egz*0.6);
  }
}
bool palygintivardus(studentas& a, studentas& b){
  return tie(a.vardas,a.pavarde)<tie(b.vardas,b.pavarde);
}
bool palygintigalutinius(studentas& a,studentas& b){
  return a.galutinis<b.galutinis;
}
bool palygintigalutiniusalt(studentas& a,studentas& b){
  return a.galutinis>b.galutinis;
}