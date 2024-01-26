#ifndef GRAFO_H
#define GRAFO_H
#include <string>
class arco {
  private:
    std::string X; // nodo origen
    std::string Y; // nodo destino
    arco* nextX; // pointer a otro arco con origen en X
    arco* nextY; // pointer a otro arco con destino en Y
  public:
    arco(std::string,std::string);
    std::string getOrigen() {return X;}
    std::string getDestino() {return Y;}
    arco* getNextX() {return nextX;}
    arco* getNextY() {return nextY;}
    void setNextX(arco* next) {nextX = next;}
    void setNextY(arco* next) {nextY = next;}
};

arco::arco(std::string idOrigen,std::string idDestino) {
    X = idOrigen;
    Y = idDestino;
    nextX = nullptr;
    nextY = nullptr;
}

class nodo {
  private:
    std::string id;
    nodo * next; // pointer a nodo siguiente en la lista
    arco *headOrigen; // lista de arcos en los cuales el nodo es origen
    arco* headDestino; // lista de arcos en los cuales el nodo es destino
  public:
    nodo(std::string);
    std::string getId() {return id;}
    nodo* getNext() {return next;}
    void setNext(nodo* _next) {next = _next;}
    void addArco(arco*);
    void addArco(nodo*);
    bool esAdyacente(nodo*);
    bool esAdyacente(std::string);
};

nodo::nodo(std::string){
    // ToDo
}

void nodo::addArco(arco*){
    // ToDo
}

void nodo::addArco(nodo*){
    // ToDo
}

bool nodo::esAdyacente(nodo*){
    return false;
    // ToDo
}

bool nodo::esAdyacente(std::string){
    return false;
    // ToDo
}

class grafo {
  private:
    nodo* head; // lista de nodos
  public:
    grafo();
    nodo* addNodo(std::string);
    nodo* buscarNodo(std::string);
    void addAdyacencia(std::string,std::string);
    bool sonAdyacentes(std::string,std::string);
};

nodo *grafo::buscarNodo(std::string id) {
    nodo *p = head;
    while (p != nullptr) {
        if (p->getId() == id) {
            return p;
        }
        p = p->getNext();
    }
    return addNodo(id);
}

nodo* grafo::addNodo(std::string id) {
    nodo *p = head, *tail = nullptr;
    while (p != nullptr) {
        tail = p;
        p = p->getNext();
    }
    p = new nodo(id);
    if (tail != nullptr) {
        tail->setNext(p);
    }
    else {
        head = p;
    }
    return p;
}

void grafo::addAdyacencia(std::string idA,std::string idB) {
    nodo *A = buscarNodo(idA);
    nodo *B = buscarNodo(idB);
    arco* adyacencia;
    adyacencia = new arco(idA,idB);
    A->addArco(adyacencia);
    B->addArco(adyacencia);
}

bool grafo::sonAdyacentes(std::string idA,std::string idB){
    nodo *A = buscarNodo(idA);
    return A->esAdyacente(idB);
}

#endif