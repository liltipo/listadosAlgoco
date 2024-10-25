#include <iostream>
using namespace std;

int main() {
    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (a.first == b.first && a.first == c.first && (a.second + b.second + c.second) == a.first) {
        cout << "YES" << endl;

    } else if (a.first == b.first && (a.second + b.second) == c.first && (a.first + c.second) == c.first) {
        cout << "YES" << endl;

    } else if (b.first == c.first && (b.second + c.second) == a.first && (b.first + a.second) == a.first) {
        cout << "YES" << endl;

    } else if (a.second == b.second && (a.first + b.first) == c.second && (a.second + c.first) == c.second) {
        cout << "YES" << endl;

    } else if (b.second == c.second && (b.first + c.first) == a.second && (b.second + a.first) == a.second) {
        cout << "YES" << endl;

    } else if (a.second == b.second && a.second == c.second && (a.first + b.first + c.first) == a.second) {
        cout << "YES" << endl;

    } else if (b.first + c.second == a.first && a.second + b.second == a.first && b.second == c.first) {
        cout << "YES" << endl;
    
    } else if (b.second + c.first == a.first && a.second + b.first == a.first && b.first == c.second) {
        cout << "YES" << endl;

    } else {
        cout << "NO" << endl;
    }

    return 0;
}