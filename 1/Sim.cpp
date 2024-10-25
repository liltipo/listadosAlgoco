#include <iostream>
#include <list>
using namespace std;

int main() {
    int numTests;
    cin >> numTests;
    cin.ignore();  // Ignora el salto de línea

    for(int tests = 0; tests < numTests; tests++) {
        string line;
        getline(cin, line);

        list<char> output;
        auto pos = output.end();

        for(char c : line) {
            if(c == '<') {
                if(pos != output.begin()) {
                    pos--;
                    pos = output.erase(pos);
                }

            } else if(c == '[') {
                pos = output.begin();

            } else if(c == ']') {
                pos = output.end();

            } else {
                output.insert(pos, c);
            }
        }

        for(char c : output) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}