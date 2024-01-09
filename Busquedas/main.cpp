#include "arreglo.h"
#include <cstdlib>
#include <iostream>

using namespace std;
int busquedaSecuencial(arreglo&,int);

int main() {
    arreglo A(1000); // Se crea arreglo de tamaño 1000

    // Se llena con valodes de entre 0 y 4999
    for (int i = 0; i < 1000; i++) {
        A.set(i,rand() % 3000);
    }

    // Imprime los primeros 100 valores del arreglo
    for (int i = 0; i < 100; i++) {
        cout << A[i];
        if ((i+1) % 10 == 0)
            cout << endl;
        else
            cout << "\t";
    }

    cout << endl << "Busqueda secuencial:" << endl;
    for (int i = 0; i < 10; i++) {
        int clave = rand() % 3000;
        cout << clave << ": " << busquedaSecuencial(A,clave) << endl;
    }

    return 0;
}

int busquedaSecuencial(arreglo& A,int clave) {
    int n = A.length();
    for (int i = 0;i < n; i++) {
        if (A[i] == clave) {
            return i;
        }
    }
    return -1; // no se encontro
}