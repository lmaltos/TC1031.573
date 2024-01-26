#include <iostream>
#include <vector>
#include "grafoMA.h"
#include "grafoLA.h"

using namespace std;

int main() {
    grafoLA G;
    G.addAdyacencia("A","B"); // crear nodos A y B y las adyacencias A->B y B->A    G.addArco('A','B');
    G.addAdyacencia("B","C");
    G.addAdyacencia("C","D");
    G.addAdyacencia("A","E");
    G.addAdyacencia("C","F");
    G.addAdyacencia("E","G");
    G.addAdyacencia("E","H");
    G.addAdyacencia("H","I");
    G.addAdyacencia("H","J");
    G.addAdyacencia("A","H");
    G.addAdyacencia("B","E");
    G.addAdyacencia("C","E");
    G.addAdyacencia("F","J");
    G.addAdyacencia("G","J");
    string ans;
    ans = G.BreadthFirst();
    cout << "Recorrido Breadht First" << endl;
    cout << ans << endl;
    return 0;
}

int mainMA() {
    grafoMA G(5);
    G.setTag(0,'A');
    G.setTag(1,'B');
    G.setTag(2,'C');
    G.setTag(3,'D');
    G.setTag(4,'E');
    G.addArco('A','B');
    G.addArco('A','C');
    G.addArco('A','E');
    G.addArco('B','D');
    G.addArco('C','D');
    G.addArco('D','E');
    for (char i = 'A'; i <= 'E'; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            if (i != j) {
                if (G.sonAdyacentes(i,j)) {
                    cout << i << " -> " << j << endl;
                }
            }
        }
    }
    return 0;
}