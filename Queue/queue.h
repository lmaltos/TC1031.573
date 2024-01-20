#ifndef QUEUE_H
#define QUEUE_H
#include "..\linkedList\nodo.h"
#include <iostream>

template <typename T>
class queue {
  private:
    nodo<T> *tail;
    int size;
  public:
    queue();
    ~queue();
    void push(T);
    void pop();
    T front();
    bool isFull();
    bool isEmpty();
    void print();
};

template <typename T>
queue<T>::queue() {
    tail = nullptr;
    size = 0;
}

template <typename T>
queue<T>::~queue() {
    nodo<T> *p,*q;
    p = tail->getNext();
    for (int i = 0;i < size; i++) {
        q = p->getNext();
        //std::cout << "~delete p " << p->getData() << std::endl;
        delete p;
        p = q;
    }
    tail;
}

template <typename T>
void queue<T>::push(T dato) {
    nodo<T> *nuevo;
    nodo<T> *primero;
    nuevo = new nodo<T>(dato);
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

template <typename T>
void queue<T>::pop() {
    nodo<T> *primero,*segundo;
    if (isEmpty()) return;
    primero = tail->getNext();
    segundo = primero->getNext();
    //std::cout << "pop() delete primero " << primero->getData() << std::endl;
    delete primero;
    if (primero == segundo) { // solo habia un elemento
        tail = nullptr; // 
    }
    else {
        tail->setNext(segundo);
    }
    size--;
}

template <typename T>
T queue<T>::front() {
    nodo<T> *primero;
    primero = tail->getNext();
    return primero->getData();
}

template <typename T>
bool queue<T>::isFull() {
    return false; // no tiene llenadera
}

template <typename T>
bool queue<T>::isEmpty() {
    return (tail == nullptr);
}

template <typename T>
void queue<T>::print() {
    if (isEmpty())
        return;
    std::cout << "[ ";
    nodo<T> *p;
    p = tail->getNext();
    for (int i = 0;i < size; i++) {
        //std::cout << p->getData() << " ";
        p = p->getNext();
    }
    std::cout << "]";
}

#endif