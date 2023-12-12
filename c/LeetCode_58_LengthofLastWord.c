#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;


int lengthOfLastWord(char* s) {
	int len = strnlen_s(s, 100);

	if (len <= 0) {
		return 0;
	}

	int counter = 0;
	bool looseLock = false;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			counter += 1;
			looseLock = true;
		}
		else if (looseLock && s[i] == ' ') {
			break;
		}
	}

	return counter;
}

int main() {
	int size = 0;

	fputs("Size of the sentence: ", stdout);
	scanf_s("%d%*c", &size);

	char* str = (char*)malloc(size * sizeof(char));
	fputs("Sentence: ", stdout);
	fgets(str, size, stdin);

	printf_s("Result: %d", lengthOfLastWord(str));

	return 0;
}