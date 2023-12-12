#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;


int searchInsert(int* nums, int numsSize, int target) {

	// check if target exists in array
	int i = 0;
	bool isExists = false;
	for (; i < numsSize; i++) {
		if (nums[i] == target) {
			isExists = true;
			return i;
		}
	}

	// check where should target be 
	if (numsSize > 1) {
		int j = 0;
		for (; j < numsSize - 1; j++) {
			if (nums[j] < target) {
				if (nums[j + 1] >= target) {
					return j + 1;
				}
			}
			else {
				return j;
			}
		}
		return j + 2;
	}
	else if (numsSize == 1) {
		if (nums[0] > target) {
			return numsSize;
		}
		else {
			return 0;
		}
	}

	return -1;
}


int main() {
	int size = 0;

	fputs("Size of the array: ", stdout);
	scanf_s("%d", &size);

	int* arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		fputs("Array: ", stdout);
		scanf_s("%d", &arr[i]);
	}

	int target = 0;
	fputs("Target: ", stdout);
	scanf_s("%d", &target);

	printf("%d", searchInsert(arr, size, target));

	return 0;
}