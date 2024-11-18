#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solveKnapsack(int capacity, const vector<pair<int, int>>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // Construcción de la tabla DP
    for (int i = 1; i <= n; i++) {
        int value = items[i - 1].first;
        int weight = items[i - 1].second;
        for (int j = 0; j <= capacity; j++) {
            if (weight > j) {
                dp[i][j] = dp[i - 1][j]; // No se puede tomar este objeto
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value); // Tomar o no tomar
            }
        }
    }

    // Reconstrucción de la solución
    vector<int> selectedItems;
    int remainingCapacity = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity]) {
            selectedItems.push_back(i - 1); // El objeto fue incluido
            remainingCapacity -= items[i - 1].second; // Reducir capacidad
        }
    }

    // Output
    reverse(selectedItems.begin(), selectedItems.end());
    cout << selectedItems.size() << endl; // Número de elementos seleccionados
    for (int index : selectedItems) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    int capacity, n;
    while (cin >> capacity >> n) {
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; i++) {
            cin >> items[i].first >> items[i].second; // value, weight
        }
        solveKnapsack(capacity, items);
    }
    return 0;
}