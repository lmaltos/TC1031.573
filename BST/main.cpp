#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST miArbol;
    cout << "Agrega elementos" << endl;
    miArbol.add(20);
    miArbol.add(13);
    miArbol.add(10);
    miArbol.add(18);
    miArbol.add(33);
    miArbol.add(21);
    miArbol.add(25);
    cout << "Preorden" << endl;
    miArbol.preorden();
    cout << "Inorden" << endl;
    miArbol.preorden();
    miArbol.del(13);
    cout << "Preorden" << endl;
    miArbol.preorden();
    cout << "Inorden" << endl;
    miArbol.preorden();
    cout << endl;
    for (int i = 10; i < 34; i++) {
        cout << "Busca " << i << (miArbol.search(i) ? " encontrado" : " no encontrado") << endl;
    }
    return 0;
}