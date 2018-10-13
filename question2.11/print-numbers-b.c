#include <stdbool.h>
#include <stdio.h>

#define START 1
#define END 101

bool isEven(int n) {
    return n % 2 == 0;
}

void printEvenSquares(void) {
    for (int n = START; n <= END; n++) {
        if (isEven(n)) {
            int x = n * n;

            if (x > END) {
                break;
            }

            printf("%i\n", x);
        }
    }
}

int main(void) {
    printEvenSquares();

    return 0;
}