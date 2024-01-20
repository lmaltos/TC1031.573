#ifndef STACKINT_H
#define STACKINT_H

#define MAX_STACK_SIZE 10

class stackInt {
  private:
    int datos[MAX_STACK_SIZE];
    int tope;
  public:
    stackInt();
    bool isFull();
    bool isEmpty();
    void push(int);
    void pop();
    int top();
};

stackInt::stackInt() {
    tope = -1;
}

bool stackInt::isFull() {
    return (tope == MAX_STACK_SIZE - 1);
}

bool stackInt::isEmpty() {
    return (tope == -1);
}

void stackInt::push(int dato) {
    if (isFull())
        return;
    tope++;
    datos[tope] = dato;
}

void stackInt::pop() {
    if (isEmpty())
        return;
    tope--;
}

int stackInt::top() {
    return datos[tope];
}

#endif