#ifndef HASH2_H
#define HASH2_H
#define HASH2_MAX_SIZE 67
#include <iostream>

class hashNode {
  private:
    int dato;
    hashNode* next;
  public:
    hashNode(int _dato) {dato = _dato; next = nullptr;}
    hashNode(int _dato, hashNode *_next) {dato = _dato; next = _next;}
    int Dato() {return dato;}
    hashNode* Next() {return next;}
    void SetDato(int _dato) {dato = _dato;}
    void SetNext(hashNode *_next) {next = _next;}
};

class Hash2 {
  private:
    hashNode *A[HASH2_MAX_SIZE];
    int funcionHash(int);
  public:
    Hash2();
    bool search(int);
    void add(int);
    void del(int);
    void print();
};

Hash2::Hash2() {
    for (int i = 0; i < HASH2_MAX_SIZE; i++) A[i] = nullptr;
}

int Hash2::funcionHash(int dato) {
    return dato % HASH2_MAX_SIZE;
}

bool Hash2::search(int dato) {
    int idx = funcionHash(dato);
    if (A[idx] == nullptr)
        return false; // no se ha recibido ningun dato con esa llave/indice
    hashNode *p = A[idx];
    while (p->Dato() != dato) {
        p = p->Next();
    }
    return p != nullptr;
}

void Hash2::add(int dato) {
    if (search(dato))
        return; // ya esta en nuestro hash
    int idx = funcionHash(dato);
    hashNode *p;
    p = new hashNode(dato,A[idx]);
    A[idx] = p;
}

void Hash2::del(int dato) {
    if (!search(dato))
        return; // no esta en nuestro hash
    int idx = funcionHash(dato);
    hashNode *p = A[idx], *q = nullptr;
    while (p->Dato() != dato) {
        q = p;
        p = p->Next();
    }
    if (q != nullptr) {
        q->SetNext(p->Next());
    }
    else {
        A[idx] = p->Next();
    }
    delete p;
}

void Hash2::print() {
    for (int i = 0; i < HASH2_MAX_SIZE; i++) {
        if (A[i] != nullptr) {
            std::cout << i << ":";
            hashNode *p = A[i];
            while (p != nullptr) {
                std::cout << " " << p->Dato();
                p = p->Next();
            }
            std::cout << std::endl;
        }
    }
}

#endif