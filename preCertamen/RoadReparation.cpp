#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges; // {cost, u, v}

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, u - 1, v - 1}); // Convertir a índice 0
    }

    // Ordenar aristas por costo (greedy: primero las más baratas)
    sort(edges.begin(), edges.end());

    vector<bool> connected(n, false);
    connected[0] = true; // Empezar desde la ciudad 0
    int connectedCount = 1;
    int totalCost = 0;

    while (connectedCount < n) {
        bool found = false;

        for (auto it = edges.begin(); it != edges.end(); ++it) {
            int cost, u, v;
            tie(cost, u, v) = *it;

            // Verificar si conecta una ciudad dentro del conjunto con una fuera
            if ((connected[u] && !connected[v]) || (!connected[u] && connected[v])) {
                totalCost += cost;
                connected[u] = connected[v] = true;
                connectedCount++;
                edges.erase(it); // Eliminar arista usada
                found = true;
                break;
            }
        }

        // Si no encontramos una conexión válida, el grafo no es conexo
        if (!found) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << totalCost << endl;
    return 0;
}
