/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *array;
    int total;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *arr = (NumArray*) malloc(sizeof(NumArray));
    arr->array = (int*) malloc(numsSize * sizeof(int));
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        arr->array[i] = sum;
    }    
    arr->total = numsSize;
    return arr;
}


int numArraySumRange(NumArray* obj, int left, int right) {
    if (left == 0) {
        return obj->array[right];
    } 

    return obj->array[right] - obj->array[left - 1];
}


void numArrayFree(NumArray* obj) {
    free(obj->array);
    free(obj);
}


int main() {
    int numsSize = 6;
    int nums[] = {-2, 0, 3, -5, 2, -1};

    NumArray *obj = numArrayCreate(nums, numsSize);
    int param_1 = numArraySumRange(obj, 0, 2);

    numArrayFree(obj);
    return 0;
}