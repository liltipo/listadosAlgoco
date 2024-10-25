#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, n, m, a, s, saves = 0;
    cin >> n >> m;
    N = n;

    vector<int> minutosActuales;
    vector<pair<int, int>> investigadores(n); // {llegada, timpo de uso}
    
    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        investigadores[i] = {a, s};
    }
    
    minutosActuales.push_back(investigadores[0].first + investigadores[0].second); // Salida del primer investigador

    for (int i = 0; i < investigadores.size(); i++) {
        cout << "investigadores[i].first: " << investigadores[i].first << " ";
        cout << "investigadores[i].second: " << investigadores[i].second << endl;
    }


    while (--n) {
        cout << "n: " << n << endl;

        bool tuvoQueDesbloquear = true;
        for (int i = 0; i < minutosActuales.size(); i++) {
            cout << "minutosActuales[i]: " << minutosActuales[i] << endl;
            cout << "investigadores[N-n].first: " << investigadores[N-n].first << endl;
            cout << "investigadores[N-n].first <= minutosActuales[i] + m: " << investigadores[N-n].first << " <= " << minutosActuales[i] + m << endl;

            if (investigadores[N-n].first <= minutosActuales[i] + m) { // Si la entrada es menor o igual a la salida + m
                saves++;
                tuvoQueDesbloquear = false;
                minutosActuales[i] = minutosActuales[i] + investigadores[N-n].second; 
                break;
            }
        }
        if (tuvoQueDesbloquear) {
            cout << "tuvoQueDesbloquear" << endl;

            minutosActuales.push_back(investigadores[N-n].first + investigadores[N-n].second); // Salida del investigador
        }
        sort(minutosActuales.begin(), minutosActuales.end());
        
        for (int i = 0; i < minutosActuales.size(); i++) {
            cout << "minutosActuales[i]: " << minutosActuales[i] << endl;
        }
    }

    cout << saves << endl;

    return 0;
}