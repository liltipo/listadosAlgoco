#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Definimos la matriz para almacenar el estado actual del puzzle
    char puzzle[4][4];

    // Definimos un mapa para almacenar las posiciones objetivo de cada letra en el tablero ya que el tamaño es fijo
    unordered_map<char, pair<int, int>> posicionObjetivo = {
        {'A', {0, 0}}, {'B', {0, 1}}, {'C', {0, 2}}, {'D', {0, 3}},
        {'E', {1, 0}}, {'F', {1, 1}}, {'G', {1, 2}}, {'H', {1, 3}},
        {'I', {2, 0}}, {'J', {2, 1}}, {'K', {2, 2}}, {'L', {2, 3}},
        {'M', {3, 0}}, {'N', {3, 1}}, {'O', {3, 2}}, {'.', {3, 3}}
    };

    // Leer la cuadrícula de 4x4 del input
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> puzzle[i][j];
        }
    }

    int scatterTotal = 0;

    // Calcular las distancias Manhattan
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char letra = puzzle[i][j];
            if (letra != '.') { // Ignorar el espacio vacío
                auto posicion = posicionObjetivo[letra]; // Obtener la posición objetivo de la letra (valor de la clave letra)
                int distancia = abs(i - posicion.first) + abs(j - posicion.second);
                scatterTotal += distancia;
            }
        }
    }

    cout << scatterTotal << endl;

    return 0;
}
