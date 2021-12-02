#include <stdio.h>
#include <iostream>

using namespace std;

void obrada(int *niz, int velicina) {
    for (int i = 0; i < velicina; i++) {
        if (niz[i] % 2 == 0) {
            niz[i] = 0;
        } else {
            niz[i] += 10;
        }
    }
}

void povecaj_za_10(int* a) {
    *a += 10;    
}

int main()
{
    int brojevi[4] = {3, 5, 12, 24};
    
    int a = 5;
    cout << "a je: " << a << endl;
    povecaj_za_10(&a);
    cout << "a je: " << a << endl;
    
    for (int i = 0; i < 4; i++) {
        cout << brojevi[i] << endl;
    }
    
    cout << "-----------------" << endl;
    
    obrada(brojevi, 4);
    
    for (int i = 0; i < 4; i++) {
        cout << brojevi[i] << endl;
    }
    
    return 0;
}

