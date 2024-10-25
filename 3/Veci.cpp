#include <iostream>
#include <algorithm>  // Para usar next_permutation
using namespace std;

int main() {
    string numero;
    cin >> numero;
    string menorNumeroMayor = numero;

    // Ordenar los dígitos para comenzar desde la permutación más pequeña posible
    sort(menorNumeroMayor.begin(), menorNumeroMayor.end());

    do {
        if (numero < menorNumeroMayor) {
            break;
        }
    } while (next_permutation(menorNumeroMayor.begin(), menorNumeroMayor.end()));

    // Si encontramos una permutación mayor al número ingresado
    if (menorNumeroMayor > numero) {
        cout << menorNumeroMayor << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}