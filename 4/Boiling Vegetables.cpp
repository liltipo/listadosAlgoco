#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Función para calcular el número mínimo de cortes necesarios para un solo peso
int cuts_needed(double T, int weight, int min_weight) {
    int cuts = 0;
    // Mientras la proporción entre el mayor y el menor no supere a T
    while (static_cast<double>(min_weight) / (weight / (cuts + 1)) <= T) {
        cuts++;
    }
    return cuts;
}

int main() {
    // Leer los valores de entrada
    double T;
    int N;
    cin >> T >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    // Ordenar los pesos para obtener el mínimo
    sort(weights.begin(), weights.end());
    int min_weight = weights[0]; // El menor peso

    // Calcular el número total de cortes necesarios
    int total_cuts = 0;
    for (int i = 1; i < N; i++) {
        total_cuts += cuts_needed(T, weights[i], min_weight);
    }

    // Imprimir el número total de cortes
    cout << total_cuts << endl;

    return 0;
}
