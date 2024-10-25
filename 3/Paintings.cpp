#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Función que genera todas las permutaciones posibles usando backtracking
void generarPermutaciones(int idx, vector<string>& colores, vector<bool>& usado, vector<string>& actual, vector<vector<string>>& soluciones, unordered_map<string, set<string>>& restricciones) {
    if (idx == colores.size()) {
        soluciones.push_back(actual);
        return;
    }
    
    for (int i = 0; i < colores.size(); i++) {
        if (!usado[i]) {
            // Verificamos que el color actual no viole las restricciones
            if (idx > 0 && restricciones[actual[idx - 1]].count(colores[i])) continue;
            
            usado[i] = true;
            actual[idx] = colores[i];
            generarPermutaciones(idx + 1, colores, usado, actual, soluciones, restricciones);
            usado[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        
        vector<string> colores(N);
        for (int i = 0; i < N; i++) {
            cin >> colores[i];
        }
        
        int M;
        cin >> M;
        
        unordered_map<string, set<string>> restricciones;
        for (int i = 0; i < M; i++) {
            string c1, c2;
            cin >> c1 >> c2;
            restricciones[c1].insert(c2);
            restricciones[c2].insert(c1);
        }
        
        // Generamos todas las permutaciones válidas
        vector<bool> usado(N, false);
        vector<string> actual(N);
        vector<vector<string>> soluciones;
        
        generarPermutaciones(0, colores, usado, actual, soluciones, restricciones);
        
        // Ordenamos las soluciones en función de las preferencias
        sort(soluciones.begin(), soluciones.end(), [&](const vector<string>& a, const vector<string>& b) {
            for (int i = 0; i < N; i++) {
                if (a[i] != b[i]) {
                    return find(colores.begin(), colores.end(), a[i]) < find(colores.begin(), colores.end(), b[i]);
                }
            }
            return false;
        });
        
        // Imprimimos la cantidad de soluciones y la preferida
        cout << soluciones.size() << endl;
        for (const string& color : soluciones[0]) {
            cout << color << " ";
        }
        cout << endl;
    }

    return 0;
}


//LOL