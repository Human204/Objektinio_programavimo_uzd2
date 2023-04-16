#include "MyLib.h"
#include "skaiciavimai.h"
#include "failai.h"

void Skaitymas(deque<studentas> &temp,std::stringstream &temp2){
  int temp_paz,l=0,tipas;
  cout<<"Kuria strategija naudot?(1/2)";cin>>tipas;
  studentas temp3;
  string check,tp;
  temp2>>check>>check;
  while(true){
    temp2>>check;
    if(check[0]=='N')l++;
    else{
      break;
    } 
  }
  Timer t_failas,t_vis;
  while(temp2>>temp3.vardas>>temp3.pavarde){
      for(int i=0;i<l;i++){
      temp2>>temp_paz;
      temp3.paz.push_back(temp_paz);
      temp_paz=0;
    }
    temp2>>temp3.egz;
    mediana(temp3);
    vidurkis(temp3);
    temp3.paz.clear();
    galutinis(temp3,"failas");
    temp.push_back(temp3);
  }
  cout<<"Failo skaitymas uztruko: "<<t_failas.elapsed()<<endl;
  isskaidymas(temp,tipas);
  cout<<"Visas programos laikas: "<<t_vis.elapsed()<<endl;
  
}

void outf(deque<studentas> &temp){
  ofstream fout ("out.txt");
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(16)<<"Galutinis (Vid.) "<<setw(16)<<"Galutinis (Med.)\n";
  fout<<"---------------------------------------------------------------\n";
    for(int i=0;i<temp.size();i++){
      // cout<<temp[i].vardas<<endl;
      fout<<left<<setw(15)<<temp[i].vardas<<setw(15)<<temp[i].pavarde<<setw(16);
      fout.precision(2);
      fout<<std::fixed;
      fout<<temp[i].galutinis;
      fout<<" "<<setw(16);
      fout.precision(2);
      fout<<std::fixed;
      fout<<temp[i].galutinis2<<'\n';
    }
    
    fout.close();
}

void sukurtifaila(int filesize,int ndsk){
  int temp_egz;
  std::random_device rd;
  std::mt19937 mt (rd());
  std::uniform_int_distribution<int> dist(0,10);
  std::stringstream ss,nd;
  int paz_temp;
  double laikas;
  Timer t_dal;
  ss<<"Stud"<<filesize<<".txt";
  string failas = ss.str(),nd_tekstas;
  ofstream fout (failas);
  fout<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde";
  for(int i=0;i<ndsk;i++){
    nd<<"ND"<<(i+1);
    nd_tekstas=nd.str();
    fout<<setw(4)<<left<<nd_tekstas;
    nd.str(string());nd.clear();
  }
  fout<<setw(4)<<left<<"Egz.\n";
  std::stringstream vardas, pavarde;
  for(int i=0;i<filesize;i++){
    vardas<<"Vardas"<<(i+1);
    pavarde<<"Pavarde"<<(i+1);
    fout<<setw(15)<<left<<vardas.str()<<setw(15)<<left<<pavarde.str();
    for(int j=0;j<ndsk;j++){
      fout<<setw(4)<<left<<dist(mt);
      paz_temp=0;
    }
    fout<<setw(4)<<left<<dist(mt)<<'\n';
    vardas.str(string());vardas.clear();
    pavarde.str(string());pavarde.clear();
  }
  fout.close();
  cout<<"Failo kurimas uztruko: "<<t_dal.elapsed()<<endl;
}

void isskaidymas(deque<studentas> &studentai,int tipas){
  bool skaidymo_zenkl=false;
  Timer t_dal;
  if(tipas==2) tipas2(studentai);
  else{
    sort(studentai.begin(),studentai.end()-1,palygintigalutinius);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    deque<studentas> cringe,based;
    for(studentas &i : studentai){
      if(i.galutinis<5){
        cringe.push_back(i);
      }
      else based.push_back(i);
    }
    studentai.clear();
    cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    out_failo_sukurimas(cringe,"cringe");
    t_dal.reset();
    out_failo_sukurimas(based,"based");
    cringe.clear();
    based.clear();
  }
}

void out_failo_sukurimas(deque<studentas> &temp,string tipas){
  string file;
  std::stringstream ss;
  ss<<tipas<<".txt";
  file=ss.str();
  ofstream fout(file);
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(13)<<"Gal vid\n";
  fout<<"-----------------------------------------------\n";
  for(int i=0;i<temp.size();i++){
    fout<<setw(15)<<left<<temp[i].vardas<<setw(15)<<left<<temp[i].pavarde;
    fout.precision(2);
    fout<<std::fixed;
    fout<<temp[i].galutinis<<'\n';
  }
}

void tipas2(deque <studentas> &studentai){
  Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutinius);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    deque<studentas> cringe;
    for(studentas &i:studentai){
      if(i.galutinis<5){
        cringe.push_back(i);
        studentai.pop_front();
      }
    }
    cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    out_failo_sukurimas(cringe,"cringe");
    t_dal.reset();
    out_failo_sukurimas(studentai,"based");
    cringe.clear();
    studentai.clear();
}