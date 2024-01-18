#ifndef QUEUEINT_H
#define QUEUEINT_H
#define MAX_QUEUE_SIZE 10
#include <iostream>

class queueInt {
  private:
    int datos[MAX_QUEUE_SIZE];
    int ini, fin;
  public:
    queueInt();
    void push(int);
    void pop();
    int front();
    bool isFull();
    bool isEmpty();
    void print();
};

queueInt::queueInt() {
    ini = fin = -1;
}

void queueInt::push(int dato) {
    if (isFull())
        return;
    if (isEmpty()) {
        ini++;
    }
    fin++;
    if (fin == MAX_QUEUE_SIZE)
        fin = 0;
    datos[fin] = dato;
}

void queueInt::pop() {
    if (isEmpty())
        return;
    if (ini == fin) { // queda solo un elemento
        ini = fin = -1;
    }
    else {
        ini++;
        if (ini == MAX_QUEUE_SIZE)
            ini = 0;
    }
}

int queueInt::front() {
    return datos[ini];
}

bool queueInt::isFull() {
    return ((fin + 1) % MAX_QUEUE_SIZE == ini);
}

bool queueInt::isEmpty() {
    return (ini == -1);
}

void queueInt::print() {
    std::cout << "[ ";
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (ini <= fin) {
            if (i >= ini && i <= fin)
                std::cout << datos[i] << " ";
            else 
                std::cout << "# ";
        }
        else {
            if (i >= ini || i <= fin)
                std::cout << datos[i] << " ";
            else
                std::cout << "# ";
        }
    }
    std::cout << "]";
}

#endif