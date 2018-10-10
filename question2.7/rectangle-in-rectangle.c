#include <stdio.h>
#include <stdbool.h>

#define OUTER_RECTANGLE_HEIGHT 7
#define OUTER_RECTANGLE_WIDTH 8

#define SOLID_CHARACTER_1 "*"
#define SOLID_CHARACTER_2 "#"
#define WHITESPACE_CHARACTER " "

void newLine(void) {
    printf("\n");
}

bool isCharacterOnTopOrBottomOuterBorder(int row) {
    return row == 0 || row == OUTER_RECTANGLE_HEIGHT-1;
}

bool isCharacterOnLeftOrRightOuterBorder(int col) {
    return col == 0 || col == OUTER_RECTANGLE_WIDTH-1;
}

bool isCharacterOnOuterBorder(int row, int col) {
    if (isCharacterOnTopOrBottomOuterBorder(row)) {
        return true;
    } else if (isCharacterOnLeftOrRightOuterBorder(col)) {
        return true;
    } else {
        return false;
    }
}

bool isCharacterOnInnerTopOrBottomBorderRow(int row) {
    return row == 2 || row == 4;
}

bool isCharacterOnInnerTopOrBottomBorderRowBetweenConstraint(int col) {
    return col >= 2 && col <= 5;
}

bool isCharacterOnInnerLeftOrRightBorderCol(int col) {
    return col == 2 || col == 5;
}

bool isCharacterOnInnerTopOrBottomBorderColBetweenConstraint(int row) {
    return row >= 2 && row <= 4;
}

bool isCharacterOnInnerBorder(int row, int col) {
    if (isCharacterOnInnerTopOrBottomBorderRow(row)) {
        if (isCharacterOnInnerTopOrBottomBorderRowBetweenConstraint(col)) {
            return true;
        } else {
            return false;
        }
    } else if (isCharacterOnInnerLeftOrRightBorderCol(col)) {
        if (isCharacterOnInnerTopOrBottomBorderColBetweenConstraint(row)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void drawCharacter(int row, int col) {
    if (isCharacterOnOuterBorder(row, col)) {
        printf(SOLID_CHARACTER_1);
    } else if (isCharacterOnInnerBorder(row, col)) {
        printf(SOLID_CHARACTER_2);
    } else {
        printf(WHITESPACE_CHARACTER);
    }
}

void drawRow(int row) {
    for (int col = 0; col < OUTER_RECTANGLE_WIDTH; col++) {
        drawCharacter(row, col);
    }
}

void drawRectangleInRectangle(void) {
    for (int row = 0; row < OUTER_RECTANGLE_HEIGHT; row++) {
        drawRow(row);
        newLine();
    }
}

int main(void) {
    drawRectangleInRectangle();

    return 0;
}