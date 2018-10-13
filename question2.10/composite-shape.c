#include <stdio.h>
#include <stdbool.h>

#define WIDTH 7
#define HEIGHT 8

#define ASTERISK "*"
#define HASHTAG "#"
#define WHITESPACE " "

bool isOnAsteriskTriangleTopBorder(int row) {
    return row == 0;
}

bool isOnAsteriskTriangleDiagonalBorder(int row, int col) {
    return row == col;
}

bool isOnAsteriskTriangleRightBorder(int row, int col) {
    return col == WIDTH-1 && row != HEIGHT-1;
}

bool isOnAsteriskTriangleBorder(int row, int col) {
    if (isOnAsteriskTriangleTopBorder(row)) {
        return true;
    } else if (isOnAsteriskTriangleRightBorder(row, col)) {
        return true;
    } else if (isOnAsteriskTriangleDiagonalBorder(row, col)) {
        return true;
    } else {
        return false;
    }
}

bool isOnHashtagTriangleBottomBorder(int row) {
    return row == HEIGHT-1;
}

bool isOnHashtagTriangleLeftBorder(int row, int col) {
    return col == 0 && row != 0;
}

bool isOnHashtagTriangleDiagonalBorder(int row, int col) {
    return row == col+1;
}

bool isOnHashtagTriangleBorder(int row, int col) {
    if (isOnHashtagTriangleBottomBorder(row)) {
        return true;
    } else if (isOnHashtagTriangleLeftBorder(row, col)) {
        return true;
    } else if (isOnHashtagTriangleDiagonalBorder(row, col)) {
        return true;
    } else {
        return false;
    }
}

void drawRow(int row) {
    for (int col = 0; col < WIDTH; col++) {
        if (isOnAsteriskTriangleBorder(row, col)) {
            printf(ASTERISK);
        } else if (isOnHashtagTriangleBorder(row, col)) {
            printf(HASHTAG);
        } else {
            printf(WHITESPACE);
        }
    }
}

void newLine(void) {
    printf("\n");
}

void drawCompositeShape(void) {
    for (int row = 0; row < HEIGHT; row++) {
        drawRow(row);
        newLine();
    }
}

int main(void) {
    drawCompositeShape();

    return 0;
}