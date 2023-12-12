#include <stdio.h>
#include <stdlib.h>


int getLength(char *c) {
    int counter = 0;
    while (*c != '\0') {
        *(c++);
        ++counter;
    }

    return counter;
}


int titleToNumber(char* columnTitle) {
    if (columnTitle == NULL) {
        return 0; 
    }

    unsigned long int total = 0;
    int mult = 1;

    int index = getLength(columnTitle) - 1;
    while (index >= 0) {
        total += (columnTitle[index] - 64) * mult;
        --index;
        mult *= 26;
    }


    return total;
}


int main() {
    char *a = "AB"; // 28
    char *b = "FXSHRXW"; // 701

    printf_s("%d\n", titleToNumber(a));
    printf_s("%d", titleToNumber(b));

    return 0;
}