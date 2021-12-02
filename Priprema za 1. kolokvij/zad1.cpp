#include <stdio.h>
#include <iostream>

using namespace std;

int zbroj_znamenki(int broj) {
    // 287 % 10 = 7
    // 287 / 10 = 28.7
    // broj nam je 28
    // 28 % 10 = 8
    // 28 / 10 = 2
    // 2 % 10 = 2
    // 2 / 10 = 0
    int suma = 0;
    while (broj != 0) {
        int zadnja = broj % 10;
        suma += zadnja;
        broj = broj / 10;
    }
    return suma;
}

int main()
{
    int suma = zbroj_znamenki(3124123);
    
    cout << "Suma znamenki je:" << suma << endl;
    return 0;
}

