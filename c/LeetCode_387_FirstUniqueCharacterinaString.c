#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int firstUniqChar(char* s) {
    int len = strlen(s);
    int hash[26] = {0};

    for (int i = 0; i < len; ++i) {
        ++hash[s[i] - 'a'];
    }

    for (int i = 0; i < len; ++i) {
        if (hash[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}


int main() {
    char *s = "aabb";
    printf("%d ", firstUniqChar(s));
    return 0;
}