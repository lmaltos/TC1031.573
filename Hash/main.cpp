#include <iostream>
#include "Hash.h"

using namespace std;

int myfuncion(int a) {
    return a % MAX_HASH_SIZE;
}

int otraFuncion(int a) {
    return a * a % MAX_HASH_SIZE;
}

int main() {
    Hash<int> S(&otraFuncion);
    for (int i = 0; i < 15; i++) {
        int a = rand() % 100;
        cout << a << " ";
        S.add(a);
    }
    cout << endl;
    cout << "Tabla hash:" << endl;
    S.print();
}