#include <iostream>
using namespace std;

int main() {
    int N, M, gate1, gate2;
    cin >> N >> M;
    int izq = 0, der = N;

    for(int i = 0; i < M; i++) {
        cin >> gate1 >> gate2;

        if(gate1 > izq){
            izq = gate1;
        }
        if(gate2 < der){
            der = gate2;
        }
    }

    if (izq <= der) {
        cout << der - izq + 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}