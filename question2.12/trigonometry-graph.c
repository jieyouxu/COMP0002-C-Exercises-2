#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../graphics/graphics.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 300

#define X_SCALE_FACTOR (250.0 / 360.0)  // pixels/degree
#define X_LABEL_STEP_SIZE 45.0          // degrees
#define Y_SCALE_FACTOR (150.0 / 3)      // pixels/unit
#define Y_LABEL_STEP_SIZE 1.0           // units

#define X_OFFSET 0
#define Y_OFFSET 150

#define PI 3.14159265358979

#define TOTAL_POINTS 720

#define X_START 0
#define X_END 720

void drawXAxis(void) {
    drawLine(0, 150, 500, 150);
}

void drawYAxis(void) {
    drawLine(250, 0, 250, 300);
}

void drawXAxisTickMarks(void) {
    double x = 0;

    while (x <= WINDOW_WIDTH) {
        drawLine((int)x, 150, (int)x, 160);
        x += X_LABEL_STEP_SIZE * X_SCALE_FACTOR;
    }
}

void drawXAxisNumberLabels(void) {
    double degree = -360;
    double x = 0;
    char str[10];

    while (x <= WINDOW_WIDTH) {
        sprintf(str, "%i", (int)degree);
        drawString(str, (int)x, 170);
        degree += X_LABEL_STEP_SIZE;
        x += X_LABEL_STEP_SIZE * X_SCALE_FACTOR;
    }
}

void drawXAxisLabels(void) {
    drawXAxisTickMarks();
    drawXAxisNumberLabels();
}

void drawYAxisTickMarks(void) {
    double y = 0;

    while (y <= WINDOW_HEIGHT) {
        drawLine(250, (int)y, 260, (int)y);
        y += Y_LABEL_STEP_SIZE * Y_SCALE_FACTOR;
    }
}

void drawYAxisNumberLabels(void) {
    double unit = 3;
    double y = 0;
    char str[10];

    while (y <= WINDOW_HEIGHT) {
        sprintf(str, "%i", (int)unit);
        drawString(str, 270, (int)y);
        unit -= Y_LABEL_STEP_SIZE;
        y += Y_LABEL_STEP_SIZE * Y_SCALE_FACTOR;
    }
}

void drawYAxisLabels(void) {
    drawYAxisTickMarks();
    drawYAxisNumberLabels();
}

typedef struct Point {
    double x;
    double y;
} Point_t;

double degreeToRadian(double d) {
    return d * (PI / 180.0);
}

Point_t cosinePoints[TOTAL_POINTS];
Point_t sinePoints[TOTAL_POINTS];
Point_t tangentPoints[TOTAL_POINTS];

void calculateTrigPoints(Point_t* points, double (*trigFunction)(double)) {
    int x = X_START;
    for (int n = 0; n < TOTAL_POINTS; n++) {
        double x_in_radians = degreeToRadian(x);
        double x_coordinate = x;
        double y_coordinate = (*trigFunction)(x_in_radians);

        (*(points + n)).x = x_coordinate;
        (*(points + n)).y = y_coordinate;

        x++;
    }
}

void offsetAndScaleTrigPoints(Point_t* points) {
    for (int n = 0; n < TOTAL_POINTS; n++) {
        (*(points + n)).x *= X_SCALE_FACTOR;
        (*(points + n)).x += X_OFFSET;
        (*(points + n)).y *= -Y_SCALE_FACTOR;
        (*(points + n)).y += Y_OFFSET;
    }
}

void calculateTrigCurve(Point_t* points, double (*trigFunction)(double)) {
    calculateTrigPoints(points, trigFunction);
    offsetAndScaleTrigPoints(points);
}

bool tangentIsUndefinedAt(int n) {
    return (n + 90) % 180 == 0 || (n + 1 + 90) % 180 == 0;
}

void _drawTangentCurve() {
    calculateTrigCurve(tangentPoints, tan);

    for (int n = 0; n < TOTAL_POINTS - 1; n++) {
        if (tangentIsUndefinedAt(n)) {
            continue;
        } else {
            double x1 = tangentPoints[n].x;
            double y1 = tangentPoints[n].y;
            double x2 = tangentPoints[n + 1].x;
            double y2 = tangentPoints[n + 1].y;

            drawLine(x1, y1, x2, y2);
        }
    }
}

void drawTrigCurve(Point_t* points, double (*trigFunction)(double)) {
    calculateTrigCurve(points, trigFunction);

    for (int n = 0; n < TOTAL_POINTS - 1; n++) {
        double x1 = (*(points + n)).x;
        double y1 = (*(points + n)).y;
        double x2 = (*(points + n + 1)).x;
        double y2 = (*(points + n + 1)).y;

        drawLine(x1, y1, x2, y2);
    }
}

void drawSineCurve(void) {
    setColour(red);
    drawTrigCurve(sinePoints, sin);
    setColour(black);
}

void drawCosineCurve(void) {
    setColour(blue);
    drawTrigCurve(cosinePoints, cos);
    setColour(black);
}

void drawTangentCurve(void) {
    setColour(green);
    _drawTangentCurve();
    setColour(black);
}

void drawGraph(void) {
    drawXAxis();
    drawXAxisLabels();
    drawYAxis();
    drawYAxisLabels();
    drawSineCurve();
    drawCosineCurve();
    drawTangentCurve();
}

int main(void) {
    drawGraph();

    return 0;
}