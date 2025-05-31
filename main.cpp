#include <iostream>
using namespace std;

#include "nisza.h"
#include "osobniki.h"
#include "sasiedztwo.h"

int main()
{
    Srodowisko ekoSystem(8, 12);

    ekoSystem.lokuj(new Glon(), 0, 10);
    ekoSystem.lokuj(new Glon(), 1, 10);
    ekoSystem.lokuj(new Glon(), 1, 13);
    ekoSystem.lokuj(new Glon(), 3, 10);
    ekoSystem.lokuj(new Grzyb(), 1, 11);
    ekoSystem.lokuj(new Grzyb(), 0, 0);
    ekoSystem.lokuj(new Bakteria(), 3, 3);
    ekoSystem.lokuj(new Bakteria(), 2, 6);

    unsigned long i = 0;

    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        std::cout << "Krok symulacji: " << i << std::endl;
        std::cout << std::endl << ekoSystem << std::endl;
        std::cin.ignore(1);
        ekoSystem++;
        i++;
    } while (i < 200 && !ekoSystem.martwy());

    cout << endl;
    return 0;
}
