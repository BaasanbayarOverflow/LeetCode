#include <stdio.h>
#include <stdlib.h>


int findSpecialInteger(int* arr, int arrSize) {
    float probability = arrSize / 4;

    int prev = -1;
    int countr = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (prev != arr[i]) {
            countr = 0;
            prev = arr[i];
        }
        
        ++countr;

        if (countr > probability) {
            return arr[i];
        }
    }

    return 0;
}


int main() {
    int arr[] = {1,2,2,6,6,6,6,7,10};
    int size = 9;

    int *p = arr;
    findSpecialInteger(p, size);

    return 0;
}