#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Definimos dp[i] como el número mínimo de monedas para formar la suma i
    vector<int> dp(x + 1, 1e9); // Inicializamos con un valor grande (infinito)
    dp[0] = 0; // Caso base: 0 monedas para la suma 0

    // Transición
    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    // Verificamos el resultado
    if (dp[x] == 1e9) {
        cout << -1 << endl; // No se puede formar la suma x
    } else {
        cout << dp[x] << endl; // Mínimo número de monedas para formar x
    }

    return 0;
}
