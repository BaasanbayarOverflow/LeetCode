#include <stdio.h>
#include <stdlib.h>


int reverse(int x){
    int is_negative = (x < 0) ? 1 : 0;

    x = abs(x);
    int rev = 0;
    while (x != 0) {
        rev *= 10;
        rev += x % 10;
        x /= 10;
    }

    if (rev <= -2147483648 || rev >= 2147483647) {
        return 0;
    }

    return (is_negative) ? (rev * -1) : rev;
}


int main() {
    reverse(123);
    return 0;
}