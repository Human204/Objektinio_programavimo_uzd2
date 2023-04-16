#include "MyLib.h"
#include "skaiciavimai.h"
#include "failai.h"

void Skaitymas(vector<studentas> &temp,std::stringstream &temp2){
  int tipas;
  cout<<"Kuria strategija naudoti?(1/2/3)";cin>>tipas;
  int temp_paz,l=0;
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
      temp3.paz.reserve(l);
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

void outf(vector<studentas> &temp){
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

void isskaidymas(vector<studentas> &studentai,int tipas){
  bool skaidymo_zenkl=false;
  Timer t_dal;
  if(tipas==2) tipas2(studentai);
  else if(tipas==3)tipas3(studentai);
  else{
    sort(studentai.begin(),studentai.end()-1,palygintigalutiniusalt);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<studentas> cringe,based;
    cringe.reserve(studentai.size()*0.7);based.reserve(studentai.size()*0.7);
    for(studentas &i : studentai){
      if(i.galutinis<5){
        cringe.push_back(i);
      }
      else based.push_back(i);
    }
    cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
    studentai.clear();
    t_dal.reset();
    out_failo_sukurimas(cringe,"cringe");
    cout<<"'Cringe' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    out_failo_sukurimas(based,"based");
    cout<<"'Based' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
    cringe.clear();based.clear();
  }

}

void out_failo_sukurimas(vector<studentas> &temp,string tipas){
  string file;
  std::stringstream ss;
  ss<<tipas<<".txt";
  file=ss.str();
  ofstream fout(file);
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(13)<<"Gal vid\n";
  fout<<"-----------------------------------------------\n";
  for(studentas i:temp){
    fout<<setw(15)<<left<<i.vardas<<setw(15)<<left<<i.pavarde;
    fout.precision(2);
    fout<<std::fixed;
    fout<<i.galutinis<<'\n';
  }
}

void tipas2(vector <studentas> &studentai){
  Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutinius);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<studentas> cringe;
    cringe.reserve(studentai.size()*0.7);
    vector<studentas>::size_type j = 0;
    for(int i=studentai.size();i>=0;i--){
      if(studentai[i].galutinis<5){
        cringe.push_back(studentai[i]);
        studentai.pop_back();
      }
    }
    cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    out_failo_sukurimas(cringe,"cringe");
    cout<<"'Cringe' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    out_failo_sukurimas(studentai,"based");
    cout<<"'Based' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
    cringe.clear();
    studentai.clear();
}

void tipas3(vector <studentas> &studentai){
    Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutiniusalt);
  // vector<studentas>::iterator it=partition(studentai.begin(),studentai.end(),partition);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<studentas>::size_type j = 0;
    vector<studentas>::iterator it =find_if(studentai.begin(),studentai.end(),paz_skirst);
    // vector<studentas> cringe;
    // int cringe_size=studentai.end()-it-1;
    // int cringe_size=it-studentai.begin()-1;
    // cringe.resize(cringe_size);
    //partition dalis
    // copy(studentai.begin(),it-1,cringe.begin());
    // studentai.erase(studentai.begin(),it-1);
    //partition dalis

    //find dalis
    // copy(it,studentai.end()-1,cringe.begin());
    // studentai.erase(it,studentai.end());
     //find dalis

    cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    // out_failo_sukurimas(cringe,"cringe");
    out_failo_sukurimas3(studentai,"cringe",it);
    // cringe.clear();
    out_failo_sukurimas3(studentai,"based",it);
    studentai.clear();

}
bool paz_skirst(studentas &temp){
  return((temp.galutinis==5.0));
}
bool partition(studentas &temp){
  return(temp.galutinis<5);
}

void out_failo_sukurimas3(vector<studentas> &temp,string tipas,vector<studentas>::iterator it){
  string file;
  std::stringstream ss;
  ss<<tipas<<".txt";
  file=ss.str();
  ofstream fout(file);
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(13)<<"Gal vid\n";
  fout<<"-----------------------------------------------\n";
  if(tipas=="based"){
    std::stringstream tekstas;
    for(;it<temp.end();++it){
      tekstas<<setw(15)<<left<<it->vardas<<setw(15)<<left<<it->pavarde;
      tekstas.precision(2);
      tekstas<<std::fixed;
      tekstas<<it->galutinis<<'\n';
    }
    string tekstas2=tekstas.str();
    tekstas.str(string());tekstas.clear();
    fout<<tekstas2;
    tekstas2.clear();
  }
  else if(tipas=="cringe"){
    std::stringstream tekstas;
    it--;
    for(;it>temp.begin();--it){
      tekstas<<setw(15)<<left<<it->vardas<<setw(15)<<left<<it->pavarde;
      tekstas.precision(2);
      tekstas<<std::fixed;
      tekstas<<it->galutinis<<'\n';
    }
    string tekstas2=tekstas.str();
    tekstas.str(string());tekstas.clear();
    fout<<tekstas2;
    tekstas2.clear();
  }
}