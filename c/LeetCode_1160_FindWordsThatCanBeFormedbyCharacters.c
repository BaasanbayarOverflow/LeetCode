#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int countCharacters(char** words, int wordsSize, char* chars) {
    if (wordsSize <= 0) {
        return 0;
    }
    
    int sum = 0;
    for (int i = 0; i < wordsSize; ++i) {
        int counter = 0;
        int j = 0;
        char *tmp = (char*) malloc(strlen(chars) * sizeof(char));
        strcpy(tmp, chars);
        while (words[i][j] != '\0') {
            int k = 0;
            while (tmp[k] != '\0') {
                if (words[i][j] == tmp[k]) {
                    tmp[k] = '-';
                    ++counter;
                    break;
                }
                ++k;
            }

            ++j;
        }

        if (strlen(words[i]) == counter) {
            sum += counter;
        }
    }

    return sum;
}


int main() {
    char *chars = "welldonehoneyr";
    int wordsSize = 3;
    char *words[10] = {"hello","world","leetcode"};

    printf("%d ", countCharacters(words, wordsSize, chars));

    return 0;
}