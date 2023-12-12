#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* largestOddNumber(char* num) {
    int inx = -1;
    int len = strlen(num) - 1;
    for (int i = len; i >= 0; --i) {
        if (num[i] % 2 == 1) {
            inx = i;
            break;
        }
    }

    num[inx + 1] = '\0';

    return num;
}


int main() {
    char *str = "52";
    
    largestOddNumber(str);

    return 0;
}



/*
def largestOddNumber(num: str) -> str:
    n = len(num)
    for i in range(n):
        number = num[(n - 1) - i]
        if (number % 2 == 1):
            return num[0 : (n - i)]        
    
    return ''
    

print(largestOddNumber("35427"))
*/