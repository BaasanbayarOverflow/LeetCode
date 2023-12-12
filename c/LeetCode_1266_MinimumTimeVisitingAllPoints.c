#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 1) {
        *pointsColSize = 0;
        return 0;
    }

    int duration = 0;
    for (int i = 0; i < pointsSize - 1; ++i) {
        duration += max(abs(points[i][0] - points[i + 1][0]), abs(points[i][1] - points[i + 1][1]));
    }

    return duration;
}


int main() {


    return 0;
}