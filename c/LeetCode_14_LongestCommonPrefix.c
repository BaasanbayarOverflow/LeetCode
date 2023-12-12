#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 20

typedef enum {true, false} bool;


char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize > 200 || strsSize < 0) {
		return (char*)calloc(1, 1);
	}

	int len = 0, min = 1000;
	for (int i = 0; i < strsSize; i++) {
		//len = strnlen_s(strs[i], 100) - 1;
		len = strlen(strs[i]) - 1;
		if (min > len) {
			min = len;
		}
	}
	
	char fLetter;
	int tmpInx = 0;
	bool isBreak = false;
	for (int i = 0; i < min; i++) {
		fLetter = strs[0][i];
		for (int j = 0; j < strsSize; j++) {
			if (fLetter != strs[j][i]) {
				isBreak = true;
				break;
			}
		}
		if (isBreak) break;
		tmpInx += 1;
	}

	if (tmpInx != 0) {
		char* retVal = (char*)malloc(tmpInx * sizeof(char) + 1);
		for (int i = 0; i < tmpInx; i++) {
			retVal[i] = strs[0][i];
		}
		retVal[tmpInx] = '\0';
		return retVal;
	}

	return (char*)calloc(1, 1);
}


int main() {
	int size;
	char* word;
	char** sentence;

	fputs("Sentence size: ", stdout);
	scanf_s("%d%*c", &size);

	sentence = (char**)malloc(size * sizeof(char*));
	word = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
	for (int i = 0; i < size; i++) {
		sentence[i] = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
		fputs("New word: ", stdout);
		fgets(word, MAX_WORD_SIZE, stdin);
		strcpy_s(sentence[i], MAX_WORD_SIZE, word);
	}

	printf(longestCommonPrefix(sentence, size));

	free(sentence);
	free(word);
	return 0;
}