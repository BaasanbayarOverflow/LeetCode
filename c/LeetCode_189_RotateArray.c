#include <stdio.h>
#include <stdlib.h>


void rotate(int* nums, int numsSize, int k) {
    k = numsSize - (k % numsSize);

    int inx = 0;
    int *tmp = (int*) malloc(numsSize * sizeof(int));
    for (int i = k; i < numsSize; ++i) {
        tmp[inx] = nums[i];
        ++inx;
    }

    for (int i = 0; i < k; ++i) {
        tmp[inx] = nums[i];
        ++inx; 
    }

    for (int i = 0; i < numsSize; ++i) {
        nums[i] = tmp[i];
    }

    free(tmp);
}


int main() {
    return 0;
}