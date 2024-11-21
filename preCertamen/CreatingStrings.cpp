#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string> perms;
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    perms.push_back(s);
    while (next_permutation(s.begin(), s.end())) {
        perms.push_back(s);
    }
    sort(perms.begin(), perms.end());
    cout << perms.size() << endl;
    for (string perm : perms) {
        cout << perm << endl;
    }

    return 0;
}