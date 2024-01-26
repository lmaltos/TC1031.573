#include <iostream>
#include <vector>
#include "grafoMA.h"
#include "grafoLA.h"

using namespace std;

int main() {
    grafoLA G;
    G.addAdyacencia("A","B"); // crear nodos A y B y las adyacencias A->B y B->A    G.addArco('A','B');
    G.addAdyacencia("A","C");
    G.addAdyacencia("A","E");
    G.addAdyacencia("B","D");
    G.addAdyacencia("C","D");
    G.addAdyacencia("D","E");
    vector<string> ids = {"A","B","C","D","E"};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                if (G.sonAdyacentes(ids[i],ids[j])) {
                    cout << ids[i] << " -> " << ids[j] << endl;
                }
            }
        }    
    }
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