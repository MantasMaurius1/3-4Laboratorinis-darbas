#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

struct studentas
{
    char vardas[20], pavarde[20];
    int egz;
    double galutv, vdrk, galutm;
};
int main()
{
int stsk, nd;
cout<<"Iveskite studentu skaiciu"<<endl;
cin>>stsk;
studentas skaicius[stsk];
studentas *r;
r=skaicius;
for(int i=0;i<stsk;i++)
{
cout<<"Iveskite studento varda"<<endl;
cin>>(r+i)->vardas;
cout<<"Iveskite studento pavarde"<<endl;
cin>>(r+i)->pavarde;
cout<<"Iveskite namu darbu rezultatus"<<endl;
vector<double> ndm;
ND: for (int j=0;j<3;j++)      //Namu darbu ivedimo ciklas
{
cin>>nd;
if(nd>0&&nd<=10)              //Ar namu darbo rezultatas desimtbaleje sistemoje
{
ndm.push_back(nd);
ndm.size();
sort(ndm.begin(), ndm.end());
}
else
{
break;
cout<<"Namu darbu rezultatai, tik desimtbaleje sistemoje"<<endl;
goto ND;
}
}
cout<<"Iveskite studento egzamino rezultata"<<endl;
EGZ: cin>>(r+i)->egz;
if((r+i)->egz>0&&(r+i)->egz<=10)   //Ar egzamino rezultatas nesimtbaleje sistemoje
{
(r+i)->vdrk=(ndm[0]+ndm[1]+ndm[2])/3;
(r+i)->galutv=(0.4*(r+i)->vdrk)+(0.6*(r+i)->egz);
(r+i)->galutm=(0.4*ndm[1])+(0.6*(r+i)->egz);
}
else{
cout<<"Egzamino rezultatas, tik desimtbaleje sistemoje"<<endl;
goto EGZ;
}
}
cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis(Med.)"<<endl;
cout<<"-"<<setfill('-')<<setw(53)<<"-"<<endl;
for(int i=0;i<stsk;i++)
{
cout<<left<<setfill(' ')<<setw(10)<<(r+i)->vardas<<setfill(' ')<<setw(10)<<(r+i)->pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<(r+i)->galutv<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<(r+i)->galutm<<endl;
}
}
