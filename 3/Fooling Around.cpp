#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Función para generar primos hasta un máximo límite
vector<int> generarPrimos(int limite) {
    vector<bool> esPrimo(limite + 1, true);
    esPrimo[0] = esPrimo[1] = false; // 0 y 1 no son primos
    for (int i = 2; i * i <= limite; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= limite; j += i) {
                esPrimo[j] = false;
            }
        }
    }
    vector<int> primos;
    for (int i = 2; i <= limite; i++) {
        if (esPrimo[i]) primos.push_back(i);
    }
    return primos;
}

int main() {
    int Q;
    cin >> Q;

    // Limitar el rango de los primos a un número razonable
    vector<int> primos = generarPrimos(1000); // Generar primos hasta 10,000

    while (Q--) {
        long long N;
        cin >> N;

        // Programación dinámica para determinar el estado ganador
        // Suponemos un estado de ganadores hasta el límite N
        vector<bool> dp(N + 1, false); // dp[i] será true si el estado i es ganador para Alice

        for (long long i = 1; i <= N; i++) {
            // Verificar cada primo para ver si Alice puede ganar
            for (int p : primos) {
                if (p - 1 > i) break; // No podemos quitar más piedras que las que hay
                if (!dp[i - (p - 1)]) { // Si Bob está en un estado perdedor
                    dp[i] = true; // Alice puede ganar
                    break; // No necesitamos verificar más
                }
            }
        }

        // Resultado final basado en el estado de N
        if (dp[N]) {
            cout << "Alice" << endl; // Alice gana
        } else {
            cout << "Bob" << endl; // Bob gana
        }
    }

    return 0;
}
