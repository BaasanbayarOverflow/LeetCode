#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool; 


bool isHappy(int n) {
    for (int i = 0; i <= n; ++i) {
        int sum = 0; 
        while (n != 0) {
            int tmp = n % 10; 
            sum += tmp * tmp;
            n /= 10;
        }
        if (sum == 1) return 1;
        n = sum;
    }

    return 0;
}


int main() {
    printf("%d ", isHappy(19));

    return 0;
}