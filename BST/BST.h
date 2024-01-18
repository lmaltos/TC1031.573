#ifndef BST_H
#define BST_H
#include "nodeT.h"
#include <iostream>

class BST {
  private:
    nodeT *root;
    void borrar(nodeT*);
  public:
    BST() {root = nullptr;}
    ~BST();
    bool search(int);
    void add(int);
};

BST::~BST() {
    borrar(root);
}

void BST::borrar(nodeT *nodo) {
    if (nodo == nullptr)
        return;
    borrar(nodo->Left());
    borrar(nodo->Right());
    std::cout << "~delete nodo " << nodo->getData() << std::endl;
    delete nodo;
}

bool BST::search(int dato) {
    nodeT *p = root;
    while (p != nullptr) {
        if (p->getData() == dato)
            return true; // se encontro el dato
        p = (p->getData() > dato) ? p->Left() : p->Right();
    }
    return false; // no se encontro el dato
}

void BST::add(int dato) {
    if (search(dato))
        return; // ya esta en nuestro arbol
    nodeT *p = root, *padre = nullptr;
    while (p != nullptr) {
        padre = p;
        p = (p->getData() > dato) ? p->Left() : p->Right();
    }
    nodeT *nuevo;
    nuevo = new nodeT(dato); // creamos nuevo nodo
    if (padre != nullptr) { // agregamos hijo al padre
        if (padre->getData() > dato)
            padre->setLeft(nuevo);
        else
            padre->setRight(nuevo);
    }
    else { // este elemento sera el root por ser el primer elemento a agregar
        root = nuevo;
    }
}

#endif