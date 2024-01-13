#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "nodo_int.h"
#include <iostream>

class linkedList {
  private:
    nodo_int* head;
    int size;
  public:
    linkedList() {
        head = nullptr;
        size = 0;
    }
    ~linkedList(); // destructor
    // imprimr
    void print();
    // ordenar
    // contar
    int getSize() {return size;}
    // almacenar
    // agregar un elemnto
    void addFirst(int);
    // sumar los elementos
    // buscar elemento
    // concatenar listas
    // borrar un elemento
    // modificar un elemento
};

linkedList::~linkedList() {
    nodo_int* p = head, *q;
    for (int i = 0; i < size; i++) {
        q = p->getNext();
        //std::cout << "delete p: " << p->getData() << std::endl;
        delete p;
        p = q;
    }
}

void linkedList::addFirst(int data) {
    nodo_int* nuevo; // primer paso crear el nodo
    nuevo = new nodo_int(data);
    nuevo->setNext(head); // guardar referencia al head anterior
    head = nuevo; // ultimo paso actualizar head
    size++;
    //delete nuevo; // ???
}

void linkedList::print() {
    nodo_int* p = head;
    for (int i = 0; i < size; i++) {
        std::cout << p->getData() << std::endl;
        p = p->getNext();
    }
}

#endif