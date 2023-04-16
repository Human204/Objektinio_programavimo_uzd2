#include "MyLib.h"
#include "skaiciavimai.h"
#include "failai.h"
#include "studentas.h"
void Skaitymas(vector<Studentasc> &temp,std::stringstream &temp2){
  int tipas;
  cout<<"Kuria strategija naudoti?(1/2/3)";cin>>tipas;
  int temp_paz,l=0;
  // Studentasc temp3;
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
  while(!temp2.eof()){
      Studentasc temp3(temp2,l);
      temp.push_back(temp3);
  }
  cout<<"Failo skaitymas uztruko: "<<t_failas.elapsed()<<endl;
  isskaidymas(temp,tipas);
  cout<<"Visas programos laikas: "<<t_vis.elapsed()<<endl;
  
}

void outf(vector<Studentasc> &temp){
  ofstream fout ("out.txt");
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(16)<<"Galutinis (Vid.) "<<setw(16)<<"Galutinis (Med.)\n";
  fout<<"---------------------------------------------------------------\n";
    for(int i=0;i<temp.size();i++){
      std::stringstream str = temp[i].output_string();
      string tekstas=str.str();
      fout<<tekstas;
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

void isskaidymas(vector<Studentasc> &studentai,int tipas){
  bool skaidymo_zenkl=false;
  Timer t_dal;
  if(tipas==2) tipas2(studentai);
  else if(tipas==3)tipas3(studentai);
  else{
    sort(studentai.begin(),studentai.end()-1,palygintigalutiniusalt);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<Studentasc> cringe,based;
    cringe.reserve(studentai.size()*0.7);based.reserve(studentai.size()*0.7);
    for(Studentasc &i : studentai){
      if(i.getGal()<5){
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

void out_failo_sukurimas(vector<Studentasc> &temp,string tipas){
  string file;
  std::stringstream ss;
  ss<<tipas<<".txt";
  file=ss.str();
  ofstream fout(file);
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(13)<<"Gal vid\n";
  fout<<"-----------------------------------------------\n";
  for(Studentasc i:temp){
    fout<<setw(15)<<left<<i.getVardas()<<setw(15)<<left<<i.getPavarde();
    fout.precision(2);
    fout<<std::fixed;
    fout<<i.getGal()<<'\n';
  }
}

void tipas2(vector <Studentasc> &studentai){
  Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutinius);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<Studentasc> cringe;
    cringe.reserve(studentai.size()*0.7);
    vector<Studentasc>::size_type j = 0;
    for(int i=studentai.size();i>=0;i--){
      if(studentai[i].getGal()<5){
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

void tipas3(vector <Studentasc> &studentai){
    Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutiniusalt);
  // vector<Studentasc>::iterator it=partition(studentai.begin(),studentai.end(),partition);
    cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
    t_dal.reset();
    vector<Studentasc>::size_type j = 0;
    vector<Studentasc>::iterator it =find_if(studentai.begin(),studentai.end(),paz_skirst);
    // vector<Studentasc> cringe;
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
bool paz_skirst(Studentasc &temp){
  return((temp.getGal()==5.0));
}
bool partition(Studentasc &temp){
  return(temp.getGal()<5);
}

void out_failo_sukurimas3(vector<Studentasc> &temp,string tipas,vector<Studentasc>::iterator it){
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
      tekstas=it->output_string();
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
      tekstas=it->output_string();
    }
    string tekstas2=tekstas.str();
    tekstas.str(string());tekstas.clear();
    fout<<tekstas2;
    tekstas2.clear();
  }
}