#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {true, false} bool;

bool check(char* num, int loop, int sub) {
	for (int i = 0; i < loop; i++) {
		if (num[i] != num[loop * 2 - i - sub]) {
			return false;
		}
	}
	free(num);
	return true;
}

bool isPalindrome(int x) {
	if (x > 0) {
		int length = snprintf(NULL, 0, "%d", x) + 1;
		char* num = (char*)malloc(length * sizeof(char));
		
		snprintf(num, length, "%d", x);

		int loop = (int)(ceil((length - 1) / 2));
		if ((length - 1) % 2 == 0) {
			return check(num, loop, 1);
		}
		else {
			return check(num, loop, 0);
		}
	}
	else if (x == 0) {
		return true;
	}
	return false;
}

int main() {
	int x;

	fputs("Enter x - ", stdout);
	scanf_s("%d", &x);

	printf("%d", isPalindrome(x));

	return 0;
}