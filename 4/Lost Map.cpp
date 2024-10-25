#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // Para sort
using namespace std;

int main() {
    int n;
    cin >> n;

    // Leer la matriz de distancias
    vector<vector<int>> distances(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }

    vector<bool> connected(n, false); // Aldeas conectadas
    vector<pair<int, int>> connections; // Conexiones del MST
    connected[0] = true; // Comenzamos conectando la primera aldea

    for (int i = 0; i < n - 1; i++) {
        int min_distance = numeric_limits<int>::max();
        int village_a = -1, village_b = -1;

        // Buscar la conexión más corta entre aldeas conectadas y no conectadas
        for (int u = 0; u < n; u++) {
            if (connected[u]) { // Solo si la aldea ya está conectada
                for (int v = 0; v < n; v++) {
                    if (!connected[v] && distances[u][v] < min_distance) {
                        min_distance = distances[u][v];
                        village_a = u;
                        village_b = v;
                    }
                }
            }
        }

        // Conectar las aldeas encontradas
        connections.push_back({village_a + 1, village_b + 1}); // +1 para la salida 1-indexed
        connected[village_b] = true; // Marcar la nueva aldea como conectada
    }

    // Ordenar las conexiones para cumplir con el formato deseado
    sort(connections.begin(), connections.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    // Imprimir las conexiones
    for (const auto& conn : connections) {
        cout << conn.first << " " << conn.second << endl;
    }

    return 0;
}
