#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;
using std::vector;

struct studentas
{

    string vardas, pavarde;
    double egz;
    vector<double> ndm, vdrk, galutv, galutm;
};
int main()
{
ifstream is;
is.open("kursiokai.txt");
double nd; char uzkl='t'; string budas;
vector<studentas> lent; studentas temp;
cout<<"Iveskite programos veikimo buda(rankinis,isfailo,atsitiktinis)"<<endl;
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
cin.clear(); cin.ignore(256,'\n');
cin>>nd;
if(nd>0&&nd<=10)
{
temp.ndm.push_back(nd);
temp.ndm.size();
sort(temp.ndm.begin(), temp.ndm.end());
}
else if(nd==0){}
else
{
cout<<"Namu darbu rezultatai, tik desimtbaleje sistemoje"<<endl;
}
}
cout<<"Iveskite studento egzamino rezultata"<<endl;                                          //Egzamino ivedimas
cin.clear(); cin.ignore(256,'\n');
cin>>temp.egz;
if(temp.egz>0&&temp.egz<=10){}
else
{
cout<<"Egzamino rezultatas, tik desimtbaleje sistemoje"<<endl;
}
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
cout<<"Norint baigti ivedima, iveskite n"<<endl;
cin>>uzkl;
}
}
else if (budas=="isfailo")                                                                    //Ivedimas is failo
{
if(is.fail())
{
cout<<"Failo atverti nepavyko"<<endl;
exit(-1);
}
else
{
char str[100];
while(is.get(*str))
cout<<str;
is.close();
}
}
cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis(Med.)"<<endl; // Isvedimas
cout<<"-"<<setfill('-')<<setw(53)<<"-"<<endl;
for(auto i: lent)
{
for(auto v: i.galutv)
for(auto m: i.galutm)
cout<<left<<setfill(' ')<<setw(10)<<i.vardas<<setfill(' ')<<setw(10)<<i.pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<v<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<m<<endl;
}
return 0;
}


