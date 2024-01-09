#include "arreglo.h"
#include <cstdlib>
#include <iostream>

#define ARRAY_SIZE 100000
#define MAX_NUM_VAL 200000

using namespace std;
int busquedaSecuencial(arreglo&,int);
int busquedaBinaria(arreglo&,int);

int main() {
    arreglo A(ARRAY_SIZE); // Se crea arreglo de tamaño 1000

    // Se llena con valodes de entre 0 y 4999
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A.set(i,rand() % MAX_NUM_VAL);
    }

    cout << "Ordenamos nuestro arreglo de tamaño " << A.length() << endl;
    
    // Imprime los primeros 100 valores del arreglo
    for (int i = 0; i < 100; i++) {
        cout << A[i];
        if ((i+1) % 10 == 0)
            cout << endl;
        else
            cout << "\t";
    }

    //cout << endl << "Busqueda secuencial y binaria:" << endl;
    //for (int i = 0; i < 10; i++) {
    //    int clave = rand() % MAX_NUM_VAL;
    //    cout << clave << ":\tSecuencial: " << busquedaSecuencial(A,clave) << "\tBinaria: " << busquedaBinaria(A,clave) << endl;
    //}

    cout << "Test busqueda secuencial" << endl;
    int count = 0;
    for (int i = 0; i < MAX_NUM_VAL; i++) {
        if (busquedaSecuencial(A,i) != -1)
            count++;
        if ((i+1) % 10000 == 0)
            cout << count << " numeros al paso " << i + 1 << endl;
    }
    cout << "Se encontraron " << count << " numeros con busqueda secuencial" << endl;

    
    cout << "Test busqueda binaria" << endl;
    A.ordenIntercambio();
    cout << "Se termina de ordenar el arreglo" << endl;
    count = 0;
    for (int i = 0; i < MAX_NUM_VAL; i++) {
        if (busquedaBinaria(A,i) != -1)
            count++;
        if ((i+1) % 10000 == 0)
            cout << count << " numeros al paso " << i + 1 << endl;
    }
    cout << "Se encontraron " << count << " numeros con busqueda binaria" << endl;

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

int busquedaBinaria(arreglo& A,int clave) {
    int central,bajo,alto,valorCentral,n;
    bajo = 0;
    n = A.length();
    alto = n - 1;
    while (bajo <= alto) {
        central = (alto + bajo) / 2;
        valorCentral = A[central];
        if (valorCentral == clave) {
            return central;
        }
        else if (clave < valorCentral) {
            alto = central - 1; // posicion previa a central
        }
        else {
            bajo = central + 1; // posicion posterior a central
        }
    }
    return -1;
}