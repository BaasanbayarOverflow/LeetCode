#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {false, true} bool; 


bool canConstruct(char* ransomNote, char* magazine) {
    int l_ran = strlen(ransomNote);
    int l_mag = strlen(magazine);

    int *hash = (int*) calloc(26, sizeof(int));
    for (int i = 0; i < l_mag; ++i) {
        ++hash[magazine[i] - 'a'];
    }    

    for (int i = 0; i < l_ran; ++i) {
        --hash[ransomNote[i] - 'a'];
        if (hash[ransomNote[i] - 'a'] < 0) return false;
    }

    return true;
}


int main() {

    return 0;
}