#include <iostream>
#include <set> 
using namespace std;

int main() {
    int numObstacles, numFound;
    cin >> numObstacles >> numFound;

    set <int> foundSet; // Obstaculos encontrados por mario
    for (int i = 0; i < numFound; i++) {
        int foundObstacle;
        cin >> foundObstacle;
        foundSet.insert(foundObstacle);
    }

    for (int i = 0; i < numObstacles; i++) {
        if (foundSet.find(i) == foundSet.end()) { // find(i) retorna un iterador al elemento si lo encuentra, si no, retorna un iterador al final del set
            cout << i << endl;
        }
    }

    cout << "Mario got " << numFound << " of the dangerous obstacles.";

    return 0;
}