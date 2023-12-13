#include <stdio.h>
#include <stdlib.h>


int numSpecial(int** mat, int matSize, int* matColSize) {
    int *rows = (int*) calloc(matSize, sizeof(int));
    int *columns = (int*) calloc(*matColSize, sizeof(int));
    int *ones = (int*) malloc((matSize * *matColSize) * 10 * sizeof(int));

    int inx = 0;
    for (int i = 0; i < matSize; ++i) {
        for (int j = 0; j < *matColSize; ++j) {
            if (mat[i][j] == 1) {
                rows[i] += 1;
                columns[j] += 1;

                ones[inx] = i;
                ones[++inx] = j;
                ++inx;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < (inx / 2); ++i) {
        int index = 2 * i;
        int x = ones[index];
        int y = ones[index + 1];

        if (rows[x] == 1 && columns[y] == 1) {
            ++result;
        }
    }


    return result;
}


int main() {
    int matr[10][10] = {{0,0,1,0},{0,0,0,0},{0,0,0,0},{0,1,0,0}};

    int p = 4;
    numSpecial(matr, 4, &p);

    return 0;
}