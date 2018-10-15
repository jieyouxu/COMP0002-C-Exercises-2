#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../graphics/graphics.h"

#include "spiral.h"

#define PI M_PI
#define DEG_TO_RAD (PI / 180.0)

#define NUM_OF_POINTS (360 * 5)
#define X_SCALE_FACTOR 1
#define Y_SCALE_FACTOR 1
#define X_OFFSET 250
#define Y_OFFSET 150

#define INITIAL_RADIUS 30.0
#define RADIUS_STEP_INCREMENT 0.1

Point_t spiralPoints[NUM_OF_POINTS];

void generateInitialSpiralPoints(void) {
    double radius = INITIAL_RADIUS;
    for (int angle = 0; angle < NUM_OF_POINTS; angle++) {
        spiralPoints[angle].x = radius * cos(angle * DEG_TO_RAD);
        spiralPoints[angle].y = radius * sin(angle * DEG_TO_RAD);
        radius += RADIUS_STEP_INCREMENT;
    }
}

void scaleSpiralPoints(void) {
    for (int i = 0; i < NUM_OF_POINTS; i++) {
        spiralPoints[i].x *= X_SCALE_FACTOR;
        spiralPoints[i].y *= Y_SCALE_FACTOR;
    }
}

void offsetSpiralPoints(void) {
    for (int i = 0; i < NUM_OF_POINTS; i++) {
        spiralPoints[i].x += X_OFFSET;
        spiralPoints[i].y += Y_OFFSET;
    }
}

void drawSpiralSegments(void) {
    for (int i = 0; i < NUM_OF_POINTS-1; i++) {
        double x1 = spiralPoints[i].x;
        double y1 = spiralPoints[i].y;
        double x2 = spiralPoints[i+1].x;
        double y2 = spiralPoints[i+1].y;

        drawLine(x1, y1, x2, y2);
    }
}

void drawSpiral(void) {
    generateInitialSpiralPoints();
    scaleSpiralPoints();
    offsetSpiralPoints();
    drawSpiralSegments();
}

int main(void) {
    drawSpiral();

    return 0;
}