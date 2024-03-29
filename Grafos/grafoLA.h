#ifndef GRAFOLA_H
#define GRAFOLA_H
#include <string>
#include <iostream>
#include "..\Queue\queue.h"
#include "..\Stack\stack.h"

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
    nodoAdyacente* getAdyacencias() {return head;}
};

class grafoLA {
  private:
    nodoLA *head;
    bool dirigido = true;
  public:
    grafoLA() {head = nullptr;}
    nodoLA* addNodo(std::string);
    nodoLA *buscarNodo(std::string) const;
    int getNodos() const;
    int buscarPosNodo(nodoLA*) const;
    void addAdyacencia(std::string,std::string);
    bool sonAdyacentes(std::string,std::string);
    void BreadthFirst(std::ostream&) const;
    void DepthFirst() const;
    friend std::ostream& operator<<(std::ostream&,const grafoLA&);
};

nodoLA::nodoLA(std::string _id) {
    id = _id;
    head = nullptr;
    next = nullptr;
}

nodoLA *grafoLA::buscarNodo(std::string id) const {
    nodoLA *p = head;
    while (p != nullptr) {
        if (p->getId() == id) {
            return p;
        }
        p = p->getNext();
    }
    return nullptr;
}

int grafoLA::buscarPosNodo(nodoLA *q) const{
    nodoLA *p = head;
    int n = 0;
    while (p != nullptr) {
        if (p == q) {
            return n;
        }
        n++;
        p = p->getNext();
    }
    return -1;
}

nodoLA* grafoLA::addNodo(std::string id) {
    nodoLA *p = head, *tail = nullptr;
    while (p != nullptr) {
        tail = p;
        p = p->getNext();
    }
    p = new nodoLA(id);
    if (tail != nullptr) {
        tail->setNext(p);
    }
    else {
        head = p;
    }
    return p;
}

void grafoLA::addAdyacencia(std::string idA,std::string idB) {
    nodoLA *A = buscarNodo(idA);
    nodoLA *B = buscarNodo(idB);
    A->addAdyacencia(idB);
    if (dirigido)
        B->addAdyacencia(idA);
}

bool grafoLA::sonAdyacentes(std::string idA,std::string idB){
    nodoLA *A = buscarNodo(idA);
    return A->esAdyacente(idB);
}

nodoAdyacente::nodoAdyacente(std::string _id) {
    id = _id;
    next = nullptr;
}

nodoAdyacente::nodoAdyacente(std::string _id, nodoAdyacente* _next) {
    id = _id;
    next = _next;
}

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
    nodoAdyacente *p,*last = nullptr;
    p = head;
    while (p != nullptr) {
        last = p;
        p = p->getNext();
    }
    p = new nodoAdyacente(idB);
    if (last != nullptr) {
        last->setNext(p);
    }
    else {
        head = p;
    }
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

enum Estatus {
    EnEspera,
    Procesado,
    Listo,
};

void grafoLA::BreadthFirst(std::ostream& os) const {
    os << "[";
    Estatus *estado;
    int n,i,k;
    nodoLA *p = head,*q,*r;
    n = 0;
    while (p != nullptr) {
        p = p->getNext();
        n++;
    }
    //std::cout << "hay " << n << " nodos" << std::endl;
    estado = new Estatus[n];
    for (i = 0; i < n; i++) {
        estado[i] = EnEspera;
    }
    p = head;
    i = 0;
    queue<nodoLA*> fila;
    while (p != nullptr) {
        if (estado[i] == EnEspera) {
            //std::cout << "nodo " << p->getId() << " en espera" << std::endl;
            fila.push(p);
        }
        while (!fila.isEmpty()) {
            q = fila.front();
            os << " " + q->getId();
            fila.pop(); // se remueve
            //std::cout << "nodo " << q->getId() << " visitado" << std::endl;
            k = buscarPosNodo(q);
            estado[k] = Procesado;
            nodoAdyacente* s = q->getAdyacencias();
            while (s != nullptr) {
                //std::cout << "nodo " << s->getId() << " adyacente a " << q->getId() << std::endl;
                r = buscarNodo(s->getId());
                k = buscarPosNodo(r);
                if (estado[k] == EnEspera) {
                    //std::cout << "nodo " << r->getId() << " en espera" << std::endl;
                    fila.push(r);
                    estado[k] = Listo;
                }
                s = s->getNext();
            }
        }
        i++;
        p = p->getNext();
    }
    os << " ]";
    delete[] estado;
    //std::cout << "termina BreadthFirst() " << ans << std::endl;
}

int grafoLA::getNodos() const {
    int n;
    nodoLA *p = head;
    n = 0;
    while (p != nullptr) {
        p = p->getNext();
        n++;
    }
    return n;
}

void grafoLA::DepthFirst() const {
    Estatus *estado;
    int n,i,k;
    nodoLA *p,*q,*r;
    n = getNodos();
    //std::cout << "hay " << n << " nodos" << std::endl;
    estado = new Estatus[n];
    for (i = 0; i < n; i++) {
        estado[i] = EnEspera;
    }
    stack<nodoLA*> pila;
    //std::cout << "Crea pila" << std::endl;
    i = 0;
    p = head;
    while (p != nullptr) {
        if (estado[i] == EnEspera) {
            //std::cout << "nodo " << p->getId() << " en espera" << std::endl;
            pila.push(p);
        }
        while (!pila.isEmpty()) {
            q = pila.top();
            pila.pop();
            k = buscarPosNodo(q);
            if (estado[k] == EnEspera) {
                estado[k] = Procesado; // se marca la visita del nodo
                std::cout << q->getId() << " ";
                nodoAdyacente* s = q->getAdyacencias();
                while (s != nullptr) {
                    //std::cout << "nodo " << s->getId() << " adyacente a " << q->getId() << std::endl;
                    r = buscarNodo(s->getId());
                    k = buscarPosNodo(r);
                    if (estado[k] != Procesado) {
                        //std::cout << "nodo " << r->getId() << " en espera" << std::endl;
                        pila.push(r);
                    }
                    s = s->getNext();
                }
            }
        }
        i++;
        p = p->getNext();
    }

    delete[] estado;
}

std::ostream& operator<<(std::ostream& os,const grafoLA& G) {
    G.BreadthFirst(os);
    return os;
}

#endif