#include <iostream>
#include "AVL.h"

using namespace std;

int main2() {
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
    cout << "\nInorden" << endl;
    miArbol.inorden();
    cout << "\nPostorden" << endl;
    miArbol.postorden();
    cout << "\nPor Nivel" << endl;
    miArbol.porNivel();
    miArbol.del(13);
    cout << "\nPreorden" << endl;
    miArbol.preorden();
    cout << "\nInorden" << endl;
    miArbol.inorden();
    cout << "\nPostorden" << endl;
    miArbol.postorden();
    cout << "\nPor Nivel" << endl;
    miArbol.porNivel();
    cout << endl;
    for (int i = 10; i < 34; i++) {
        cout << "Busca " << i << (miArbol.search(i) ? " encontrado" : " no encontrado") << endl;
    }
    return 0;
}

int main() {
    AVL arbol;
    for (int i = 0; i < 50; i++) {
        arbol.add(i);
        if ((i + 1) % 10 == 0){
            arbol.porNivel();
            cout << endl;
        }
    }
}