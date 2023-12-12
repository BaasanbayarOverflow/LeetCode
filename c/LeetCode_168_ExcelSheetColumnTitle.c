#include <stdio.h>
#include <stdlib.h>


char* convertToTitle(int columnNumber) {
    if (columnNumber <= 0) {
        return NULL;
    }

    char *c = (char*) malloc(10 * sizeof(char));
    int i = 0;
    int tmp = 0;
    while (columnNumber != 0) {
        int tmp = (columnNumber % 26 == 0) ? 26 : columnNumber % 26;
        columnNumber = (columnNumber % 26 == 0) ? columnNumber - 1 : columnNumber;

        c[i] = tmp + 64;
        columnNumber /= 26;
        ++i;
    }
    c[i] = 0;
    --i;

    int j = 0;
    char tmp = ' ';
    while (j < i) {
        tmp = c[j];
        c[j] = c[i];
        c[i] = tmp;

        ++j; --i;
    }

    return c;
}


int main() {
    int i = 0;

    printf_s("Number: "); 
    scanf_s("%d", &i);

    convertToTitle(i);

    return 0;
}

