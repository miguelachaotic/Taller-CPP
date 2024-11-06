#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> // Para std::atoi

using namespace std;

long factorial(long n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

bool condicion(long n) {
    string numeroStr = to_string(n);
    int templanza = 1;
    bool resultado = false;
    
    for (size_t i = 0; i < numeroStr.length(); i++) {
        int digito = numeroStr[i] - '0';
        int potencia = static_cast<int>(pow(digito, i + 1)); 
        templanza *= potencia;
    }

    if (templanza > 0 && templanza % 3 == 0) {
        resultado = true;
    }
    return resultado;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Error: Se requiere un argumento entero." << endl;
        return 1;
    }
    
    long numColum = std::atoi(argv[1]);
    long totalTemplanza = 0;

    for (long i = 1; i < numColum; i++) {
        if (condicion(i)) {
            totalTemplanza++;
        }
    }

    cout << factorial(totalTemplanza) << endl;
    return 0;
}

