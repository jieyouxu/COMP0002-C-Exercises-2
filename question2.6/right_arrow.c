#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define RIGHT_ARROW_HEIGHT 9
#define RIGHT_ARROW_THICKNESS 5

#define WHITESPACE_CHARACTER " "
#define SOLID_CHARACTER "*"

void newLine(void) {
    printf("\n");
}

void printCharacters(int numOfCharacters, const char* character) {
    for (int characterPosition = 0; characterPosition < numOfCharacters; characterPosition++) {
        printf(character);
    }
}

void printWhitespaces(int numOfWhitespaces) {
    printCharacters(numOfWhitespaces, WHITESPACE_CHARACTER);
}

void printSolidCharacters(int numOfSolidCharacters) {
    printCharacters(numOfSolidCharacters, SOLID_CHARACTER);
}

bool printRow(int numOfWhitespaces, int numOfSolidCharacters) {
    printWhitespaces(numOfWhitespaces);
    printSolidCharacters(numOfSolidCharacters);
    newLine();
}

void printTopHalf(void) {
    int whitespaces = 0;
    for (int row = 0; row < RIGHT_ARROW_HEIGHT / 2; row++) {
        printRow(whitespaces, RIGHT_ARROW_THICKNESS);
        whitespaces++;
    }
}

void printCenter(void) {
    printRow(4, RIGHT_ARROW_THICKNESS);
}

void printBottomHalf(void) {
    int whitespaces = 3;
    int startIndex = (RIGHT_ARROW_HEIGHT / 2) + 1;
    for (int row = startIndex; row < RIGHT_ARROW_HEIGHT; row++) {
        printRow(whitespaces, RIGHT_ARROW_THICKNESS);
        whitespaces--;
    }
}

void printRightArrow(void) {
    printTopHalf();
    printCenter();
    printBottomHalf();
}

int main(void) {
    printRightArrow();
    return 0;
}