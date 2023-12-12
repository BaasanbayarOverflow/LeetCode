#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int hammingWeight(uint32_t n) {
    int total = 0;

    for (unsigned short i = 0; i < 32; ++i) {
        total += (n & 1);
        n >>= 1;
    }   

    return total; 
}


int main() {
    hammingWeight(11);
    return 0;
}