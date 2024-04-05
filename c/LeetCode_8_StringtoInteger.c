#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int myAtoi(char* s) {
    int num = 0;
    int sign = 0;
    int is_negative = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] >= 48 && s[i] <= 57) {
            num *= 10;
            num += (s[i] - 48);
            sign = 1;
        } else if (s[i] == 45) {
            if (sign) break;
            sign = 1;
            is_negative = 1;
        } else if (s[i] == 43) {
            if (sign) break;
            sign = 1;
        } else if (s[i] == 32) {
            if (sign) break;
            continue;
        } else {
            break;
        }
    }

    if (is_negative) {
        num *= -1;
    }

    if (num <= -2147483648 || num >= 2147483647) {
        return (is_negative) ? -2147483648 : 2147483647;
    }

    return num;
}


int main() {
    char *s = "42";

    printf("%d ", myAtoi(s));
    return 0;
}