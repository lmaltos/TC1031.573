#ifndef NODO_STR_H
#define NODO_STR_H
#include <string>

class nodo_str {
  private:
    std::string data;
    nodo_str* next;
  public:
    nodo_str(std::string);
    nodo_str(std::string,nodo_str*);
    std::string getData();
    nodo_str* getNext();
    void setData(std::string);
    void setNext(nodo_str*);
};

nodo_str::nodo_str(std::string _data) {
    data = _data;
    next = nullptr; // NULL
}

nodo_str::nodo_str(std::string _data,nodo_str* _next) {
    data = _data;
    next = _next;
}

std::string nodo_str::getData() {
    return data;
}

nodo_str* nodo_str::getNext() {
    return next;
}

void nodo_str::setData(std::string _data) {
    data = _data;
}

void nodo_str::setNext(nodo_str* _next) {
    next = _next;
}

#endif