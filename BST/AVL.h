#ifndef AVL_H
#define AVL_H
#include "BST.h"

class AVL : public BST {
  private:
    bool isBalanced(nodeT*);
    bool balanced(nodeT*);
    int altura(nodeT*);
    void intercambia(nodeT*,nodeT*);
  public:
    void add(int);
};

void AVL::add(int dato) {
    std::cout << "AVL::add " << dato << std::endl;
    BST::add(dato);
    // validar se mantenga balance
    if (isBalanced(root))
        return;
    std::cout << "AVL::add desbalanceado" << std::endl;
    // si no estsa balanceado, identificar el tipo de rotacion a realizar
    nodeT *p = root, *pivote;
    while (p->getData() != dato) {
        if (!balanced(p)) {
            pivote = p;
        }
        p = p->getData() > dato ? p->Left() : p->Right();
    }
    // p apunta al nodo recien agregado
    // pivote apunta al ancestro mas cercano con desbalance
    if (pivote->getData() < dato) {
        nodeT *A = pivote->Right();
        if (A->getData() < dato) {
            std::cout << "AVL::add RSI" << std::endl;
            // Rotacion simple a la izquierda
            pivote->setRight(A->Left());
            A->setLeft(pivote);
            intercambia(pivote,A);
        }
        else {
            // Rotacion doble a la izquierda
        }
    }
    else {
        nodeT *A = pivote->Left();
        // Rotacion simple a la derecha
        // Rotacion doble a la derecha
    }

}

/// @brief Valida que el nodo y sus subarboles esten balanceados
/// @param nodo 
/// @return 
bool AVL::isBalanced(nodeT *nodo) {
    if (nodo == nullptr)
        return true;
    if (!isBalanced(nodo->Left()))
        return false;
    if (!isBalanced(nodo->Right()))
        return false;
    return balanced(nodo);
}

/// @brief Valida que el nodo este balanceado
/// @param nodo 
/// @return 
bool AVL::balanced(nodeT *nodo) {
    int altL = altura(nodo->Left());
    int altR = altura(nodo->Right());
    std::cout << "nodo(" << nodo->getData() << ") altIzq = " << altL << " altDer = " << altR << std::endl;
    if (altL > altR + 1 || altR > altL + 1)
        return false;
    return true;
}

int AVL::altura(nodeT* nodo) {
    if (nodo == nullptr)
        return 0;
    int altL = altura(nodo->Left());
    int altR = altura(nodo->Right());
    return 1 + ((altL > altR) ? altL : altR);
}

/// @brief Cambia la referencia que apuntaba a B ahora apunta a A
/// @param B 
/// @param A 
void AVL::intercambia(nodeT *B,nodeT *A) {
    // buscar el padre de B, hacer que apunte a A
    nodeT *p = root, *padre = nullptr;
    while (p != B) {
        padre = p;
        p = p->getData() > B->getData() ? p->Left() : p->Right();
    }
    if (padre == nullptr) {
        root = A;
    }
    else {
        if (padre->getData() > B->getData())
            padre->setLeft(A);
        else
            padre->setRight(A);
    }
}

#endif