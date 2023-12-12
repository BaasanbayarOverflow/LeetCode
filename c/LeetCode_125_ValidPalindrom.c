#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {false, true} bool;


int getLength(char *s) {
    int counter = 0;
    while(s[counter] != '\0') {
        ++counter;
    }
    return counter;
}


bool isAscii(char c) {
    c = tolower(c);
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}


bool isPalindrome(char* s) {
    if (s == NULL) {
        return 1;
    }

    bool flag = true;

    int len = getLength(s);

    int i = 0; 
    int end = len - 1;
    while (i != end && i < end) {
        while (!isAscii(s[i])) {
            if (i == len - 1) { break; }
            ++i;
        }

        while (!isAscii(s[end])) {
            if (end == 0) { break; }
            --end;
        }

        if (!isAscii(s[i]) || !isAscii(s[end])) {
            break;
        } else if (tolower(s[i]) != tolower(s[end])) {
            flag = false;
        }

        ++i;
        --end;
    }

    return flag;
}


int main() {
    char *s = "A man, a plan, a canal: Panama";
    char *a = ",; W;:GlG:;l ;,";

    printf_s("%d", isPalindrome(a));

    return 0;
}


/*
while (i != end && i < end) {
    while (s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == ':') {
        ++i;
    }

    while (s[end] == ' ' || s[end] == ',' || s[end] == '.' || s[end] == ':') {
        --end;
    }

    if (tolower(s[i]) != tolower(s[end])) {
        flag = false;
    }

    ++i;
    --end;
}
*/