#include <stdio.h>
#include <stdlib.h>


int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    if (matrixColSize == NULL || matrix == NULL) {
        return NULL;
    }
    
    *returnSize = 0;

    int inx = 0;
    int **T = (int**) malloc(*matrixColSize * sizeof(int*));
    for (int j = 0; j < *matrixColSize; ++j) {
        int *tmp = (int*) malloc(*matrixColSize * sizeof(int));
        for (int i = 0; i < matrixSize; ++i) {
            printf("%d ", matrix[i][j]);
            tmp[i] = matrix[i][j];
        }
        ++inx;
        T[j] = tmp;
    }

    for (int i = 0; i < inx; ++i) {
        (*returnColumnSizes)[i] = matrixSize;
    }

    *returnSize = inx;
    return T;
}


int main() {
    
    int **matr = (int**) malloc(3 * sizeof(int*));
    
    int a_1[] = {1, 2, 3};
    int *p_a_1 = a_1;
    matr[0] = p_a_1; 

    int a_2[] = {4, 5, 6}; 
    int *p_a_2 = a_2;
    matr[1] = p_a_2;

    int a_3[] = {7, 8, 9}; 
    int *p_a_3 = a_3;
    matr[2] = p_a_3;
    
    int col = 3;
    int p = 0;
    int *ps = &p;

/*
    int **matr = (int**) malloc(2 * sizeof(int*));
    
    int a_1[] = {1, 2, 3};
    int *p_a_1 = a_1;
    matr[0] = p_a_1; 

    int a_2[] = {4, 5, 6}; 
    int *p_a_2 = a_2;
    matr[1] = p_a_2;

    int col = 3;
    int p = 0;
    int *ps = &p;
    

    int **matr = (int**) malloc(2 * sizeof(int*));
    
    int a_1[] = {1};
    int *p_a_1 = a_1;
    matr[0] = p_a_1; 

    int a_2[] = {4}; 
    int *p_a_2 = a_2;
    matr[1] = p_a_2;

    int col = 1;
    int p = 0;
    int *ps = &p;
*/    
    transpose(matr, 3, &col, &p, &ps);

    return 0;
}