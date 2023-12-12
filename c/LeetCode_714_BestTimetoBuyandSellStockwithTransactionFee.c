#include <stdio.h>
#include <stdlib.h>


int max(int n_1, int n_2) {
    if (n_1 > n_2) {
        return n_1;
    }
    return n_2;
}


int maxProfit(int* prices, int pricesSize, int fee){
    int free = 0;
    int hold = -prices[0];

    for (int i = 0; i < pricesSize; i++) {
        int tmp = hold; 
        hold = max(hold, free - prices[i]);
        free = max(free, tmp + prices[i] - fee);
    }

    return free;
}


int main() {
    int arr_size = 0;

    fputs("Array size: ", stdout);
    scanf_s("%d", &arr_size);

    int* prices = (int*)malloc(arr_size * sizeof(int));
    for (int i = 0; i < arr_size; i++) {
        printf_s("Element[%d]:", i);
        scanf_s("%d", &prices[i]);
    }

    int fee = 0;
    fputs("Fee: ", stdout);
    scanf_s("%d", &fee);


    printf_s("Max profit: %d", maxProfit(prices, arr_size, fee));


    free(prices);

    return 0;
}