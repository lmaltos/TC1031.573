#ifndef MYCLASS_H
#define MYCLASS_H

template <typename T, typename D>
class myClass {
  private:
    T a;
    T b;
    D c;
    float f;
  public:
    myClass(); // <- constructor default
    myClass(T a, T b, D c); // constructor alternativo
    myClass(T a, T b, float f); // otro constructor altrnativo
    T getA() {return a;}
    T getB() {return b;}
    D getC() {return c;}
};

template <typename T, typename D>
myClass<T,D>::myClass(){
    
}

template <typename T, typename D>
myClass<T,D>::myClass(T a, T _b, D _c){
    this->a = a;
    b = _b;
    c = _c;
}

template <typename D, typename E>
myClass<D,E>::myClass(D a, D b, float f){
    this->a = a;
    this->b = b;
    this->f = f;
}
    

#endif