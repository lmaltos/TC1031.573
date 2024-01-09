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
    void ordenIntercambio();
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

void arreglo::ordenIntercambio() {
    int tmp;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                tmp = a[i]; // se guarda el valor de a[i]
                a[i] = a[j]; // se pierde el valor de a[i]
                a[j] = tmp;
            }
        }
    }
}    

#endif