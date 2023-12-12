#include <stdio.h>
#include <stdlib.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows <= 0) {
        return NULL;
    }

    *returnSize = numRows;
    (*returnColumnSizes) = (int*) malloc(numRows * sizeof(int));

    int i = 0;
    int **arr = (int**) malloc(numRows * sizeof(int*));
    while (i < numRows) {
        (*returnColumnSizes)[i] = i + 1;

        int j = 0;
        arr[i] = (int*) malloc((i + 1) * sizeof(int));
        while (j <= i) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
            ++j;
        }
        ++i;
    }

    return arr;
}


int main() {
    int p;
    int *c;
    generate(1, &p, &c);

    return 0;
}