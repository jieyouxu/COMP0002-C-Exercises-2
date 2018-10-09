#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_LEVELS 6

#define WHITESPACE_CHARACTER " "
#define SOLID_CHARACTER "*"

void printLevel(int level, int whitespaceCount) {
    int whitespacesToPrint = whitespaceCount;
    for (int character = 0; character < NUMBER_OF_LEVELS; character++) {
        if (whitespacesToPrint > 0) {
            printf(WHITESPACE_CHARACTER);
            whitespacesToPrint--;
        } else {
            printf(SOLID_CHARACTER);
        }
    }
}

void newLine(void) {
    printf("\n");
}

void drawUpsideDownPyramid(void) {
    int whitespaceCount = 0;
    for (int level = NUMBER_OF_LEVELS; level > 0; level--) {
        printLevel(level, whitespaceCount);
        whitespaceCount++;
        newLine();
    }
}

int main(void) {
    drawUpsideDownPyramid();
    return 0;
}