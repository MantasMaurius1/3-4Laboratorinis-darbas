# v1.0

Šioje versijoje vykdomas studentų rūšiavimo (dalijimo) į dvi kategorijas ("vargšiukų" ir "kietekų") optimizavimas:

Naudojant pirmą strategiją vidutinis programos veikimo laikas, generuojant 1000 atsitiktinių studentų duomenų, su šiais konteineriais:

* Vector ≈ 15,6 msec
* List ≈ 10,6 msec
* Deque ≈ 9,6 msec

Naudojant antrą strategiją vidutinis programos veikimo laikas, generuojant 1000 atsitiktinių studentų duomenų, su šiais konteineriais:

* Vector ≈ 8,8 msec
* List ≈ 6,8 msec
* Deque ≈ 7 msec

_P.S. Su kiekviena strategija ir jai naudojamu konteineriu, bandymai atlikti 5 kartus ir išvestas aritmetinis vidurkis._

