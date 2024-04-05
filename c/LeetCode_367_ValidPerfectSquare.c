#include <stdio.h>
#include <stdlib.h>


typedef enum {false, true} bool;


bool isPerfectSquare(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }

    int low = 0;
    int mid = 0;
    int high = num; 
    while (low < high - 1) {
        mid = low + ((high - low) / 2);

        int sqr = mid * mid;
        if (sqr == num) {
            return 1;
        } else if (sqr > num) {
            high = mid;
        } else if (sqr < num) {
            low = mid;
        }
    }

    return 0;
}


int main() {
    return 0;
}