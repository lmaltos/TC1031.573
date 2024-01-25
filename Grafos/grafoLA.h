#ifndef GRAFOLA_H
#define GRAFOLA_H
#include <string>

class nodoAdyacente;
class nodoLA;

class grafoLA {
  private:
    nodoLA *head;
    bool dirigido = true;
    nodoLA* addNodo(std::string);
  public:
    grafoLA() {head = nullptr;}
    nodoLA *buscarNodo(std::string);
    void addAdyacencia(std::string,std::string);
    bool sonAdyacentes(std::string,std::string);
};

nodoLA *grafoLA::buscarNodo(std::string id) {
    nodoLA *p = head;
    while (p != nullptr) {
        if (p->getId() == id) {
            return p;
        }
        p = p->getNext();
    }
}

nodoLA* grafoLA::addNodo(std::string id) {

}

void grafoLA::addAdyacencia(std::string idA,std::string idB) {
    nodoLA *A = buscarNodo(idA);
    nodoLA *B = buscarNodo(idB);
    A->addAdyacencia(idB);
    if (dirigido)
        B->addAdyacencia(idA);
}

bool grafoLA::sonAdyacentes(std::string idA,std::string idB){
    return true; // ToDo
}

class nodoLA {
  private:
    std::string id;
    nodoLA *next;
    nodoAdyacente *head;
  public:
    nodoLA(std::string);
    std::string getId() {return id;}
    nodoLA *getNext() {return next;}
    void setNext(nodoLA* _next) {next = _next;}
    bool esAdyacente(std::string);
    void addAdyacencia(std::string);
    void delAdyacencia(std::string);
};

bool nodoLA::esAdyacente(std::string idA) {
    nodoAdyacente *p = head;
    while (p != nullptr) {
        if (p->getId() == idA)
            return true;
        p = p->getNext();
    }
    return false;
}

void nodoLA::addAdyacencia(std::string idB) {
    nodoAdyacente *p = new nodoAdyacente(idB,head);
    head = p;
}

void nodoLA::delAdyacencia(std::string idB) {
    nodoAdyacente *p = head, *q = nullptr;
    while (p != nullptr) {
        if (p->getId() == idB) {
            if (q == nullptr) {
                head = p->getNext();
            }
            else {
                q->setNext(p->getNext());
            }
            delete p;
            return;
        }
        q = p;
        p = p->getNext();
    }
}

class nodoAdyacente {
  private:
    std::string id;
    nodoAdyacente *next;
  public:
    nodoAdyacente(std::string);
    nodoAdyacente(std::string, nodoAdyacente*);
    std::string getId() {return id;}
    nodoAdyacente* getNext() {return next;}
    void setNext(nodoAdyacente* _next) {next = _next;}
};

nodoAdyacente::nodoAdyacente(std::string _id) {
    id = _id;
    next = nullptr;
}

nodoAdyacente::nodoAdyacente(std::string _id, nodoAdyacente* _next) {
    id = _id;
    next = _next;
}

#endif