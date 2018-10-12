#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 5
#define HEIGHT 9

#define SOLID_CHARACTER "*"
#define WHITESPACE_CHARACTER " "

bool isOnLeftEdge(int col) {
    return col == 0;
}

bool isOnTopHalfOfTriangleBorder(int row, int col) {
    if (row == col) {
        return true;
    } else {
        return false;
    }
}

bool isOnMiddleOfTriangleBorder(int row, int col) {
    if (col == MAX_WIDTH-1) {
        return true;
    } else {
        return false;
    }
}

bool isOnBottomHalfOfTriangleBorder(int row, int col) {
    if (row > (HEIGHT/2) && col == HEIGHT-1-row) {
        return true;
    } else {
        return false;
    }
}

bool isOnTriangleEdges(int row, int col) {
    if (isOnLeftEdge(col)) {
        return true;
    } else if (isOnTopHalfOfTriangleBorder(row, col)) {
        return true;
    } else if (isOnMiddleOfTriangleBorder(row, col)) {
        return true;
    } else if (isOnBottomHalfOfTriangleBorder(row, col)) {
        return true;
    } else {
        return false;
    }
}

void drawTopHalfRow(int row) {
    for (int col = 0; col <= row; col++) {
        if (isOnTriangleEdges(row, col)) {
            printf(SOLID_CHARACTER);
        } else {
            printf(WHITESPACE_CHARACTER);
        }
    }
}

void drawMiddleRow(void) {
    for (int col = 0; col < MAX_WIDTH; col++) {
        if (isOnTriangleEdges(HEIGHT/2, col)) {
            printf(SOLID_CHARACTER);
        } else {
            printf(WHITESPACE_CHARACTER);
        }
    }
}

void drawBottomHalfRow(int row) {
    for (int col = 0; col <= HEIGHT-1-row; col++) {
        if (isOnTriangleEdges(row, col)) {
            printf(SOLID_CHARACTER);
        } else {
            printf(WHITESPACE_CHARACTER);
        }
    }
}

void newLine(void) {
    printf("\n");
}

void drawTopHalf(void) {
    for (int row = 0; row < HEIGHT / 2; row++) {
        drawTopHalfRow(row);
        newLine();
    }
}

void drawMiddle(void) {
    drawMiddleRow();
    newLine();
}

void drawBottomHalf(void) {
    for (int row = ((HEIGHT/2)+1); row < HEIGHT; row++) {
        drawBottomHalfRow(row);
        newLine();
    }
}

void drawRightTriangle(void) {
    drawTopHalf();
    drawMiddle();
    drawBottomHalf();
}

int main(void) {
    drawRightTriangle();

    return 0;
}