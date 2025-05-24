#include <iostream>
#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"

using namespace std;

void wyswietl(UstawieniaSymulacji & UST){
    cout << "Znak glon:" << UST.znakGlon
         << " zycieMin=" << UST.glonZycieMin
         << " zycieMax=" << UST.glonZycieMax << endl;
}

int main()
{
    //1. Dostep do obiektu klasy UstawieniaSymulacji
    UstawieniaSymulacji & UST1
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji & UST2
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji & UST3
            = UstawieniaSymulacji::pobierzUstawienia();

    cout << "Pobranie ustawien 3x" << endl;
    cout << "UST1: "; wyswietl(UST1);
    cout << "UST2: "; wyswietl(UST2);
    cout << "UST3: "; wyswietl(UST3);


    cout << endl << "Zmiana wartosci tylko 1x" << endl;
    UST2.glonZycieMax = 100;
    cout << "UST1: "; wyswietl(UST1);
    cout << "UST2: "; wyswietl(UST2);
    cout << "UST3: "; wyswietl(UST3);

	//Testy dla generatorlosowy.cpp
    cout << "Liczby losowe typu int:" << endl;
    cout << " od 0 do 5: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(5) << " ";
    cout << endl << " od 0 do 3: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(3) << " ";
    cout << endl << " od 0 do 20: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(20) << " ";

    cout << endl << endl;

    cout << "Liczby losowe typu long: " << endl;
    cout << " od -2 do 2:";
    for(int i=0; i<10; i++)
        cout << GEN::losujPomiedzy(-2L, 2L) <<" ";

    cout << endl << endl
         << "Liczby losowe typu unsigned short: " << endl;
    cout << " od 2 do 6: ";
    unsigned short min=2, max=6;

    for(int i=0; i<10; i++)
        cout << GEN::losujPomiedzy(max, min) <<" ";

    cout << endl << endl;

    return 0;
}
