#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numDatasets;
    cin >> numDatasets;

    for (int dataset = 0; dataset < numDatasets; dataset++) {
        int datasetNumber, steps = 0, behind;
        vector<int> heights, orderedHeights;

        // Lee las 21 entradas, pero ignora la primera que es el número del dataset
        cin >> datasetNumber;
        for (int i = 0; i < 20; i++) {
            int height;
            cin >> height;
            heights.push_back(height);
        }

        // Ordena las alturas
        for (int i = 0; i < 20; i++) {
            bool inserted = false;
            // Añade la primera altura al vector ordenado
            if (i == 0) {
                orderedHeights.push_back(heights[i]);
                continue;
            }

            // Busca la posición donde insertar
            for (int j = 0; j < orderedHeights.size(); j++) {
                if (orderedHeights[j] > heights[i]) {
                    behind = orderedHeights.size() - j;
                    steps += behind;
                    orderedHeights.insert(orderedHeights.begin() + j, heights[i]);
                    inserted = true;
                    break;
                }
            }

            // Si no se insertó, añadir al final
            if (!inserted) {
                orderedHeights.push_back(heights[i]);
            }
        }

        // Imprimir el resultado para el conjunto de datos actual
        cout << datasetNumber << " " << steps << endl;
    }

    return 0;
}