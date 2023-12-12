#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {false, true} bool; 


int getNumberOfWords(char *s, int len) {
    int words = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            ++words;
        }
    }

    return ++words;
}


bool compareWords(char **words, int len, char *word) {
    for (int i = 0; i < len; ++i) {
        if (words[i][0] != '\0') {
            if (strcmp(words[i], word) == 0) {
                return false;
            }
        }
    }

    return true;
}


bool wordPattern(char* pattern, char* s) {
    int p_len = strlen(pattern);
    int s_len = strlen(s);

    int num_words = getNumberOfWords(s, s_len);
    if (p_len != num_words) {
        return false;
    }

    char **words = (char**) malloc(26 * sizeof(char*));
    for (int i = 0; i < 26; ++i) {
        words[i] = (char*) malloc(sizeof(char));
        words[i][0] = '\0';
    }

    int inx = 0;
    for (int i = 0; i < p_len; ++i) {
        while (s[inx] != ' ' && s[inx] != '\0') {
            ++inx;
        }

        char *word = (char*) malloc((inx + 1) * sizeof(char));
        strncpy(word, s, inx);
        word[inx] = '\0';

        if (words[pattern[i] - 'a'][0] == '\0') {
            if (!compareWords(words, 26, word)) {
                return 0;
            }

            words[pattern[i] - 'a'] = realloc(words[pattern[i] - 'a'], (inx + 1) * sizeof(char));
            strcpy(words[pattern[i] - 'a'], word);
        } else if (strcmp(word, words[pattern[i] - 'a']) != 0) {
            return 0;
        }

        if (s[inx] != '\0') {
            s += inx + 1;
        }

        inx = 0;
    }

    return 1;
}


int main() {
    char pattern[] = "abba";
    char s[] = "dog cat cat dog";

    char *p = pattern;
    char *p_1 = s;

    wordPattern(p, p_1);

    return 0;
}