void reverseString(char* s, int sSize) {
    if (sSize <= 0) return;

    int low = 0;
    int high = sSize - 1; 

    while (low < high) {
        char tmp = s[low];
        s[low] = s[high];
        s[high] = tmp;

        ++low;
        --high;
    }
}