#include <stdio.h>


int findMinimumOperations(char* s1, char* s2, char* s3) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l3 = strlen(s3);
    int min = (l1 < l2) ? l1 : l2;
    min = (l3 < min) ? l3 : min;

    int counter = 0;
    for (int i = 0; i < min; ++i) {
        if (s1[i] == s2[i] && s1[i] == s3[i]) {
            ++counter;
        } else {
            break;
        }
    }

    if (counter == 0) { return -1; }

    return (l1 + l2 + l3) - (counter * 3);
}