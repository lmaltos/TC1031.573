#include "myClass.h"
#include <iostream>

int main() {
    myClass<int,char> x(99,100,4.5f),y(1,2,'x');
    myClass<char,std::string> z('x','y',"Hola mundo de los templates");
    myClass<myClass<int,char>,char> w(x,y,'z');
    std::cout << "x.a = " << x.getA() << std::endl;
    std::cout << "x.b = " << x.getB() << std::endl;
    std::cout << "y.a = " << y.getA() << std::endl;
    std::cout << "y.b = " << y.getB() << std::endl;
    std::cout << "z.a = " << z.getA() << std::endl;
    std::cout << "z.b = " << z.getB() << std::endl;
    std::cout << "z.c = " << z.getC() << std::endl;
    std::cout << "w.a.a = " << w.getA().getA() << std::endl;
    std::cout << "w.b.b = " << w.getB().getB() << std::endl;
    return 0;
}