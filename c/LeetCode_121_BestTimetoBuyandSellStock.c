#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }

    int start = prices[0];
    int result = 0;

    for (int i = 1; i < pricesSize; ++i) {
        if (start > prices[i]) {
            start = prices[i];
        } else if (prices[i] - start > result) {
            result = prices[i] - start;
        }
    }

    return result;
}


int main() {
    int pr[] = {2,4,1};
    int *p = pr;
    printf("%d", maxProfit(p, 3));

    return 0;
}