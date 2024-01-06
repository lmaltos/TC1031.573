#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    cout << "Numeros fibonacci:" << endl;
    for (int i = 1; i < 20; i++) {
        cout << "f(" << i << ") : " << fibonacci(i) << endl;
    }
    cout << endl;

    cout << "Factorial de numeros:" << endl;
    for (int i = 1; i < 12; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }

    cout << endl << "Funcion 91 Mc Carthy" << endl;
    for (int i = 1; i < 200; i++) {
        cout << "f91(" << i << ") = " << funcion91(i);
        if (i % 5 == 0) { // estamos en un multiplo de 5
            cout << endl;
        }
        else {
            cout << "\t";
        }
    }
    cout << endl << endl;

    cout << "Conjetura de Colatz" << endl;
    // 3,10,5,16,8,4,2,1
    for (int i = 1; i < 100; i++) {
        cout << i << ": " << tresNMasUno(i) << endl;
    }
}