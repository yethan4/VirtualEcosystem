#include <iostream>
#include <string>

using namespace std;

#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "nisza.h"
#include "osobniki.h"

static Nisza n1, n2, n3;

static char sep = UstawieniaSymulacji::
        pobierzUstawienia().znakSeparator;

void wyswietlNisze()
{
    cout << n1.jakisSymbol() << sep
         << n2.jakisSymbol() << sep
         << n3.jakisSymbol() << endl;
}

int main()
{
    cout << "Puste nisze: ";
    wyswietlNisze();

    cout << "Lokowanie mieszkańców: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    cout << "Przesuwanie lokatorów: ";
    n2 = n1;
    wyswietlNisze();

    cout << "Przesuwanie lokatorów:";
    n3 = n2;
    wyswietlNisze();

    cout << endl;
    return 0;
}

