#ifndef BST_H
#define BST_H
#include "nodeT.h"
#include "..\Queue\queue.h"
#include <iostream>

class BST {
  private:
    nodeT *root;
    void borrar(nodeT*);
    nodeT* predecesor(nodeT*);
    void preorden(nodeT*);
    void inorden(nodeT*);
    void postorden(nodeT*);
  public:
    BST() {root = nullptr;}
    ~BST();
    bool search(int);
    void add(int);
    void del(int);
    void preorden() {preorden(root);}
    void inorden() {inorden(root);}
    void postorden() {postorden(root);}
    void porNivel();
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

void BST::del(int dato) {
    if (!search(dato))
        return; // no se encuentra el dato en el arbol
    nodeT *p = root, *padre = nullptr;
    //std::cout << "del" << std::endl;
    while (p->getData() != dato) {
        padre = p;
        //std::cout << p->getData() << std::endl;
        p = (p->getData() > dato) ? p->Left() : p->Right();
    }
    if (p->Left() == nullptr && p->Right() == nullptr) { // nodo sin hijos
        //std::cout << "nodo sin hijos" << std::endl;
        // Buscar el nodo padre
        padre;
        // Desconectarlo
        if (padre != nullptr) {
            if (padre->getData() > dato)
                padre->setLeft(nullptr); // el nodo a borrar estaba a la izquierda del padre
            else
                padre->setRight(nullptr); // el nodo a borrar estaba a la derecha del padre
        }
        else {
            root = nullptr;
        }
        // Liberar el nodo
        //std::cout << "del caso sin hijos " << p->getData() << std::endl;
        delete p;
    }
    else if (p->Left() != nullptr && p->Right() != nullptr) { // tiene dos hijos
        //std::cout << "nodo con dos hijos" << std::endl;
        // Localizar el nodo predecesor o sucesor del nodo a borrar
        nodeT *pred = p->Left();
        padre = p; // puntero para seguir al padre del predecesor
        //std::cout << pred->getData() << std::endl;
        while (pred->Right() != nullptr) {
            padre = pred;
            std::cout << pred->getData() << std::endl;
            pred = pred->Right();
        }
        //std::cout << "predecesor: " << pred->getData() << std::endl;
        //std::cout << "Padre del predecesor: " << padre->getData() << std::endl;
        // Eliminar el predecesor o sucesor según sea el caso
        if (padre->getData() > pred->getData())
            padre->setLeft(nullptr);
        else
            padre->setRight(nullptr);
        // Copiar la informacion
        //std::cout << "Reemplazamos " << p->getData() << " por " << pred->getData() << std::endl;
        p->setData(pred->getData());
        //std::cout << "del caso 2 hijos " << dato << " se borra predecesor: " << p->getData() << std::endl;
        delete pred;
    }
    else { // tiene un hijo
        //std::cout << "nodo con un hijo" << std::endl;
        // Buscar el nodo padre del nodo a borrar
        padre;
        // Conectar el hijo con el padre del nodo a borrar
        nodeT *hijo;
        hijo = (p->Left() == nullptr) ? p->Right() : p->Left();
        if (padre != nullptr) {
            if (dato < padre->getData())
                padre->setLeft(hijo);
            else
                padre->setRight(hijo);
        }
        else {
            root = hijo;
        }
        // Liberar el nodo
        //std::cout << "del caso 1 hijo " << p->getData() << std::endl;
        delete p;
    }
}

nodeT* BST::predecesor(nodeT* nodo) {
    nodeT *pred;
    pred = nodo->Left();
    while (pred->Right() != nullptr) {
        pred = pred->Right();
    }
    return pred;
}

void BST::preorden(nodeT *nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->getData() << " ";
        preorden(nodo->Left());
        preorden(nodo->Right());
    }
}

void BST::inorden(nodeT *nodo) {
    if (nodo != nullptr) {
        inorden(nodo->Left());
        std::cout << nodo->getData() << " ";
        inorden(nodo->Right());
    }
}

void BST::postorden(nodeT *nodo) {
    if (nodo != nullptr) {
        postorden(nodo->Left());
        postorden(nodo->Right());
        std::cout << nodo->getData() << " ";
    }
}

void BST::porNivel() {
    queue<nodeT*> fila;
    nodeT* p;
    if (root != nullptr)
        fila.push(root);
    while (!fila.isEmpty()) {
        p = fila.front();
        fila.pop();
        std::cout << p->getData() << " ";
        if (p->Left() != nullptr) fila.push(p->Left());
        if (p->Right() != nullptr) fila.push(p->Right());
    }
}
#endif