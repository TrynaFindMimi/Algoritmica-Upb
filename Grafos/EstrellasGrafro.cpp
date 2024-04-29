#include <iostream> 
using namespace std; 
 
int main() { 
    int filas, columnas; 
    while (cin >> filas >> columnas && filas > 0 && columnas > 0) { 
 
        char grafo[filas][columnas]; 
 
        for(int i = 0; i < filas; i++) { 
            for(int j = 0; j < columnas; j++) { 
                cin >> grafo[i][j]; 
            } 
        } 
 
        int estrellas = 0; 
        for(int i = 0; i < filas; i++) { 
            for(int j = 0; j < columnas; j++) { 
                if (grafo[i][j] == '*') { 
                    bool estrellaS = true; 
                    for (int k = i-1; k <= i+1; k++) { 
                        for (int l = j-1; l <= j+1; l++) { 
                            if (k >= 0 && k < filas && l >= 0 && l < columnas && grafo[k][l] == '*' && (k != i || l != j)) { 
                                estrellaS = false;  
                            } 
                        } 
                    } 
                    if (estrellaS) { 
                        estrellas++; 
                    } 
                } 
            } 
        } 
 
        cout << estrellas << endl; 
    } 
 
    return 0; 
}

