#include <stdio.h>
#include <stdbool.h>

#define SOLID_CHARACTER_1 "*"
#define SOLID_CHARACTER_2 "#"

#define WIDTH 6
#define HEIGHT 6

bool isOdd(int n) {
    return n % 2 != 0;
}

void drawCharacter(int row, int col) {
    if (isOdd(row)) {
        if (isOdd(col)) {
            printf(SOLID_CHARACTER_1);
        } else {
            printf(SOLID_CHARACTER_2);
        }
    } else {
        if (isOdd(col)) {
            printf(SOLID_CHARACTER_2);
        } else {
            printf(SOLID_CHARACTER_1);
        }
    }
}

void drawRow(int row) {
    for (int col = 0; col < WIDTH; col++) {
        drawCharacter(row, col);
    }
}

void newLine(void) {
    printf("\n");
}

void drawContent(void) {
    for (int row = 0; row < HEIGHT; row++) {
        drawRow(row);
        newLine();
    }
}

int main(void) {
    drawContent();

    return 0;
}