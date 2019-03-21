#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct studentas
{
    char vardas[20], pavarde[20];
    int egz, nd;
    double galut, vdrk;
};
int main()
{
studentas skaicius[3];
studentas *r;
studentas ndskaicius[3];
studentas *t;
t=ndskaicius;
r=skaicius;
for(int i=0;i<3;i++)
{
cout<<"Iveskite studento varda"<<endl;
cin>>(r+i)->vardas;
cout<<"Iveskite studento pavarde"<<endl;
cin>>(r+i)->pavarde;
cout<<"Iveskite namu darbu rezultatus"<<endl;
for (int j=0;j<3;j++)
{
cin>>(t+j)->nd;
(r+i)->vdrk=((t+j)->nd)/3;
}
cout<<"Iveskite studento egzamino rezultata"<<endl;
cin>>(r+i)->egz;
(r+i)->galut=(0.4*(r+i)->vdrk)+(0.6*(r+i)->egz);
}

cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
cout<<"-"<<setfill('-')<<setw(35)<<"-"<<endl;
for(int i=0;i<3;i++)
{
cout<<left<<setfill(' ')<<setw(10)<<(r+i)->vardas<<setfill(' ')<<setw(10)<<(r+i)->pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<(r+i)->galut<<endl;
}
}

