#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* largestGoodInteger(char* num) {
    int len = strlen(num);
    if (num == NULL && len < 3) {
        return "";
    }

    char c = '+';
    for (int i = 0; i < len - 2; ++i) {
        if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
            if (num[i] > c) {
                c = num[i];
            }
        }
    }

    if (c == '+') return "";

    char *result = (char*) malloc(4 * sizeof(char));
    result[0] = result[1] = result[2] = c;
    result[3] = '\0';
    return result;
}


int main() {
    char c[] = "6777133339"; //"6777133339";
    char *p = c;

    char *t = largestGoodInteger(p);
    for (int i = 0; i < 3; ++i) {
        printf("%c ", t[i]);
    }

    return 0;
}