/* #include <iostream>
#include <list>
#include <sstream>
using namespace std;

void printList(const list<int>& list) {
    cout << "[";
    for (auto pos = list.begin(); pos != list.end(); ++pos) {
        cout << *pos;
        if (next(pos) != list.end()) {  // Si no es el último elemento, imprime una coma
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();  // Ignora el salto de línea

    for(int cases = 0; cases < numCases; cases++) {
        bool flag = true; 
        string BAPC, listaRaw; // Lista de operaciones y lista en string
        getline(cin, BAPC);

        int size;   // Tamaño de la lista
        cin >> size;
        cin.ignore();  // Ignora el salto de línea

        getline(cin, listaRaw);
        
        // Verifica si la lista está vacía
        if (listaRaw.size() < 2) {
            cerr << "error" << endl;
            continue;
        }

        listaRaw = listaRaw.substr(1, listaRaw.size() - 2); // Elimina los corchetes
        list<int> list;
        stringstream ss(listaRaw);
        string temp;

        while (getline(ss, temp, ',')) {
            list.push_back(stoi(temp));
        }

        for(char c : BAPC) {
            if(c == 'R') {
                list.reverse();

            } else if(c == 'D') {
                if (list.empty()) {
                    cerr << "error" << endl;
                    flag = false;
                    break;
                }
                list.pop_front();
            }
        }

        if (flag) {
            printList(list);
        }
    }

    return 0;
} */

#include <iostream>
#include <list>
#include <sstream>
#include <string>
using namespace std;

void printList(const list<int>& list, bool reversed) {
    cout << "[";
    if (reversed) {
        for (auto pos = list.rbegin(); pos != list.rend(); ++pos) {
            cout << *pos;
            if (next(pos) != list.rend()) {
                cout << ",";
            }
        }
    } else {
        for (auto pos = list.begin(); pos != list.end(); ++pos) {
            cout << *pos;
            if (next(pos) != list.end()) {
                cout << ",";
            }
        }
    }
    cout << "]" << endl;
}

int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();  // Ignora el salto de línea

    for(int cases = 0; cases < numCases; cases++) {
        string BAPC, listaRaw;
        getline(cin, BAPC);

        int size;
        cin >> size;
        cin.ignore();  // Ignora el salto de línea

        getline(cin, listaRaw);

        // Verifica si la lista está vacía
        if (listaRaw == "[]") {
            bool hasDrop = BAPC.find('D') != string::npos;
            if (hasDrop) {
                cout << "error" << endl;
                continue;
            } else {
                cout << "[]" << endl;
                continue;
            }
        }

        listaRaw = listaRaw.substr(1, listaRaw.size() - 2); // Elimina los corchetes
        list<int> list;
        stringstream ss(listaRaw);
        string temp;

        while (getline(ss, temp, ',')) {
            list.push_back(stoi(temp));
        }

        bool reversed = false;
        bool error = false;

        for(char c : BAPC) {
            if(c == 'R') {
                reversed = !reversed;
            } else if(c == 'D') {
                if (list.empty()) {
                    cout << "error" << endl;
                    error = true;
                    break;
                }
                if (reversed) {
                    list.pop_back();
                } else {
                    list.pop_front();
                }
            }
        }

        if (!error) {
            printList(list, reversed);
        }
    }

    return 0;
}
