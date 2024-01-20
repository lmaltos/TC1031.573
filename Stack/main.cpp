#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack s;
    for (int i = 0; i < 20; i++) {
        s.push(rand() % 50);
        cout << "top: " << s.top() << endl;
    }
    for (int i = 0; i < 5; i++) {
        s.pop();
        cout << "pop()" << endl;
        cout << "top: " << s.top() << endl;
    }
    return 0;
}