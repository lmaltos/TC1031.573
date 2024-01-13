#ifndef LINKEDLISTSTR_H
#define LINKEDLISTSTR_H
#include "nodo_str.h"
#include <iostream>

class linkedList {
  private:
    nodo_str* head;
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
    void addFirst(std::string);
    // sumar los elementos
    // buscar elemento
    // concatenar listas
    // borrar un elemento
    // modificar un elemento
};

linkedList::~linkedList() {
    nodo_str* p = head, *q;
    for (int i = 0; i < size; i++) {
        q = p->getNext();
        //std::cout << "delete p: " << p->getData() << std::endl;
        delete p;
        p = q;
    }
}

void linkedList::addFirst(std::string data) {
    nodo_str* nuevo; // primer paso crear el nodo
    nuevo = new nodo_str(data);
    nuevo->setNext(head); // guardar referencia al head anterior
    head = nuevo; // ultimo paso actualizar head
    size++;
    //delete nuevo; // ???
}

void linkedList::print() {
    nodo_str* p = head;
    for (int i = 0; i < size; i++) {
        std::cout << p->getData() << std::endl;
        p = p->getNext();
    }
}

#endif