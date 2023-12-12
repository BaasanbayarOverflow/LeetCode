#include <stdio.h>
#include <stdlib.h>


void merge(int *nums, int low, int mid, int high) {
    int n1 = mid + 1 - low;
    int n2 = high - mid;

    int *a_1 = (int*) malloc(n1 * sizeof(int));
    int *a_2 = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i) {
        a_1[i] = nums[low + i];
    }

    for (int i = 0; i < n2; ++i) {
        a_2[i] = nums[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2) {
        if (a_1[i] < a_2[j]) {
            nums[k] = a_1[i];
            ++i;
        } else {
            nums[k] = a_2[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        nums[k] = a_1[i];
        ++i; ++k;
    }

    while (j < n2) {
        nums[k] = a_2[j];
        ++j; ++k;
    }
}


void mergeSort(int *nums, int low, int high) {
    if (low < high) {
        int mid = (low + high - 1) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
}


int threeSumClosest(int* nums, int numsSize, int target) {
    if (numsSize <= 2) {
        return 0;
    }

    mergeSort(nums, 0, numsSize - 1);

    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int j = i + 1;
        int k = numsSize - 1;

        int sum = 0;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];

            if (abs(sum - target) < abs(result - target)) {
                result = sum;
            }
            
            if (sum < target) {
                ++j;
            } else {
                --k;
            }
        }
    }

    return result;
}

int main() {
    int arr[] = {-1, 2, 1, -4};
    int *p = arr;

    printf_s("%d", threeSumClosest(p, 4, 1));

    return 0;
}