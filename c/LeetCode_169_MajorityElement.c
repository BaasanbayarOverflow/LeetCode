#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int majorityElement(int* nums, int numsSize) {
    int ind = 0;
    int counter = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[ind] == nums[i]) {
            ++counter;
        } else {
            --counter;
        }

        if (counter == 0) {
            ind = i;
            counter = 1;
        }
    }

    return nums[ind];
}


int main() {
    int *nums = malloc(3 * sizeof(int));
    nums[0] = 3;
    nums[1] = 3;
    nums[2] = 4;

    majorityElement(nums, 3);
    return 0;
}