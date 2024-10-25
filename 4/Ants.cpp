#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int l, n; 
        cin >> l >> n;
        
        int menorTiempo = 0;
        int mayorTiempo = 0;
        
        for (int i = 0; i < n; i++) {
            int position;
            cin >> position;
            
            int distanciaBordeCercano = min(position, l - position);
            int distanciaBordeLejano = max(position, l - position);
            
            // Actualizamos el tiempo más temprano y más tardío
            menorTiempo = max(menorTiempo, distanciaBordeCercano);
            mayorTiempo = max(mayorTiempo, distanciaBordeLejano);
        }
        
        // Imprimir el tiempo más temprano y más tardío
        cout << menorTiempo << " " << mayorTiempo << endl;
    }
    
    return 0;
}
