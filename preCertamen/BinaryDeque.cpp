/* #include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int t, n, s;
    cin >> t;

    while(t--){
        cin >> n >> s;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum < s) {
            cout << -1 << endl;
            continue;
        }
        if(sum == s) {
            cout << 0 << endl;
            continue;
        }

        int left = 0, right = n - 1, lado = 0, posLeft = 0, posRight = n - 1; // 0 izquierda, 1 derecha
        int closest = -1, total = 0;


        while(sum > s) {
            // Buscar el 1 más cercano
            while(left <= right) {
                if(v[right] == 1) {
                    closest = right;
                    v[right] = 0;  
                    lado = 1;
                    break;
                } else if(v[left] == 1) {
                    closest = left;
                    lado = 0;
                    v[left] = 0;
                    break;
                }
                left++;
                right--;
            }

            if(closest != -1) {
                if(lado == 0) {
                    total += closest - posLeft + 1;
                    posLeft = closest + 1;
                } else {
                    total += posRight - closest + 1;
                    posRight = closest - 1;
                }
                sum--;
            }
        }
        cout << total << endl;
    }


    return 0;
} */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t;
    cin >> t;

    while (t--) {
        long n, s;
        cin >> n >> s;

        vector<long> v(1, -1);  // Inicializamos con -1 para manejar los bordes
        for (long p = 0; p < n; p++) {
            int x;
            cin >> x;
            if (x) {
                v.push_back(p);
            }
        }
        v.push_back(n);  // Agregamos el tamaño del array como borde final

        if (v.size() < s + 2) {  // Verificamos si es posible alcanzar la suma s
            cout << -1 << '\n';
            continue;
        }

        long mxlen = 0;
        for (long p = s; p + 1 < v.size(); p++) {
            long len = (v[p + 1] - 1) - v[p - s];
            mxlen = max(mxlen, len);
        }

        cout << (n - mxlen) << '\n';
    }

    return 0;
}
