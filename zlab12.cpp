#include "zlab12.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void ZLab12::strumienTekstowy()
{
    //Formatowanie
    ostringstream strumien1;

    strumien1 << "Poczatek tekstu" << endl
            << "Liczba1: " << 2 << endl
            << "Liczba2: " << 3.14 << endl;

    cout << strumien1.str() << endl;

    //Parsowanie
    string liniaDanych = "liczby: 3.4 4.5 -3.2 aa";

    string opis;
    double x, y, z;

    istringstream strumien2(liniaDanych);

    strumien2 >> opis >> x >> y >> z;

    if (!strumien2.fail())
        cout << "opis: " << opis << endl
             << "x=" << x << endl
             << "y=" << y << endl
             << "z=" << z << endl;
    else cout <<"Nie udało się!" << endl << endl;
}

void ZLab12::zapisTekstowyDoPliku(string nazwaPliku)
{
    ofstream plik;

    cout << "Otwieram plik." << endl;
    plik.open(nazwaPliku, ios_base::out);

    if(plik.is_open()){
        cout << "Zapisuje do pliku" << endl;
        for(int i=1; i<=10; i++)
            plik << i << " " << i*i << " " << i*i*i << endl;
    }

    plik.close();

    cout << "Plik zamknięty" << endl;
}

void ZLab12::odczytPlikuTekstowego(string nazwaPliku)
{
    ifstream plik;
    cout << "Otwieram plik." << endl;
    plik.open(nazwaPliku, ios_base::in);

    int a, b, c;

    if (plik.is_open()) {
        while (plik >> a >> b >> c) {
            cout << "a=" << a << " b=" << b << " c=" << c << endl;
        }
    }

    plik.close();
}

void ZLab12::zapisBinarnyDoPliku(string nazwaPliku)
{
    ofstream plik;
    cout << "Otwieram plik." << endl;

    plik.open(nazwaPliku, ios_base::out | ios_base::binary);

    if (plik.is_open()) {
        cout << "Zapisuje do pliku" << endl;

        for (int i = 1; i <= 10; i++) {
            int k = i;
            plik.write(reinterpret_cast<char*>(&k), sizeof(k));

            k = i * i;
            plik.write(reinterpret_cast<char*>(&k), sizeof(k));

            k = i * i * i;
            plik.write(reinterpret_cast<char*>(&k), sizeof(k));
        }
    }

    plik.close();
    cout << "Plik zamknięty" << endl;
}

void ZLab12::odczytPlikuBinarnego(string nazwaPliku)
{
    ifstream plik;
    cout << "Otwieram plik." << endl;
    plik.open(nazwaPliku, ios_base::in |ios_base::binary);

    int a, b, c;

    if(plik.is_open()){
        while(!plik.eof()){
            plik.read(reinterpret_cast<char*>(&a),
                      sizeof (a));
            plik.read(reinterpret_cast<char*>(&b),
                      sizeof (a));
            plik.read(reinterpret_cast<char*>(&c),
                      sizeof (a));
            if(plik.eof()) break;
            cout << "a="<<a<<" b="<<b<<" c="<<c <<endl;
        }
    }

    plik.close();
}
