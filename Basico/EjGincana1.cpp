#include <iostream>
using namespace std;

bool esPrimo(long n) {
    bool primo = true;
    long rangoMin = 2;
    long rangoMax = n;
    while (primo && rangoMin < rangoMax) {
        if (n % rangoMin == 0) {
            primo = false;
        }
        rangoMin++;
    }
    return primo;
}

long sumPrimos(long n) {
    long numPrimos = 0;
    long sumPrimos = 0;
    for (long i = 1; i < n; i++) {
        if (esPrimo(i)) {
            numPrimos++;
            sumPrimos += i;
        }
    }
    return sumPrimos * numPrimos;
}

int main() {
    cout << "En proceso" << endl;
    cout << sumPrimos(4 * 11 * 1997) << endl;
    return 0;
}

