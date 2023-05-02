#ifndef SKAICIAVIMAI_H
#define SKAICIAVIMAI_H
#include "MyLib.h"
#include "studentas.h"


/*!
Laikrodis skirtas programos veikimo spartai apskaiciuoti
*/
class Timer {
private:
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
std::chrono::time_point<hrClock> start;
public:
Timer() : start{ hrClock::now() } {}
void reset() {
start = hrClock::now();
}
double elapsed() const {
return durationDouble (hrClock::now() - start).count();
}
};


/*!
palygintigalutinius ir palygintigalutiniusalt rusiuoja studentus pagal ju galutinius pazymius, taciau vienas kitam atvirksciai
*/
bool palygintivardus(Studentasc& a, Studentasc& b);
bool palygintigalutinius(Studentasc& a,Studentasc& b);
bool palygintigalutiniusalt(Studentasc& a,Studentasc& b);
#endif