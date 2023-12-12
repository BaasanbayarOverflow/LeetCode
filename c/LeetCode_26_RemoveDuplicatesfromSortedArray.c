#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize <= 0) {
		return 0;
	}

	int k = 0;
	int tmp = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] != nums[i + 1]) {
			nums[k] = nums[i + 1];
			k += 1;
		}
	}
	nums[k] = nums[numsSize - 1];
	k += 1;

	return k;
}

int main() {
	int size;
	
	fputs("Size of the array: ", stdout);
	scanf_s("%d", &size);

	int* nums = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		fputs("Array: ", stdout);
		scanf_s("%d", &nums[i]);
	}

	printf("%d", removeDuplicates(nums, size));

	return 0;
}