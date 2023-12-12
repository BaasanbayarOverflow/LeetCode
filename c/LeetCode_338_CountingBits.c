#include <stdio.h>
#include <stdlib.h>


int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int *arr = (int*) calloc(*returnSize, sizeof(int));
    for (int i = 1; i < *returnSize; ++i) {
        arr[i] = arr[i >> 1] + (i & 1);
    }

    return arr;
}


int main() {
    int p = 0;
    countBits(5, &p);

    return 0;
}