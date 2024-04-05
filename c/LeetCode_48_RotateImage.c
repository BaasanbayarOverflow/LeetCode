#include <stdio.h>
#include <stdlib.h>


void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i + 1; j < matrixSize; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    int hlf = matrixSize / 2;
    for (int i = 0; i < matrixSize; ++i) {
        int inx = matrixSize - 1;
        for (int j = 0; j < hlf; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][inx];
            matrix[i][inx] = tmp;
            --inx;
        }
    }
}