#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;


bool isUgly(int n) {
    while (n >= 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 5 == 0) {
            n /= 5;
        } else if (n == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}