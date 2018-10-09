#include <stdio.h>

#define LARGEST_FACTOR 13

void printThirteenTimesTable(void) {
    int product = 0;
    for (int factor = 1; factor <= LARGEST_FACTOR; factor++) {
        product = factor * 13;
        printf("%i * 13 = %i\n", factor, product);
    }
}

int main(void) {
    printThirteenTimesTable();
}