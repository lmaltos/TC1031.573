#ifndef NODO_INT_H
#define NODO_INT_H

class nodo_int {
  private:
    int data;
    nodo_int* next;
  public:
    nodo_int(int);
    nodo_int(int,nodo_int*);
    int getData();
    nodo_int* getNext();
    void setData(int);
    void setNext(nodo_int*);
};

#endif