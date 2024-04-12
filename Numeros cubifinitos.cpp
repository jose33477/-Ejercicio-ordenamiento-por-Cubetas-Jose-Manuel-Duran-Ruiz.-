#include <iostream>
using namespace std;
// Funci�n para calcular la suma de los d�gitos al cubo de un n�mero
int sumaDigitosAlCubo(int n) {
    int suma = 0;
    while (n != 0) {
        int digito = n % 10;
        suma += digito * digito * digito;
        n /= 10;
    }
    return suma;
}

// Funci�n para buscar un n�mero en un arreglo
bool buscarNumeroEnArreglo(int n, int valores[], int tam) {
    for (int i = 0; i < tam; ++i) {
        if (valores[i] == n) {
            return true;
        }
    }
    return false;
}

// Funci�n para determinar si un n�mero es cubifinito o no
bool esCubifinito(int n, int valores[], int tam) {
    int suma = n;
    while (true) {
        suma = sumaDigitosAlCubo(suma);
        if (suma == 1) {
            return true;
        }
        if (buscarNumeroEnArreglo(suma, valores, tam) || suma == n) {
            return false;
        }
        valores[tam++] = suma;
    }
}

// Funci�n principal para leer la entrada y validar si cada caso es cubifinito o no
void casosDePrueba() {
    int n;
    while (true) {
    	cout<<"Numero: ";
        cin >> n;
        if (n == 0) {
            break;
        }
        int valores[100]; // Supongamos que el m�ximo n�mero de transformaciones es 100
        valores[0] = n;
        if (esCubifinito(n, valores, 1)) {
            cout << n << " es cubifinito.\n";
        } else {
            cout << n << " no es cubifinito.\n";
        }
    }
}

int main() {
    casosDePrueba();
    return 0;
}
