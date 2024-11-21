#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countSolutions = 0; // Contador de soluciones válidas
vector<string> board(8); // Tablero de 8x8
vector<bool> cols(8, false), diag1(15, false), diag2(15, false); // Restricciones

// Backtracking para colocar reinas fila por fila
void placeQueen(int row) {
    if (row == 8) { // Caso base: se han colocado 8 reinas
        countSolutions++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*' || cols[col] || diag1[row - col + 7] || diag2[row + col])
            continue; // No se puede colocar aquí
        
        // Marcar restricciones
        cols[col] = diag1[row - col + 7] = diag2[row + col] = true;
        
        // Llamada recursiva para la siguiente fila
        placeQueen(row + 1);
        
        // Desmarcar restricciones (backtracking)
        cols[col] = diag1[row - col + 7] = diag2[row + col] = false;
    }
}

int main() {
    // Leer el tablero
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    
    // Iniciar el proceso de backtracking
    placeQueen(0);
    
    // Imprimir el resultado
    cout << countSolutions << endl;
    return 0;
}
