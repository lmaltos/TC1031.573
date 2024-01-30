#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>

class date {
    int mes,dia,hh,mm,ss;
};

class ipAdress {
  private:
    int ip1,ip2,ip3,ip4;
  public:
    ipAdress(int a,int b,int c,int d) {ip1 =a; ip2 = b; ip3 = c; ip4 = d;}
    bool operator>(ipAdress&);
};

enum tipo {
    fecha,
    ip,
};

class registroBitacora {
  private:
    static tipo t;
    date fecha;
    ipAdress ip;
    std::string mensaje;
  public:
    bool operator>(registroBitacora&);
};

bool ipAdress::operator>(ipAdress &v) {
    if (ip1 > v.ip1)
        return true;
    else if (ip1 < v.ip1)
        return false;
    // ToDo ...
    return false;    
}

bool registroBitacora::operator>(registroBitacora& v) {
    if (t == fecha) {
        // hacer comparacion por fecha
    }
    else if (t == ip) {
        return ip > v.ip;
    }
    return false; // caso default
}

#endif