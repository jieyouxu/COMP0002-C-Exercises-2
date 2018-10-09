#include <stdio.h>

#define LARGEST_FACTOR 13

void printThirteenTimesTable(void) {
    int factor = 1;
    int product = 0;

    do {
        product = factor * 13;
        printf("%i * 13 = %i\n", factor, product);
        factor++;
    } while (factor <= LARGEST_FACTOR);
}

int main(void) {
    printThirteenTimesTable();
}