#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	//*returnSize = digitsSize;
	if (digitsSize <= 0) return NULL;

	int* tmp;
	if (digitsSize == 1) {
		if (digits[0] == 9) {
			tmp = (int*)malloc(2 * sizeof(int));
			tmp[0] = 1;
			tmp[1] = 0;
		}
		else {
			tmp = (int*)malloc(1 * sizeof(int));
			tmp[0] = digits[0] + 1;
		}
	}
	else {
		if (digits[digitsSize - 1] == 9) {
			digits[digitsSize - 1] += 1;
			digits[digitsSize - 2] += 1;
		}
		else {
			digits[digitsSize - 1] += 1;
		}
		tmp = (int*)malloc(digitsSize * sizeof(int));
		for (int i = 0; i < digitsSize; i++) {
			tmp[i] = digits[i];
		}
	}
	return tmp;
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

	plusOne(arr, size, NULL);

	return 0;
}