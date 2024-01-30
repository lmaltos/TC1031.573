#ifndef HASH_H
#define HASH_H
#define MAX_HASH_SIZE 37
#include <ostream>

enum status {
    ocupado,
    vacio,
    borrado,
};

template <typename T>
class cell {
  private:
    status s;
    T dato;
  public:
    cell() {s = vacio;}
    status Status() {return s;}
    //void setStatus(status _s) {s = _s;}
    T Value() {return dato;}
    void setValue(T newDato) {dato = newDato; s = ocupado;}
    void delValue() {s = borrado;}
};

template <typename T>
class Hash {
  private:
    cell<T> A[MAX_HASH_SIZE];
    int (*pFncn)(T);
    int funcionHash(T);
    int _search(T);
  public:
    Hash(int (*)(T));
    bool search(T);
    void add(T);
    void del(T);
    status Status(int idx) {return A[idx].Status();}
    T operator[](int idx) {return A[idx].Value();}
    void print();
};

template <typename T>
Hash<T>::Hash(int (*p)(T)) {
    pFncn = p;
}

template <typename T>
int Hash<T>::funcionHash(T dato) {
    int idx = (*pFncn)(dato);
    idx %= MAX_HASH_SIZE; // nos garantiza que quede un valor entre 0 y MAX_HASH_SIZE
    return idx;
}

/// @brief Busca el indice donde se encuentra el dato
/// @tparam T 
/// @param dato 
/// @return 
template <typename T>
int Hash<T>::_search(T dato) {
    int idx0 = funcionHash(dato), idx;
    idx = idx0;
    while (A[idx].Status() != vacio) {
        if (A[idx].Status() == ocupado && A[idx].Value() == dato)
            return idx;
        idx++;
        if (idx == MAX_HASH_SIZE) idx = 0;
        if (idx == idx0) break; // ya recorrimos todo el arreglo
    }
    return -1; // el dato no esta en nuestro arreglo
}

/// @brief Determina si el dato esta en nuestro hash
/// @tparam T 
/// @param dato 
/// @return 
template <typename T>
bool Hash<T>::search(T dato) {
    int idx = _search(dato);
    return idx >= 0;
}

template <typename T>
void Hash<T>::add(T dato) {
    if (search(dato))
        return; // no se puede agregar porque ya esta
    int idx0 = funcionHash(dato), idx;
    idx = idx0;
    while (A[idx].Status() == ocupado) {
        idx++;
        if (idx == MAX_HASH_SIZE) idx = 0;
        if (idx == idx0) return; // ya recorrimos todo el arreglo, no cabe :(
    }
    A[idx].setValue(dato);
}

template <typename T>
void Hash<T>::del(T dato) {
    if (!search(dato))
        return; // no se puede elminiar porque no esta
    int idx = _search(dato);
    A[idx].delValue();
}

template <typename T>
void Hash<T>::print() {
    for (int i = 0; i < MAX_HASH_SIZE; i++){
        if (Status(i) == ocupado) {
            std::cout << i << ":" << (*this)[i] << std::endl;
        }
    }
}

#endif