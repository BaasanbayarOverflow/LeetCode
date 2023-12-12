#include <stdio.h>
#include <stdlib.h>


void merge(int *nums, int start, int midd, int end) {
    int n1 = midd + 1 - start;
    int n2 = end - midd;

    int *a_1 = (int*) malloc(n1 * sizeof(int));
    int *a_2 = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i) {
        a_1[i] = nums[start + i];
    }

    for (int i = 0; i < n2; ++i) {
        a_2[i] = nums[midd + i + 1];
    }

    int i = 0;
    int j = 0; 
    int k = start;
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
 

void mergeSort(int *nums, int start, int end)
{
    if (start < end) {
        int midd = (start + end) / 2;
 
        mergeSort(nums, start, midd);
        mergeSort(nums, midd + 1, end);
 
        merge(nums, start, midd, end);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize <= 2) {
        return NULL;
    }

    *returnSize = 0;
    //int size = 0;
    int **result = (int**) malloc(100000 * sizeof(int*));

    mergeSort(nums, 0, numsSize - 1);
    
    for (int i = 0; i < numsSize - 2; i++) {
        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                int *arr = (int*) malloc(3 * sizeof(int));
                arr[0] = nums[i];
                arr[1] = nums[j];
                arr[2] = nums[k];

                int f = 1;
                for (int z = 0; z < (*returnSize); ++z) {
                    if (result[z][0] == arr[0] && result[z][1] == arr[1] && result[z][2] == arr[2]) {
                        f = 0;
                    }
                }

                if (f) {
                    result[(*returnSize)++] = arr;
                }

                //result[size] = arr;
                //result[(*returnSize)++] = arr;
                //++size;
                ++j;
            }

            if (nums[i] + nums[j] + nums[k] > 0) {
                --k;
            }

            if (nums[i] + nums[j] + nums[k] < 0) {
                ++j;
            }
        }
    }

    //*returnColumnSizes = (int*) malloc((*returnSize) * sizeof(int));
    //for (int i = 0; i < (*returnSize); ++i) {
    //    (*returnColumnSizes)[i] = 3;
    //}

    return result;
}


int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int *p = nums;
    int returnSize;
    int **returnColumnSizes;

    int **matr = threeSum(p, 6, &returnSize, returnColumnSizes);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf_s("%d  ", matr[i][j]);
        }
        printf_s("\n");
    }

    return 0;
}



// Optimized version

/*
void merge(int *nums, int start, int midd, int end) {
    int n1 = midd + 1 - start;
    int n2 = end - midd;

    int *a_1 = (int*) malloc(n1 * sizeof(int));
    int *a_2 = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i) {
        a_1[i] = nums[start + i];
    }

    for (int i = 0; i < n2; ++i) {
        a_2[i] = nums[midd + i + 1];
    }

    int i = 0;
    int j = 0; 
    int k = start;
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
 

void mergeSort(int *nums, int start, int end)
{
    if (start < end) {
        int midd = (start + end) / 2;
 
        mergeSort(nums, start, midd);
        mergeSort(nums, midd + 1, end);
 
        merge(nums, start, midd, end);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize <= 2) {
        return NULL;
    }

    *returnSize = 0;
    //int size = 0;
    int **result = (int**) malloc((numsSize ^ 2) * 10 * sizeof(int*));

    mergeSort(nums, 0, numsSize - 1);
    
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; 
        }

        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                int *arr = (int*) malloc(3 * sizeof(int));
                arr[0] = nums[i];
                arr[1] = nums[j];
                arr[2] = nums[k];

                //result[size] = arr;
                result[(*returnSize)++] = arr;
                
                //++size;
                while (j < k && nums[j] == result[*returnSize - 1][1]) {
                    j++;
                }
                while (j < k && nums[k] == result[*returnSize - 1][2]) {
                    k--;
                }
            }

            if (nums[i] + nums[j] + nums[k] > 0) {
                --k;
            }

            if (nums[i] + nums[j] + nums[k] < 0) {
                ++j;
            }
        }
    }

    *returnColumnSizes = (int*) malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
*/
