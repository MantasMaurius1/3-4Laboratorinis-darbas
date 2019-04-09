# 3-4 Laboratorinis darbas

#     Užduoties formuluotė

* Parašykite programą, kuri nuskaito šiuos studentų duomenis:
  * vardą ir pavardę
  * n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
* Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis):

galutinis = 0.4 * vidurkis + 0.6 * egzaminas

#     Programos veikimo principai

Programos veikimo būdas yra nusprendžiamas vartotojo.
Programos veikimo būdai:

* Rankinis;
* Iš sukurto tekstinio failo;
* Atsitiktinis;

#     Programos veikimo principų paaiškinimas

* Rankinis

Pasirinkęs rankinį programos veikimo būdą, vartotojas, turės įvesti studento vardą bei pavardę, taip pat namų darbų balus, egzamino rezultatą.
Vartotojo įvesti rezultatai turi būti dešimtbalėje sistemoje, t.y. nuo 1 iki 10.
Po kiekvieno studento įvestų duomenų, programa paklaus ar norite tęsti duomenų įvedimą.
Studentų skaičius bei namų darbų kiekis nėra ribojamas.
Gavusi visus duomenis, programa apskaičiuoja galutinį studento pažymį dviem būdais(pagal nurodytą formulę užduotyje): naudodama visų namų darbų pažymių vidurkį bei naudodama visų namų darbų pažymių mediana.

* Iš sukurto tekstinio failo

Pasirinkus šį programos veikimo būdą, programa automatiškai nuskaitys duomenis iš tekstinio failo, pavadinimu: "kursiokai.txt".
Nuskaičiusi duomenis, programa apskaičiuoja galutinį studento pažymį dviem būdais(pagal nurodytą formulę užduotyje): naudodama visų namų darbų pažymių vidurkį bei naudodama visų namų darbų pažymių mediana.

* Atsitiktinis

Vartotojas pasirinkęs šį programos veikimo būdą, turės nurodyti kiek atsitiktinių duomenų programa turės sugeneruoti.
Įvedus skaičių, programa atsitiktinai sugeneruoja penkis studento namų darbų pažymius bei egzamino pažymį. Tuomet pagal atsitiktinai sugeneruotus duomenis programa apskaičiuoja studento pažymį naudodamą visų namų darbų pažymių vidurkį bei naudodama visų namų darbų pažymiu mediana.
