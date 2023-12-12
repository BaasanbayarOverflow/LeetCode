#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 16

int sumTotal(int sum, int flag, int cat) {
	if (flag < cat) {
		sum += cat - (flag * 2);
	}
	else {
		sum += cat;
	}

	return sum;
}

int romanToInt(char *s) {
	const char* romans = "IVXLCDM";
	int _flag = 1001;
	int _sum = 0;

	if (strlen(s) > 15) {
		exit(0);
	}

	int _len = strlen(s);


	while (_len != 0) {
		if (strchr(romans, *s) != NULL) {
			
			switch (*s) {
			case 'I':
				_sum = sumTotal(_sum, _flag, 1);
				_flag = 1;
				break;
			case 'V':
				_sum = sumTotal(_sum, _flag, 5);
				_flag = 5;
				break;
			case 'X':
				_sum = sumTotal(_sum, _flag, 10);
				_flag = 10;
				break;
			case 'L':
				_sum = sumTotal(_sum, _flag, 50);
				_flag = 50;
				break;
			case 'C':
				_sum = sumTotal(_sum, _flag, 100);
				_flag = 100;
				break;
			case 'D':
				_sum = sumTotal(_sum, _flag, 500);
				_flag = 500;
				break;
			case 'M':
				_sum = sumTotal(_sum, _flag, 1000);
				_flag = 1000;
				break;
			};

			_len--;
			if (_len != 0) {
				*s++;
			}
		}
		else {
			exit(0);
		}
	}

	return _sum;
}

int main() {
	char* str; 
	int result;
	str = (char*)malloc(MAX_STRING_SIZE * sizeof(char));

	if (str == NULL) {
		fputs("Memory not allocated!", stdout);
		exit(0);
	}

	fputs("Enter string: ", stdout);
	fgets(str, MAX_STRING_SIZE, stdin);

	result = romanToInt(str);
	printf("Total: %d", result);

	free(str);

	return 0;
}
