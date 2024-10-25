#include <iostream>
#include <vector>

using namespace std;

// Función para descrifrar un byte cifrado
int descrifrar(int b) {
    for (int x = 0; x < 256; ++x) {
        if ((x ^ (x << 1) & 255) == b) {
            return x;
        }
    }
    return -1; // En caso de no encontrar (no debería ocurrir)
}

int main() {
    int n;
    cin >> n; // Leer el número de bytes
    
    vector<int> bytes(n);
    for (int i = 0; i < n; ++i) {
        cin >> bytes[i]; // Leer los bytes cifrados
    }
    
    // Descrifrar cada byte
    for (int i = 0; i < n; ++i) {
        int original = descrifrar(bytes[i]);
        cout << original << " "; // Imprimir el byte original
    }
    cout << endl;
    
    return 0;
}
