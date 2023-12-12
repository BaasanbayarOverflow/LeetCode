#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    
    // XOR all elements in the array
    for (int i = 0; i < numsSize; ++i) {
        result ^= nums[i];
    }
    
    return result;
}

int main() {
    int nums[] = {1, 3, 2, 1, 2, 3, 4}; 
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = singleNumber(nums, numsSize);
    
    printf("The single number is: %d\n", result);

    return 0;
}