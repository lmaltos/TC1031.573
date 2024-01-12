#include <iostream>

using namespace std;

void intercambia(int&,int&);
void intercambia(int*,int*);

int testIntercambio() {
    int a = 5, b = 10;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "a = " << a << "\tb = " << b << endl;
    intercambia(a,b);
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "a = " << a << "\tb = " << b << endl;
    return 0;
}

int main() {
    //testIntercambio();
    int a = 5, *p;
    p = new int; // reservamos memoria dinamica
    *p = a;
    a = *p + 2;
    cout << a << " " << *p << endl;
    cout << "&a = " << &a << endl;
    cout << "p = " << p << endl;
    delete p; // liberamos la memoria dinamica que solicitamos
    cout << "Despues de delete p" << endl;
    cout << a << " " << *p << endl; // puede dar error en algunos casos
    cout << "p = " << p << endl; // p sigue apuntando a la misma seccion de memoria
    return 0;
}

void intercambia(int &x, int &y) {
    int tmp = y;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    cout << "x = " << x << "\ty = " << y << endl;
    y = x;
    x = tmp;
    cout << "despues del intercambio" << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    cout << "x = " << x << "\ty = " << y << endl;
}

void intercambia(int *p, int *q) {
    int tmp;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "*p = " << *p << "\t*q = " << *q << endl;
    tmp = *p;
    *p = *q;
    *q = tmp;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "*p = " << *p << "\t*q = " << *q << endl;
}