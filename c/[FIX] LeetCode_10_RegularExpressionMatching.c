#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {true, false} bool;


bool isMatch(char* s, char* p) {
    int rows = strlen(s);
    int columns = strlen(p);

    if (rows == 0 && columns == 0) {
        return true;
    } else if (rows == 0) {
        return false;
    }

    int **matrix = (int**) malloc((rows + 2) * sizeof(int*));
    for (int i = 0; i < columns; ++i) {
        matrix[i] = (int*) calloc(columns + 2, sizeof(int));
    }
    matrix[0][0] = 1;

    for (int i = 2; i < columns + 1; ++i) {
        if (p[i - 1] == '*') {
            matrix[0][i] = matrix[0][i - 2];
        }
    }

    for (int i = 1; i < rows + 1; ++i) {
        for (int j = 1; j < columns + 1; ++j) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else if (j > 1 && p[j - 1] == '*') {
                matrix[i][j] = matrix[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    matrix[i][j] = matrix[i][j] || matrix[i - 1][j];
                }
            }
        }
    }


    return matrix[rows][columns];
}


int main() {
    char *s = "aa";
    char *p = "a*";

    isMatch(s, p);

    return 0;
}