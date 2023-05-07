 # ObjektinioProgramavimo_uzd
## Sistemos specifikacijos:
* CPU: Intel core i5 10400f 2.9GHz

* RAM: 16GB DDR4 2667MHz

* SSD: Kingston SA2000M8500G 

SEQ1MQ8T1 Read: 1939.59 MB/s

SEQ1MQ8T1 Write: 658.69 MB/s

## Instaliacijos instrukcijos
Kartu su programa ateina makefile, exe failo sukūrimui įrašykite make, jo paleidimui make run, norint instaliuoti testus paleiskite komandą make test.

Taip pat prie release įdėtas setup, kuris instaliuos programą kaip Obj_p, norint kurti ar skaityti failus, tą programą reiks paleisti administratoriaus privilegijomis.

## Naudojimosi instrukcija
Paleidus programą gausite pasirinkimą įrašyti studentus bei jų pažymius ranka, nuskaityti juos iš failo, ar sugeneruoti naują atsitiktinų pažymių ir studentų failą testuoti programos greičiui.

Pasirinkus rašyti pažymius ranka galėsite pasirinkti galutinį pažymį skaičiuoti su vidurkiu ar mediana ir vėliau įrašyti studentus bei jų pažymius.

Pasirinkus skaityti pažymius iš failo reikės įrašyti failo pavadinimą ir pasirinkti kokia strategija skaičiuoti.

Pasirinkus kurti failą jūsų prašys failo dydį ir kiek pažymių turi kiekvienas studentas.

## Doxygen

Šioje repozitorijoje taip pat rasite Doxyfile failą, jį paleidus, (komanda doxygen) bus sugeneruotas projekto aprašas, aprašantis naudojamas klases.

## RAM naudojimas

RAM naudojimas skaičiuojamas testuojant su failu, kuriame yra 10000000 studentų su 7 namų darbų pažymiais)

1 Strategija - Saugoti studentams dviejuose naujuose konteineris (naudoja max 3.2 GB RAM)

2 Strategija - Saugoti studentams sukuriamas vienas naujas konteineris (naudoja max 2.6 GB RAM)

3 Strategija - Studentų saugojimui nesukuriamas joks naujas konteineris (naudoja max 2.2 GB RAM) 

## Optimizavimo flag poveikis (10000000 studentų failas)

|                                 | O1        | O2        | O3        |
|---------------------------------|-----------|-----------|-----------|
| Duomenų nuskaitymas             | 11.269    | 11.286    | 11.279    |
| Studentų Rikiavimas             | 3.008     | 2.895     | 2.74103   |
| Studentų skirstymas į dvi dalis | 0.0369983 | 0.0310036 | 0.0279997 |
| exe failo dydžiai               | 162,974 baitai| 158,708 baitai| 168,825 baitai |

## std::vector ir vector.h greiciai:

naudojamas 100000 studentų dydžio failas naudojant 1 strategiją:

|                                 |std::vector| vector.h  |
|---------------------------------|-----------|-----------|
| Duomenų nuskaitymas             | 0.104501  | 0.109981  |
| Studentų Rikiavimas             | 0.0169989 | 0.0420322 |
| Studentų skirstymas į dvi dalis | 0.0045019 |0.010967   |
|Perskirstymų sk. (10000000)      |25 |25|
