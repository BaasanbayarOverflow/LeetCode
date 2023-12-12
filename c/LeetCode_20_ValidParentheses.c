#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;


bool isValid(char *s) {
    int len = strlen(s);
    int *stack = (int*) malloc(len * sizeof(int));
    int top = -1;

    if (len % 2 != 0) {
        return false;
    }

    for (int i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1) {
                return false;
            } 

            char x = stack[--top];

            if (x == '(' && s[i] != ')') {
                return false;
            } else if (x == '{' && s[i] != '}') {
                return false;
            } else if (x == '[' && s[i] != ']') {
                return false;
            }
        }
    }

    return top == -1;
}


int main() {
	int size;
	char* str;

	fputs("Size of the string: ", stdout);
	scanf_s("%d%*c", &size);

	str = (char*)malloc(size * sizeof(char));
	
	fputs("String: ", stdout);
	fgets(str, size + 1, stdin);


	printf("%d", isValid(str));

	return 0;
}






/*
// BARELY FUNCTIONAL CODE


char reverseChar(char letter) {
	if (letter == '(') {
		return ')';
	}
	else if (letter == '[') {
		return ']';
	}
	else if (letter == '{') {
		return '}';
	}
	else {
		exit(0);
	}

	return 'a';
}

bool detect(char* s, int len) {
	int a_1 = 0;
	int a_2 = 0;
	int a_3 = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			a_1 += 1;
		}
		else if (s[i] == ')') {
			a_1 -= 1;
		}

		if (s[i] == '[') {
			a_2 += 2;
		}
		else if (s[i] == ']') {
			a_2 -= 2;
		}

		if (s[i] == '{') {
			a_3 += 3;
		}
		else if (s[i] == '}') {
			a_3 -= 3;
		}
	}

	if (a_1 == 0 && a_2 == 0 && a_3 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

bool isValid(char* s) {
	int len = 0;
	char* tmp = s;
	while (*tmp != '\0') {
		len++;
		*tmp++;
	}

	if (len > 10000) {
		return false;
	}

	if (len % 2 != 0) {
		return false;
	}

	int tmpInx = 0;
	int lock = 1;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			tmpInx = i;
			if (s[tmpInx + 1] == '\0') {
				return false;
			}
			else {
				char letter = s[tmpInx];
				int flag = tmpInx + 1;
				for (int j = tmpInx + 1; j < len; j++) {
					if (s[j] == reverseChar(letter)) {
						for (int z = tmpInx; z <= j; z++) {
							s[z] = '0';
						}
						if ((j - tmpInx) % 2 == 0) {
							return false;
						}
						else {
							if (lock == 1 && (j - tmpInx > 1)) {
								return false;
							}
							lock -= 1;
						}
						break;
					}
					flag += 1;
				}
				if (flag == len) {
					return false;
				}
			}
		}
	}

	return detect(s, len);
}
*/
