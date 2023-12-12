// WITH ASCII 26 works 
// WITH UNICODE 256 works

#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool;

bool isAnagram(char* s, char* t) {
    int l_1 = strlen(s);
    int l_2 = strlen(t);

    if (l_1 != l_2) return false;

    int hash_1[26] = {0};
    int hash_2[26] = {0};
    for (int i = 0; i < l_1; ++i) {
        ++hash_1[s[i] - 'a'];
        ++hash_2[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (hash_1[i] != hash_2[i]) return false;
    }

    return true;
}