#include <stdio.h>
#include <stdlib.h>


int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int *ones_row = (int*) calloc(gridSize, sizeof(int));
    int *ones_col = (int*) calloc(*gridColSize, sizeof(int));
    int *zeros_row = (int*) calloc(gridSize, sizeof(int));
    int *zeros_col = (int*) calloc(*gridColSize, sizeof(int));

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == 0) {
                zeros_row[i] += 1;
                zeros_col[j] += 1;
            } else if (grid[i][j] == 1) {
                ones_row[i] += 1;
                ones_col[j] += 1;
            }
        }
    }

    *returnSize = gridSize;
    *returnColumnSizes = (int*) malloc(*returnSize * sizeof(int));
    int **diff = (int**) malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; ++i) {
        int *row = (int*) calloc(*gridColSize, sizeof(int));
        for (int j = 0; j < *gridColSize; ++j) {
            row[j] = ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j];
        }
        diff[i] = row;
        (*returnColumnSizes)[i] = *gridColSize;
    }

    return diff;
}



int main() {

    return 0;
}