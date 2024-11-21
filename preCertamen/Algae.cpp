#include <iostream>
using namespace std;

int main() {
    int r, D, x;
    cin >> r >> D >> x;

    for (int i = 0; i < 10; i++) {
        x = r * x - D;
        cout << x << endl;
    }

    return 0;
}