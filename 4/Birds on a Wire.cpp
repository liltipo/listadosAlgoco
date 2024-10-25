#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int l, d, n, pajaro;
    cin >> l >> d >> n;
    int final = l - 6;

    vector<int> pajaros;
    for (int i = 0; i < n; i++) {
        cin >> pajaro;
        pajaros.push_back(pajaro);
    }
    sort(pajaros.begin(), pajaros.end());

    int maxPajaros = 0;

    if (pajaros.size() != 0) {
        // Desde 6 cm hasta el primer pájaro
        int espacioInicial = pajaros[0] - 6;
        maxPajaros += espacioInicial / d;

        // Entre pájaros ya colocados
        for (int i = 1; i < n; i++) {
            int espacioEntrePajaros = pajaros[i] - pajaros[i - 1];
            maxPajaros += (espacioEntrePajaros / d) - 1; // -1 para no contar la posición del pájaro ya sentado
        }

        // Desde el último pájaro hasta `l - 6`
        int espacioFinal = final - pajaros.back();
        maxPajaros += espacioFinal / d;
    } else {
        // Si no hay pájaros, contar cuántos caben desde 6 cm hasta `l - 6` cm
        maxPajaros = (final - 6) / d + 1;
    }

    cout << maxPajaros << endl;

    return 0;
}
