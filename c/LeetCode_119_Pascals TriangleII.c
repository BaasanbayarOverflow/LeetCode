#include <stdio.h>
#include <stdlib.h>


int* getRow(int rowIndex, int* returnSize) {
    int *arr = (int*) malloc((rowIndex + 1) * sizeof(int));
    *returnSize = (rowIndex + 1);

    arr[0] = 1;
    int tmp = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        int num = (tmp * (rowIndex - i + 1)) / i;
        arr[i] = num;
        tmp = num;
    }

    return arr;
}


int main() {
    int p;
    getRow(3, &p);

    return 0;
}