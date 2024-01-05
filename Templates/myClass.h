#ifndef MYCLASS_H
#define MYCLASS_H

template <typename T>
class myClass {
  private:
    T a;
    T b;
    char c;
    float f;
  public:
    myClass(); // <- constructor default
    myClass(T a, T b, char c); // constructor alternativo
    myClass(T a, T b, float f); // otro constructor altrnativo
    T getA() {return a;}
    T getB() {return b;}
};

template <typename T>
myClass<T>::myClass(){
    
}

template <typename T>
myClass<T>::myClass(T a, T _b, char _c){
    this->a = a;
    b = _b;
    c = _c;
}

template <typename D>
myClass<D>::myClass(D a, D b, float f){
    this->a = a;
    this->b = b;
    this->f = f;
}
    

#endif