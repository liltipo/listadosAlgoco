#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;

    while(i < n && j < m) {
        if(a[i] <= b[j] + k && a[i] >= b[j] - k) { // Si el tamaño deseado esta en el rango
            i++;
            j++;
            ans++;
        } else if (a[i] < b[j] - k) { // Si el tamaño deseado es menor al rango
            i++;
        } else { // Si el tamaño deseado es mayor al rango
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}