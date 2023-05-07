# Custom vector failas

## veikiancios funkcijos:

https://github.com/Human204/Vector_class/blob/main/README.md

## metodu testai:

https://github.com/Human204/Vector_class/tree/test


## std::vector ir vector.h greiciai:

naudojamas 100000 studentų dydžio failas naudojant 1 strategiją:

|                                 |std::vector| vector.h  |
|---------------------------------|-----------|-----------|
| Duomenų nuskaitymas             | 0.104501  | 0.109981  |
| Studentų Rikiavimas             | 0.0169989 | 0.0420322 |
| Studentų skirstymas į dvi dalis | 0.0045019 |0.010967   |
|Perskirstymų sk. (10000000)      |25 |25|

## push_back greiciai

|                                 |std::vector| vector.h  |
|---------------------------------|-----------|-----------|
| 100000            | 0.0010005  | 0.0010005  |
| 1000000             | 0.0029984 | 0.0020023 |
| 10000000 | 0.0369991 |0.0330011   |
|100000000      |0.325999 |0.309003|
