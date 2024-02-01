#include "registro.h"
#include "AVL.h"

class contadorIP {
    ipAdress ip;
    int accesos = 0;
    bool operator>(contadorIP& v) {
        if (accesos > v.accesos)
            return true;
        else if (accesos < v.accesos)
            return false;
        else return ip > v.ip;
    }
};

int main() {
    AVL<contadorIP> arbol;
    vector<registroBitacora> registros;
    // leer registros
    ipAdress ipAnt;
    for (registroBitacora r : registros) {
        if (ipAnt != r.ip) {
            contadorIP nuevo{ipAnt,count};
            arbol.add(nuevo);
            count = 0;
            ipAnt = r.ip;
        }
        count++;
    }
    contadorIP nuevo{ipAnt,count};
    arbol.add(nuevo); // ultimo
}