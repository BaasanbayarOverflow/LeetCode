#include <stdio.h>
#include <stdlib.h>


int divide(int dividend, int divisor) {
    int is_negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? 1 : 0;
    dividend = abs(dividend);
    divisor = abs(divisor);

    int result = 0;
    while (dividend >= divisor) {
        int div = divisor;
        int mul = 1;
        while (dividend >= div) {
            dividend -= div;
            result += mul;
            mul += mul; 
            div += div;
        }
    }

    result = (is_negative) ? -result : result;
    
    if (result >= 2147483647) {
        return 2147483647;
    } else if (result <= -2147483648) {
        return -2147483648;
    }

    return result;
}


int main() {
    return 0;
}