#include "myClass.h"
#include <iostream>

int main() {
    myClass x,y(1,2,'x');
    std::cout << "x.a = " << x.getA() << std::endl;
    std::cout << "x.b = " << x.getB() << std::endl;
    std::cout << "y.a = " << y.getA() << std::endl;
    std::cout << "y.b = " << y.getB() << std::endl;
    return 0;
}