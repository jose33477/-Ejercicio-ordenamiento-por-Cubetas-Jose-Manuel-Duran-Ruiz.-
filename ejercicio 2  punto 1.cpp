#include <iostream>

using namespace std;

void calcularAfortunados(int n) {
    bool eliminado[n + 1] = {false};
    int afortunados[n]; // Suponiendo que el número máximo de afortunados no excede n
    int idx = 0;

    for (int i = 2; i <= n; ++i) {
        if (!eliminado[i]) {
            afortunados[idx++] = i;
            for (int j = i; j <= n; j += i) {
                eliminado[j] = true;
            }
        }
    }

    cout << n << ": ";
    for (int i = idx - 1; i >= 0; --i) {
        cout << afortunados[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        calcularAfortunados(n);
    }

    return 0;
}

