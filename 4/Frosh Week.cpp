#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, l, done = 0;
    cin >> t >> l;

    vector<int> tasks(t);
    vector<int> intervals(l);

    for (int& num : tasks) {
        cin >> num;
    }

    for (int& num : intervals) {
        cin >> num;
    }

    sort(tasks.begin(), tasks.end());
    sort(intervals.begin(), intervals.end());

    int i = 0, j = 0;

    // Emparejar tareas con intervalos usando dos punteros
    while (i < t && j < l) {
        if (tasks[i] <= intervals[j]) {
            done++;  // Si la tarea cabe en el intervalo, incrementamos
            i++;    // Avanzar al siguiente
            j++;    // Avanzar al siguiente intervalo
        } else {
            j++;    // Si la tarea no cabe, probar el siguiente intervalo
        }
    }

    cout << done << endl;

    return 0;
}
