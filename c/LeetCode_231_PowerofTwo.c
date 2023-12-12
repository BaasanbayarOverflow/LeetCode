#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool;


bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return !(n & (n - 1));
}

int main() {
    isPowerOfTwo(4);

    return 0;
}