#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {false, true} bool;


bool isPowerOfThree(int n) {
    if (n <= 0) return 0;

    double x = log10(n) / log10(3);
    double diff = x - (int)x;
    if (diff == 0) return 1;
    return 0;    
}


int main() {
    printf("%d ", isPowerOfThree(4782968));

    return 0;
}