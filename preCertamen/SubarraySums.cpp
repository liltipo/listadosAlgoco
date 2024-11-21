/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A;
    int n, x, a, ans = 0;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> a;
        A.push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        a = 0;
        for(int j = i; j < n; j++){
            a += A[j];
            if(a == x){
                ans++;
            }
            if(a > x){
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
} */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int left = 0, currentSum = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        currentSum += A[right]; // Agrega el elemento actual a la suma

        // Reduce la suma mientras sea mayor que x
        while (currentSum > x) {
            currentSum -= A[left];
            left++;
        }

        // Si la suma es igual a x, contamos este subarreglo
        if (currentSum == x) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
