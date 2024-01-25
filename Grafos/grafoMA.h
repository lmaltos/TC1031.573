#ifndef GRAFOMA_H
#define GRAFOMA_H
#include <iostream>

class grafoMA {
  private:
    int n; // numero de nodos
    bool **A;
    char *tag;
    int findTag(char);
    bool dirigido;
  public:
    grafoMA(int);
    ~grafoMA();
    void setDirigido(bool _dirigido) {dirigido = _dirigido;}
    void setTag(int i,char a) {tag[i] = a;} // fija la etiqueta del nodo i
    void addArco(int i,int j) {A[i][j] = true;} // agrega arco de i -> j
    void delArco(int i,int j) {A[i][j] = false;} // borra arco de i -> j
    char getNodo(int i) {return tag[i];} // regresa la etiqueta del nodo i
    bool sonAdyacentes(int i,int j) {return A[i][j];}
    void addArco(char A,char B); // agrega arco de nodo A -> nodo B
    void delArco(char A,char B); // borra arco de nodo A -> nodo B
    bool sonAdyacentes(char A,char B);
};

grafoMA::grafoMA(int a) {
    n = a;
    A = new bool*[n]; // arreglo de n elementos bool*
    for (int i = 0; i < n; i++) {
        A[i] = new bool[n]; // arreglo de n elementos bool
        for (int j = 0; j < n; j++) A[i][j] = false; // limpiamos arreglo
    }
    tag = new char[n];
    dirigido = true;
}

grafoMA::~grafoMA() {
    for (int i = 0; i < n; i++) {
        delete[] A[i]; // borra arreglo de n elementos bool
    }
    delete[] A; // borra arreglo de n elementos bool*
    delete[] tag;
}

int grafoMA::findTag(char a) {
    for (int i = 0; i < n; i++) {
        if (tag[i] == a)
            return i;
    }
    return -1;
}

void grafoMA::addArco(char A,char B){
    int idxA = findTag(A);
    int idxB = findTag(B);
    if (idxA < 0 || idxB < 0) {
        return;
    }
    addArco(idxA,idxB);
    if (dirigido)
        addArco(idxB,idxA);
}

void grafoMA::delArco(char A,char B){
    int idxA = findTag(A);
    int idxB = findTag(B);
    if (idxA < 0 || idxB < 0){
        return;
    }
    delArco(idxA,idxB);
    if (dirigido)
        delArco(idxB,idxA);
}

bool grafoMA::sonAdyacentes(char A,char B) {
    int idxA = findTag(A);
    int idxB = findTag(B);
    if (idxA < 0 || idxB < 0) {
        return false;
    }
    return sonAdyacentes(idxA,idxB);
}

#endif