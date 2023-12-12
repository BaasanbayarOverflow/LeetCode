#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

#define MAX_SIZE 40


bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    if (word1Size == 0 && word2Size == 0) return 1;
    if (word1Size <= 0 || word2Size <= 0) return 0;

    int inx_i = 0;
    char* tmp_1 = (char*) malloc((MAX_SIZE * word1Size) * sizeof(char));
    for (int i = 0; i < word1Size; ++i) {
        int j = 0;
        while (word1[i][j] != '\0') {
            tmp_1[inx_i] = word1[i][j];
            ++j; ++inx_i;
        }
    }

    int inx_j = 0;
    char* tmp_2 = (char*) malloc((MAX_SIZE * word2Size) * sizeof(char));
    for (int i = 0; i < word2Size; ++i) {
        int j = 0;
        while (word2[i][j] != '\0') {
            tmp_2[inx_j] = word2[i][j];
            ++j; ++inx_j;
        }
    }

    if (inx_i != inx_j) return 0;

    int i = 0;
    while (i < inx_i) {
        if (tmp_1[i] != tmp_2[i]) {
            return 0;
        }
        ++i;
    }

    return 1;
}

int main() {
    char *word_1[] = {"a", "cb"};
    char *word_2[] = {"ab", "c"};

    printf("%d", arrayStringsAreEqual(word_1, 2, word_2, 2));

    return 0;
}