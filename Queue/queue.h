#ifndef QUEUE_H
#define QUEUE_H
#include "..\LinkedList\nodo_int.h"
#include <iostream>

class queue {
  private:
    nodo_int *tail;
    int size;
  public:
    queue();
    ~queue();
    void push(int);
    void pop();
    int front();
    bool isFull();
    bool isEmpty();
    void print();
};

queue::queue() {
    tail = nullptr;
    size = 0;
}

queue::~queue() {
    nodo_int *p,*q;
    p = tail->getNext();
    for (int i = 0;i < size; i++) {
        q = p->getNext();
        std::cout << "~delete p " << p->getData() << std::endl;
        delete p;
        p = q;
    }
    tail;
}

void queue::push(int dato) {
    nodo_int *nuevo;
    nodo_int *primero;
    nuevo = new nodo_int(dato);
    if (tail == nullptr) {
        primero = nuevo; // es el mismo el primer elemento
    }
    else {
        primero = tail->getNext();
        tail->setNext(nuevo); // penultimo elemento apunta al ultimo
    }
    //primero = (tail == nullptr) ? nuevo : tail->getNext(); // alternativa a codigo anterior
    nuevo->setNext(primero); // nuevo ultimo elemento apunta al primero
    tail = nuevo; // actualizamos referencia a el ultimo elemento
    size++;
}

void queue::pop() {
    nodo_int *primero,*segundo;
    if (isEmpty()) return;
    primero = tail->getNext();
    segundo = primero->getNext();
    std::cout << "pop() delete primero " << primero->getData() << std::endl;
    delete primero;
    if (primero == segundo) { // solo habia un elemento
        tail = nullptr; // 
    }
    else {
        tail->setNext(segundo);
    }
    size--;
}

int queue::front() {
    nodo_int *primero;
    primero = tail->getNext();
    return primero->getData();
}

bool queue::isFull() {
    return false; // no tiene llenadera
}

bool queue::isEmpty() {
    return (tail == nullptr);
}

void queue::print() {
    if (isEmpty())
        return;
    std::cout << "[ ";
    nodo_int *p;
    p = tail->getNext();
    for (int i = 0;i < size; i++) {
        std::cout << p->getData() << " ";
        p = p->getNext();
    }
    std::cout << "]";
}

#endif