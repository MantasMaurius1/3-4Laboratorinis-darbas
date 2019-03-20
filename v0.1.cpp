#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct studentas
{
    char vardas[20], pavarde[20];
    int nd, egz, N;
    double galut=5;
};
int main()
{
studentas skaicius[3];
studentas *r;
r=skaicius;
for(int i=0;i<3;i++)
{
cout<<"Iveskite studento varda"<<endl;
cin>>(r+i)->vardas;
cout<<"Iveskite studento pavarde"<<endl;
cin>>(r+i)->pavarde;
cout<<"Iveskite namu darbu rezultata"<<endl;
cin>>(r+i)->nd;
cout<<"Iveskite studento egzamino rezultata"<<endl;
cin>>(r+i)->egz;
}
cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
cout<<"-"<<setfill('-')<<setw(35)<<"-"<<endl;

for(int i=0;i<3;i++)
{
cout<<left<<setfill(' ')<<setw(10)<<(r+i)->vardas<<setfill(' ')<<setw(10)<<(r+i)->pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<(r+i)->galut<<endl;
}
}
