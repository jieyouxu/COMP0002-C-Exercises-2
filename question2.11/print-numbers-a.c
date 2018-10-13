#include <stdbool.h>
#include <stdio.h>

#define START 1
#define END 100

void printSquares(void) {
    for (int i = START; i <= END; i++) {
        int x = i*i;
        if (x <= END) {
            printf("%i\n", x);
        } else {
            break;
        }
    }
}

int main(void) {
    printSquares();

    return 0;
}