#include <stdio.h>
#include <stdlib.h>

int numberOfMatches(int n){
    int matches = 0; 
    while (n / 2 != 0) {
        int rem = n % 2;
        n = n / 2;
        matches += n;
        n += rem; 
    }

    return matches;
}

int main() {
    return 0;
}