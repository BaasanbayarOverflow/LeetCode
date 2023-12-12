#include <stdio.h>
#include <math.h>

int mySqrt(int x) {
    if (x < 0) {
        return 0;
    }

    if (x < 2) {
        return x;
    }

    int min = 1; 
    int max = x;
    while (min <= max) {
        unsigned int ave = (min + max) / 2;
        if (ave * ave == x) {
            return ave;
        }
        else if (ave * ave < x) {
            min = ave + 1;
        }
        else {
            max = ave - 1;
        }
    }
    return max;
}

int main() {
	int x;
	scanf_s("%d", &x);
	printf("%d", mySqrt(x));

	return 0;
}