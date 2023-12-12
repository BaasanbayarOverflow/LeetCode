#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize <= 0) {
        return NULL;
    }

    int counter = 0;
    char **arr = (char**) malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; ++i) {
        int s = nums[i];
        while (i + 1 < numsSize && nums[i] + 1 == nums[i + 1]) {
            ++i;
        }

        arr[counter] = (char*) malloc(20 * sizeof(char));
        if (s != nums[i]) {
            snprintf(arr[counter], 20, "%d->%d", s, nums[i]);
        } else {
            snprintf(arr[counter], 20, "%d", s);
        }
        ++counter;
    }

    *returnSize = counter;
    return arr;
}


int main () {
    int nums[] = {0,1,2,4,5,7};
    int *p = nums;
    int *r;

    summaryRanges(p, 6, r);

    return 0;
}