    #ifndef ARREGLO_H
#define ARREGLO_H

class arreglo {
  private:
    int n;
    int *a;
  public:
    arreglo(int);
    ~arreglo(); // destructor
    int operator[](int);
    void set(int,int);
    int length() {return n;}
};

arreglo::arreglo(int _n) {
    n = _n;
    if (n > 0)
        a = new int[n];
    else
        a = nullptr;
}

arreglo::~arreglo() {
    delete[] a;
}

int arreglo::operator[](int i) {
    return a[i];
}

void arreglo::set(int i ,int val) {
    a[i] = val;
}
    

#endif