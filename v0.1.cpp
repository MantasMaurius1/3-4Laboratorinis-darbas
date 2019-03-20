#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct studentai
{
    char vardas[20], pavarde[20];
    int nd, egz;
    double galut;
};
int main()
{
struct studentai a1;
cout<<"Iveskite studento varda"<<endl;
cin>>a1.vardas;
cout<<"Iveskite studento pavarde"<<endl;
cin>>a1.pavarde;
cout<<"Iveskite namu darbu rezultata"<<endl;
cin>>a1.nd;
cout<<"Iveskite studento egzamino rezultata"<<endl;
cin>>a1.egz;
a1.galut=(0.4*a1.nd)+(0.6*a1.egz);
cout<<left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
cout<<"-"<<setfill('-')<<setw(35)<<"-"<<endl;
cout<<left<<setfill(' ')<<setw(10)<<a1.vardas<<setfill(' ')<<setw(10)<<a1.pavarde<<setfill(' ')<<setw(15)<<right<<fixed<<setprecision(2)<<a1.galut<<endl;
}
