#include "sasiedztwo.h"
#include "generatorlosowy.h"
#include <initializer_list>

RodzajMieszkanca *Sasiedztwo::elementWewnetrzny(Polozenie polozenie)
{
    switch (polozenie)
    {
    case P:
        return &sasiad[1][2];
    case PG:
        return &sasiad[0][2];
    case G:
        return &sasiad[0][1];
    case LG:
        return &sasiad[0][0];
    case L:
        return &sasiad[1][0];
    case LD:
        return &sasiad[2][0];
    case D:
        return &sasiad[2][1];
    case PD:
        return &sasiad[2][2];
    case NIGDZIE:
        return nullptr;
    }
    return nullptr;
}

Polozenie Sasiedztwo::losujPolozenie()
{
    unsigned short min = 0, max = 8;
    return static_cast<Polozenie>(GeneratorLosowy::losujPomiedzy(min, max));
}

Sasiedztwo::Sasiedztwo(RodzajMieszkanca rodzaj)
{
    for (auto i : {0, 1, 2})
        for (auto j : {0, 1, 2})
            sasiad[i][j] = rodzaj;

    sasiad[1][1] = NIEZNANE;
}

void Sasiedztwo::okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj)
{
    if (polozenie != NIGDZIE)
        *elementWewnetrzny(polozenie) = rodzaj;
}

RodzajMieszkanca Sasiedztwo::
    ktoJestSasiadem(Polozenie polozenie)
{
    if (polozenie != NIGDZIE)
        return *elementWewnetrzny(polozenie);
    else
        return NIEZNANE;
}

unsigned short Sasiedztwo::
    ile(RodzajMieszkanca rodzaj) const
{
    unsigned short licznik = 0;

    for (int i : {0, 1, 2})
        for (int j : {0, 1, 2})
        {
            if (i == 1 && j == 1)
                continue;
            if (sasiad[i][j] == rodzaj)
                licznik++;
        }

    return licznik;
}

Polozenie Sasiedztwo::
    losujSasiada(RodzajMieszkanca rodzaj)
{
    if (ile(rodzaj) == 0)
        return NIGDZIE;
    else
    {
        Polozenie polozenie = Sasiedztwo::losujPolozenie();

        while (ktoJestSasiadem(polozenie) != rodzaj)
            polozenie = Sasiedztwo::losujPolozenie();

        return polozenie;
    }
}

void Sasiedztwo::zmienIdeksyWgPolozenia(Polozenie polozenie,
                          long &wiersz, long &kolumna)
{
    if (polozenie == PG || polozenie == P || polozenie == PD)
        kolumna++;
    else if (polozenie == LG || polozenie == L || polozenie == LD)
        kolumna--;

    if (polozenie == LG || polozenie == G || polozenie == PG)
        wiersz--;
    else if (polozenie == LD || polozenie == D || polozenie == PD)
        wiersz++;
}

void Sasiedztwo::zmienIdeksyWgPolozenia(Polozenie polozenie,
                                        unsigned int &wiersz, unsigned int &kolumna)
{
    long w = static_cast<long>(wiersz);
    long k = static_cast<long>(kolumna);

    zmienIdeksyWgPolozenia(polozenie, w, k);

    wiersz = static_cast<unsigned int>(w);
    kolumna = static_cast<unsigned int>(k);
}

//sasiedztwo test

/*string nazwaRodzaju(RodzajMieszkanca rodzaj) {
    switch (rodzaj) {
        case GLON: return "GLON";
        case GRZYB: return "GRZYB";
        case BAKTERIA: return "BAKTERIA";
        case PUSTKA: return "PUSTKA";
        case SCIANA: return "ŚCIANA";
        case TRUP: return "TRUP";
        case NIEZNANE: return "NIEZNANE";
        default: return "NIEZNANE";
    }
    return "NIEZNANE";
}*/

/*int main()
{
    cout << "test";
    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    cout << "Przegląd sąsiedztwa:" << endl;

    for (int i = 0; i < 8; i++) {
        Polozenie p = static_cast<Polozenie>(i);
        RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);

        cout << "polozenie=" << p << " rodzaj="
             << nazwaRodzaju(r) << endl;
    }

    cout << endl << "Policzenie sasiadów"
         << " określonego rodzaju:" << endl
         << " glony=" << sasiedztwo.ile(GLON) << endl
         << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
         << " trupy=" << sasiedztwo.ile(TRUP) << endl;

    cout << endl << "Wylosowanie sasiada:" << endl
         << " glon -> "
         << sasiedztwo.losujSasiada(GLON) << endl
         << " pustka -> "
         << sasiedztwo.losujSasiada(PUSTKA) << endl
         << " trup -> "
         << sasiedztwo.losujSasiada(TRUP) << endl;

    long wiersz, kolumna;
    cout << endl
         << "Zmiana indeksów [5][7]"
         << " wg polozenia:" << endl;

    for (int i = 0; i < 8; i++) {
        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 5;
        kolumna = 7;

        Sasiedztwo::zmienIdeksyWgPolozenia(p, wiersz, kolumna);

        cout << " położenie: " << p << " ->[" << wiersz
             << "][" << kolumna << "]" << endl;
    }

    cout << endl;

    return 0;
}*/