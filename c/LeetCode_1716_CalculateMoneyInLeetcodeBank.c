#include <stdio.h>
#include <stdlib.h>


int totalMoney(int n) {
    int total = 0;
    int adder = 0;
    int restarter = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 7 == 0) {
            adder = restarter;
            ++restarter;
        }
        
        total += adder;
        ++adder;
    }

    return total;
}


int main() {
    printf("%d ", totalMoney(20));

    return 0;
}