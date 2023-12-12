#include <stdio.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
	if (numsSize <= 0) {
		return 0;
	}

	int k = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != val) {
			nums[k] = nums[i];
			k++;
		}
	}

	return k;
}


int main() {
	int size = 0;
	
	fputs("Size of the array: ", stdout);
	scanf_s("%d", &size);

	int* nums = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		fputs("Array: ", stdout);
		scanf_s("%d", &nums[i]);
	}

	int val;
	fputs("Value: ", stdout);
	scanf_s("%d", &val);

	printf("%d", removeElement(nums, size, val));

	return 0;
}