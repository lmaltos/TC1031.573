#ifndef STACK_H
#define STACK_H
#include "..\LinkedList\nodo_int.h"
#include <iostream>

class stack {
  private:
    nodo_int* _top;
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

stack::stack() {
    size = 0;
    _top = nullptr; // NULL
}

stack::~stack() {
    nodo_int *p, *q;
    p = _top;
    for(int i = 0; i < size; i++) {
        q = p->getNext();
        std::cout << "~delete top " << p->getData() << std::endl;
        delete p;
        p = q;
    }
}

bool stack::isFull () {
    return false;
}

bool stack::isEmpty() {
    return (size == 0);
}

void stack::push(int dato) {
    nodo_int *nuevo;
    nuevo = new nodo_int(dato,_top);
    _top = nuevo;
    size++;
}

void stack::pop() {
    if (isEmpty())
        return;
    nodo_int *p;
    p = _top->getNext();
    std::cout << "delete top " << _top->getData() << std::endl;
    delete _top; // liberamos memoria dinamica
    _top = p;
    size--;
}

int stack::top() {
    return _top->getData();
}

#endif