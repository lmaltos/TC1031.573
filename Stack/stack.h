#ifndef STACK_H
#define STACK_H
#include "..\LinkedList\nodo.h"
#include <iostream>

template <typename T>
class stack {
  private:
    nodo<T>* _top;
    int size;
  public:
    stack();
    ~stack();
    bool isFull();
    bool isEmpty();
    void push(int);
    void pop();
    int top();
};

template <typename T>
stack<T>::stack() {
    size = 0;
    _top = nullptr; // NULL
}

template <typename T>
stack<T>::~stack() {
    nodo<T> *p, *q;
    p = _top;
    for(int i = 0; i < size; i++) {
        q = p->getNext();
        std::cout << "~delete top " << p->getData() << std::endl;
        delete p;
        p = q;
    }
}

template <typename T>
bool stack<T>::isFull () {
    return false;
}

template <typename T>
bool stack<T>::isEmpty() {
    return (size == 0);
}

template <typename T>
void stack<T>::push(int dato) {
    nodo<T> *nuevo;
    nuevo = new nodo<T>(dato,_top);
    _top = nuevo;
    size++;
}

template <typename T>
void stack<T>::pop() {
    if (isEmpty())
        return;
    nodo<T> *p;
    p = _top->getNext();
    std::cout << "delete top " << _top->getData() << std::endl;
    delete _top; // liberamos memoria dinamica
    _top = p;
    size--;
}

template <typename T>
int stack<T>::top() {
    return _top->getData();
}

#endif