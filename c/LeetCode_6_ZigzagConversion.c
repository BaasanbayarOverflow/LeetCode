#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* convert(char* s, int numRows) {
    if (numRows <= 1) {
        return s;
    }

    int len = strlen(s);

    int inx = 0;
    int low = 0;
    int high = (numRows * 2) - 2;
    char *arr = (char*) malloc((len + 10) * sizeof(char));
    for (int i = 0; i < numRows; ++i) {
        int flag = 0;
        int j = i; 
        while (j < len) {
            arr[inx++] = s[j];

            if (flag && low != 0 || !high) {
                j += low;
                flag = 0;
            } else {
                j += high;
                flag = 1;
            }
        }

        low += 2;
        high -= 2;
    }

    arr[inx] = '\0';
    return arr;
}


int main() {
    convert("PAYPALISHIRING", 3);
    return 0;
}