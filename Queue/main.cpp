#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    queue Q;
    int a;
    for (int i = 0; i < 15; i++) {
        Q.push(rand() % 50 - 25);
        cout << "front: " << Q.front() << endl;
        Q.print();
    }
    for (int i = 0; i < 5; i++) {
        Q.pop();
        cout << "pop" << endl;
        cout << "front: " << Q.front() << endl;
        Q.print();
    }
    for (int i = 0; i < 15; i++) {
        a = rand();
        if (a % 2) {
            Q.pop();
            cout << "a: pop" << endl;
        }
        else {
            Q.push(a % 50  -25);
            cout << "push " << a % 50 << endl;
        }
        cout << "front: " << Q.front() << endl;
        Q.print();
    }
    while (!Q.isEmpty()) {
        Q.pop();
        Q.print();
    }
    cout << "termina" << endl;
    return 0;
}