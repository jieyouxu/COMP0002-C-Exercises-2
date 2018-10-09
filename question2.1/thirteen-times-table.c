#include <stdio.h>

#define LARGEST_FACTOR 13

void printThirteenTimesTable(void) {
    int factor = 1;
    int product = 0;
    while (factor <= LARGEST_FACTOR) {
        product = factor * 13;
        printf("%i * 13 = %i\n", factor, product);
        factor++;
    }
}

int main(void) {
    printThirteenTimesTable();
}