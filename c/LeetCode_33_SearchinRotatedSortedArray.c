#include <stdio.h>
#include <stdlib.h>


int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        if (nums[low] == target) {
            return low;
        }

        if (nums[high] == target) {
            return high; 
        }

        ++low;
        --high;
    }

    return -1;
}


int main() {

    return 0;
}