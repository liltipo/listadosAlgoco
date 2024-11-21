#include <iostream>
using namespace std;

int main() {
    int A, B;
    while (cin >> A >> B) {
        if(A > 12) {
            cout << B << endl;
        } else if (A > 5) {
            cout << B/2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}