#include <stdio.h>
#include <stdlib.h>


void moveZeroes(int* nums, int numsSize) {
    int zeros = 0;

    int inx = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == 0) {
            ++zeros;
            inx = i + 1;
            while (nums[inx] == 0 && inx < numsSize - 1) {
                ++inx;
            }
            nums[i] = nums[inx];
            nums[inx] = 0;
        }
    }

    
}


int main() {
    int arr[] = {0, 1, 0, 3, 12};

    moveZeroes(&arr, 5);
    return 0;
}