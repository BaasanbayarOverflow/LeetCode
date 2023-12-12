#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;


int strStr(char* haystack, char* needle) {
	int len_1 = strlen(haystack);
	int len_2 = strlen(needle);

	bool flag = false;
	int nothing = 0;
	int inx_i = 0;
	int inx_j = 0;
	while (inx_i < len_1) {
		if (haystack[inx_i] == needle[inx_j]) {
			flag = true;
			inx_j += 1;
		}
		else if (haystack[inx_i] != needle[inx_j] && flag) {
			inx_i = nothing;
			inx_j = 0;
			nothing += 1;
			flag = false;
		}

		inx_i += 1;

		if (flag && inx_j == len_2) {
			return inx_i - inx_j;
		}
	}

	return -1;
}


int main() {
	const int size = 50;
	char* haystack = (char*)malloc(size * sizeof(char));
	char* needle = (char*)malloc(size * sizeof(char));

	fputs("Haystack: ", stdout);
	fgets(haystack, size, stdin);

	fputs("Needle: ", stdout);
	fgets(needle, size, stdin);

	printf("%d", strStr(haystack, needle));

	return 0;
}