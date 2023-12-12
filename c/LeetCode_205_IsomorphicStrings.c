// not working

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {true, false} bool;

#define MAX_CHARS 256


bool isIsomorphic(char* s, char* t) {
    int l = strlen(s);
    int l_1 = strlen(t);
    if (l != l_1) {
        return false;
    }    

    bool marked[MAX_CHARS];
    memset(marked, 1, sizeof(marked));
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));

    for (int i = 0; i < l; ++i) {
        if (map[s[i]] == -1) {
            if (marked[t[i]] == true) {
                return false;
            }

            marked[t[i]] = true;
            map[s[i]] = t[i];
        } else if (map[s[i]] != t[i]) {
            return false;
        }
    }

    return true;
}


int main() {
    char *s = "egg";
    char *t = "add";

    printf("%d ", isIsomorphic(s, t));

    return 0;
}