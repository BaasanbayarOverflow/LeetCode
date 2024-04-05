#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findMax(const int a, const int b) {
    return (a > b) ? a : b;
}


int maxScore(char* s) {
    int len = strlen(s);

    int ones = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') {
            ++ones;
        }
    }   

    int s0 = 0;
    int s1 = 0;
    int res = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (s[i] == '0') {
            ++s0;
        } else if (s[i] == '1') {
            ++s1;
        }

        res = findMax(res, s0 + ones - s1);
    }

    return res;
}


int main() {
    char *s = "00";
    maxScore(s);

    return 0;
}