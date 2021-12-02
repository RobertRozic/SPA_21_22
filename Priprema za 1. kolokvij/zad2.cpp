/#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
    int m, n;
    
    cout << "Unesi broj redaka:" << endl;
    cin >> m;
    
    cout << "Unesi broj stupaca:" << endl;
    cin >> n;
  
    int M[m][n];
    
    // Unos elemenata u matricu
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Unesi element na poziciji: " << i << "-" << j << endl;
            cin >> M[i][j];
        }
    }
    
    // Ispis matrice
    cout << endl << "Matrica M: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    
    
    // 00, 01, 02, 03
    // 10, 11, 12, 13
    // 20, 21, 22, 23
    
    // Zbroj elemenata na rubovima
    int suma = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                int el = M[i][j];
                suma += el;
            }
            
        }
    }
    
    cout << "Suma elemenata na rubovima je: " << suma; 
    return 0;
}

