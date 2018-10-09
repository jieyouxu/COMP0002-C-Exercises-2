#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_ROWS 4
#define NUMBER_OF_COLUMNS 5


#define BORDER_CHARACTER "*"
#define WHITESPACE_CHARCTER " "

void newLine(void) {
    printf("\n");
}

bool isAtBorder(int row, int column) {
    if (row == 0 || row == NUMBER_OF_ROWS-1) {
        return true;
    } else if (column == 0 || column == NUMBER_OF_COLUMNS-1) {
        return true;
    } else {
        return false;
    }
}

void printAsteriskBorder(void) {
    for (int row = 0; row < NUMBER_OF_ROWS; row++) {
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
            if (isAtBorder(row, col)) {
                printf(BORDER_CHARACTER);
            } else {
                printf(WHITESPACE_CHARCTER);
            }
        }
        newLine();
    }
}

int main(void) {
    printAsteriskBorder();

    return 0;
}