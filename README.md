# ObjektinioProgramavimo_uzd
## Sistemos specifikacijos:
* CPU: Intel core i5 10400f 2.9GHz

* RAM: 16GB DDR4 2667MHz

* SSD: Kingston SA2000M8500G 

SEQ1MQ8T1 Read: 1939.59 MB/s

SEQ1MQ8T1 Write: 658.69 MB/s

## Instaliacijos instrukcijos
Kartu su programa ateina makefile, exe failo sukūrimui įrašykite make, jo paleidimui make run.

## Naudojimosi instrukcija
Paleidus programą gausite pasirinkimą įrašyti studentus bei jų pažymius ranka, nuskaityti juos iš failo, ar sugeneruoti naują atsitiktinų pažymių ir studentų failą testuoti programos greičiui.


Pasirinkus rašyti pažymius ranka galėsite pasirinkti galutinį pažymį skaičiuoti su vidurkiu ar mediana ir vėliau įrašyti studentus bei jų pažymius.

Pasirinkus skaityti pažymius iš failo reikės įrašyti failo pavadinimą ir pasirinkti kokia strategija skaičiuoti.

Pasirinkus kurti failą jūsų prašys failo dydį ir kiek pažymių turi kiekvienas studentas.

## RAM naudojimas

RAM naudojimas skaičiuojamas testuojant su failu, kuriame yra 10000000 studentų su 7 namų darbų pažymiais)

1 Strategija - Saugoti studentams dviejuose naujuose konteineris (naudoja max 3.2 GB RAM)

2 Strategija - Saugoti studentams sukuriamas vienas naujas konteineris (naudoja max 2.6 GB RAM)

3 Strategija - Studentų saugojimui nesukuriamas joks naujas konteineris (naudoja max 2.2 GB RAM) 

## Programos greičiai

* 1000 studentų su 7 namų darbų pažymiais:

|Operacijos                       | Vektoriai (1s) | Vektoriai (2s) | Vektoriai (3s) | Deque (1s)     | Deque (2s) | List (1s)     | List (2s) |
|---------------------------------|----------------------|----------------------|---|-----------|------------|-----------|-----------|
| Duomenų nuskaitymas             | 0.0009996            | 0.015  | - |0.0025015 | - |0.0025012 | - |
| Studentų Rikiavimas             | 0                    | 0      | 0 |0.0005007 | 0.0010003 |0.000499  | 0 |
| Studentų skirstymas į dvi dalis | 0                    | 0      | 0 |0.0009989 | 0.0010008 |0.0005021 | 0.006002 |

* 10000 studentų su 7 namų darbų pažymiais:

|Operacijos                       | Vektoriai (1s) | Vektoriai (2s) | Vektoriai (3s) | Deque (1s)     | Deque (2s) | List (1s)     | List (2s) |
|---------------------------------|----------------------|----------------------|---|-----------|------------|-----------|-----------|
| Duomenų nuskaitymas             | 0.0144994 | 0.109973  | - | 0.0144999 | - |0.0214997 | - |
| Studentų Rikiavimas             | 0.0014993 | 0.0015016 | 0.0010005 |  0.0074989 | 0.0059993 |0.0014988 | 0.0020008 |
| Studentų skirstymas į dvi dalis | 0.0004994 | 0.0005008 | 0 | 0.0070001 | 0.0020004 |0.0029976 | 0.0009999 |

* 100000 studentų su 7 namų darbų pažymiais:

|Operacijos                       | Vektoriai (1s) | Vektoriai (2s) | Vektoriai (3s) | Deque (1s)     | Deque (2s) | List (1s)     | List (2s) |
|---------------------------------|----------------------|----------------------|---|-----------|------------|-----------|-----------|
| Duomenų nuskaitymas             | 0.104501  | 0.117501 | - |0.162998  | - | 0.196002  | - |
| Studentų Rikiavimas             | 0.0169989 | 0.0179989 | 0.0149992 | 0.0954995 | 0.0909987 | 0.0284994 | 0.0269703 |
| Studentų skirstymas į dvi dalis | 0.0045019 | 0.0025012 | 0 | 0.0875352 | 0.0279996 | 0.0365014 |  0.0109983 |

* 1000000 studentų su 7 namų darbų pažymiais:

|Operacijos                       | Vektoriai (1s) | Vektoriai (2s) | Vektoriai (3s) | Deque (1s)     | Deque (2s) | List (1s)     | List (2s) |
|---------------------------------|----------------------|----------------------|---|-----------|------------|-----------|-----------|
| Duomenų nuskaitymas             | 1.008     | 1.2175 | - | 1.632     | - | 1.9945    | - |
| Studentų Rikiavimas             | 0.213498  | 0.231502 | 0.24 | 1.493     | 1.367 | 0.591996  | 0.501999 |
| Studentų skirstymas į dvi dalis | 0.0430027 | 0.0305241 | 0.0030008 | 0.881502  |  0.353| 0.393502  | 0.125001 |

* 10000000 studentų su 7 namų darbų pažymiais:

|Operacijos                       | Vektoriai (1s) | Vektoriai (2s) | Vektoriai (3s) | Deque (1s)     | Deque (2s) | List (1s)     | List (2s) |
|---------------------------------|----------------------|----------------------|---|-----------|------------|-----------|-----------|
| Duomenų nuskaitymas             | 10.8645   | 11.344| - | 14.979    | - | 17.8685   | - |
| Studentų Rikiavimas             | 2.6655    | 2.973 | 2.582 | 17.2065   | 16.5979 | 8.854     | 8.006 |
| Studentų skirstymas į dvi dalis | 0.430501  | 0.228001 | 0.0300007 | 65.7495   | 21.7311 | 4.1305    | 1.458 |

## Failų kūrimo greičiai
* 1000 studentų su 7 namų darbų pažymiais
![1000 studentų](./screenshotai/v0.4_kurimas/1000_7.png)
* 10000 studentų su 7 namų darbų pažymiais
![10000 studentų](./screenshotai/v0.4_kurimas/10000_7.png)
* 100000 studentų su 7 namų darbų pažymiais
![100000 studentų](./screenshotai/v0.4_kurimas/100000_7.png)
* 1000000 studentų su 7 namų darbų pažymiais
![1000000 studentų](./screenshotai/v0.4_kurimas/1000000_7.png)
* 10000000 studentų su 7 namų darbų pažymiais
![10000000 studentų](./screenshotai/v0.4_kurimas/10000000_7.png)
