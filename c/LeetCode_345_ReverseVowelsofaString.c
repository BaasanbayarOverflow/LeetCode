#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* stringToArray(char *s, int size) {
    char *arr = (char*) malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; ++i) {
        arr[i] = s[i];
    }

    arr[size] = '\0';
    return arr;
}


char* reverseVowels(char* s) {
    int low = 0;
    int high = strlen(s) - 1;

    char *arr = stringToArray(s, high + 1);
    while (low <= high) {
        int isLowVowel = (arr[low] == 'a' || arr[low] == 'A') || (arr[low] == 'e' || arr[low] == 'E') || (arr[low] == 'i' || arr[low] == 'I') || (arr[low] == 'o' || arr[low] == 'O') || (arr[low] == 'u' || arr[low] == 'U');
        int isHighVowel = (arr[high] == 'a' || arr[high] == 'A') || (arr[high] == 'e' || arr[high] == 'E') || (arr[high] == 'i' || arr[high] == 'I') || (arr[high] == 'o' || arr[high] == 'O') || (arr[high] == 'u' || arr[high] == 'U');
        if (!isLowVowel) {
            ++low;
        }

        if (!isHighVowel) {
            --high;
        }

        if (isLowVowel && isHighVowel) {
            char tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;

            ++low;
            --high;
        }
    }

    return arr;
}


int main() {
    char *str = "leetcode";
    
    reverseVowels(str);

    return 0;
}