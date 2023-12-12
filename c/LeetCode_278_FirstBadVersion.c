#include <stdio.h>
#include <stdlib.h>


int firstBadVersion(int n) {
    int low = 0;
    int high = n; 
    int middle = 0;

    while (low < high) {
        middle = low + (high - low) / 2;
        if (isBadVersion(middle)) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    return low;
}


int main() {
    printf("%d ", firstBadVersion(5));

    return 0;
}