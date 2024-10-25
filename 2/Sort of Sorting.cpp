#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Compara las primeras dos letras de los apellidos
bool compare(const string& a, const string& b) {
    string a2 = a.substr(0, 2);
    string b2 = b.substr(0, 2);

    return a2 < b2;
}


int main() {
    while (true) {
        int lastNames;
        cin >> lastNames;

        // Se detiene cuando la entrada es 0
        if (lastNames == 0) {
            break;
        }

        // Lee los apellidos y los guarda en un vector
        vector<string> names;
        for (int i = 0; i < lastNames; i++) {
            string name;
            cin >> name;
            names.push_back(name);
        }

        // Ordena los apellidos según sus primeras 2 letras utilizando stable_sort
        stable_sort(names.begin(), names.end(), compare);

        // Imprime los apellidos ordenados
        for (const string& name : names) {
            cout << name << endl;
        }

        cout << endl; // Línea en blanco entre datasets
    }

    return 0;
}
