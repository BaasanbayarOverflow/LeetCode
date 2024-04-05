#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* expand(char *s, int low, int high) {
    while (low >= 0 && high < strlen(s) && s[low] == s[high]) {
        --low;
        ++high;
    }

    ++low;
    int length = high - low;
    char *word = (char*) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; ++i) {
        word[i] = s[low];
        ++low;
    }
    word[length] = '\0';
    return word;
}


char* longestPalindrome(char* s) {
    int length = strlen(s);
    char *result = "";
    char *word = NULL;
    for (int i = 0; i < length; ++i) {
        word = expand(s, i, i);
        if (strlen(result) < strlen(word)) {
            result = word;
        }
        word = expand(s, i, i + 1);
        if (strlen(result) < strlen(word)) {
            result = word;
        }
    }

    return result;
}


int main() {
    char *words = "babad";
    longestPalindrome(words);
    return 0;
}