#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "nodo.h"
#include <iostream>

template <typename T>
class linkedList {
  private:
    nodo<T>* head;
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
    void addFirst(T);
    // sumar los elementos
    // buscar elemento
    // concatenar listas
    // borrar un elemento
    // modificar un elemento
};

template <typename T>
linkedList<T>::~linkedList() {
    nodo<T>* p = head, *q;
    for (int i = 0; i < size; i++) {
        q = p->getNext();
        //std::cout << "delete p: " << p->getData() << std::endl;
        delete p;
        p = q;
    }
}

template <typename T>
void linkedList<T>::addFirst(T data) {
    nodo<T>* nuevo; // primer paso crear el nodo
    nuevo = new nodo<T>(data);
    nuevo->setNext(head); // guardar referencia al head anterior
    head = nuevo; // ultimo paso actualizar head
    size++;
    //delete nuevo; // ???
}

template <typename T>
void linkedList<T>::print() {
    nodo<T>* p = head;
    for (int i = 0; i < size; i++) {
        std::cout << p->getData() << std::endl;
        p = p->getNext();
    }
}

#endif