#include <stdio.h>
#include <stdlib.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1Size == 0 && nums2Size == 0) {
		return 0.0;
	}

	int totLen = nums1Size + nums2Size;

	int inx_1 = 0;
	int inx_2 = 0;
	int* mArr = (int*)malloc(totLen * sizeof(int));

	int i = 0, j = 0, z = 0;
	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			mArr[z] = nums1[i];
			i += 1;
		}
		else {
			mArr[z] = nums2[j];
			j += 1;
		}
		z += 1;
	}

	while (i < nums1Size) {
		mArr[z] = nums1[i];
		i += 1;
		z += 1;
	}

	while (j < nums2Size) {
		mArr[z] = nums2[j];
		j += 1;
		z += 1;
	}

	/*
	for (int j = 0; j < totLen; j++) {
		printf("[%d]", mArr[j]);
	}
	*/

	if (totLen % 2 == 0) {
		int fInx = (totLen / 2) - 1;
		int lInx = totLen / 2;
		return (mArr[fInx] + mArr[lInx]) / 2.0;
	}
	else if (totLen % 2 == 1) {
		int mInx = totLen / 2;
		return mArr[mInx];
	}
	
	return 0.0;
}
 
int main() {
	int nSize_1 = 0;
	int nSize_2 = 0;

	fputs("Size of first array: ", stdout);
	scanf_s("%d", &nSize_1);

	fputs("Size of second array: ", stdout);
	scanf_s("%d", &nSize_2);

	int* arr_1 = (int*)malloc(nSize_1 * sizeof(int));
	int* arr_2 = (int*)malloc(nSize_2 * sizeof(int));
	
	for (int i = 0; i < nSize_1; i++) {
		fputs("First array: ", stdout);
		scanf_s("%d", &arr_1[i]);
	}

	for (int i = 0; i < nSize_2; i++) {
		fputs("Second array: ", stdout);
		scanf_s("%d", &arr_2[i]);
	}

	printf("%2f", findMedianSortedArrays(arr_1, nSize_1, arr_2, nSize_2));

	return 0;
}


/*

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1Size == 0 && nums2Size == 0) {
		return 0.0;
	}

	int totLen = nums1Size + nums2Size;

	int inx_1 = 0;
	int inx_2 = 0;
	int* mArr = (int*)malloc(totLen * sizeof(int));

	int i = 0;
	for (; i < totLen; i++) {
		if (*(nums1 + inx_1) > *(nums2 + inx_2)) {
			mArr[i] = *(nums2 + inx_2);
			inx_2 += 1;

			if (inx_2 == nums2Size) {
				*(nums2 + inx_2) = 100000;
			}
		}
		else if (*(nums1 + inx_1) <= *(nums2 + inx_2)) {
			mArr[i] = *(nums1 + inx_1);
			inx_1 += 1;

			if (inx_1 == nums1Size) {
				*(nums1 + inx_1) = 100000;
			}
		}
	}

	if (i % 2 == 0) {
		int fInx = (i / 2) - 1;
		int lInx = i / 2;
		return (mArr[fInx] + mArr[lInx]) / 2.0;
	}
	else if (i % 2 == 1) {
		int mInx = i / 2;
		return mArr[mInx];
	}

	return 0.0;
}

*/