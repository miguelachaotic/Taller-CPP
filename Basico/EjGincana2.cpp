#include <iostream>
#include <cstdlib> // Para std::atoi

using namespace std;

long cuadradoSuma(long n) {
    long resultado = 0;
    for (long i = 1; i <= n; i++) {
        resultado += i;
    }
    return resultado * resultado;
}

long sumaCuadrados(long n) {
    long resultado = 0;
    long temp;
    for (long i = 1; i <= n; i++) {
        temp = i * i;
        resultado += temp;
    }
    return resultado;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Error: Se requiere un argumento entero." << endl;
        return 1;
    }
    long cuerda = std::atoi(argv[0]);
    cout << (cuadradoSuma(cuerda) - sumaCuadrados(cuerda)) << endl;
    return 0;
}

