#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* getAverages(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize <= 0) {
        return NULL;
    }

    int* avg = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        avg[i] = -1;
    }

    int real_size = k * 2 + 1;

    if (real_size > numsSize) {
        return avg;
    }
    
    long sum = 0;
    for (int i = 0; i < real_size; i++) {
        sum += nums[i];
    }

    for (int i = k; i + k < numsSize; i++) {
        avg[i] = sum / real_size;
        if (i + k + 1 < numsSize) {
            sum += nums[i + k + 1] - nums[i - k];
        }
    }
    return (avg);
}   


int main() {
    int arr_size = 0;

    fputs("Array size: ", stdout);
    scanf_s("%d", &arr_size);

    int* arr = (int*)malloc(arr_size * sizeof(int));
    for (int i = 0; i < arr_size; i++) {
        printf("Element %d: ", i);
        scanf_s("%d", &arr[i]);
    }

    int k = 0;
    fputs("k: ", stdout);
    scanf_s("%d", &k);

    int* temp;
    temp = getAverages(arr, arr_size, k, temp);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", temp[i]);
    }

    free(arr);
    return 0;
}