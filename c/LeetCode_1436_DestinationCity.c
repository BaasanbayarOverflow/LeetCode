#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* destCity(char paths[100][100][100], int pathsSize, int* pathsColSize) {
    char **destination = (char**) malloc(pathsSize * sizeof(char*));
    char **source = (char**) malloc(pathsSize * sizeof(char*));
    
    for (int i = 0; i < pathsSize; ++i) {
        source[i] = paths[i][0];
        destination[i] = paths[i][1];
    }

    for (int i = 0; i < pathsSize; ++i) {
        int flag = 0;
        for (int j = 0; j < pathsSize; ++j) {
            if (strcmp(destination[i], source[j]) == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) return destination[i];
    }

    return 0;
}


int main() {
    char paths[100][100][100] = {{"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"}};
    int colSize = 2;

    destCity(paths, 3, &colSize);

    return 0;
}