#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int p;
    long long descuento = 0;
    cin >> p;

    vector <int> precios(p);
    for (int& num : precios) {
        cin >> num;
    }
    sort(precios.begin(), precios.end(), greater<int>());

    for (int i = 2; i < p; i += 3) {
        if (i < precios.size()) { 
            descuento += precios[i];  
        }
    }

    cout << descuento << endl;

    return 0;
}

