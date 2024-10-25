#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Conjunto de vocales para verificar fácilmente si un caracter es vocal o consonante
const unordered_set<char> VOCALS = {'A', 'E', 'I', 'O', 'U'};

// Función que realiza la búsqueda recursiva (backtracking) para contar las palabras agradables
void contarPalabrasAgradables(string &str, int pos, int consecutivoVocal, int consecutivoConsonante, bool contieneL, long long &total) {
    // Si alcanzamos el final del string, verificamos si la palabra formada es agradable
    if (pos == str.size()) {
        if (contieneL) { // La palabra debe contener al menos una 'L'
            total++;
        }
        return;
    }

    // Si el caracter actual es un '_', necesitamos probar todas las letras del abecedario
    if (str[pos] == '_') {
        for (char c = 'A'; c <= 'Z'; ++c) {
            bool esVocal = VOCALS.count(c);
            // Decidir cuántas vocales o consonantes consecutivas se tienen al agregar 'c'
            if (esVocal) {
                if (consecutivoVocal + 1 < 3) {
                    contarPalabrasAgradables(str, pos + 1, consecutivoVocal + 1, 0, contieneL || (c == 'L'), total);
                }
            } else {
                if (consecutivoConsonante + 1 < 3) {
                    contarPalabrasAgradables(str, pos + 1, 0, consecutivoConsonante + 1, contieneL || (c == 'L'), total);
                }
            }
        }
    } else {
        // Si el caracter no es un '_', continuamos con las restricciones actuales
        bool esVocal = VOCALS.count(str[pos]);
        if (esVocal) {
            if (consecutivoVocal + 1 < 3) {
                contarPalabrasAgradables(str, pos + 1, consecutivoVocal + 1, 0, contieneL || (str[pos] == 'L'), total);
            }
        } else {
            if (consecutivoConsonante + 1 < 3) {
                contarPalabrasAgradables(str, pos + 1, 0, consecutivoConsonante + 1, contieneL || (str[pos] == 'L'), total);
            }
        }
    }
}

int main() {
    string str;
    cin >> str;

    long long totalPalabrasAgradables = 0;
    contarPalabrasAgradables(str, 0, 0, 0, false, totalPalabrasAgradables);

    cout << totalPalabrasAgradables << endl;
    return 0;
}
