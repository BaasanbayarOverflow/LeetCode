#include <stdio.h>


double myPow(double x, int n) {
    int is_negative = (n < 0) ? 1 : 0;
    n = abs(n);
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res *= x;
        }
        x *= x;
        n /= 2;
    }

    return (is_negative) ? 1 / res : res;
}


int main() {
    myPow(2, -2);
    return 0;
}