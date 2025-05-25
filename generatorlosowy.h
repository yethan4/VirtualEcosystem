#ifndef GENERATORLOSOWY_H
#define GENERATORLOSOWY_H

#include <random>

class GeneratorLosowy
{
private:
    static std::random_device device;
    GeneratorLosowy(){};

public:
    static unsigned short losujPomiedzy
    (unsigned short min, unsigned short max);

    static long losujPomiedzy(long min, long max);
    static int losujOdZeraDo(int max);
};
typedef GeneratorLosowy GEN; 



#endif 

//testy
// int main()
// {
//     //Testy dla generatorlosowy.cpp
//     cout << "Liczby losowe typu int:" << endl;
//     cout << " od 0 do 5: ";
//     for(int i=0; i<10; i++)
//         cout << GEN::losujOdZeraDo(5) << " ";
//     cout << endl << " od 0 do 3: ";
//     for(int i=0; i<10; i++)
//         cout << GEN::losujOdZeraDo(3) << " ";
//     cout << endl << " od 0 do 20: ";
//     for(int i=0; i<10; i++)
//         cout << GEN::losujOdZeraDo(20) << " ";

//     cout << endl << endl;

//     cout << "Liczby losowe typu long: " << endl;
//     cout << " od -2 do 2:";
//     for(int i=0; i<10; i++)
//         cout << GEN::losujPomiedzy(-2L, 2L) <<" ";

//     cout << endl << endl
//          << "Liczby losowe typu unsigned short: " << endl;
//     cout << " od 2 do 6: ";
//     unsigned short min=2, max=6;

//     for(int i=0; i<10; i++)
//         cout << GEN::losujPomiedzy(max, min) <<" ";

//     cout << endl << endl;

// }
