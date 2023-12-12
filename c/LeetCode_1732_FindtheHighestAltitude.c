#include <stdio.h>
#include <stdlib.h>

int largestAltitude(int* gain, int gainSize){
    if (gainSize <= 0) {
        return 0;
    }

    int max = -10000;
    int begin = 0;
    for (int i = 0; i < gainSize; i++) {
        begin += gain[i];
        if (begin > max) {
            max = begin;
        }
    }

    if (max < 0) {
        return 0;
    }
    return max;
}


int main() {
    int arr_size = 0;

    fputs("Array size: ", stdout);
    scanf_s("%d", &arr_size);

    int* arr = (int*)malloc(arr_size * sizeof(int));
    for (int i = 0; i < arr_size; i++) {
        printf_s("Element %d: ", i);
        scanf_s("%d", &arr[i]);
    }

    printf_s("Highest altitude: %d", largestAltitude(arr, arr_size));

    return 0;
}