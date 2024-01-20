#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
    linkedList<int> listaInts;
    for (int i = 0; i < 100; i++) {
        listaInts.addFirst(rand() % 500);
    }
    //listaInts.print();
    linkedList<string> L;
    L.addFirst("Olla");
    L.addFirst("Estufa");
    L.addFirst("Jarra");
    L.addFirst("Plato");
    L.print();
    cout << "Creamos lista de listas de ints" << endl;
    linkedList<linkedList<int>*> listaDeListas;
    listaDeListas.addFirst(&listaInts);
    listaDeListas.addFirst(&listaInts);
    listaDeListas.addFirst(&listaInts);
    listaDeListas.addFirst(&listaInts);
    listaDeListas.addFirst(&listaInts);
    cout << "de tamaño " << listaDeListas.getSize() << endl;
}