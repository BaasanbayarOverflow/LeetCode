#include <stdio.h>
#include <stdlib.h>


int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int max_2 = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > max) {
            max_2 = max;
            max = nums[i];
        } else {
            max_2 = (max_2 > nums[i]) ? max_2 : nums[i];
        }
    }

    return (max - 1) * (max_2 - 1);
}


int main() {
    int nums[] = {10,2,5,2};
    int n = 4;

    printf("%d ", maxProduct(nums, n));

    return 0;
}