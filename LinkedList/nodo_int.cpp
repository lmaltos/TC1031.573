#include "nodo_int.h"

nodo_int::nodo_int(int _data) {
    data = _data;
    next = nullptr; // NULL
}

nodo_int::nodo_int(int _data,nodo_int* _next) {
    data = _data;
    next = _next;
}

int nodo_int::getData() {
    return data;
}

nodo_int* nodo_int::getNext() {
    return next;
}

void nodo_int::setData(int _data) {
    data = _data;
}

void nodo_int::setNext(nodo_int* _next) {
    next = _next;
}