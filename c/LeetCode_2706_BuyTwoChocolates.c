#include <stdio.h>
#include <stdlib.h>

/*
void merge(int* prices, int l, int m, int h) {
    int size_1 = m - l + 1;
    int size_2 = h - m;

    int *arr_1 = (int*) malloc(size_1 * sizeof(int));
    int *arr_2 = (int*) malloc(size_2 * sizeof(int));
    for (int i = 0; i < size_1; ++i) {
        arr_1[i] = prices[l + i];
    }
    for (int i = 0; i < size_2; ++i) {
        arr_2[i] = prices[m + i + 1];
    }

    int i = 0;
    int j = 0;
    int inx = l;
    while (i < size_1 && j < size_2) {
        if (arr_1[i] <= arr_2[j]) {
            prices[inx] = arr_1[i];
            ++i;
        } else {
            prices[inx] = arr_2[j];
            ++j;
        }
        ++inx;
    } 

    while (i < size_1) {
        prices[inx] = arr_1[i];
        ++i;
        ++inx;
    }

    while (j < size_2) {
        prices[inx] = arr_2[j];
        ++j;
        ++inx;
    }
}


void mergeSort(int *prices, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(prices, low, mid);
        mergeSort(prices, mid + 1, high);
        merge(prices, low, mid, high);
    } 
}


int buyChoco(int* prices, int pricesSize, int money){
    mergeSort(prices, 0, pricesSize - 1);

    int sum = prices[0] + prices[1];
    return (sum > money) ? money : money - sum;
}
*/


int buyChoco(int* prices, int pricesSize, int money){
    int min = 100001;
    int min_m = min;
    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < min) {
            min_m = min;
            min = prices[i];
        } else if (min <= prices[i] && min_m > prices[i]) {
            min_m = prices[i];
        }
    }

    int sum = min + min_m;
    return (sum > money) ? money : money - sum;
}


int main() {
    int arr[15] = {98,54,6,34,66,63,52,39};
    int m = 8;

    printf("%d ", buyChoco(arr, 8, 62));

    return 0;
}