#include "funciones.h"

/// @brief Numeros de fibonacci
/// @param n numero buscado
/// @return Regresa el numero fibonacci de la posicion n
int fibonacci(int n) {
    if (n < 3) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

/// @brief Calcular el factorial de un numero
/// @param n numero a calcular el factorial
/// @return el factorial de n, n!
int factorial(int n) {
    if (n < 2) {
        return 1;
    }
    return n * factorial(n - 1);
}

int funcion91(int n) {
    if (n > 100) {
        return n - 10;
    }
    else {
        return funcion91(funcion91(n + 11));
    }
}

/// @brief Calcular el numero de iteraciones para llegar a 1
/// @param n 
/// @return 
int tresNMasUno(int n) {
    if (n == 1) {
        return 0;
    }
    if (n % 2 == 0) {// n & 1
        n = n / 2;
    }
    else {
        n = 3 * n + 1;
    }
    return 1 + tresNMasUno(n);
}