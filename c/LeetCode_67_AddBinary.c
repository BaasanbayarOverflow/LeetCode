#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * addBinary(char * a, char * b){
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char * output = (char *)malloc(sizeOutput + 1);
    int sum = 0;
    
    output[sizeOutput] = '\0';
    
    while(sizeA > 0 || sizeB > 0 || sum > 0) {
        
        if(sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;   
}

int main() {    
    int n = 0;
    char *a = NULL;
    char *b = NULL;

    printf_s("Size of the first string: ");
    scanf_s("%d%*c", &n);

    a = (char*) malloc(n * sizeof(char));
    fputs("String: ", stdout);
    fgets(a, n + 1, stdin);

    printf_s("Size of the second string: ");
    scanf_s("%*c%d%*c", &n);
    
    b = (char*) malloc(n * sizeof(char));
    fputs("String: ", stdout);
    fgets(b, n + 1, stdin);

    addBinary(a, b);

    free(a);
    free(b);

    return 0;
}


/*

int binary(int num) {
    int res = 0;
    int p = 0;
    int tmp = 0;
    while (num != 0) {
        tmp = num % 10;
        if (tmp == 1) {
            res += pow(2, p);
        }
        p += 1;
        num /= 10;
    }

    return res;
}

int decimal(int bin) {
    int tmp = 0;
    int res = 1;
    while (bin != 1) {
        tmp = bin % 2;
        res = (tmp == 0) ? (res * 10) : (res * 10 + 1);
        bin /= 2;  
    }
    return res;
}

char* string(int sum) {
    int len = 1;
    int tmp = sum;
    while (tmp != 1) {
        len += 1;
        tmp %= 10;
    }
    len += 1;

    char *r = NULL;
    r = (char*) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        tmp = sum % 10;
        r[i] = tmp + '0';
    }

    return r;
}

*/