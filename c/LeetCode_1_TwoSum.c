#include <stdio.h>
#include <stdlib.h>


int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
	*returnSize = 2;
	
	int sub = 1;
	int* result = (int*)malloc(*returnSize * sizeof(int));
	
	while (sub != numsSize + 1) {
		for (int i = 0; i < numsSize - sub; i++) {
			if ((nums[i] + nums[i + sub]) == target) {
				result[0] = i;
				result[1] = i + sub;
				return result;
 			}
		}
		sub += 1;
	}

	result[0] = -1;
	result[1] = -1;
	return result;
}

int main() {
	int target;
	int size;
	int* nums;

	fputs("Size of the array: ", stdout);
	scanf_s("%d", &size);

	nums = (int*)malloc(size * sizeof(int));
	if (nums == NULL) {
		fputs("Memory is not allocated!", stdout);
		exit(0);
	}

	fputs("Array: ", stdout);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &nums[i]);
	}

	fputs("Target: ", stdout);
	scanf_s("%d", &target);


	int* returnSize = NULL;
	int *result = twoSum(nums, size, target, returnSize);

	for (int i = 0; i < 2; i++) {
		printf("%d ", result[i]);
	}

	free(nums);

	return 0;
}