#include <iostream>
#include <string>
using namespace std;

int main() {
    string row1, row2;
    cin >> row1 >> row2;

    int n = row1.size();
    int bishwocks = 0;

    for (int i = 0; i < n - 1; ++i) {
        // Arriba izquierda
        if (row1[i] == '0' && row1[i + 1] == '0' && row2[i] == '0') {
            bishwocks++;
            row1[i] = row1[i + 1] = row2[i] = 'X';
        }
        // Arriba derecha
        else if (row1[i] == '0' && row1[i + 1] == '0' && row2[i + 1] == '0') {
            bishwocks++;
            row1[i] = row1[i + 1] = row2[i + 1] = 'X';
        }
        // Abajo izquierda
        else if (row1[i] == '0' && row2[i] == '0' && row2[i + 1] == '0') {
            bishwocks++;
            row1[i] = row2[i] = row2[i + 1] = 'X';
        }
        // Abajo derecha
        else if (row2[i] == '0' && row2[i + 1] == '0' && row1[i + 1] == '0') {
            bishwocks++;
            row2[i] = row2[i + 1] = row1[i + 1] = 'X';
        }
        
    }

    cout << bishwocks << endl;

    return 0;
}
