#ifndef MYCLASS_H
#define MYCLASS_H

class myClass {
  private:
    int a;
    int b;
    char c;
    float f;
  public:
    myClass(); // <- constructor default
    myClass(int a, int b, char c); // constructor alternativo
    myClass(int a, int b, float f); // otro constructor altrnativo
    int getA() {return a;}
    int getB() {return b;}
};

myClass::myClass(){
    
}

myClass::myClass(int a, int _b, char _c){
    this->a = a;
    b = _b;
    c = _c;
}

myClass::myClass(int a, int b, float f){
    this->a = a;
    this->b = b;
    this->f = f;
}
    

#endif