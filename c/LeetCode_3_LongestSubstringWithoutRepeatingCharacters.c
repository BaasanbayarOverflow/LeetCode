#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char* s) {
    int visited[256] = {0};
    for (int i = 0; i < 256; ++i) {
        visited[i] = -1;
    }

    int result = 0; 
    int low = 0;
    for (int i = 0; i < strlen(s); ++i) {
        char letter = s[i];
        if (visited[letter] != -1 && low <= visited[letter]) {
            low = visited[letter] + 1;
        } else {
            int tmp = i - low + 1;
            result = (result > tmp) ? result : tmp;
        }
        visited[letter] = i;
    }

    return result;
}


int main() {

    return 0;
}