#include <iostream>

using namespace std;

void regla01();
void regla02();
void regla03();
void regla04();
void regla05();
void regla06();
void regla07();
void regla08();
void regla09();
void regla10();

int main() {
    regla10();
    return 0;
}

// Por cada new hay un delete
void regla01() {
    int *p,*q;
    cout << "p = " << p << endl;
    p = new int;
    q = new int;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    delete p;
    delete q;
    p = new int;
    cout << "p = " << p << endl;
    delete p;
    p = new int;
    cout << "p = " << p << endl;
    delete p;
    p = new int;
    cout << "p = " << p << endl;
    delete p;
    p = new int;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    delete p;
    //delete q; no se puede liberar dos veces
}

void regla02() {
    int *p,*q,*r;
    cout << "Inicializacion" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    p = new int;
    cout << "p = new int" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    q = r = p;
    cout << "q = r = p" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    delete r;
    cout << "delete r" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
}

int* regla03_1() {
    int *p;
    p = new int;
    *p = 123;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    // no se esta haciendo el delete de p
    return p;
}

void regla03() {
    int *q;
    q = regla03_1();
    cout << "&q = " << &q << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    delete q;
}

void regla04() {
    int *p, *q = NULL;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "*p = " << *p << endl;
    // *p = 10; // aunque parece un segmento de memoria valido, no se puede utilizar
    //cout << "*p = " << *p << endl;
    //cout << "*q = " << *q << endl;
    delete q; // no hay problema en hacer delete de NULL
}

void regla05() {
    int *p, a = 234;
    p = &a;
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "p = " << p << endl;
    cout << "&p = " << &p << endl;
    //delete p; // munmap_chunk(): invalid pointer
}

void regla06() {
    int *p = NULL;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
}

void regla07() {
    int *p, *q = NULL;
    cout << "&p = " << &p << endl;
    cout << "&q = " << &q << endl;
    for (int i = 0; i < 10; i++) {
        p = new int;
        cout << "p = new int direccion:" << p << endl;
        delete q;
        cout << "delete q direccion:" << q << endl;
        *p = i;
        cout << "*p = " << *p << endl;
        q = p;
    }
    delete q;
    cout << "delete" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
}

void regla08() {
    int *p, *q, a;
    cout << "&p = " << &p << endl;
    cout << "&q = " << &q << endl;
    cout << "&a = " << &a << endl;
    a = 123;
    q = new int;
    *q = 234;
    cout << "Asignaciones" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "a = " << a << endl;
    //cout << "*p = " << *p << endl; // puede tronar por no tener una referencia valida
    cout << "*q = " << *q << endl;
    p = &a;
    (*p)++;
    cout << "p = &a" << endl;
    cout << "p = " << p << endl; 
    p = q;
    *p = a * 10;
    cout << "p = q" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "a = " << a << endl; 
    cout << "*q = " << *q << endl;
}

void regla09Comparaciones(int *p, int *q, int *r) {
    cout << "Comparaciones" << endl;
    if (p == q) {
        cout << "p == q" << endl;
    }
    if (q == r) {
        cout << "q == r" << endl;
    }
    if (r == p) {
        cout << "r == p" << endl;
    }
    if (p != q) {
        cout << "p != q" << endl;
    }
    if (q != r) {
        cout << "q != r" << endl;
    }
    if (r != p) {
        cout << "r != p" << endl;
    }
}

void regla09() {
    int *p, *q, *r, a = 123, b = 42, c = 111;
    cout << "&p = " << &p << endl;
    cout << "&q = " << &q << endl;
    cout << "&r = " << &r << endl;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    
    p = NULL;
    q = &a;
    r = new int;
    cout << "termina asignacion" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    regla09Comparaciones(p,q,r);
    p = &b;
    cout << "p = &b;" << endl;
    regla09Comparaciones(p,q,r);
    q++;
    cout << "q++;" << endl;
    regla09Comparaciones(p,q,r);
    delete r;
}

void regla10() {
    int *p, a;
    a = 5;
    p = new int;
    cout << "*p = " << *p << endl;
    *p = a;
    cout << "*p = " << *p << endl;
    (*p)++;
    cout << "(*p)++;" << endl;
    cout << "*p = " << *p << endl;
    (*p)+= a;
    cout << "(*p)+= a;" << endl;
    cout << "*p = " << *p << endl;
    (*p)*= a;
    cout << "(*p)*= a;" << endl;
    cout << "*p = " << *p << endl;
    (*p)/= 7;
    cout << "(*p)/= 7;" << endl;
    cout << "*p = " << *p << endl;
    
    delete p;
}