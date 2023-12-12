#include <stdio.h>
#include <stdlib.h>


int addDigits(int num) {
    if (num == 0) return 0;
    return (num % 9 == 0) ? 0 : (num % 9);
}


int main() {

    return 0;
}