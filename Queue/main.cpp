#include <iostream>
#include "queueInt.h"

using namespace std;

int main() {
    queueInt Q;
    int a;
    for (int i = 0; i < 15; i++) {
        Q.push(rand() % 50);
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
            Q.push(a % 50);
            cout << "push " << a % 50 << endl;
        }
        cout << "front: " << Q.front() << endl;
        Q.print();
    }
    return 0;
}