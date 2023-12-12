#include <stdio.h>
#include <stdlib.h>


void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    if (n == 0) {
        return;
    }

    int size = m + n;
    if (m > nums1Size || n > nums2Size || nums1Size < size) {
        return;
    } 

    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }


    int *temp = NULL;
    temp = (int*) malloc(size * sizeof(int));
    int i = 0;
    int j = 0;
    int z = 0;
    for (z = 0; z < size; z++) {
        if (nums1[i] <= nums2[j]) {
            temp[z] = nums1[i];
            ++i;
            if (i == m) break;
        } else if (nums2[j] < nums1[i]) {
            temp[z] = nums2[j];
            ++j;
            if (j == n) break;
        } 
    }

    ++z;
    if (i == m) {
        for (int i = j; i < n; ++i) {
            temp[z] = nums2[i];
            ++z;
        }
    } else if (j == n) {
        for (int j = i; j < m; ++j) {
            temp[z] = nums1[j];
            ++z;
        }
    }

    for (int i = 0; i < nums1Size; i++) {
        nums1[i] = temp[i];
    }

    free(temp);
}


int main() {
    int m = 0;
    int n = 0;

    printf_s("Enter size 1: ");
    scanf_s("%d", &m);

    int *nums_1 = NULL;
    nums_1 = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        printf_s("Element %d - ", i);
        scanf_s("%d", &nums_1[i]);
    }

    printf_s("Enter size 2: ");
    scanf_s("%d", &n);

    int *nums_2 = NULL;
    nums_2 = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf_s("Element %d - ", i);
        scanf_s("%d", &nums_2[i]);
    }

    merge(nums_1, m, 5, nums_2, n, 1);

    return 0;
}