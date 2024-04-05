#include <stdio.h>
#include <stdlib.h>


int maxProductDifference(int* nums, int numsSize){
    int max = 0;
    int max_m = max; 
    int min = 10000;
    int min_m = min;

    for (int i = 0; i < numsSize; ++i) {
        if (max < nums[i]) {
            max_m = max;
            max = nums[i];
        } else if (nums[i] > max_m || nums[i] == max) {
            max_m = nums[i];
        }

        if (min > nums[i]) {
            min_m = min;
            min = nums[i];
        } else if (nums[i] < min_m || nums[i] == min) {
            min_m = nums[i];
        }
    }

    return (max * max_m) - (min * min_m);
}


int main() {
    return 0;
}