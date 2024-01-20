#ifndef NODO_H
#define NODO_H

template <typename T>
class nodo {
  private:
    T data;
    nodo* next;
  public:
    nodo(T);
    nodo(T,nodo*);
    T getData() {return data;}
    nodo* getNext();
    void setData(T);
    void setNext(nodo*);
};

template <typename T>
nodo<T>::nodo(T _data) {
    data = _data;
    next = nullptr; // NULL
}

template <typename T>
nodo<T>::nodo(T _data,nodo<T>* _next) {
    data = _data;
    next = _next;
}

template <typename T>
nodo<T>* nodo<T>::getNext() {
    return next;
}

template <typename T>
void nodo<T>::setData(T _data) {
    data = _data;
}

template <typename T>
void nodo<T>::setNext(nodo<T>* _next) {
    next = _next;
}
#endif