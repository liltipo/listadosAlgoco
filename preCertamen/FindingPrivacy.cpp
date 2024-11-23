#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    if(N < 2 * K - 1) {
        cout << "*" << endl;
        return 0;
    }

    if(K == 1 && N > 2) {
        cout << "*" << endl;
        return 0;
    }

    vector <char> v(N, '-');

    for(int i = 0; i < N; i++) {
        v[i] = 'X';
        i  += static_cast<int>(N/K);
    }

    for(int i = 0; i < N; i++) {
        cout << v[i];
    }

    return 0;
}

/* #include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int k, n;
    cin >> k >> n;
    n -= k;
    vector<int> cnt(k + 1, 0);
    for (int i = 1; i < k; i++) {
        cnt[i]++;
        n--;
    }
    if (n < 0) {
        cout << "*" << endl;
        return;
    }
    for (int i = 0; i < k; i++) {
        int d = 2;
        if (i == 0 || i == k) d--;
        while (cnt[i] && n > 0) {
            cnt[i]++;
            n--;
        }
    }
    if (n != 0) {
        cout << "*" << endl;
        return;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < cnt[i]; j++) 
            cout << "-";
        if (i != k) {
            cout << "X";
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
 */