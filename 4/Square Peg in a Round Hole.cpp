#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, M, K, casa;
    cin >> N >> M >> K;

    vector<int> plots(N);
    vector<double> casas(M+K); 

    for (int& num : plots) {
        cin >> num;
    }

    for (int i = 0; i < M+K; i++) {
        if (i < M) {
            cin >> casa;
            casas[i] = casa;  // Radio de las casas circulares
        } else {
            cin >> casa;
            casas[i] = casa / sqrt(2);  // Radio efectivo de las casas cuadradas
        }
    }

    sort(casas.begin(), casas.end());
    sort(plots.begin(), plots.end());

    int i = 0, j = 0, filled = 0;

    // Emparejar casas con plots
    while (i < M+K && j < N) {
        if (casas[i] < plots[j]) {
            filled++;
            i++;
            j++;
        } else {
            j++;  // Avanzamos al siguiente plot
        }
    }

    cout << filled << endl;

    return 0;
}
