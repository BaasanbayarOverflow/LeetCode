#include <stdio.h>


int climbStairs(int n){
    if (n == 0 || n == 1 || n == 2) {
        return n;
    } 

    int ini = 1;
    int tmp = 2;
    int res = 0;
    for (int i = 0; i < n - 2; i++) {
        res = ini + tmp;
        ini = tmp;
        tmp = res;
    }

    return res;
}

int main() {
    int n = 0;

    printf_s("n - ");
    scanf_s("%d", &n);

    printf_s("output - %d", climbStairs(n));

    return 0; 
}