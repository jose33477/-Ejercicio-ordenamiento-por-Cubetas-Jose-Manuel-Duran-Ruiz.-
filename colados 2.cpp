#include <iostream>

using namespace std;

int main() {
    int numPersonas;
    cin >> numPersonas;

    int numerosCola[numPersonas];
    for (int i = 0; i < numPersonas; ++i) {
        cin >> numerosCola[i];
    }

    int colados = 0;
    for (int i = 1; i < numPersonas; ++i) {
        if (numerosCola[i] != numerosCola[i-1] + 1) {
            colados++;
        }
    }

    cout << colados << endl;

}
