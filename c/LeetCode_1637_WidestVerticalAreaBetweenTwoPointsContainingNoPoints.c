#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}


int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int *xs = (int*) malloc(pointsSize * sizeof(int));
    for (int i = 0; i < pointsSize; ++i) {
        xs[i] = points[i][0];
    } 

    qsort(xs, pointsSize, sizeof(int), cmp);

    int max = 0;
    for (int i = 0; i < pointsSize - 1; ++i) {
        int tmp = points[i + 1] - points[i];
        if (tmp > max) {
            max = tmp;
        }
    }

    return max;
}


int main() {

    return 0;
}