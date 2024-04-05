#include <stdio.h>
#include <stdlib.h>


int guessNumber(int n){
    int low = 0;
    int high = n;
    int res = guess(n);
    while (res != 0) {
        int mid = low + ((high - low) / 2);

        res = guess(mid);
        if (res == 0) {
            return mid;
        } else if (res == 1) {
            low = mid;
        } else if (res == -1) {
            high = mid;
        }
    }

    return n;
}


int main() {

    return 0;
}