#include <stdio.h>
#include <stdlib.h>


typedef enum {true, false} bool;


bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    else if (n == 1) return 1;

    int pow = 4;
    while (n >= pow) {
        if (pow == n) return true;
        pow *= 4;
    }

    return false;
}


int main() {
    isPowerOfFour(16);

    return 0;
}