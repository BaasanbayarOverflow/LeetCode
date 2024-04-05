#include <stdio.h>
#include <stdlib.h>


int maxArea(int* height, int heightSize) {
    int low = 0;
    int high = heightSize - 1;
    int max_volume = 0;
    while (low < high) {
        int m_min = (height[low] > height[high]) ? height[high] : height[low];
        int volume = (high - low) * m_min;
        if (volume > max_volume) {
            max_volume = volume;
        }

        if (height[low] > height[high]) {
            --high;
        } else {
            ++low;
        }
    }

    return max_volume;
}


int main() {

    return 0;
}