#include <stdio.h>
#include <stdbool.h>

#define START 1
#define END 100

bool isPrime(int n) {
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void printPrimeNumbers() {
    for (int i = START; i <= END; i++) {
        if (isPrime(i)) {
            printf("%i\n", i);
        }
    }
}

int main(void) {
    printPrimeNumbers();

    return 0;
}