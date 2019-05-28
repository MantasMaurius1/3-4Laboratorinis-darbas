#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <fstream>
#include <exception>
#include <random>
#include <chrono>

using namespace std;
using std::vector;
using namespace std::chrono;

struct studentas
{
    string vardas, pavarde;
    double egz;
    vector<double> ndm, vdrk, galutv, galutm;
};

double nd; char uzkl='t'; string budas; char A[9999];
vector<studentas> lent; studentas temp;

void skaiciavimai(){
sort(temp.ndm.begin(), temp.ndm.end());
temp.vdrk.push_back((accumulate(temp.ndm.begin() , temp.ndm.end(), 0))/(temp.ndm.size()));  //Galutinis su vidurkiu
temp.galutv.push_back((temp.vdrk.back()*0.4)+(temp.egz*0.6));
size_t size=temp.ndm.size();                                                                //Galutinis su mediana
if (size%2==0)
{
temp.galutm.push_back((((temp.ndm[size/2-1]+temp.ndm[size/2])/2)*0.4)+(temp.egz*0.6));
}
else
{
temp.galutm.push_back(((temp.ndm[size/2])*0.4)+(temp.egz*0.6));
}
lent.push_back(temp);
temp.ndm.clear();
temp.vdrk.clear();
temp.galutv.clear();
temp.galutm.clear();
}

int main()
{
BUDAS: cout<<"Iveskite programos veikimo buda(rankinis,isfailo,atsitiktinis)"<<endl;
cin>>budas;
if (budas=="rankinis")                                                                        //Rankinis ivedimas
{
while (uzkl!='n')
{
cout<<"Iveskite studento varda"<<endl;
cin>>temp.vardas;
cout<<"Iveskite studento pavarde"<<endl;
cin>>temp.pavarde; nd=1;
cout<<"Iveskite namu darbu rezultatus(ivede 0 pereisite prie sekancio etapo)"<<endl;         //Namu darbu ivedimo ciklas
while(nd!=0)
{
ND:cin.clear(); cin.ignore(256,'\n');
cin>>nd;
if(nd>0&&nd<=10)
{
temp.ndm.push_back(nd);
temp.ndm.size();
}
else if (nd==0){
if (temp.ndm.size()==0)
{
cout<<"Neivesti namu darbai"<<endl;
cout<<"Iveskite namu darbu rezultatus(ivede 0 pereisite prie sekancio etapo)"<<endl;
goto ND;
}
}
else
{
cout<<"Klaida"<<endl;
cout<<"Namu darbu rezultatai tik desimtbaleje sistemoje"<<endl;
}
}
cout<<"Iveskite studento egzamino rezultata"<<endl;                                          //Egzamino ivedimas
EGZ:cin.clear(); cin.ignore(256,'\n');
cin>>temp.egz;
if(temp.egz>0&&temp.egz<=10){}
else
{
cout<<"Klaida"<<endl;
cout<<"Egzamino rezultatas, tik desimtbaleje sistemoje"<<endl;
cout<<"Iveskite studento egzamino rezultata"<<endl;
goto EGZ;
}
cout<<"Norint baigti ivedima, iveskite n"<<endl;
cin>>uzkl;
auto start = high_resolution_clock::now();
skaiciavimai();
auto end = high_resolution_clock::now();
duration<double> diff= end-start;
cout<<"Programos veikimo laikas: "<<duration_cast<milliseconds>(end-start).count()<<" msec"<<endl;
}
}
else if (budas=="isfailo")                                                                    //Ivedimas is failo
{
auto start = high_resolution_clock::now();
ifstream is;
is.open("kursiokai.txt");
if(is.fail())
{
cout<<"Failo atverti nepavyko"<<endl;
exit(-1);
}
else
{
is.ignore(58);
while(is.get(*A)){
is>>temp.vardas>>temp.pavarde;
while(temp.ndm.size()!=5){
is>>nd;                                                                                  //Namu darbu ivedimo ciklas
temp.ndm.size();
temp.ndm.push_back(nd);
}
is>>temp.egz;
skaiciavimai();
}
}
auto end = high_resolution_clock::now();
duration<double> diff= end-start;
cout<<"Programos veikimo laikas: "<<duration_cast<milliseconds>(end-start).count()<<" msec"<<endl;
}
else if (budas=="atsitiktinis")
{
cout<<"Iveskite studentu skaiciu, kuriu duomenis generuosime atsitiktiniu budu"<<endl;
int randsk;
cin>>randsk;
random_device rd;
mt19937 eng(rd());
uniform_int_distribution<> distr(1,10);
ofstream os;
os.open("gg.txt");
auto start = high_resolution_clock::now();
for(int i=0;i<randsk;i++){
temp.vardas="Vardas";
temp.vardas+=to_string(i);
temp.pavarde="Pavarde";
temp.pavarde+=to_string(i);
for(int j=0;j<5;j++){
nd=distr(eng);
temp.ndm.push_back(nd);
}
temp.egz=distr(eng);
skaiciavimai();
}
auto end = high_resolution_clock::now();
duration<double> diff= end-start;
cout<<"Programos veikimo laikas: "<<duration_cast<milliseconds>(end-start).count()<<" msec"<<endl;
os<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis(Med.)"<<endl;
os<<"-"<<setfill('-')<<setw(53)<<"-"<<endl;
for(auto i: lent)
{
for(auto v: i.galutv)
for(auto m: i.galutm)
os<<left<<setfill(' ')<<setw(10)<<i.vardas<<setfill(' ')<<setw(10)<<i.pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<v<<setfill(' ')<<setw(18)<<right<<fixed<<setprecision(2)<<m<<endl;
}
temp.vardas.clear();
temp.pavarde.clear();
}
else
{
cout<<"Klaida"<<endl;
goto BUDAS;
}
cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis(Med.)"<<endl; // Isvedimas
cout<<"-"<<setfill('-')<<setw(53)<<"-"<<endl;
for(auto i: lent)
{
for(auto v: i.galutv)
for(auto m: i.galutm)
cout<<left<<setfill(' ')<<setw(10)<<i.vardas<<setfill(' ')<<setw(10)<<i.pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<v<<setfill(' ')<<setw(18)<<right<<fixed<<setprecision(2)<<m<<endl;
}
return 0;
}
